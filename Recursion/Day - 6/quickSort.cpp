#include <iostream>

using namespace std;

void swap(int arr[], int s, int e){
    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;
}

int partition(int arr[], int s, int e){
    /*
        ## Fulfill 2 condition of partition:
        a. Finding the correct position of the "PIVOT ELEMENT"
            1. let the first element of arr to be the "PIVOT ELEMENT"
            2. count all the elements lesser than "PIVOT ELEMENT"
            3. now the correct position of "PIVOT ELEMENT" is (s+count) -> place the pivot element at it's correct position
        b. All elements to the left of "PIVOT" is less while to the right are greater
            1. Take two pointers, say: i=s and j=e
            2. compare them to "PIVOT" and
                - if value at i>pivot and j<pivot then swap them and move both
                - if value at i>pivot and j>pivot then move j and repeat the above steps
                - if value at i<picot and j<pivot then move i and repeat the above steps
            3. Now just return the correct position of the "PIVOT ELEMENT"
    */

   int pivot = arr[s];
   int count = 0;
   for(int i=s+1; i<=e; i++){
    if(arr[i] <= pivot) count++;
   }
   swap(arr, s, s+count);
   int pivotIndex = s+count;
   int i=s; int j=e;
   while(i < pivotIndex && j > pivotIndex){
    if(arr[i] > pivot && arr[j] < pivot) { swap(arr, i, j); i++; j--;}
    else if(arr[i] > pivot && arr[j] > pivot) { j--; }
    else i++;
   }

   return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    // base case 
    if(s >= e){
        return;
    }

    // processing - finding the partition
    int p = partition(arr, s, e);

    // recursion - to sort the array
    // left part - recursive call
    quickSort(arr, s, p-1);
    // right part - recursive call
    quickSort(arr, p+1, e);
}


int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[1000];
    cout << "Enter array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, size-1);

    cout << "Result: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}