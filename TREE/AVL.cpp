#include<iostream>
#define SPACE 10 


using namespace std;

class Treenode{
public:
    int value;
    Treenode* left;
    Treenode* right;

    Treenode(): value{0},left{NULL},right{NULL} {}
    Treenode(int data): value{data},left{NULL},right{NULL} {}

};

class AVLTree{
public:
    Treenode* root;

    AVLTree(): root{NULL} {}

    bool isTreeEmpty(){
        return ((!root)?true:false);
    }

    int height(Treenode* r){
        if(r==NULL) return -1;
        else{
            int lheight = height(r->left);
            int rheight = height(r->right);
            if(lheight>rheight){
                return (lheight+1);
            }
            else{
                return (rheight+1);
            }
        }
    }
};