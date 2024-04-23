#include <iostream>
#include <vector>

using namespace std;

int sumArrElements(vector<int>& arr, int index){
    // base case
    if(index == arr.size())
        return 0;
    
    // recursion
    cout << "index: before: " << index << endl;
    int remaining = sumArrElements(arr, index+1);
    cout << "index: after: " << index << endl;
    return arr[index] + remaining;
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    int totalSum = sumArrElements(arr, 0);
    cout << "Total sum: " << totalSum << endl;

    return 0;
}