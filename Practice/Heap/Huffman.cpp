#include<bits/stdc++.h>

using namespace std;
class MinHeapNode{
    public:
    char data;
    unsigned freq;
    MinHeapNode *left,*right;

    MinHeapNode(char da,int fre){
        data = da;
        freq = fre;
        left = NULL;
        right = NULL;
    }
};

class  MinHeap{
    public:
    int size;
    int capacity;
    MinHeapNode** array;

    MinHeap(int cap,char arr[],int freq[]){
        size =cap ;
        capacity = cap;
        array = (MinHeapNode**)malloc(cap*sizeof(MinHeapNode*));
        for(int i= 0 ;i<cap;i++){
            array[i] = new MinHeapNode(arr[i],freq[i]);
        }   

    }
}   ; 
void swapMinHeapNode( MinHeapNode** a, 
                      MinHeapNode** b) 
  
{ 
  
    MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 

void minheapify(MinHeap *minHeap,int ptr){
    int left = ptr *2 +1;
    int right = ptr*2 +2;
    int smallest = ptr;

    if( left< minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq ){
        smallest = left;
    }
    if( right< minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq ){
        smallest = right;
    }
    if(smallest != ptr){
        swapMinHeapNode(&  (minHeap->array[ptr]),& (minHeap->array[smallest]));
        minheapify(minHeap,smallest);
    }

}
void buildMinHeap(MinHeap *minheap,int size){
    for(int i = size/2 - 1; i>=0;i--){
        minheapify(minheap,i);
    }
}

MinHeapNode* getMinimum(MinHeap* minHeap){
MinHeapNode* minHeapNode = minHeap->array[0];
minHeap->array[0] = minHeap->array[minHeap->size -1];
minHeap->size = minHeap->size -1 ;
minheapify(minHeap,0);
return minHeapNode;
}

void insert(MinHeap **minHeap,MinHeapNode* minHeapNode){
    (*minHeap)->size ++;
  int i = (*minHeap)->size - 1; 
  
    while (i && minHeapNode->freq < (*minHeap)->array[(i - 1) / 2]->freq) { 
  
        (*minHeap)->array[i] = (*minHeap)->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    (*minHeap)->array[i] = minHeapNode; 
}

MinHeapNode* getHuffManTree(char arr[],int freq[],int size){
    MinHeap* minHeap = new MinHeap(size,arr,freq);
    buildMinHeap(minHeap,size);
    while(minHeap->size > 1){
        MinHeapNode *m1 = getMinimum(minHeap);
        MinHeapNode *m2 = getMinimum(minHeap);
        MinHeapNode *n1 = new MinHeapNode('N',m1->freq + m2->freq);
        n1->left = m1;
        n1->right = m2;
                cout<<endl<<"bi : new size"<<minHeap->size;

        insert(&minHeap,n1);
        
        cout<<endl<<"new size"<<minHeap->size;
    }
   return minHeap->array[0];
}

void printNode(MinHeapNode *minHeapNode){
if(minHeapNode == NULL)
    return ;
else{
    printNode(minHeapNode ->left);
    cout<<minHeapNode->data<<" "<<minHeapNode->freq<<endl;
    printNode(minHeapNode ->right);
}
}
int main(){
 char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 13, 16, 45 , 5, 9, 12}; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    MinHeapNode* mhn = getHuffManTree(arr, freq, size); 
    printNode(mhn);
return 0;
}
