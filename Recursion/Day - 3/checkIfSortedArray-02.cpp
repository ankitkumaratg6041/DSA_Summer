#include <iostream>

using namespace std;

bool checkSorted(int arr[], int n){
    // base case
    if(n == 0 || n == 1){
        return 1;
    }

    // processing
    if(arr[0] > arr[1]) return 0;
    else return checkSorted(arr+1, n-1);
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[100];
    cout << "Enter array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    
    bool ans = checkSorted(arr, size);
    cout << "ans: " << ans << endl;
}