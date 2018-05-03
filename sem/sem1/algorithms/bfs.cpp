#include <iostream>
#include "bfs.h"
#include <unordered_set>
#include <omp.h>
#include <queue>

using namespace std;

// Naimplementujte efektivni algoritmus pro nalezeni nejkratsi cesty v grafu.
// V teto metode nemusite prilis optimalizovat pametove naroky, a vhodnym algo-
// ritmem tak muze byt napriklad pouziti prohledavani do sirky (breadth-first
// search.
//
// Metoda ma za ukol vratit ukazatel na cilovy stav, ktery je dosazitelny pomoci
// nejkratsi cesty.
std::shared_ptr<const state> bfs2(std::shared_ptr<const state> root) {
    unordered_set<unsigned long long int > beenIn;
    queue<std::shared_ptr<const state>> fronta;
    fronta.push(root);
    shared_ptr<const state> curr;
    shared_ptr<const state> ret = nullptr;
    bool end = false;
    int vrstva = 0;
    while (!fronta.empty() && !end) {
        curr = fronta.front();
        fronta.pop();
        while (curr->current_cost() == vrstva) {

            if (curr->is_goal()) {
                ret = curr;
                end = true;
            }
            vector<std::shared_ptr<const state>> nxt = curr->next_states();
            unsigned long long int currId = curr->get_identifier();
            for (auto state : nxt) {
                //sleep(2);
                unsigned long long int id = state->get_identifier();

                if (beenIn.find(id) == beenIn.end()) {
                    fronta.push(state);
                }
            }
            beenIn.insert(currId);
            curr = fronta.front();
            fronta.pop();
        }
        fronta.push(curr);
        vrstva++;
    }
    return ret;


}

std::shared_ptr<const state> bfs(std::shared_ptr<const state> root) {
    unordered_set<unsigned long long int > beenIn;
    vector<shared_ptr<const state>> vrsNodes;
    vector<shared_ptr<const state>> tempNodes;
    vrsNodes.push_back(root);
    shared_ptr<const state> ret;
    bool end = false;
    beenIn.insert(root->get_identifier());
    while (!vrsNodes.empty() && !end) {

#pragma omp parallel for
        for (unsigned long i = 0; i < vrsNodes.size(); ++i) {
            if(end){
                continue;
            }
            shared_ptr<const state> node = vrsNodes.at(i);
            //            std::cout << node->get_identifier() << std::endl;
            //            std::cout << node->current_cost() <<
            // std::endl;
            vector<shared_ptr<const state>> nxt = node->next_states();

            unsigned long long int currId = node->get_identifier();
            for (auto state : nxt) {
#pragma omp cancelation point
                //std::cout << state->current_cost() << std::endl;
                //sleep(2);
                if (state->is_goal()) {
                    //cout << "End" << endl;
#pragma omp critical
                    {
                        ret = state;
                    };

                    end = true;
#pragma omp cancel for
                }
                unsigned long long int id = state->get_identifier();
                    if (beenIn.find(id) == beenIn.end()) {
#pragma omp critical
                        {
                            beenIn.insert(id);
                            tempNodes.push_back(state);
                        }
                    }
            }
            //beenIn.insert(currId);
        }
        if(!end) {
            vrsNodes = tempNodes;
            tempNodes.clear();

        } else break;
    }


    return ret;


}