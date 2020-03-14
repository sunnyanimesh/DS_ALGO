#include<bits/stdc++.h>

using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
void maxheapify(int arr[],int n,int i){
    int largest = i ;
    int left = 2*i + 1 ;
    int right = 2*i +  2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(&arr[i],&arr[largest]);
        maxheapify(arr,n,largest);
    }
}   
void heapsort(int arr[],int n){
    for(int i= n/2 -1;i>=0;i--){
        maxheapify(arr,n,i);
    }

    for(int i = 0;i<n;i++){
        swap(&arr[0],&arr[n-i-1]);
        maxheapify(arr,n-i-1,0);
    }
}

/* A utility function to print array of size n */

// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapsort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 
