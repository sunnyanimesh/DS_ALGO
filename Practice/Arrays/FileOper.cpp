#include<bits/stdc++.h>
using namespace std;

class FileOper{
    FILE* nameOfTheFile;
    int *arr;
    unsigned long size;
    public:

    FileOper(unsigned long n,char filename[]){
        size = n;
        nameOfTheFile = fopen(filename,"r");
        arr = new int[n];
    }
    ~FileOper(){
           fclose(nameOfTheFile);

    }


    int* getArray(){
       int count =0;
       int iter = 0;
       for(; fscanf(nameOfTheFile, "%d", &iter) && !feof(nameOfTheFile) && count<size;)
        { 
            arr[count] = iter;
            count++;
      
         }
        return  arr;
    }

    void printArray(){
        if(arr!=NULL  || size ==0){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<"\t";
            }

        }
        else
        cout<<"Array empty";
            cout<<endl;
    }
};