#include<bits/stdc++.h>

#define el <<endl
using namespace std;
int main(){
    map<int,char *> umap;

    umap[2] = "hi";
    
   umap.insert(make_pair(1,"pi"));
    for(auto it = umap.begin();it !=umap.end();it++){
  //          umap.insert(it,make_pair(-1,strcat("dsf","d")));
            cout<<it->first;
            cout<<" ";
            cout<<it->second el;

    }
   
    for(auto it = umap.begin();it !=umap.end();it++){
            // umap.insert(it,make_pair(-1,"dsf"));
             cout<<it->first;
            cout<<" ";
            cout<<it->second el;

    }
}