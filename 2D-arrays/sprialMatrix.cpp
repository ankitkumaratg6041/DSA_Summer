#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& arr){
    for(vector<int>& row: arr){
        for(int val: row){
            cout << val << " ";
        }
        cout << endl;
    }
}

void spiralMatrix(const vector<vector<int>>& arr){
    int rows = arr.size();
    int cols = arr[0].size();

    vector<int> result;

    int startRowInd = 0;
    int endRowInd = rows-1;
    int startColInd = 0;
    int endColInd = cols-1;

    int count = 0;
    int totalCount = rows * cols;

    while(count < totalCount){
        for(int i=startColInd; i <= endColInd && count < totalCount; i++){
                result.push_back(arr[startRowInd][i]);
                count++;
        }
        startRowInd++;
        for(int i=startRowInd; i <= endRowInd && count < totalCount; i++){
            result.push_back(arr[i][endColInd]);
            count++;
        }
        endColInd--;
        for(int i=endColInd; i>=startColInd && count < totalCount; i--){
            result.push_back(arr[endRowInd][i]);
            count++;
        }
        endRowInd--;
        for(int i=endRowInd; i>=startRowInd && count < totalCount; i--){
            result.push_back(arr[i][startColInd]);
            count++;
        }
        startColInd++;

    }
    for(auto i: result){
        cout << i << " ";
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

    spiralMatrix(arr);
    
    return 0;
}