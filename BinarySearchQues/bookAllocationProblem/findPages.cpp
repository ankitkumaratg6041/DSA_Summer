#include <iostream>
#include <vector>

using namespace std;

class BookAllocation{
 private:
    int studentCount = 0;
    int bookCount = 0;
    int s = 0;
    int e = 0;
    int mid = 0;

 public:
    bool isPossible(vector<int>& bookShelf){
        int pageCount = 0;
        int numStudentsAllocated = 1;
        for(int i=0; i<bookCount; i++){
            if((pageCount + bookShelf[i]) <= mid){
                pageCount += bookShelf[i];
            }
            else{
                numStudentsAllocated++;
                pageCount = bookShelf[i];
                if(numStudentsAllocated > studentCount || bookShelf[i] > mid){
                    return false;
                }
            }
        }
        return true;
    }

    int findPages(vector<int>& arr){
        int sum = 0;
        for(int i=0; i<bookCount; i++){
            sum += arr[i];
        }
        e = sum;
        mid = s + ((e - s)/2);
        int ans = 0;

        while(s < e){
            if(isPossible(arr)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + ((e - s)/2);
        }
        return ans;
    }

    int setValues(vector<int>& bookShelf, int bookCount, int studentCount){
        this->studentCount = studentCount;
        this->bookCount = bookCount;
        return findPages(bookShelf);
    }
};

int main(void){
    BookAllocation* ba = new BookAllocation();
    int studentCount = 0;
    int bookCount = 0;

    cout << "Enter student count: ";
    cin >> studentCount;
    cout << "Enter book count: ";
    cin >> bookCount;
    vector<int> bookShelf(bookCount);
    cout << "Enter books: ";
    for(int i=0; i<bookCount; i++){
        cin >> bookShelf[i];
    }

    int result = ba->setValues(bookShelf, bookCount, studentCount);
    cout << "Max no. of Min pages assigned: " << result << endl;

    return 0;
}