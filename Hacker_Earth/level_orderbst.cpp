#include<bits/stdc++.h>
using namespace std;

class node{

        public:

    int data;


    node *left;
    node *right;
    node(int data){
        ((node *)this)->data = data;
        ((node *)this)->left = NULL;
        ((node *)this)->right  = NULL;
    }
};

int getHeight(node *head){
    if(head == NULL) return 0;

    int lh = getHeight(head->left);
    int rh = getHeight(head->right);
    return lh>rh?lh+1:rh+1;
}


void levelOrderOfHeight(node *node,int curr_height,int h,int *x){
        if(node == NULL) return;
        if(curr_height==h && *x ==0)
          {  cout<<node->data<<" ";
            *x = 1;
          }
        if(curr_height<h){

            levelOrderOfHeight(node->left,curr_height+1,h,x);
            levelOrderOfHeight(node->right,curr_height+1,h,x);
        } 

}

void levelOrder(node *head){
    int height = getHeight(head);
    cout<<"height : "<<height<<endl;
    for(int i=0;i<height;i++){
        int x =0;
        levelOrderOfHeight(head,0,i,&x);        
    }
}
int main(){
    
node *head = new node(1);
    head->left = new node(2);                           
    head->right = new node(3);
    head->left->left = new node(4);
    head->right->left = new node(5);
    head->left->right = new node(6);

    head->right->left->left = new node(7);
    head->left->left->left = new node(8);

    levelOrder(head);
    return 0;
}