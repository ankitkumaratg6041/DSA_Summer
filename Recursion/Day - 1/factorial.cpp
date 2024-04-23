#include <iostream>

using namespace std;

int factorial(int n){
   // base case
   if(n == 1 || n == 0){
    return 1;
   }

   // recursion and processing
   return n * factorial(n-1);
}

int main(void){

    int n;
    cout << "Enter n: ";
    cin >> n;
    int ans = factorial(n);
    cout << "ans: " << ans << endl;

    return 0;
}