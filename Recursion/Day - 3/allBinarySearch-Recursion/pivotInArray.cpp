#include <iostream>
#include <vector>

using namespace std;

int findPivot(vector<int>& arr, int s, int e){
    int mid = s + ((e-s)/2);
    if(s > e) return s;

    if(arr[mid] >= arr[0]) { return findPivot(arr, mid+1, e); }
    else { return findPivot(arr, s, mid-1); }
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "\nIndex: " << findPivot(arr, 0, size-1) << endl;

    return 0;
}