#include<stdio.h>
#include<stdlib.h>

void heapSort(int *arr,int size);   // Min heap
void heapify(int *arr,int par,int li);
void swap(int* a,int* b);

int main(){
    int arr[]={10,20,11,21,30,90,80,71,100};
    int arr_size= sizeof arr /sizeof(int);

    for(int i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }
    puts("\n");
    heapSort(arr,arr_size);

    for(int i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }

    return EXIT_SUCCESS;

}

void heapSort(int *arr,int size){
    int par_c=size/2;
    int last_in = size-1;
    for(int cur_par = par_c;cur_par>=0;cur_par--){
        heapify(arr,cur_par,last_in);
    }
    int temp;
    temp = arr [ 0 ];
    arr [ 0 ] = arr [ last_in ];
    arr [ last_in ] = temp;
    last_in -=1;
    while ( last_in )
    {
    heapify ( arr, 0, last_in);
    temp = arr [ 0 ];
    arr [ 0 ] = arr [ last_in ];
    arr [ last_in ] = temp;
    last_in -=1;
    }

}

void heapify(int *arr,int par,int li){
    int left = par*2+1;
    int right  = par*2+2;
    if(left>li){
        return;  //no child -> left index gt last index
    }
    if(left==li){
        if(arr[left]>arr[par]){
            swap(&arr[left],&arr[par]); // only one child -> left child is the last ind and 
        }        
        return;                       // the value in left gt par so swap
    }
    if((arr[left]>arr[par]) || (arr[right]>arr[par])){
        if(arr[right]<arr[left]){
            swap(&arr[left],&arr[par]);
            heapify(arr,left,li);
        }
        else{
            swap(&arr[right],&arr[par]);
            heapify(arr,right,li);
        }
    }

}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
