#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution{
    public:
        int reverse(int x){
            int ans = 0;

            while(x != 0){
                int digit = x % 10;
                if((ans > (INT_MAX/10)) || (ans < (INT_MIN/10))) return 0;
                ans = (ans * 10) + digit;
                x /= 10;
            }
            return ans;
        }
};

int main(void){
    Solution* s = new Solution();
    int n;
    cout << "Enter n: ";
    cin >> n;
    int result = s->reverse(n);
    cout << result << endl;


    return 0;
}