#include <iostream>
using namespace std;

int comparison = 0;

void merge(int arr[], int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int b[end - start + 1];

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
            k++;
        }
        else{
            b[k] = arr[j];
            j++;
            k++;
        }
        comparison ++;

    }
    if(i > mid){
        while(j <= end){
            b[k] = arr[j];
            j++;
            k++;
            comparison ++;
        }
    }
    else{
        while(i <= mid){
            b[k] = arr[i];
            i++;
            k++;
            comparison ++;
        }
    }

    for(int i = 0; i < end - start +1; i++){
        arr[start + i] = b[i];
    }
}

void mergeSort(int arr[], int start, int end){
    
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[] = {1,45,6,2,12,53,4,45,57,56,82,3,45,11,6,5,56,13};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    mergeSort(arr,0,size - 1);
    cout << endl;
    for(int j = 0; j<size; j++){
        cout << arr[j] << " ";
    }
    cout << "\n\nNumber of comparisons are: " << comparison; 
    return 0;
}