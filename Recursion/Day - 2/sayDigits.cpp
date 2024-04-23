#include <iostream>

using namespace std;

void sayDigits(int n, string arr[]){
    // base case
    if(n == 0){
        return;
    }

    // processing and recursion
    int digit = 0;
    digit = n % 10; // gives you the last digit of a number

    sayDigits(n/10, arr);
    
    cout << arr[digit] << " ";

}

int main(void){
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",
                    "Seven", "Eight", "Nine"};

    int n;
    cout << "Enter number: ";
    cin >> n;

    sayDigits(n, arr);

    return 0;
}