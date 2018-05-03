#include <unordered_set>
#include <iostream>
#include "iddfs.h"

using namespace std;

std::shared_ptr<const state> iddfs_inside (std::shared_ptr<const state> curr, unsigned long long int depth, unordered_set<unsigned long long int > beenIn);

// Naimplementujte efektivni algoritmus pro nalezeni nejkratsi (respektive nej-
// levnejsi) cesty v grafu. V teto metode mate ze ukol naimplementovat pametove
// efektivni algoritmus pro prohledavani velkeho stavoveho prostoru. Pocitejte
// s tim, ze Vami navrzeny algoritmus muze bezet na stroji s omezenym mnozstvim
// pameti (radove nizke stovky megabytu). Vhodnym pristupem tak muze byt napr.
// iterative-deepening depth-first search.
//
// Metoda ma za ukol vratit ukazatel na cilovy stav, ktery je dosazitelny pomoci
// nejkratsi/nejlevnejsi cesty.


std::shared_ptr<const state> iddfs(std::shared_ptr<const state> root) {
    unordered_set<unsigned long long int > beenIn;
    int it = 1;
    beenIn.insert(root->get_identifier());
    while(true) {
        cout << "Outside" << endl;
        shared_ptr<const state> found = iddfs_inside(root, it, beenIn);
        if(found!= nullptr) return found;
        else beenIn.clear();
        beenIn.insert(root->get_identifier());
        ++it;
        cout << it << endl;
    }
}

std::shared_ptr<const state> ret;

std::shared_ptr<const state> iddfs_inside (std::shared_ptr<const state> curr, unsigned long long int depth, unordered_set<unsigned long long int > beenIn){
    cout << "Inside" << endl;
    cout << depth << endl;
    if(depth==0 && curr->is_goal()) return curr;
    else if(depth>0){
#pragma omp parallel
        {
#pragma omp single
            {
                for (auto nd : curr->next_states()) {

                    unsigned long long int nextDepth = depth - 1;
                    unsigned long long int id = nd->get_identifier();
                    if (beenIn.find(id) == beenIn.end()) {
                        beenIn.insert(id);
                        std::shared_ptr<const state> next = nullptr;
                        #pragma omp task
                        {
                            next = iddfs_inside(nd, nextDepth, beenIn);

                            if (next->is_goal()) {
                                ret = next;
                                #pragma omp cancel taskgroup
                            }
                        }
                    }
                }
            }
        };
    } else return nullptr;
    return ret;
}