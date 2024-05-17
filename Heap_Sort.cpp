#include <iostream>
using namespace std;

int comparison = 0;

void heapify(int arr[], int size, int i){
    int largest = i;
    int leftidx = i*2;
    int rightidx = i*2 + 1;

    if(leftidx < size && arr[leftidx] > arr[largest]){
        largest = leftidx;
        comparison++;
    }
    if(rightidx < size && arr[rightidx] > arr[largest]){
        largest = rightidx;
        comparison++;
    }


    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void buildheap(int arr[],int size){
    for(int i = size/2; i>0; i--){
        heapify(arr,size,i);
    }
}

void heapSortRecursive(int arr[], int size){
    buildheap(arr, size);
    
    if(size == 1){
        return;
    }
    else{
        swap(arr[size], arr[1]);
        heapSortRecursive(arr, size - 1);
    }  
}

void heapSortIterative(int arr[], int size) {
    buildheap(arr, size);

    for (int i = size; i > 1; i--) {
        swap(arr[1], arr[i]);  
        heapify(arr, i - 1, 1); 
    }
}

void print(int arr[], int size){
    for(int i = 1; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main(){
    int arr[] = {-1,6,8,3,2,7,56,5,8,11,23,6,46,73,6,6,123,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    heapSortIterative(arr,size - 1);
    print(arr,size);
    cout << "\nNumber of comparisons: " << comparison;
    return 0;
}