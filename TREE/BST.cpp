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

    void preOrder(Treenode* r){
        if(r==NULL){
            return;
        }
        cout<<r->value<<" ";
        preOrder(r->left);
        preOrder(r->right);

    }

    // void preOrderPrint(){
    //     preOrderHelper(root);
    // }

    void inOrder(Treenode * r){
        if(r==NULL) return;
        inOrder(r->left);
        cout<<r->value<<" ";
        inOrder(r->right);
    }

    void postOrder(Treenode* r){
        if(r==NULL) return;
        postOrder(r->left);
        postOrder(r->right);
        cout<<r->value<<" ";
    }


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

    // Treenode* search(int val){   ///Iterative search
    //     if(root==NULL){
    //         return root;
    //     }
    //     else{
    //         Treenode* temp = root;
    //         while(temp){
    //             if(temp->value==val){
    //                 break;
    //             }
    //             if(temp->value<val){
    //                 temp=temp->right;
    //             }
    //             else{
    //                 temp=temp->right;
    //             }
    //         }
    //         return temp;

    //     }
    // }

    Treenode* search(Treenode* r,int val){
        if(r==NULL || r->value==val){
            return r;
        }
        else if(r->value<val){
           return search(r->right,val);
        }
        else{
           return search(r->left,val);
        }
    }

    int height(Treenode* r){
        if(r==NULL) return -1;
        else{
            int left = height(r->left);
            int right = height(r->right);
            if(left>right) return left+1;
            else return right+1;
        }
    }

    void printLevelOrderBST(Treenode * r){
        if(r==NULL){
            return ;
        }
        else{
            int h = height(r);
            for(int i=0;i<=h;i++){
                printLevelOrder(r,i);
            }
        }
    }

    void printLevelOrder(Treenode* r,int n){
        if(r==NULL){
            return;
        }
        else if(n==0){
            cout<<r->value<<" ";
        }
        else{
            printLevelOrder(r->left,n-1);
            printLevelOrder(r->right,n-1);
        }
    }

    // min right node
    Treenode* minRightNode(Treenode* r){
        Treenode* ptr = r;
        while(ptr->left!=NULL){
            ptr=ptr->left;
        }
        return ptr;
    }

    // Delete a node
    Treenode* deleteNode(Treenode* r,int val){
        if(r==NULL){
            return r;
        }
        else if(val < (r->value)){
            r->left = deleteNode(r->left,val);
        }
        else if(val>(r->value)){
            r->right = deleteNode(r->right,val);
        }
        else{
            if(r->left==NULL){
                Treenode* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                Treenode* temp  = r->left;
                delete r;
                return temp;
            }
            else{
                Treenode* minRight = minRightNode(r->right);
                r->value=minRight->value;
                r->right=deleteNode(r->right,minRight->value);
            }
        }
        return r;
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
    cout<<"5.Height of Tree"<<endl;
    cout<<"6.Clear Screen"<<endl;
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
        cout<<"Search"<<endl;
        cout<<"Enter the value to search"<<endl;
        cin>>val;
        if(bst.search(bst.root,val)){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Value not found"<<endl;
        }
        break;

    case 3:
        cout<<"DeleteNode"<<endl;
        cout<<"Enter the node to be deleted ";
        cin>>val;
        if(bst.search(bst.root,val)){
            bst.deleteNode(bst.root,val);
            cout<<"Node deleted"<<endl;
        }
        else{
            cout<<"Node not found"<<endl;
        }
        break;
    
    case 4:
        cout<<"Print Tree"<<endl;
        cout<<"Tree in 2D 90deg:"<<endl;
        bst.print2D(bst.root,5);
        cout<<endl;
        cout<<"Tree in PreOrder:"<<endl;
        bst.preOrder(bst.root);
        cout<<endl;
        cout<<"Tree in InOrder:"<<endl;
        bst.inOrder(bst.root);
        cout<<endl;
        cout<<"Tree in PostOrder:"<<endl;
        bst.postOrder(bst.root);
        cout<<endl;
        break;

    case 5:
        cout<<"Tree Height"<<endl;
        int h;
        h= bst.height(bst.root);
        cout<<"The height of tree is "<<h<<endl;

        bst.printLevelOrderBST(bst.root);

        break;
    
    case 6:
        system("cls");
        break;

    default:
        cout<<"Enter proper option number."<<endl;
        break;
    }


   }while(option); // option!=0


}