#include <iostream>

using namespace std;

void rCount(int n){
    // base case 
    if(n == 0){
        cout << 0 << " ";
        return;
    }

    rCount(n-1);
    cout << n << " ";
}

int main(void){
    int n;
    cout << "Enter n: ";
    cin >> n;

    rCount(n);

    return 0;
}