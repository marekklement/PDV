#ifndef DATABASEQUERIES_QUERY_H
#define DATABASEQUERIES_QUERY_H

#include <vector>
#include <functional>
#include <atomic>
#include <iostream>

template<typename row_t>
using predicate_t = std::function<bool(const row_t &)>;



template<typename row_t>
bool is_satisfied_for_all(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table);

template<typename row_t>
bool is_satisfied_for_any(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table);


template<typename row_t>
bool is_satisfied_for_all(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table) {
    // Doimplementujte telo funkce, ktera rozhodne, zda pro VSECHNY dilci dotazy (obsazene ve
    // vektoru 'predicates') existuje alespon jeden zaznam v tabulce (reprezentovane vektorem
    // 'data_table'), pro ktery je dany predikat splneny.

    // Pro inspiraci si prostudujte kod, kterym muzete zjistit, zda prvni dilci dotaz plati,
    // tj., zda existuje alespon jeden radek v tabulce, pro ktery predikat reprezentovany
    // funkci predicates[i] plati:

    //throw "Not implemented yet";
    unsigned int pred_count = predicates.size();
    std::atomic<bool> global_satisfied = {true};
#pragma omp parallel for
    for (int j = 0; j < pred_count; j++) {
        //#pragma omp cancellation point parallel
        auto &first_predicate = predicates[j];        // Funkce reprezentujici predikat prvniho poddotazu

        unsigned int row_count = data_table.size();
        bool one_satisfied = false;
        for (unsigned int i = 0; i < row_count; i++) {
            auto &row = data_table[i];                // i-ty radek tabulky ...
            bool is_satisfied = first_predicate(row);  // ... splnuje prvni predikat, pokud funkce first_predicate
            if (is_satisfied) {
                one_satisfied = true;
                break;

            }
        }
        if(!one_satisfied) {
            global_satisfied = false;
#pragma omp cancel for
        }

        // Radek, pro ktery by prvni predikat platil, jsme nenasli. Prvni dilci dotaz je tedy
        // nepravdivy
        //return false;
    }
    return global_satisfied;
}

template<typename row_t>
bool is_satisfied_for_any(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table) {
    unsigned int pred_count = predicates.size();
    unsigned int row_count = data_table.size();
    bool global_satisfied = false;
    bool ret = false;
    #pragma omp parallel for
    for (unsigned int i = 0; i < row_count; i++) {
        auto &row = data_table[i];
        bool  is_satisfied = false;
        for (int j = 0; j < pred_count; ++j) {
            is_satisfied = predicates[j](row);
            if (is_satisfied) {
                global_satisfied = true;
                break;
            }
        }
        if(global_satisfied){
            ret = true;
            #pragma omp cancel for
        }
    }
    return ret;
}

#endif //DATABASEQUERIES_QUERY_H
