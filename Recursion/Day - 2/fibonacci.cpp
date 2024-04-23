#include <iostream>

using namespace std;

int fibo(int n){
    // base case
    if(n == 1){
        return n; // or return 1;
    }
    if(n == 0){
        return n; // or return 0;
    }

    // processing and recursion
    cout << fibo(n-1) + fibo(n-2); 

}

int main(void){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "ans: ";
    fibo(n);

    return 0;
}