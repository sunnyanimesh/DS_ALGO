#include<bits/stdc++.h>
#include"FileOper.cpp"
#include"reverse.cpp"
using namespace std;

void rotate_array(int arr[],int num,int d){
    
    reverse_num(arr,0,d);
    reverse_num(arr,d,num);
    reverse_num(arr,0,num);
}


int main(){
    char st[] = "myFile.txt";
  FileOper *fp;
    try{
     fp = new FileOper(600000000000,st);
    }catch(bad_alloc a){
        cout<<a.what();
    }
    int *a = fp->getArray();
   // cout<<a[0];
   auto start = high_resolution_clock::now(); 
     reverse_num(a,0,600000000000);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
        cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
  
     start = high_resolution_clock::now(); 
     reverse(a,a+600000000000);

    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 
        cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
   

  //   fp->printArray();
    return 0;
}