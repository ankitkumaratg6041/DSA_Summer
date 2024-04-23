#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class BinarySearch{
 private:
    int start = 0;
    int end = 0;
    int mid = 0;
    int size = 0;
    int key = 0;
    int leftIndex = -1;
    int rightIndex = -1;
    vector<int> array;
 public:
    void inputHandler(){
        int size;
        cout << "Enter size: ";
        cin >> size;
        this->size = size;

        cout << "Enter the vector: ";
        array.resize(this->size);
        int len = size;
        int i = 0;
        while(len--){
            cin >> array[i];
            i++;
        }

    }

    int keyInputHandler() {
        cout << "Enter key: ";
        cin >> key;
        return key;
    }

    void binarySearch(){
        inputHandler();
        keyInputHandler();

        start = 0;
        end = this->array.size() - 1;
        mid = start + ((end-start)/2);

        while(start <= end){
            if(array[mid] == key) {
                break;
            }
            if(array[mid] > key){
                end = mid-1;
            }
            if(array[mid] < key){
                start = mid+1;
            }
            mid = start + ((end - start)/2);
        }
        cout << "Key found at index: " << mid << endl;
    }
    void firstAndLastPosition(){
        inputHandler();
        keyInputHandler();

        leftIndex = leftBSHandler(key);
        rightIndex = rightBSHandler(key);

        if(rightIndex < 0 || leftIndex < 0){
            cout << "Element not found." << endl;
        } else{
            cout << "Element found at: [" << leftIndex << ", " << rightIndex << "]" << endl;
        }
    }

    int leftBSHandler(int key){
        int start = 0;
        int end = array.size()-1;
        int mid = start + ((end-start)/2);
        while(start <= end){
            if(array[mid] == key){
                leftIndex = mid;
                end = mid-1;
            }
            else if(array[mid] > key){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + ((end-start)/2);
        }
        return leftIndex;
    }

    int rightBSHandler(int key){
        int start = 0;
        int end = array.size()-1;
        int mid = start+((end-start)/2);
        while(start <= end){
            if(array[mid] == key){
                rightIndex = mid;
                start = mid+1;
            }
            else if(array[mid] > key){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + ((end-start)/2);
        }
        return rightIndex;
    }

    void totalOccurencesOfElement(){
        firstAndLastPosition();
        int totalOccurence = (rightIndex - leftIndex) + 1;
        cout << "Total occurences of key " << key << " : " << totalOccurence << endl;
    }
    void peakIndexInMountainArray(){
        inputHandler();
        end = array.size() - 1;
        mid = start + ((end - start)/2);

        while(start <= end){
            if(array[mid] < array[mid-1])
                end = mid - 1;
            else if(array[mid] < array[mid+1])
                start = mid + 1;
            else{
                cout << "Peak index is: " << mid << " and element is: " << array[mid] << endl;
                return;
            }
            
            mid = start + ((end - start) / 2);
        }
    }
    void pivotInArray(){
        inputHandler();
        end = array.size()-1;
        mid = start + ((end - start)/2);

        while(start < end){
            if(array[mid] > array[0])
                start = mid + 1;
            else if(array[mid] < array[0])
                end = mid;
            
            mid = start + ((end - start)/2);
        }
        cout << "Pivot index is: " << start << " and element is: " << array[start] << endl;
    }
    void squareRoot(){
        cout << "Enter number to find square root of: ";
        cin >> key;
        end = key;
        mid = start + ((end-start)/2);
        long long int ans = -1;
        
        while(start <= end){
            long long int square = mid * mid;
            if(square == key){
                cout << "Square root of: " << key << " is: " << mid << endl;
                return;
            }
            else if(square < key){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            
            mid = start + ((end - start)/2);
        }
        cout << "Since this number doesn't have integer square root so enter upto how many decimal places you want your answer to be" << endl;
        int precision;
        cout << "Enter precision: ";
        cin >> precision;

        int loop = precision;
        long double factor = 1;
        long double result = (long double)ans;
        long double target = key;

        while(loop){
            cout << "Loop: " << loop << endl << endl;
            factor /= 10;
            result = decimalSqRootHandler(result, factor, target, (precision - loop)+1);
            cout << "Result: " << result << endl;
            if(result == target){
                cout << "Exact square root: " << result << endl;
                return;
            }
            loop--;
        }
        cout << "Square root in " << precision <<" decimal places: " << result << endl;
    }

    // Function to truncate a long double to a specific number of decimal places without rounding
    long double truncateToDecimalPlaces(long double value, int decimalPlaces) {
        long double scale = std::pow(10.0, decimalPlaces);
        return std::trunc(value * scale) / scale;
    }

    long double decimalSqRootHandler(long double num, long double factor, long double target, int decimalPlaces){
        long double decimalHandler = factor;
        long double endPrecisionHandler = decimalHandler*9;

        long double p_start = num+decimalHandler;
        long double p_end = num + endPrecisionHandler;

        long double p_mid = p_start + ((p_end - p_start)/2);
        long double ans = 0;

        while(p_start <= p_end){
            long double square = p_mid * p_mid;

            if(square == target){
                return p_mid;
            }
            else if(square < target){
                ans = p_mid;
                p_start = p_mid + decimalHandler;
            }
            else{
                p_end = p_mid - decimalHandler;
            }
            
            p_mid = p_start + ((p_end - p_start)/2);
            p_mid = truncateToDecimalPlaces(p_mid, decimalPlaces);
        }
        return ans=p_mid;
    }
};




void programManager(){
    BinarySearch* bs = new BinarySearch();

    cout << "Follow the instructions: " << endl << endl;
    cout << "\t1 -> Binary Search" << endl;
    cout << "\t2 -> First and Last Position of an Element" << endl;
    cout << "\t3 -> Total number of occurence of an element" << endl;
    cout << "\t4 -> Peak Index in a mountain array" << endl;
    cout << "\t5 -> Pivot Index in a sorted rotated array" << endl;
    cout << "\t6 -> Square root of an element" << endl;
    int choice;
    cin >> choice;
    string chosenFunc;

    switch(choice){
        case 1: 
            bs->binarySearch();
            break;
        case 2: 
            bs->firstAndLastPosition();
            break;
        case 3: 
            bs->totalOccurencesOfElement();
            break;
        case 4: 
            bs->peakIndexInMountainArray();
            break;
        case 5: 
            bs->pivotInArray();
            break;
        case 6: 
            bs->squareRoot();
            break;
        default:
            cout << "Invalid input. Please try again!!";
            programManager();
    }


}

int main(void){

    programManager();

    return 0;
}