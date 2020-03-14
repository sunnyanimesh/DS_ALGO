#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> vec(3,vector<int>(4,7));
     for(auto it1 = vec.begin();it1 !=vec.end();it1++){
        vector<int> vec2 = *it1;
          for(auto it2 = vec2.begin();it2 !=vec2.end();it2++){
              *it2 = 8;
              cout<<*it2<<" ";
          } 
          cout<<endl;
    }

}