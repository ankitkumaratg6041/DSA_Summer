#include <iostream>

using namespace std;

bool findElement(int arr[], int n, int k){
    // base case
    if(n == 0){
        return 0;
    }

    // processing
    if(arr[0] == k){
        return true;
    }
    else return findElement(arr+1, n-1, k);
}

int main(void){
    int k = 0;
    cout << "Enter key: ";
    cin >> k;

    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[100];
    cout << "Enter array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    
    bool ans = findElement(arr, size, k);
    cout << "ans: " << ans << endl;
}