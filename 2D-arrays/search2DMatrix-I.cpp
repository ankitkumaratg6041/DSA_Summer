#include <iostream>
#include <vector>

using namespace std;

void BinarySearch_2D(vector<vector<int>>& arr, int target){
    int rows = arr.size();
    int cols = arr[0].size();

    int sIndex = 0;
    int eIndex = (rows * cols) - 1;

    int mid = sIndex + ((eIndex - sIndex) / 2);

    while(sIndex <= eIndex){
        if(arr[mid/cols][mid%cols] == target){
            cout << "Present at: " << mid/rows << ", " << mid%rows << endl;
            break;
        }
        else if(arr[mid/cols][mid%cols] < target){
            sIndex = mid + 1;
        }
        else{
            eIndex = mid - 1;
        }

        mid = sIndex + ((eIndex - sIndex) / 2);
    }
}

int main(void){

    cout << "Enter rows: ";
    int rows;
    cin >> rows;
    cout << "Enter cols: ";
    int cols;
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> arr[i][j];
        }
    }
    cout << "Enter target: ";
    int target;
    cin >> target;

    BinarySearch_2D(arr, target);

    return 0;
}