#include <iostream>

using namespace std;

int checkSorted(int arr[], int n){
    // base case
    if(n == 0){
        return 0;
    }

    // processing
    return arr[0] + checkSorted(arr+1, n-1);
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
    
    int ans = checkSorted(arr, size);
    cout << "Sum: " << ans << endl;
}