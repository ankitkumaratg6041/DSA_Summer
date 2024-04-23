#include <iostream>

using namespace std;

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void countPrimes(int n){
    int count = 0;
    for(int i=2; i<n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    cout << "Total prime numbers between 0 to " << n << " are: " << count << endl;
}

int main(void){
    cout << "Enter n: ";
    int n;
    cin >> n;

    countPrimes(n);

    return 0;
}