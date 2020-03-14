#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int key;
    Node *next;
};

void insertBig(Node **head,int key){
    Node *n = new Node();
    n->key = key;
    n->next = *head;
    *head = n;

}

void append(Node **head,int key){
    Node *temp = *head;
    Node *new_node = new Node();
    new_node->key = key;
    new_node->next = NULL;
    if(temp == NULL){
        *head = new_node;
       return;
    }
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next  = new_node;

}


void deleteBig(Node **head){
   Node *temp = *head;
    *head = temp->next;
}

void reverseList(Node **head){
    Node *prev,*curr,*next;
    prev =NULL;
    next = NULL;
    curr = *head;

    while(curr->next !=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    *head = curr;

}
void deleteEnd(Node **head){
    Node *temp = *head;
    Node *prev ;
    if(temp == NULL){
        return;
    }
    
    while(temp->next !=NULL){
        prev= temp;
        temp = temp->next;

    }
    prev->next =NULL;
    temp = NULL;
    free(temp);
}
void printList(Node *head){
    
    while(head != NULL){
        cout<<head->key<<" ";
        head = head->next;
    }       
}

void deleteNode(Node *node){
    
    Node *next_node = node->next;
    
    int temp = node->key;
    node->key = next_node->key;
    next_node->key = temp;

    node->next = next_node->next;
    free(next_node);

}



int main(){
    Node *head = NULL;
    Node* n1 = new Node;
    n1->key = 6;
    n1->next = NULL;
    head = n1;
    insertBig(&head,7);
    insertBig(&head,8);
    insertBig(&head,9);
    insertBig(&head,10);
    append(&head,11);
    printList(head);    
    reverseList(&head);
    cout<<endl;
    printList(head);
    return 0;
}