#include <iostream>

using namespace std;

bool checkSorted(int arr[], int i, int j, int n){
    // base case
    if(n == 0){
        return 1;
    }
    
    if(j >= n){
        return 1;
    }

    // processing
    bool ans = 0;
    if(arr[i] <= arr[j]) ans = 1;
    else return ans = 0;

    return checkSorted(arr, ++i, ++j, n);
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
    
    bool ans = checkSorted(arr, 0, 1, size);
    cout << "ans: " << ans << endl;
}