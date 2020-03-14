#include<bits/stdc++.h>

using namespace std;
class Node{
    public:

    int data;
    Node *left;
    Node *right;
    int count;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
        count = 0;
    }

};

void insert(Node **root,int a){
  
    if(*root == NULL){
        *root = new Node(a);
        ((*root)->count)++; 
     }
     else{
         if((*root)->data > a){
             insert(&((*root)->left),a);
         }else if((*root)->data < a){
             insert(&((*root)->right),a);
         }else{
                 ((*root)->count)++; 
         }
     }   
}

void inorder(Node *root){
    
    if(root!=NULL)
    {   
        inorder(root->left);
        int count  = root->count;
        while(count-->0)
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

Node *getLowestElement(Node *root){
    if(root->left ==NULL){
        return root;
    }
    else return getLowestElement(root->left);
}

Node *deleteNode(Node *root,int a){
    if(root==NULL)
        return NULL;

    else if(root->data == a){
        if(root->count ==1){
        if(root->left ==NULL )
           {   Node *temp = root->right; 
               delete(root);
                return temp;
            }
        else if(root->right ==NULL )
            {Node *temp = root->left;
                delete(root);
                return temp;
                }
        else {
            Node *minValuesNode = getLowestElement(root);
            root->data = minValuesNode->data;
            root->right = deleteNode(root->right,minValuesNode->data);
        }
        }else{
            root->count = root->count -1;

        }
    }
    else if(root->data>a){
        root->left =  deleteNode(root->left,a);
    }
    else if(root->data<a){
        root->right = deleteNode(root->right,a);
    }
        return root;
}
int main(){

    Node *root = NULL;

        insert(&root,4);
        insert(&root,6);
        insert(&root,3);
        insert(&root,3);
        insert(&root,7);
        insert(&root,1);
        insert(&root,6);
        inorder(root);
        root =deleteNode(root,6);
        cout<<endl;
        inorder(root);
        root =deleteNode(root,7);
        cout<<endl;
        inorder(root);

    return 0;
}