#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class firstAndLastHandler{
public:
    pair<int, int>firstAndLastOccurence(vector<int> &arr, int key){
        pair<int, int> ans;
        ans.first = leftMostOccurence(arr, key);
        ans.second = rightMostOccurence(arr, key);

        return ans;
    }

    int leftMostOccurence(vector<int> &arr, int key){
        int start = 0;
        int end = arr.size()-1;
        int mid = start + ((end-start)/2);

        int leftIndex = -1;

        while(start <= end){
            if(arr[mid] == key){
                leftIndex = mid;
                end = mid - 1;
            }
            else if(key > arr[mid]){
                start = mid + 1;
            }
            else if(key < arr[mid]){
                end = mid - 1;
            }
            mid = start + ((end-start)/2);
        }
        return leftIndex;
    }

    int rightMostOccurence(vector<int> &arr, int key){
        int start = 0;
        int end = arr.size()-1;
        int mid = start + ((end-start)/2);

        int rightIndex = -1;

        while(start <= end){
            if(arr[mid] == key){
                rightIndex = mid;
                start = mid + 1;
            }
            else if(key > arr[mid]){
                start = mid + 1;
            }
            else if(key < arr[mid]){
                end = mid - 1;
            }
            mid = start + ((end-start)/2);
        }
        return rightIndex;
    }
};

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter array: ";
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    cout << "Enter key: ";
    int key;
    cin >> key;

    pair<int, int> ans;
    firstAndLastHandler* findIndex = new firstAndLastHandler();
    ans = findIndex->firstAndLastOccurence(arr, key);

    cout << ans.first << " " << ans.second << endl;
    

    return 0;
}