#include <iostream>
using namespace std;

class Solution {
public:
 int bitwiseComplement(int n){
    if(n == 0) return 1;
    int temp = n;
    int mask = 0;
    while(temp != 0){
        mask = (mask << 1) | 1;
        temp >>= 1;
    }
    int ans = (~n) & mask;
    return ans;
 }
};

int main(void) {
    Solution* s = new Solution;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << s->bitwiseComplement(n) << endl;

    return 0;
}