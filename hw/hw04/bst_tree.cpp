#include <functional>
#include "bst_tree.h"

void bst_tree::insert(long long data) {
    node * new_node = new node(data);
    node* nd = nullptr;

    // Naimplementujte zde vlaknove-bezpecne vlozeni do binarniho vyhledavaciho stromu

    if(root == nullptr){
        //std::cout << "Fuck\n";
        if(root.compare_exchange_strong(nd,new_node))
            return;
        else return insert(data);
    }

    node* currParr = root;
    do{
        //std::cout << "Still inside?\n";
        if(data>currParr->data){
            if(currParr->right == nullptr){
                if(currParr->right.compare_exchange_strong(nd,new_node))
                    return;
            } else {
                currParr = currParr->right;
            }
        } else {
            if(currParr->left == nullptr){
                if(currParr->left.compare_exchange_strong(nd,new_node))
                    return;
            } else {
                currParr = currParr->left;
            }
        }
    } while(true);

}

bst_tree::~bst_tree() {
    // Rekurzivni funkce pro pruchod stromu a dealokaci pameti prirazene jednotlivym
    // uzlum
    std::function<void(node*)> cleanup = [&](node * n) {
        if(n != nullptr) {
            cleanup(n->left);
            cleanup(n->right);

            delete n;
        }
    };
    cleanup(root);
}
