#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr){
    cout << "Sorted array values: ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& arr){
    int len = arr.size();

    for(int i=0; i<len-1; i++){
        for(int j=0; j<arr.size()-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    print(arr);
}

int main(void){

    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter array values: ";
    vector<int> arr(size);

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    bubbleSort(arr);

    return 0;
}