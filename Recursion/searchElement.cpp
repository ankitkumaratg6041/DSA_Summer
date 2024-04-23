#include <iostream>
#include <vector>

using namespace std;

bool searchElement(vector<int>& arr, int index, int key){
    // base case
    if(index == arr.size()) return false;
    if(arr[index] == key) return true;

    // processing
    bool ans = searchElement(arr, index+1, key);
    return ans;
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    bool ans = searchElement(arr, 0, key);
    cout << "Ans: " << ans << endl;

    return 0;
}