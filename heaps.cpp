#include "iostream"
#include "stdio.h"
#include "math.h"
#define Parent(i)( floor(i/2) )
#define Left(i)( 2*i)
#define Right(i)( 2*i + 1)
#define HeapSize(A)( (sizeof(A)/sizeof(A[0])))

int l,r,largest = 1,heapsize;

void exchange(int arr[],int i, int j){
    int temp = 0;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void max_heapify(int arr[],int i){    
    l = Left(i); r = Right(i); //heapsize = 10;//(sizeof(arr)/sizeof(arr[0]));
    //printf("\n\n[largest] : %d ,[i] : %d ,[l] : %d ,[r] : %d ",largest,i,l,r);
    printf("\nHeap Size : %d \n",heapsize);
    for(int i = 1;i<=heapsize;i++){
        //printf("%d , ",arr[i]);
    }
    if(l <= heapsize && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r <= heapsize && arr[r] > arr[largest])
        largest = r;    
    
    if(largest != i)
    {   
        exchange(arr,i,largest);
        max_heapify(arr,largest);
    }

}

void build_max_heap(int arr[]){
    heapsize = 10;

    for(int i = floor(heapsize/2);i>=1;i--){
        max_heapify(arr,i);
    }
}

void heapsort(int arr[]){
    //build_max_heap(arr);
    for (int i = 10;i>=2;i--){
        exchange(arr,1,i);
        heapsize--;
        max_heapify(arr,1);
    }
}

int heap_maximum(int arr[]){
    return arr[1];
}

int heap_extract_max(int arr[]){
    if (heapsize < 1)
        return 0;
    int max = arr[1];
    arr[1] = arr[heapsize];
    heapsize--;
    max_heapify(arr,1);
    return max;
}

void heap_increase_key(int arr[],int i,int key){
    if(arr[i] > key)
        return;   
    arr[i] = key;
    int parent = Parent(i);
    while(i > 1 && arr[parent] < arr[i] ){
        exchange(arr,i,parent);
        i = parent;
        parent=Parent(i);
    }
}

void max_heap_insert(int arr[],int key){
    heapsize++;
    arr[heapsize] = -99999999999999999;
    heap_increase_key(arr,heapsize,key);
}

int main(){
    int arr[] = {0,4,1,3,2,16,9,10,14,8,7};
    //printf("Array Size : %d \n",(sizeof(arr)/sizeof(arr[0])));
    build_max_heap(arr);
    printf("\n\n------Heapified----- \n\n");
    for(int i = 1;i<(sizeof(arr)/sizeof(arr[0]));i++){
        printf("%d , ",arr[i]);
    }

    max_heap_insert(arr,15);
    printf("\n\n------Heap Updated----- \n\n");
    for(int i = 1;i<(sizeof(arr)/sizeof(arr[0]));i++){
        printf("%d , ",arr[i]);
    }
    // heapsort(arr);
    // printf("\n\n------Sorted----- \n\n");
    // for(int i = 1;i<(sizeof(arr)/sizeof(arr[0]));i++){
    //     printf("%d , ",arr[i]);
    // }

}