#include<stdio.h>
#include<stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

void print(const int *,int );
void SelectionSort(int*,int);
void swap(int *,int *);

int main(){
    int arr[] = {10,20,30,11,25,70,90,68,55};
    int arr_size;
    arr_size=SIZE(arr);
    puts("Before Selection Sort: ");
    print(arr,arr_size);
    SelectionSort(arr,arr_size);
    puts("\nAfter Selection Sort :");
    print(arr,arr_size);
    return  EXIT_SUCCESS;
}

void print(const int * arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void SelectionSort(int *arr,int size){
    int mini;
    int mini_pos;
    for(int i=0;i<size;i++){
        mini_pos=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[mini_pos]){
                mini_pos=j;
            }
        }
        swap((arr+mini_pos),(arr+i));
    }

}
