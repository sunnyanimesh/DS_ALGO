#include<bits/stdc++.h>

using namespace std;


struct node
{
    int key;
    struct node *left,*right;
};


struct node *newNode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp->key = key;
    temp->left = temp->right = NULL;    
    return temp;
}

void inorder(struct node* root){
    if(root !=NULL){
        inorder(root->left);
        cout<<root->key<<"\t";
        inorder(root->right);
    }
}

struct node *insert(struct node *root,int key){
    if(root ==NULL){
        struct node *temp = newNode(key);
        return temp;
    }
    if(root->key < key){
        root->right = insert(root->right,key);
    }
    else if(root->key > key){
        root->left = insert(root->left,key);
    }
    return root;
}

struct node *minvaludenode(struct node *node){
    if(node->left ==NULL)
        return node;
    else
        return minvaludenode(node->left);    
}

struct node *deleten(struct node *node,int key){
    if(node ==NULL) 
        return node;
 
    if(key >node->key ){
      node->right =   deleten(node->right,key);
    }
    else if(key< node->key){
        node->left  = deleten(node->left,key);
    }
    else{
        if(node->left == NULL  ){
            struct node *temp = node->right;
            cout<<"freeing :"<<node->key;

            free(node);
            node = NULL;
          //  node->key = -1;
                        cout<<"freeing :"<<node->key;

            return temp;
        }
        else if(node->right == NULL ){
            struct node *temp = node->left;
            cout<<"freeing :"<<node->key;

            free(node);
            node =NULL;
          //              node->key = -1;
            cout<<"freeing :"<<node->key;

            return temp;
        }
        else{
            struct node *temp = minvaludenode(node->right);
            cout<<"temp key"<<temp->key;
            cout<<"node key"<<node->key;
            
            node->key = temp->key;
            deleten(node->right,node->key);
                
        }
    }
   
    return node;

}

int main(){
    struct node *root = newNode(9);
    cout<<endl;
    inorder(root);
    insert(root,7);
    cout<<endl;
    inorder(root);
    insert(root,6);
    cout<<endl;
    inorder(root);
    insert(root,5);
    cout<<endl;
    inorder(root);
    insert(root,4);
    cout<<endl;
    inorder(root);
    insert(root,3);
    cout<<endl;
    inorder(root);
    insert(root,12);
    cout<<endl;
    inorder(root);
//    deleten(root,12);
//    cout<<endl;
//    inorder(root);
    deleten(root,9);
    cout<<endl;
    inorder(root);

    return 0;
}