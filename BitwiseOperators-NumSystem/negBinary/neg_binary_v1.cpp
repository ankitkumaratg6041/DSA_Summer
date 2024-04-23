#include <iostream>
using namespace std;


int onesComplement(int n){
        int mask = 0;
        int temp = n;
        while(temp != 0){
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }
        int ans = (~n) & mask;
        return ans;
}

void twosComplement(int n){
    int mask = 0;
    mask = ~mask;
    int temp = n;
    while((temp & 1) != 0){
        mask = (mask << 1) & 0;
        temp = temp >> 1;
    }
    int ans = n & mask;
    cout << ans << endl;
}

void negToBinary(int n) {
    int num = onesComplement(n);
    twosComplement(num);
}


int main(void){
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    negToBinary(n);

    return 0;
}