#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pow =1;
    int temp = 0;
    while(n != 0){
        if((n&1) == 0){              // 1101 = 1+0+4+8 = 13 
            temp += pow;            //  3210   2
        }
        pow *= 2;                   // 1 2 4 8 16 ...
        n = n >> 1;                 // - 0 1
    }
    cout << temp<<endl;
    string ans = "";
    while(temp != 0){
        if(temp & 1)
            ans = '1'+ans;
        else
        ans = '0' + ans;
        temp >>= 1;
    }
    cout<<ans;
    return 0;
}