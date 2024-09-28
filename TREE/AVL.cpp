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

    Treenode* minValueNode(Treenode* r){
        Treenode* temp=r;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    Treenode* deleteNode(Treenode* r,int v){
        if(r==NULL) return NULL;
        else if(v>r->value){
            r->right=deleteNode(r->right,v);
        }
        else if(v<r->value){
            r->left=deleteNode(r->left,v);
        }
        else{
            if(r->left==NULL){
                Treenode* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                Treenode* temp = r->left;
                delete r;
                return temp;
            }
            else{
                Treenode* temp = minValueNode(r->right);
                r->value=temp->value;
                r->right=deleteNode(r->right,temp->value);
            }
        }
        int bf = getBalanceFactor(r);

        if(bf==2 && getBalanceFactor(r->left)>=0){
            return rightRotate(r);
        }
        else if(bf==2 && getBalanceFactor(r->left)==-1){
            r->left=leftRotate(r->left);
            return rightRotate(r);
        }
        else if(bf==-2 && getBalanceFactor(r->right)<=0){
            return leftRotate(r);
        }
        else if(bf==-2 && getBalanceFactor(r->right)==1){
            r->right=rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }


};

int main(){
    AVLTree obj;
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
        obj.root=obj.insert(obj.root,n);
        break;

    case 2:
        cout<<"Search"<<endl;
        cout<<"Enter the value to search"<<endl;
        cin>>val;
        if(obj.search(obj.root,val)){
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
        if(obj.search(obj.root,val)){
            obj.deleteNode(obj.root,val);
            cout<<"Node deleted"<<endl;
        }
        else{
            cout<<"Node not found"<<endl;
        }
        break;
    
    case 4:
        cout<<"Print Tree"<<endl;
        cout<<"Tree in 2D 90deg:"<<endl;
        obj.print2D(obj.root,5);
        cout<<endl;
        break;

    case 5:
        // cout<<"Tree Height"<<endl;
        // int h;
        // h= obj.height(obj.root);
        // cout<<"The height of tree is "<<h<<endl;

        // obj.printLevelOrderBST(obj.root);

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