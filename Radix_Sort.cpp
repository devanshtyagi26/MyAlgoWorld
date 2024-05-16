#include <iostream>
using namespace std;

void countSort(int arr[], int size, int pos){
    int max = arr[0];
    for(int i = 1; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int count[10] = {0};
    
    for(int i = 0; i<size; i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i = 1; i<10; i++){
        count[i] += count[i-1];
    }
    int j = size-1;
    int sorted[size] = {0};

    while(j>=0){
        sorted[--count[(arr[j]/pos)%10]] = arr[j];
        j--;
    }
    
    for(int i = 0; i<size; i++){
        arr[i] = sorted[i];
    }
}

void radix(int arr[], int size){
    int max = arr[0];
    for(int i = 0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    for(int pos = 1; max/pos >0; pos *= 10){
        countSort(arr, size, pos);
    }
}
int main(){
    int arr[] = {3,36,36,452,356,23,3256,541,2541,324,5,345,3461,4,55,667,4,67};
    int size = sizeof(arr)/sizeof(arr[0]);
    radix(arr, size);

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}