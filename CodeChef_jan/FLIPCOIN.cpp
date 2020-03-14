#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    int leftkey;
    int rightkey;
    Node *left,*right;
    int val = 0;
    
};

Node *buildtree(int left,int right){
    Node *root = new Node();
    if(left<=right){
    root->leftkey = left;
    root->rightkey = right;
    int mid = (right+ left)/2;
    if(left<right){
    root->left = buildtree(left,mid);
    root->right = buildtree(mid+1,right);
    }
    return root;
    }
    return NULL;

}
int printCoins(Node *root,int left,int right){
    // cout<<"root->val : "<<root->val<< "   root->leftkey : "<<root->leftkey<< "   root->rightkey : "<<root->rightkey;
    // cout<<"left : "<<left<<"right : "<<right<<endl;
    
    if(root == NULL)
    {
//    cout<<"1"<<endl;
        return 0;
    }
    if(root->leftkey >right || root->rightkey < left){
  //    cout<<"2"<<endl;
        return 0 ;
    }
    
    if(root->leftkey == left && root->rightkey == right){
    //         cout<<"3"<<endl;
        return root->val;
        
    }
    else{
      //    cout<<"4";
        int mid = (root->rightkey+ root->leftkey)/2;
        int a =         printCoins(root->left,left,min(mid,right));
        int b =         printCoins(root->right,max(mid+1,left),right);
//        cout<<"returning : " <<a+b<<endl;
        return a+b;
        
        
    }
    
}
int flipCoins(Node *root,int left,int right){
    if(root == NULL)
    {
        return 0;
    }
// cout<<"root->val : "<<root->val<<"  root->leftkey"<<root->leftkey<<"  root->rightkey"<<root->rightkey<<endl;

// cout<<"  left :"<<left<<"  right :"<<right<<endl;
    if(root->rightkey== root->leftkey && (root->rightkey>=left && root->rightkey<= right)){
     
        root->val =(root->val == 0)?1:0;
   // cout<<"case 1 : root->val :" <<root->val<<endl;
    return root->val;
    }
    else if(left <=right &&  (root->rightkey>= left && root->leftkey<=right))
    {
     
     root->val =     flipCoins(root->left,left,right) + 
        flipCoins(root->right,left,right);
     //   cout<<" case 2 : root->val :" <<root->val<<endl;
     return root->val;   
    }
    
//     cout<<"root->val :" <<root->val<<endl;
    return  root->val;;
}
int main() {
    int n,t;
    cin>>n>>t;
    
    Node *root = new Node();
    root = buildtree(0,n-1);
    
    while(t-- >0){
        int l,a,b;
        cin>>l>>a>>b;
        if(l == 0){
            flipCoins(root,a,b);
  //         cout<<"root : "<<root->val<<endl;
            
        }else{
            cout<<printCoins(root,a,b)<<endl;
        }
    }
	return 0;
}
