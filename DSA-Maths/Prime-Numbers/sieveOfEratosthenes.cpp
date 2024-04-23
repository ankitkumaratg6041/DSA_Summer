#include <iostream>
#include <vector>

using namespace std;

void countPrimes(int n){
    int count = 0;
    // marking as true means numbers are considered prime
    vector<bool> prime(n+1, true); // this means array is like this 0 1 2 3 .....40 (these numbers are actually indexes and their values are true/fasle)

    prime[0] = prime[1] = false; // marking index 0 and 1 as false since 0 and 1 are not primes

    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;

            for(int j=i*2; j<n; j=j+i){
                prime[j] = false;
            }
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