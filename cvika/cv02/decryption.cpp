//
// Created by karel on 12.2.18.
//

#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include "decryption.h"

using namespace std;

void decrypt_sequential(const PDVCrypt &crypt, std::vector<std::pair<std::string, enc_params>> &encrypted, unsigned int numThreads) {
    // V sekvencni verzi je pocet vlaken (numThreads) ignorovany
    const unsigned long size = encrypted.size();
    for(unsigned long i = 0 ; i < size ; i++) {
        auto & enc = encrypted[i];
        crypt.decrypt(enc.first, enc.second);
    }
}

void decrypt_openmp(const PDVCrypt &crypt, std::vector<std::pair<std::string, enc_params>> &encrypted, unsigned int numThreads) {
    const unsigned long size = encrypted.size();

    #pragma omp parallel for num_threads(numThreads)
    for(unsigned long i = 0 ; i < size ; i++) {
        auto & enc = encrypted[i];
        crypt.decrypt(enc.first, enc.second);
    }
}

std::mutex mut;

void decrypt_threads_1(const PDVCrypt &crypt, std::vector<std::pair<std::string, enc_params>> &encrypted, unsigned int numThreads) {
    const unsigned long size = encrypted.size();
    unsigned long i = 0;
    
    // process je "vnorena" funkce (lambda funkce) void process(), ktera ma pristup
    // ke vsem promennym
    auto process = [&]() {
        while(i < size) {
            auto & enc = encrypted[i];
            i++;
            crypt.decrypt(enc.first, enc.second);
        }
    };
    
    // Spustte 'numThreads' vlaken, ktera budou spolecne resit desifrovani retezcu!
    // Vlakna budou desifrovat za pouziti funkce 'process'
    std::vector<std::thread> v;
    for (int j = 0; j < numThreads; ++j) {
        v.push_back(std::thread(process));
    }
    for (int k = 0; k < numThreads; ++k) {
        v[k].join();
    }
    //throw "Not implemented yet";

}

void decrypt_threads_2(const PDVCrypt &crypt, std::vector<std::pair<std::string, enc_params>> &encrypted, unsigned int numThreads) {

    const unsigned long size = encrypted.size();
    unsigned long i = 0;

    // process je "vnorena" funkce (lambda funkce) void process(), ktera ma pristup
    // ke vsem promennym
    auto process = [&]() {
        while(i < size) {
            std::unique_lock<std::mutex> locker(mut);
            auto & enc = encrypted[i];
            i++;
            locker.unlock();
            crypt.decrypt(enc.first, enc.second);
        }
    };

    // Spustte 'numThreads' vlaken, ktera budou spolecne resit desifrovani retezcu!
    // Vlakna budou desifrovat za pouziti funkce 'process'
    std::vector<std::thread> v;
    for (int j = 0; j < numThreads; ++j) {
        v.push_back(std::thread(process));
    }
    for (int k = 0; k < numThreads; ++k) {
        v[k].join();
    }
    // Opravte problem vznikly v metode 'decrypt_threads_1' pomoci mutexu
    //throw "Not implemented yet";
}

void decrypt_threads_3(const PDVCrypt &crypt, std::vector<std::pair<std::string, enc_params>> &encrypted, unsigned int numThreads) {
    const unsigned long size = encrypted.size();
    //unsigned long i = 0;
    std::atomic<unsigned long> i { 0 };

    // process je "vnorena" funkce (lambda funkce) void process(), ktera ma pristup
    // ke vsem promennym
    auto process = [&]() {
//        std::unique_lock<std::mutex> locker(mut);
        while(i < size) {
            unsigned long p = i++;
            if(p<size){
                auto & enc = encrypted[p];
                //i++;
                crypt.decrypt(enc.first, enc.second);
            }
        }
    };

    // Spustte 'numThreads' vlaken, ktera budou spolecne resit desifrovani retezcu!
    // Vlakna budou desifrovat za pouziti funkce 'process'
    std::vector<std::thread> v;
    for (int j = 0; j < numThreads; ++j) {
        v.push_back(std::thread(process));
    }
    for (int k = 0; k < numThreads; ++k) {
        v[k].join();
    }
    // Opravte problem vznikly v metode 'decrypt_threads_1' pomoci atomicke promenne 
    //throw "Not implemented yet";
}

void decrypt_threads_4(const PDVCrypt &crypt, std::vector<std::pair<std::string, enc_params>> &encrypted, unsigned int numThreads) {

    // Doplnte logiku vypoctu disjunktnich rozsahu pro jednotliva vlakna
    // Kod pro spusteni vlaken (a predani rozsahu) je jiz hotovy. Vasim
    // cilem je spocitat hodnoty promennych 'begin' a 'end' pro kazde
    // vlakno.
    //throw "Not implemented yet";

    const unsigned long size = encrypted.size();
    vector<thread> threads;
    for(unsigned int t = 0 ; t < numThreads ; t++) {

        // Doplnte vypocet rozsahu pro t-te vlakno zde:
        unsigned long begin = 0;
        unsigned long end = 0;

        threads.emplace_back([&](unsigned long begin, unsigned long end) {
            for(unsigned int i = begin ; i < end ; i++) {
                auto & enc = encrypted[i];
                crypt.decrypt(enc.first, enc.second);
            }
        }, begin, end);
    }
    for(unsigned int t = 0 ; t < numThreads ; t++) {
        threads[t].join();
    }

}
