#include "sort.h"
#include <iostream>

void inside_func(std::vector<std::string *> &vector_to_sort, const MappingFunction &mappingFunction, unsigned long alphabet_size, unsigned long string_lengths, long begin, long end) ;

void radix_par(std::vector<std::string *> &vector_to_sort, const MappingFunction &mappingFunction,
               unsigned long alphabet_size, unsigned long string_lengths) {
    std::vector<std::string *> buckets[alphabet_size];
    for (auto str : vector_to_sort) {
        unsigned long pos = mappingFunction((*str).at(0));
        buckets[pos].push_back(str);
    }
    #pragma omp parallel
    {
        #pragma omp single
        {
            unsigned long begin = 0;
            unsigned long end = 0;
            vector_to_sort.clear();
            int cnt = 0;
            while (cnt<alphabet_size) {
                for (auto k : buckets[cnt]) {
                    vector_to_sort.push_back(k);
                }
                end += buckets[cnt].size();
                #pragma omp task
                inside_func(vector_to_sort, mappingFunction, alphabet_size, string_lengths, begin, end);
                //
                begin += buckets[cnt].size();
                buckets[cnt].clear();
                ++cnt;

            }
        }
    }
}

void inside_func(std::vector<std::string *> &vector_to_sort, const MappingFunction &mappingFunction, unsigned long alphabet_size, unsigned long string_lengths, long begin, long end) {
    std::vector<std::string *> buckets[alphabet_size];
    for (long i = string_lengths - 1; i >= 1; --i) {
        for (long j = begin; j < end; ++j) {
            std::string *str = vector_to_sort[j];
            unsigned long pozition = mappingFunction((*str).at(i));
            buckets[pozition].push_back(str);
        }
        long cnt = begin;
        for (int k = 0; k < alphabet_size; ++k) {
            long ff = buckets[k].size();
            for (int j = 0; j < ff; ++j) {
                vector_to_sort[cnt] = buckets[k][j];
                ++cnt;
            }
            buckets[k].clear();
        }
    }
}