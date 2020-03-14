#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
   return  (a<b)? b:  a;
}
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

int diameter(node *root,int *height){

    int lh= 0;
    int rh = 0;

    int ldiameter = 0,rdiameter = 0;
    if(root == NULL){
        *height = 0;
        return 0;
    }

    ldiameter = diameter(root->left,&lh);
    rdiameter = diameter(root->right,&rh);
    
    *height =max(lh,rh) + 1;

    return max(lh+rh+1,max(rdiameter,ldiameter));

}

int getMirror(node *root,int target,node* left,node * right){
    cout<<left->data;
    cout<<right->data;

    if(left== NULL || right == NULL){
        return -1;
    }
    if(left->data == target){
        return right->data;
    }
    if(right->data == target){
        return left->data;
    }

    int l = getMirror(root,target,left->left,right->right);
    if(l!= -1)
        return l;
    int r = getMirror(root,target,left->right,right->left);
        return r;
    
}


void verticalView(node *root,int index,map<int,vector<int>> *mp){

if(root ==NULL){
    return;
}
cout<<"On element :"<<root->data;
cout<<" On index : "<<index<<endl;
auto it = (*mp).find(index);

if(it == (*mp).end() )
{

    vector<int> vc = it->second;
    vc.push_back(root->data);
    (*mp).insert(pair<int,vector<int>>(index,vc));

}
else{
    vector<int> vc = it->second;
    vc.push_back(root->data);

    (*mp)[it->first] = vc;

}
verticalView(root->left,index-1,mp);
verticalView(root->right,index+1,mp);

}

int mirror(node *root,int target){
    if(root == NULL){
        return -1;
    }

    if(root->data == target)
        return target;

    else {return getMirror(root,target,root->left,root->right);}    
}

int main(){
    
    int t,head_d;
    cin>>t>>head_d;     
    node *head = new node(head_d);
    while(--t>0){
        char string[10000];
        int data;
        cin>>string>>data;
        node *temp = head;
        for(int i =0;i<strlen(string);i++){
            char ch = string[i];
            if(ch == 'L'){
                if(temp->left ==NULL)
                  temp->left = new node(data);
                    temp = temp->left;
            }
            else if(ch =='R'){
                if(temp->right ==NULL)
                 temp->right = new node(data);
                temp = temp->right;
            }
            else{
            }
      
        }
    }
    map<int,vector<int>> mp;
    verticalView(head,0,&mp);

    for(auto i = mp.begin();i!=mp.end();i++){
        cout<<"key : "<<(*i).first<<endl;
        vector<int> vec = (*i).second;
        for(auto j = vec.begin();j!=vec.end();j++){
            cout<<(*j)<<" ";
        }
        cout<<endl;
    }    

}