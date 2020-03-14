#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int len){
cout<<endl;
for(int i =0;i< len;i++)
    cout<<arr[i]<<" ";
cout<<endl;
}


void swap(int *a,int *b){
    int temp= *a;
    *a = *b;
    *b = temp;
}
