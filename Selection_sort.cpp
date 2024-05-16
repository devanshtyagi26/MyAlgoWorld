#include <iostream>
using namespace std;


void selectionSort(int arr[], int size){
    int comparison = 0;
    for(int i = 0; i<size-1; i++){
        int min = i;
        int j = i + 1;
        for(j; j<size; j++){
            comparison++;
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    }

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "\nComparison: "<< comparison << endl;
}

int main(){
    int arr[] = {35633,56,3256,325,6,32,6,456,2,467,34,7,1,7,24,7,56,754,678346,7,536,85,38,348,34,0,5485,976,7,679};
    int size = sizeof(arr)/sizeof(arr[1]);
    selectionSort(arr,size);
    return 0;
}