#include <iostream>
using namespace std;


int partition(int arr[], int start, int end){
    int i = start + 1;
    int j = end;
    int pivot = arr[start];
    int temp;
    
    while(i<j){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    

    return j;
}

void quickSort(int arr[], int start, int end){
    int pivotIDX;

    if(start < end){
        pivotIDX = partition(arr, start, end);
        quickSort(arr, start, pivotIDX - 1);
        quickSort(arr, pivotIDX + 1, end);

    }
}

int main(){
    int arr[] = {9,8,7,6,4,3,2,1,0};
    int size = sizeof(arr)/sizeof(arr[1]);
    quickSort(arr,0,size-1);

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}