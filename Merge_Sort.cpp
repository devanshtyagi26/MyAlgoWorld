#include <iostream>
using namespace std;

void merge(int A[], int B[], int C[], int m, int n){
    int i,j,k;
    i = j = k = 0;
    int comparison = 0;

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
        comparison++;
    }

    while(i<m){
        C[k] = A[i];
        i++;
        k++;
        comparison++;
    }
    while(j<n){
        C[k] = B[j];
        j++;
        k++;
        comparison++;
    }

    cout << "Merged array: ";
    cout << "[";
    for(int i = 0; i<(m+n); i++){
        cout << C[i]<< " ";
    }
    cout <<"]";

    cout << "\n\nNumber of comparisons are: " << comparison;
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
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int C[m + n];

    merge(A, B, C, m, n);

    
    cout << endl;

    return 0;
}