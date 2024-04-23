/*
    Steps for decimal to binary representation
    1. Divide the number n by 2
    2. Store remainder
    3. Repeat the above steps until n != 0
    4. Write the result in reverse order to get your final answer

## Concepts used ## 
- Binary and Bitwise operators
- Loops
- Basic Mathematics

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void){

    cout << "Enter number n: ";
    int num;
    cin >> num;

    int i=0;
    int ans = 0;
    int count = 0;
    while(num != 0){
                                                                        // 10110
        int bit = num & 1;
        if(count == 0 && bit == 0) {count = 2;}
        // ans = (bit * pow(10, i)) + ans;
        ans = (ans * 10) + bit;
        num = num >> 1;
        i++;
        if(count == 0) count = 1;
    }
    if(count == 2) {ans *= 10;}
    cout << "Result in binary format: " << ans << endl;

    return 0;
}