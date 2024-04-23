#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2, int size1, int size2){
    int index1 = 0;
    int index2 = 0;

    vector<int> mergedArray;

    while((index1 < size1) && (index2 < size2)){
        if(arr1[index1] < arr2[index2]){
            mergedArray.push_back(arr1[index1]);
            index1++;
        }
        else{
            mergedArray.push_back(arr2[index2]);
            index2++;
        }
    }

    if(index1 < size1){
        for(index1; index1 < size1; index1++){
            mergedArray.push_back(arr1[index1]);
        }
    }
    else{
        for(index2; index2 < size2; index2++){
            mergedArray.push_back(arr2[index2]);
        }
    }

    cout << "Merged array: ";
    for(auto i: mergedArray){
        cout << i << " ";
    }
    cout << endl;

}

int main(void){
    int size1;
    cout << "Enter size1: ";
    cin >> size1;
    vector<int> arr1(size1);
    cout << "Enter array1: ";
    for(int i=0; i<size1; i++){
        cin >> arr1[i];
    }
    
    int size2;
    cout << "Enter size2: ";
    cin >> size2;
    vector<int> arr2(size2);
    cout << "Enter array2: ";

    for(int i=0; i<size2; i++){
        cin >> arr2[i];
    }

    mergeSortedArrays(arr1, arr2, size1, size2);

    return 0;
}