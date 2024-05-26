#include <iostream>
#include <vector>
using namespace std;

int fib(int n){
    if (n<=1){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

int fibMEM(int n, vector<int> &F){
    if(n<=1){
        F[n] = n;
        return n;
    }

    if(F[n] != -1){
        return F[n];
    }

    return F[n] = fibMEM(n-1, F) + fibMEM(n-2, F);
}

int fibTAB(int n, vector<int> &F){
    if(n <= 1){
        return n;
    }

    F[0] = 0;
    F[1] = 1;

    for(int i = 2; i<=n; i++){
        F[i] = F[i-1] + F[i-2];
    }

    return F[n];
}
int main(){
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    cout << "Fibonacci using Recursion: O(2^n) : " << fib(n) << endl;

    vector<int> F(n+1, -1);
    cout << "Fibonacci using Memoization: O(n) : " << fibMEM(n, F) << endl;
    
    vector<int> Fn(n+1, -1);
    cout << "Fibonacci using Tabulation: O(n) : " << fibTAB(n, Fn) << endl;
    return 0;
}