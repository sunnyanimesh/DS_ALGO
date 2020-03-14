#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};


int detectLoop(struct node* head){
    struct node *slow  =head,*fast = head;
    if(head==NULL ||head->next==NULL||head->next->next ==NULL)
     { 
           return 0;
    }
    fast = head->next->next;
    slow = head->next;
     while(fast!=NULL || slow!=NULL ){
        if(slow ==fast){
            cout<<"found loop";
            break;
        }
        else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    if(fast==NULL){
        return 0 ;
        cout<<"lo loop";
    }else{
        struct node *tmp = fast;
        fast = fast->next;
        int count = 1;
        while(fast !=tmp)
            {count++;
            fast = fast->next;}
        return count;
    }
    
}


struct node* newNode(int data){
    struct node *node= (struct node*)malloc(sizeof(struct node*));
    node->data =data;
    node->next = NULL;
    return node;
}


int main(){
    struct node *head  = newNode(2);
    node *tmp = newNode(3);
    head->next = tmp;
    head->next->next = newNode(4);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(6);
    head->next->next->next->next->next = tmp;
    // cout<<head->data;
    // cout<<head->next->data;
    // cout<<head->next->next->data;
   cout<<detectLoop(head);
}