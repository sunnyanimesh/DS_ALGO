#include"util.cpp"

void bubblesort(int arr[],int l)
{
    for(int i =l-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}


int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i =low-1;

    for(int j = low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[],int from,int to){
if(to>from){
   int i=  partition(arr,from,to);
    quicksort(arr,from,i-1);
    quicksort(arr,i+1,to);
}
}



void merge(int arr[],int a,int b,int c){
    int n1 = b -a +1;
    int n2 = c - b;
    int l1[n1],l2[n2];
    for(int i=a;i<=b;i++){
        l1[i-a] = arr[i];
    }

    for(int j =b+1;j<=c;j++){
        l2[j - b -1] = arr[j];
    }

    int a1 =0 ;
    int b1 = 0;
    int i = a;
    while(a1 != n1 && b1 != n2){
        if(l1[a1]>l2[b1]){
            arr[i] = l2[b1];
            b1++;
        }else{
            arr[i] = l1[a1];
            a1++;
        }
        i++;
    }
    while(a1 != n1){
        arr[i] = l1[a1];
        a1++;
        i++;
    }
    while(b1 != n2){
        arr[i] = l2[b1];
        b1++;
        i++;
    }
 }

void mergesort(int arr[],int start,int en){
  if(start<en){


    int mid =  start+(en-start)/2;;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,en);
        merge(arr,start,mid,en);
  }
}


void max_heapify(int arr[],int n,int index){
    int left  = 2 * index +1 ;
    int right = 2 * index +2;
    
    int largest = index;
   
    if(left<n && arr[left]>arr[largest]){
        largest = left;
   
    }
    
    if(right<n && arr[right]>arr[largest]){
        largest = right;
   
    }


    if(largest!=index){
        swap(&arr[largest],&arr[index]);
        max_heapify(arr,n,largest);
    }
}


void heapsort(int arr[],int n){
    for(int i = n/2 -1;i>=0;i--){
        max_heapify(arr,n,i);
    }

    for(int i = n-1;i>=0;i--){
   
        swap(&arr[0],&arr[i]);
        max_heapify(arr,i,0);
    
    }
}