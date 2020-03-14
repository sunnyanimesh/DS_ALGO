#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
   return  (a<b)? b:  a;
}
class node{

        public:

    char data;


    node *left;
    node *right;
    node(char data){
        ((node *)this)->data = data;
        ((node *)this)->left = NULL;
        ((node *)this)->right  = NULL;
    }
};


void dfs(node *head,int target,int *count){
    if(head == NULL)
        return ;
    dfs(head->left,target,count);

    cout<<head->data;
    if(head->data ==target)
    (*count)++;
    dfs(head->right,target,count);
}

int main(){
    

    node *head = new node('a');
    head->left = new node('b');
    head->right = new node('a');
    head->left->left = new node('b');
    head->right->left = new node('c');
    head->left->right = new node('c');

    head->right->left->left = new node('a');
    head->left->left->left = new node('b');
                                                                    //         a
                                                                    //      b     a
                                                                    //   b    c  c    b
                                                                    //         a        

    char target = 'c';
    int count = 0;
    dfs(head,target,&count);
    cout<<count;
}