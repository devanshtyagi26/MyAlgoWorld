#include <iostream>
using namespace std;

#define max 100

void mul(int A[][max], int B[][max], int r1, int c1, int r2, int c2){
    int C[r1][c2];

    if(c1 != r2){
        return;
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            C[i][j] = 0;
            for(int k = 0; k < c1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }

        }
    }
    for(int i = 0; i<r1; i++){
        for(int j = 0; j<c1; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int r1, r2, c1, c2;
    r1 = 3;
    c1 = 3;
    r2 = 3;
    c2 = 3;
    int A[max][max] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int B[max][max] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    mul(A,B, r1, c1, r2, c2);
    return 0;
}