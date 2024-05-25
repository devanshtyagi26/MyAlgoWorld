#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int subDC(int arr[], int start, int end){
    if(start == end){
        return arr[start];
    }

    int mid = start + (end - start)/2;

    int LSA = subDC(arr, start, mid);
    int RSA = subDC(arr, mid + 1, end);

    int Lsum = INT_MIN;
    int Rsum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >=0; i--){
        sum += arr[i];
        if(sum > Lsum){
            Lsum = sum;
        }
    }
    sum = 0;
    for(int j = mid + 1; j<=end; j++){
        sum += arr[j];
        if(sum > Rsum){
            Rsum = sum;
        }
    }

    int CSA = Lsum + Rsum;

    return max(max(LSA, RSA), CSA);
}

int subDCV(vector<int>&arr, int start, int end){
    if(start == end){
        return arr[start];
    }

    int mid = start + (end - start)/2;

    int LSA = subDCV(arr, start, mid);
    int RSA = subDCV(arr, mid + 1, end);

    int Lsum = INT_MIN;
    int Rsum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >=0; i--){
        sum += arr[i];
        if(sum > Lsum){
            Lsum = sum;
        }
    }
    sum = 0;
    for(int j = mid + 1; j<=end; j++){
        sum += arr[j];
        if(sum > Rsum){
            Rsum = sum;
        }
    }

    int CSA = Lsum + Rsum;

    return max(max(LSA, RSA), CSA);
}

int main(){

    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int size = arr.size();
    cout << subDCV(arr,0,size - 1);
    return 0;
}
