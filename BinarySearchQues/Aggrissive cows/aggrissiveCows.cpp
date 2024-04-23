#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isPossible(vector<int>& disBwStalls, int cows, int mid){
    int cowCount = 1;
    int lastPossibleMaxPosition = disBwStalls[0];

    for(int i=1; i<disBwStalls.size(); i++){
        if((disBwStalls[i] - lastPossibleMaxPosition) >= mid){
            cowCount++;
            if(cowCount == cows){
                return true;
            }
            lastPossibleMaxPosition = disBwStalls[i]; // This line is meaningful only when you have more than one cow
        }
    }
    return false;
}

void bubbleSortStalls(vector<int>& disBwStalls){
    for(int i=0; i<disBwStalls.size()-1; i++){
        int didSwap = false;
        for(int j=0; j<disBwStalls.size()-1-i; j++){
            if(disBwStalls[j] > disBwStalls[j+1]){
                int temp = disBwStalls[j];
                disBwStalls[j] = disBwStalls[j+1];
                disBwStalls[j+1] = temp;
                didSwap = true;
            }
        }
        if(!didSwap){
            break;
        }
    }
}

void aggrissiveCows(int cows, int stalls){
    vector<int> disBwStalls(stalls);
    int max = INT_MIN;
    cout << "Enter the distance between each stalls: ";
    for(int i=0; i<stalls; i++){
        cin >> disBwStalls[i];
        if(disBwStalls[i] > max) max = disBwStalls[i];
    }

    bubbleSortStalls(disBwStalls);

    int s = 0;
    int e = max - disBwStalls[0];
    int mid = s + ((e-s)/2);
    int ans = 0;

    while(s <= e){
        if(isPossible(disBwStalls, cows, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + ((e - s)/2);
    }
    cout << "Max possible distance between aggrissive cows: " << ans << endl;
}

int main(void){
    int cows;
    int stalls;
    cout << "Enter no. of cows: ";
    cin >> cows;
    cout << "Enter no. of stalls: ";
    cin >> stalls;

    aggrissiveCows(cows, stalls);


    return 0;
}