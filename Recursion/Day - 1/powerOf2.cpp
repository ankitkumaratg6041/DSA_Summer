#include <iostream>

using namespace std;

int powerOf2(int n){
    // base case
    if(n == 0){
        return 1;
    }

    // recursion and processing
    return 2 * powerOf2(n-1);
}

int main(void){
    int n;
    cout << "Enter power: ";
    cin >> n;

    int ans = powerOf2(n);
    cout << "ans: " << ans << endl;

    return 0;
}