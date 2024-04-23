#include <iostream>

using namespace std;

int climbStairs(int n){
    // base case
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    // recursion and processing
    return climbStairs(n-1) + climbStairs(n-2);

}

int main(void){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "combinations: " << climbStairs(n) << endl;

    return 0;
}