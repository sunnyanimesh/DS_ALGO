#include<bits/stdc++.h>
using namespace std;



int getSum(int arr[],int sum,int i,int j,int *st,int *end){

}

int main(){
    int t;
    cin>>t;

    while(t){
        int n, s;
        cin>>n>>s;
        int arr[n];
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        bool mat[n+1][s+1];    
    
        for(int i=0;i<s+1;i++)
          {
                mat[0][i]  = false;
          }
        for(int i=0;i<n+1;i++)
            {
                mat[i][0] = true;
            }

         for(int i =1;i<=n;i++){
             for(int j =1;j<=s;j++){
                 if(arr[i-1]>j){
                     mat[i][j] = mat[i-1][j];
                 }
                 else{
                     mat[i][j] = mat[i-1][j]  || mat[i-1][j- arr[i-1]];
                 }
             }
         }   

        

    }

}