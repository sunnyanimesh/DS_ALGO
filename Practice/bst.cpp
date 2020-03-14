#include<bits/stdc++.h>

using namespace std;

struct node
{
    int key;
    struct node *left,*right;
    int count ;
};

struct node *newNode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->count = 0;
    return temp;
}

struct node *minvaluenode(struct node *node){
    struct node* current = node;
    while( current && current->left !=NULL){
        current = node->left;
    }
    return current;
}

struct node *insert(struct node* node,int key){
       if(node == NULL){
        cout<<"null"<<endl;
       return newNode(key);
        //cout<<endl;"count : n :"<<n->count<<endl;
       
      //  return n;
    }
    // if(key == node->key){
    //    cout<<"count before"<<node->count<<endl;
    //     node->count ++;
    //    cout<<"count after"<<node->count<<endl;
    
    // }
        cout<<endl<<node->key<<" "<<node->count<<endl;

     if(key < node->key){
                cout<<"left"<<endl;
        node->left = insert(node->left,key);
    } 
    else if(key > node->key){
                        cout<<"right"<<endl;
        node->right = insert(node->right,key);
    }

return node;
}

struct node *deleteNode(struct node *root,int key){
    if(root->key < key){
        root->right = deleteNode(root->right,key);
    }
    else if(root->key > key){
        root->left = deleteNode(root->left,key);
    }
    else{
        if(root->left == NULL){
           struct node* temp =  root->right;
           free(root);
           return temp;
        }
        if(root->right == NULL){
           struct node* temp =  root->left;
           free(root);
           return temp;
        }
        struct node *temp =   minvaluenode(root->right);
        root->key = temp->key;
        free(temp);
    }
    return root;
}
void inorder(struct node *root)
{
 
    if(root!=NULL){
        inorder(root->left);
        int count  = root->count;
        cout<<root->key<<" "<<count<<endl;
        inorder(root->right);
    }
   
}


int main(){
//        fstream file;
//     string s, t, q, filename;

//    filename = "file2.txt";

//    file.open(filename.c_str());
//    struct node *node = NULL;
//    while (file >> s)
//     {
//     char cstr[s.size() + 1];
// 	s.copy(cstr, s.size() + 1);
// 	cstr[s.size()] = '\0';
//     int av = atoi(cstr);
//     //cout<<av;
//     node = insert(node, av);
//     }
//     inorder(node);
//     file.close();
    struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	
     insert(root, 20); 
	// insert(root, 40); 
	// insert(root, 70); 
	// insert(root, 60); 
	// insert(root, 80); 

printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    // printf("\nDelete 20\n"); 
    // root = deleteNode(root, 20); 
    // printf("Inorder traversal of the modified tree \n"); 
    // inorder(root); 
  
    // printf("\nDelete 30\n"); 
    // root = deleteNode(root, 30); 
    // printf("Inorder traversal of the modified tree \n"); 
    // inorder(root); 
  
    // printf("\nDelete 50\n"); 
    // root = deleteNode(root, 50); 
    // printf("Inorder traversal of the modified tree \n"); 
    // inorder(root); 
return 0;
}