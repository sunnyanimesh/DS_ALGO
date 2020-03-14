#include<bits/stdc++.h>
using namespace std;


int main(){
    int ar[]  = {0,4,5,6,1,2,3} ;
    sort(ar,ar + 7);
    for(int i=0;i<7;i++)
    cout<<ar[i];   
    cout<<binary_search(ar,ar+7,10);
   return 0; 
}