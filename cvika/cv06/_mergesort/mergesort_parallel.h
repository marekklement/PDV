#ifndef SORTING_MERGESORT_PARALLEL_H
#define SORTING_MERGESORT_PARALLEL_H

#include "mergesort.h"
#include "mergesort_sequential.h"

template <typename elem_t>
void mergesort_parallel_worker(elem_t *data, unsigned long size, elem_t *tmp);


template <typename elem_t>
void mergesort_parallel(std::vector<elem_t> & data) {
    const size_t size = data.size();
    std::unique_ptr<elem_t> tmp(new elem_t[size]);

    // Doimplementujte paralelni verzi algoritmu mergesort za pouziti 'task'
    // v OpenMP. Muzete se inspirovat sekvencni verzi algoritmu v souboru
    // 'mergesort_sequential.h' a muzete take pouzit sekvencni metody 'merge'
    // pro sliti dvou serazenych poli do jednoho (implementovanou v souboru
    // 'mergesort.h'). Pravdepodobne si budete potrebovat vytvorit pomocnou
    // funkci. Tu uvodte pomoci 'template <typename elem_t>', abyste meli
    // pristup k typu 'elem_t'.

    throw "Not implemented yet";
}



#endif //SORTING_MERGESORT_PARALLEL_H
