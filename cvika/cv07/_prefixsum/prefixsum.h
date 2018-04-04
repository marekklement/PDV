#ifndef SORTING_PREFIXSUM_H
#define SORTING_PREFIXSUM_H

#include <cstdlib>
#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <cmath>

template <typename T>
void prefix_sum_sequential(T * data, const size_t size);

template <typename T>
void prefix_sum_parallel(T * data, const size_t size);



template <typename T>
void prefix_sum_sequential(T * data, const size_t size) {
    for(size_t i = 1 ; i < size ; i++) {
        data[i] += data[i-1];
    }
}



template <typename T>
void prefix_sum_parallel(T * data, const size_t size) {
    #pragma omp parallel
    {
        // Rozdelte vypocet prefixni sumy pole mezi jednotliva vlakna
        // Zamyslete se, jak byste se mohli "vyhnout" zavislosti sumy
        // na prefixni sume predchazejicich prvku. (Teto zavislosti se
        // nelze vyhnout - ale mozna by nam stacilo "vysbirat" vysledky
        // ostatnich vlaken a nemuseli bychom prochazet cele pole?)
        //
        // Zkuste se nad timto problemem zamyslet - my se Vam budeme
        // snazit pokladat otazky, ktere Vas doufame dovedou k reseni.
    }

    // Sdileny vektor sum prvku v castech pole prirazenych jednotlivym vlaknum
    std::vector<T> sums(omp_get_max_threads());

    #pragma omp parallel
    {
        // Predpocitame si kterou cast pole bude zpracovavat ktere vlakno
        const unsigned int chunk_size = 1 + size / omp_get_num_threads();
        const unsigned int thread = omp_get_thread_num();
        const unsigned int begin = thread * chunk_size;
        unsigned int end = (thread + 1) * chunk_size;
        if (end > size) end = size;

        // Spocitame sumu prvku v prirazene casti pole
        T acc = 0;
        for (unsigned int i = begin; i < end; i++) {
            acc += data[i];
        }

        // Zapiseme do sdileneho vektoru
        sums[thread] = acc;

        // Pockame, az vsechny vlakna spoctou sumu ve sve casti
        #pragma omp barrier

        // Zjistime sumu prvku v castech pred prirazenou casti
        T pre = 0;
        for(unsigned int i = 0 ; i < thread ; i++) {
            pre += sums[i];
        }

        // Tuto sumu pricteme k prvnimu prvku v prirazene casti
        data[begin] += pre;
        // Spocitame prefixni sumu pres prirazenou cast
        for(unsigned int i = begin + 1 ; i < end ; i++) {
            data[i] += data[i-1];
        }
    }
}


#endif //SORTING_PREFIXSUM_H
