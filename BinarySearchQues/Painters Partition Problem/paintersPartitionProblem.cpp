#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& BoardsCollection, int mid, int painters){
    int paintersCount = 1;
    int totalTimeToPaint = 0;

    for(int i=0; i<BoardsCollection.size(); i++){
        if((totalTimeToPaint + BoardsCollection[i]) <= mid){
            totalTimeToPaint += BoardsCollection[i];
        }
        else{
            paintersCount++;
            totalTimeToPaint = BoardsCollection[i];
            if(paintersCount > painters || BoardsCollection[i] > mid){
                return false;
            }
        }
    }
    return true;
}

void paintersPartition(int painters, int boards){
    int s = 0;
    int sum = 0;
    int ans = 0;
    cout << "Enter time to paint each board: ";
    vector<int> BoardsCollection(boards);
    for(int i=0; i<boards; i++){
        cin >> BoardsCollection[i];
        sum += BoardsCollection[i];
    }
    int e = sum;

    int mid = s + ((e-s)/2);

    while(s <= e){
        if(isPossible(BoardsCollection, mid, painters)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }

        mid = s + ((e - s)/2);
    }
    cout << "Minimum time to paint: " << ans << endl;    
}

int main(void){
    int painters, boards;
    cout << "Enter no. of painters: ";
    cin >> painters;
    cout << "Enter no. of boards: ";
    cin >> boards;

    paintersPartition(painters, boards);

    return 0;
}