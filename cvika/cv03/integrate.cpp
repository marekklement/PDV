#include "integrate.h"

#include <omp.h>
#include <cmath>

double
integrate_sequential(std::function<double(double)> integrand, double a, double step_size, int step_count) {

    // Promenna kumulujici obsahy jednotlivych obdelniku
    double acc = 0.0;
    for(int i = 0; i<step_count;++i){
        double begin = a + step_size*i;
        double ned = a + step_size*(i+1);
        acc += integrand(((ned - begin)/2)+begin)*step_size;
    }

    
    // Celkovy obsah aproximuje hodnotu integralu funkce
    return acc;
}

double
integrate_omp_critical(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    double acc = 0.0;

#pragma omp parallel
    {
        const int numTreads = omp_get_num_threads();
        const int threadId = omp_get_thread_num();
        const int partSize = 1 + step_count / numTreads;

        int beg = partSize * threadId;
        int end = std::min(partSize * (threadId + 1), step_count);
        double accLoc = 0.0;
        for (int i = beg; i < end; ++i) {
            double begin = a + step_size * i;
            double ned = a + step_size * (i + 1);
            accLoc += integrand(((ned - begin) / 2) + begin) * step_size;
        }
#pragma omp critical
        {
            acc += accLoc;
        };
    };
    return acc;
}

double integrate_omp_atomic(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    double acc = 0.0;

#pragma omp parallel
    {
        const int numTreads = omp_get_num_threads();
        const int threadId = omp_get_thread_num();
        const int partSize = 1 + step_count / numTreads;

        int beg = partSize * threadId;
        int end = std::min(partSize * (threadId + 1), step_count);
        double accLoc = 0.0;
        for (int i = beg; i < end; ++i) {
            double begin = a + step_size * i;
            double ned = a + step_size * (i + 1);
            accLoc += integrand(((ned - begin) / 2) + begin) * step_size;
        }
#pragma omp atomic
        acc += accLoc;

    };
    return acc;
}


double integrate_omp_reduction(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    double acc = 0.0;

    //TODO
    // Rozdelte celkovy interval na podintervaly prislusici jednotlivym vlaknum
    // Identifikujte kritickou sekci, kde musi dojit k zajisteni konzistence mezi vlakny
    throw "Not implemented yet";

    return acc;
}

double integrate_omp_for_static(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    // Promenna kumulujici obsahy jednotlivych obdelniku
    double acc = 0.0;

    //TODO
    //rozsirte integrate_omp_reduction o staticke rozvrhovani
    throw "Not implemented yet";
    
    // Celkovy obsah aproximuje hodnotu integralu funkce
    return acc;
}

double integrate_omp_for_dynamic(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    // Promenna kumulujici obsahy jednotlivych obdelniku
    double acc = 0.0;

    //TODO
    //rozsirte integrate_omp_reduction o dynamicke rozvrhovani
    throw "Not implemented yet";
    
    // Celkovy obsah aproximuje hodnotu integralu funkce
    return acc;
}
