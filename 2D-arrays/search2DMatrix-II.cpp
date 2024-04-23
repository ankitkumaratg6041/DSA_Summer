#include <iostream>
#include <vector>

using namespace std;

void BinarySearch_2D_II(vector<vector<int>>& arr, int target){
    int rows = arr.size();
    int cols = arr[0].size();

    int rowIndex = 0;
    int colIndex = cols-1;

    while(rowIndex < rows && colIndex >= 0){
        int element = arr[rowIndex][colIndex];
        if(element == target){
            cout << "Element found at: " << rowIndex << ", " << colIndex << endl;
            break;
        }
        else if(element > target){
            colIndex--;
        }
        else{
            rowIndex++;
        }
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

    BinarySearch_2D_II(arr, target);

    return 0;
}