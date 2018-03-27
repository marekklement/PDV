// V teto domaci uloze se Vas budeme snazit presvedcit, ze vykon vasi implementace zavisi do znacne miry na podobe
// vstupnich dat. Pri navrhu efektivnich algoritmu byste se tedy meli rozhodovat i na zaklade datove sady.
//
// Vasim ukolem je doimplementovat 4 ruzne metody na pocitani sumy kazdeho vstupniho vektoru ("data").
// V kazde metode budete pouzitivat OpenMP, ale pokazde trochu jinym zpusobem. Rychlost vypoctu Vasi implementace
// budeme porovnavat s nasi referencni implementaci. Vychazet muzete z metody sumsOfVectors_sequential implementovane
// v _executor/Executor.cpp.

#include <iostream>
#include <numeric>
#include <algorithm>
#include <omp.h>
#include "SumsOfVectors.h"

void
sumsOfVectors_omp_per_vector(const vector<vector<int8_t>> &data, vector<long> &solution, unsigned long minVectorSize) {
    // V teto metode si vyzkousite paralelizaci na urovni vektoru. Naimplementujte paralelni pristup
    // k vypocteni sum jednotlivych vektoru (sumu vektoru data[i] ulozte do solution[i]). V teto
    // funkci zpracovavejte jednotlive vektory sekvencne a paralelizujte nalezeni maxima v jednom
    // konkretnim vektoru. Tento pristup by mel byt zejmena vhodny, pokud mate maly pocet vektoru
    // velke delky.
    unsigned long sz = data.size();
    for (unsigned long i = 0; i < sz; ++i) {
        long temp = 0;
        unsigned long size = data[i].size();
#pragma omp parallel reduction(+:temp)
#pragma omp for
        for (unsigned long j = 0; j < size; ++j) {
            temp += data[i][j];
        }
        solution[i] = temp;
    }

}

void sumsOfVectors_omp_static(const vector<vector<int8_t>> &data, vector<long> &solution,
                              unsigned long minVectorSize) {
    // Pokud vektory, ktere zpracovavame nejsou prilis dlouhe, ale naopak jich musime zpracovat
    // velky pocet, muzeme zparalelizovat vnejsi for smycku, ktera prochazi pres jednotlive
    // vektory. Vyuzijte paralelizaci pres #pragma omp parallel for se statickym schedulingem.
    unsigned long sz = data.size();
#pragma omp parallel for schedule(static)
    for (unsigned long i = 0; i < sz; ++i) {
        unsigned long size = data[i].size();
        long temp = 0;
        for (int j = 0; j < size; ++j) {
            temp += data[i][j];
        }
        solution[i] = temp;
    }
}

void sumsOfVectors_omp_dynamic(const vector<vector<int8_t>> &data, vector<long> &solution,
                               unsigned long minVectorSize) {
    // Na cviceni jsme si ukazali, ze staticky scheduling je nevhodny, pokud praci mezi
    // jednotliva vlakna nedokaze rozdelit rovnomerne. V teto situaci muze byt vhodnym
    // resenim pouzitim dynamickeho schedulingu. Ten je rovnez vhodny v situacich, kdy
    // nevime predem, jak dlouho budou jednotlive vypocty trvat. Dani za to je vyssi
    // rezie pri zjistovani indexu 'i', ktery ma vlakno v dane chvili zpracovavat.
    unsigned long sz = data.size();
#pragma omp parallel for schedule(dynamic)
    for (unsigned long i = 0; i < sz; ++i) {
        unsigned long size = data[i].size();
        long temp = 0;
        for (int j = 0; j < size; ++j) {
            temp += data[i][j];
        }
        solution[i] = temp;
    }

}

void sumsOfVectors_omp_shuffle(const vector<vector<int8_t>> &data, vector<long> &solution,
                               unsigned long minVectorSize) {
    // Dalsi moznosti, jak se vyhnout problemum pri pouziti statickeho schedulingu (tj.,
    // zejmena nevyvazenemu rozdeleni prace) je predzpracovani dat. V teto funkci zkuste
    // data pred zparalelizovanim vnejsi for smycky (se statickym schedulingem) nejprve
    // prohazet. To samozrejme predpoklada, ze cas potrebny na predzpracovani je radove
    // mensi, nez zisk, ktery ziskame nahrazenim dynamickeho schedulingu za staticky.
    //
    // Tip: Abyste se vyhnuli kopirovani vektoru pri "prohazovani" (ktere muze byt velmi
    // drahe!), muzete prohazovat pouze pointery na vektory. Alternativou je vytvorit si
    // nejprve pole nahodne serazenych indexu a ty pak pouzit pro pristup k poli.
    // Uzitecnymi metodami mohou byt metody std::iota(...) (ktera Vam vygeneruje posloupnost
    // indexu) a std::random_shuffle(...), ktera zajisti nahodne prohazeni prvku.
    int size = data.size();
    vector<int> schufeled (size);
    std::iota(schufeled.begin(), schufeled.end(), 0);
    std::random_shuffle(schufeled.begin(), schufeled.end());
    const unsigned long size2 = schufeled.size();
#pragma omp parallel for schedule(static)
    for (auto i = 0; i < size2; ++i) {
        auto k = schufeled[i];
        unsigned long end = data[k].size();
        long temp = 0;
        for (int j = 0; j < end; ++j) {
            temp += data[k][j];
        }
        solution[k] = temp;
    }
}
