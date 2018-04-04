#ifndef SORTING_COUNTINGSORT_H
#define SORTING_COUNTINGSORT_H

#include <vector>
#include <limits>
#include <cstdlib>
#include <chrono>
#include <omp.h>
#include "../_prefixsum/prefixsum.h"

template <typename elem_t>
void counting_sequential(std::vector<elem_t> & data) {
    elem_t min = std::numeric_limits<elem_t>::max();
    elem_t max = std::numeric_limits<elem_t>::min();

    for(auto && el : data) {
        if(el < min) min = el;
        if(el > max) max = el;
    }

    const size_t range = max - min + 1;
    std::vector<unsigned int> counts(range);

    for(auto && el : data) {
        ++counts[el-min];
    }

    unsigned int idx = 0;
    for(unsigned int i = 0 ; i < range ; i++) {
        unsigned int count = counts[i];
        unsigned int number = min + i;
        for(unsigned int k = 0 ; k < count ; k++) {
            data[idx++] = number;
        }
    }
}

template <typename elem_t>
void counting_parallel(std::vector<elem_t> & data) {
    // Naimplementujte paralelni verzi counting-sortu. Zamyslete se nad tim,
    // jak muzete paralelizovat:
    //   1) Nalezeni rozsahu hodnot v poli
    //   2) Napocitani "histogramu"
    //   3) "Vypsani" histogramu do pole 'data'
    // Inspirovat se muzete sekvencni implementaci

    elem_t min = std::numeric_limits<elem_t>::max();
    elem_t max = std::numeric_limits<elem_t>::min();

    unsigned int size = data.size();
    unsigned int numThreads = omp_get_max_threads();

    // Provedeme nad polem redukci pocitajici minimum a maximum
    #pragma omp parallel for reduction(max:max) reduction(min:min)
    for(int i = 0; i < size; i++) {
        auto &el = data[i];
        if(el < min) min = el;
        if(el > max) max = el;
    }

    const size_t range = max - min + 1;

    std::vector<unsigned int> histogram;

    // Vypocet histogramu muzeme provest dvema zpusoby
    bool histogramByAtomic = !true;

    if (histogramByAtomic){
        // Prvni zpusob je vhodny, pokud data maji vetsi rozptyl
        std::vector<unsigned int> histogramAtomic(range);
        // Jednotlive cetnosti vyscitame atomicky
        #pragma omp parallel for
        for(int i = 0; i < size; i++) {
            #pragma omp atomic
            histogramAtomic[data[i] - min]++;
        }
        histogram.swap(histogramAtomic);
    }
    else{
        // Druhy zpusob je lepsi, pokud ma kazdy prvek v poli mnoho vyskytu
        // Vytvorime si pro kazde vlakno jeden histogram
        std::vector<std::vector<unsigned int>> histogramPerThread(numThreads);
        for (int i = 0; i < numThreads; i++)
            histogramPerThread[i].resize(range);

        #pragma omp parallel
        {
            std::vector<unsigned int> &localHistogram = histogramPerThread[omp_get_thread_num()];
            // Histogram spocitame pro kazde vlakno zvlast
            #pragma omp for
            for(int i = 0; i < size; i++)
                localHistogram[data[i] - min] ++;
        };

        // Nakonec vsechny histogramy slijeme dohromady
        #pragma omp parallel for
        for(int i = 0; i < range; i++){
            for(int j = 1; j < numThreads; j++){
                histogramPerThread[0][i] += histogramPerThread[j][i];
            }
        }

        histogram.swap(histogramPerThread[0]);
    }

    // Abychom mohli setridene pole vypisovat paralelne, musi kazde vlakno vedet,
    // na jake indexy ma zapisovat jake prvky, bez toho aby muselo cekat na
    // vypsani prvku mensich. Takovou informaci lze ziskat vypoctem prefixni
    // sumy (viz slidy).

    prefix_sum_parallel(&histogram[0], range);


    // Nakonec jiz staci pole vypsat. Diky prefixni sume presne vime,
    // jaky prvek ma byt na jakem indexu nezavisle na poctu mensich prvku
    #pragma omp parallel for
    for(unsigned int i = 0 ; i < range ; i++) {
        unsigned int begin  = i == 0 ? 0 : histogram[i-1];
        unsigned int end = histogram[i];
        unsigned int number = min + i;
        for(unsigned int k = begin ; k < end ; k++) {
            data[k] = number;
        }
    }
}

#endif //SORTING_COUNTINGSORT_H
