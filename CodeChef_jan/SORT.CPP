#include<bits/stdc++.h>
#define loop(i,size) for(int i =0;i<size;i++)
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

 // 6 2 1 8 5 
 // 2 6 1 8 5
 //2 1 5 8 6
int partition(int arr[],int start,int end,int num){
    int pivot  = arr[end];
    int pos = start-1;
    for(int i = start ;i<end ;i++){
        if((arr[i]%num) < (pivot % num)){
            pos++;
            swap(&arr[pos],&arr[i]);
        }

    }

    swap(&arr[pos+1],&arr[end]);
return pos+1;
 
}
void quicksort(int arr[],int start,int end,int num){
    if(start <end){
    int temp = partition(arr,start,end,num);
    quicksort(arr,start,temp-1,num);
    quicksort(arr,temp+1,end,num);
    }
}


void insertionsor(int arr[],int size,int num){

for(int i=2;i<size;i++){
    int var = arr[i];
    int j = i-1;
    while(j>=0 && (arr[j]%num)>(var%num)){
        
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = var;
}

}

int num;

bool compare(int a,int b){
    if(a%num == b%num)
        return false;
        else return (a%num < b%num);
}
int main(){
    int size;
    cin>>size>>num;

    int arr[size];

    loop(i,size)
    {
        cin>>arr[i];
    }

    sort(arr,arr+size,compare);
    loop(i,size)
    cout<<arr[i]<<" ";

    cout<<endl;


}