#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono; 

void swap(int *a,int *b){
    
    int temp = *a;
    *a = *b;
    *b = temp;

}
void reverse_num(int arr[],int start,int size){
    
    int i=start;
    int j = size-1;
    while(i<=j){
        swap(&arr[i],&arr[j]);
        i++;
        j--;
    }

}

