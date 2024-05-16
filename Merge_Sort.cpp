#include <iostream>
using namespace std;

void merge(int A[], int B[], int C[], int m, int n){
    int i,j,k;
    i = j = k = 0;

    while(i<m && j<n){
        if(A[i] < B[j]){
            C[k] = A[i];
            i++;
            k++;
        }
        else{
            C[k] = B[j];
            j++;
            k++;
        }
    }

    while(i<m){
        C[k] = A[i];
        i++;
        k++;
    }
    while(j<n){
        C[k] = B[j];
        j++;
        k++;
    }
}

void singleArrayMerge(int A[], int B[], int start, int mid, int end){
    int i,j,k;
    i = start;
    j = mid + 1;
    k = start;

    while(i < mid && j < end){
        
    }
}

int main(){
    
    return 0;
}