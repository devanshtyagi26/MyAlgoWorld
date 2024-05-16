#include <iostream>
using namespace std;

void countSort(int arr[], int size){
    int k = arr[0];
    for(int i = 1; i<size; i++){
        if(arr[i] > k){
            k = arr[i];
        }
    }
    k += 1;
    int count[k] = {0};
    
    for(int i = 0; i<size; i++){
        count[arr[i]]++;
    }
    for(int i = 1; i<k; i++){
        count[i] += count[i-1];
    }
    int j = size-1;
    int sorted[size] = {0};

    while(j>=0){
        sorted[--count[arr[j]]] = arr[j];
        j--;
    }
    
    for(int i = 0; i<size; i++){
        arr[i] = sorted[i];
    }
}

int main(){
    int arr[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,3,3,3,3,3,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    countSort(arr, size);
    cout << endl;
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
