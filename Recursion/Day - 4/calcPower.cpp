#include <iostream>
#include <string>

using namespace std;

int calcPower_01(int a, int b){
    // base case
    if(b==0){
        return 1;
    }

    // processing and recursion
    return a * calcPower_01(a, b-1);
}

int calcPower_02(int a, int b){
    // base case
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    // recursion
    int ans = calcPower_02(a, b/2);

    // processing
    if(b%2 == 0){
        return  ans * ans;
    }
    else{
        return a * ans * ans;
    }
}

int main(void){
    int a;
    cout << "Enter a: ";
    cin >> a;
    int b;
    cout << "Enter b: ";
    cin >> b;

    // int ans = calcPower_01(a, b);
    int ans = calcPower_02(a, b);

    cout << "Power: " << ans << endl;

    return 0;
}