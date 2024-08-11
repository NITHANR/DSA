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

class BST{
public:
    Treenode*  root;

    BST(): root{NULL} {}
    BST(Treenode* node): root{node} {}

    bool isEmpty(){
        return (root==NULL)?true:false;
    }

    // void insertNode(Treenode* nn){
    // if(isEmpty()){                               // My Insertion code
    //         root=nn;
    //     }
    //     else{
    //         Treenode* ptr=root;
    //         Treenode* temp=NULL;

    //         while(ptr){
    //             if((ptr->value)<(nn->value)){
    //                 temp=ptr;
    //                 ptr=ptr->right;

    //             }else{
    //                 temp=ptr;
    //                 ptr=ptr->left;

    //             }
    //         }

    //         if((temp->value)>(nn->value)){
    //             temp->left=nn;
    //         }else{
    //             temp->right=nn;
    //         }
    //     }
    // }


    void insertNode(Treenode* newNode){
        if(root==NULL){
            root=newNode;
        }
        else{
            Treenode* temp = root;
            while(temp){
                if(temp->value==newNode->value){
                    cout<<"Value already exists."<<endl;
                    return;
                }
                else if(temp->value<newNode->value  &&  temp->right==NULL){
                    temp->right=newNode;
                    cout<<"Node Inserted to the right."<<endl;
                    break;
                }
                else if(temp->value>newNode->value  && temp->left==NULL){
                    temp->left=newNode;
                    cout<<"Node Inserted to the left."<<endl;
                    break;
                }
                else if(temp->value>newNode->value){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
        }
    }

    // void printHelper(Treenode* p){
    //     if(!p)  return;
    //     printHelper(p->left);
    //     cout<<p->value<<" ";
    //     printHelper(p->right);

    // }

    // void print(){
    //     printHelper(root);
    // }

    void print2D(Treenode* node,int space){
        if(node==NULL){
            return;
        }
        space+=SPACE;
        print2D(node->right,space);
        cout<<endl;
        for(int i= SPACE ; (i<space);i++){
            cout<<" ";
        }
        cout<<node->value<<endl;
        print2D(node->left,space);

    }

};



int main(){

    BST bst;
   int option;
   int val;

   do{

    cout<<"What option do you want to perform? Selection option Number. Enter 0 to exit."<<endl;
    cout<<"1.InserNode"<<endl;
    cout<<"2.SearchNode"<<endl;
    cout<<"3.DeleteNode"<<endl;
    cout<<"4.Print BST tree"<<endl;
    cout<<"5.Clear Screen"<<endl;
    cout<<"0.Exit Program"<<endl;
    
    cin>>option;

    Treenode* n = new Treenode();


    switch (option)
    {
    case 1:
        cout<<"Insert"<<endl;
        cout<<"Enter the value to br inserted"<<endl;
        cin>>val;
        n->value=val;
        bst.insertNode(n);
        break;

    case 2:
        break;

    case 3:
        break;
    
    case 4:
        cout<<"Print Tree"<<endl;
        bst.print2D(bst.root,5);
        break;

    case 5:
        break;

    default:
        cout<<"Enter proper option number."<<endl;
        break;
    }


   }while(option); // option!=0


}