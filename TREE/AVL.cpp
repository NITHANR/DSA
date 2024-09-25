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

    int getBalanceFactor(Treenode* r){
        if(r==NULL){
            return -1;
        }
        else{
            return (height(r->left) - height(r->right));
        }
    }

    Treenode* rightRotate(Treenode* r){
        Treenode* x =r->left;
        Treenode* SubTree =x->right;
        // roations
        x->right=r;
        r->left=SubTree;
        return x;
    }

    Treenode* leftRotate(Treenode* r){
        Treenode* x = r->right;
        Treenode* subTree = x->left;
        // rotation
        x->left=r;
        r->right=subTree;
        return x;
    }

    Treenode* insert(Treenode* r,Treenode* new_node){
        if(r==NULL){
            r=new_node;
            cout<<"Inserted at root\n";
            return r;
        }

        if(new_node->value<r->value){
            r->left=insert(r->left,new_node);
        }
        else if(new_node->value>r->value){
            r->right=insert(r->right,new_node);
        }
        else{
            cout<<"No duplication allowed\n";
            return r;
        }

        int bf = getBalanceFactor(r);

        // ll imbal
        if(bf>1 && new_node->value<r->left->value){
            return rightRotate(r);
        }

        // rr imbal
        if(bf<-1 && new_node->value>r->right->value){
            return leftRotate(r);
        }

        // lr imbal
        if(bf>1 && new_node->value>r->left->value){
            r->left=leftRotate(r->left);
            return rightRotate(r);
        }

        // rl imbal
        if(bf<-1 && new_node->value<r->right->value){
            r->right=rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

};

int main(){
    AVLTree obj;

}