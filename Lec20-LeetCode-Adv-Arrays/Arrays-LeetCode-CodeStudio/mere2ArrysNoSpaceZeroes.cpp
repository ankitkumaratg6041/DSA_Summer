#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& arr1){
    cout << "Sorted and merged array: ";
    for(auto i: arr1){
        cout << i << " ";
    }
    cout << endl;
}

void merge2ArraysNoSpaceWithZeroes(vector<int>& arr1, vector<int>& arr2){
    int size1 = arr1.size();
    int size2 = arr2.size();

    int i = (size1-size2)-1;
    int j = size2-1;
    int k = size1 - 1;

    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            swap(arr1[i], arr1[k]);
            k--;
            i--;
        }
        else{
            swap(arr2[j], arr1[k]);
            k--;
            j--;
        }
    }

    while(j >= 0){
        swap(arr1[k], arr2[j]);
        k--;
        j--;
    }

    // sort(arr1.begin()+(size1-size2), arr1.end()); // mid of arr1 to end of arr1
    // sort(arr1.begin(), (arr1.end()-size2)); // start of arr1 to mid of arr1

    print(arr1);
}

int main(void){
    int size1;
    cout << "Enter size1: ";
    cin >> size1;

    vector<int> arr1(size1);
    cout << "Enter vector 1: ";
    for(int i=0; i<size1; i++){
        cin >> arr1[i];
    }

    int size2;
    cout << "Enter size2: ";
    cin >> size2;

    vector<int> arr2(size2);
    cout << "Enter vector 2: ";
    for(int i=0; i<size2; i++){
        cin >> arr2[i];
    }

    cout << endl << "old arr1: ";
    for(auto i: arr1){
        cout << i << " ";
    }
    cout << endl;

    size1 += size2;
    for(int i=0; i<size2; i++){
        arr1.push_back(0);
    }

    cout << "arr1: ";
    for(auto i: arr1){
        cout << i << " ";
    }
    cout << endl;

    merge2ArraysNoSpaceWithZeroes(arr1, arr2);

    return 0;
}