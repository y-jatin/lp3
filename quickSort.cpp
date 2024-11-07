#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int deterministicPartition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

int randomizedPartition(vector<int> &arr, int low, int high){
    int pivotIndex = low + rand()%(high-low+1);
    swap(arr[pivotIndex],arr[high]);
    return deterministicPartition(arr,low,high);
}

void deterministicQuickSort(vector<int> &arr, int low, int high){
    if (low < high){
        int pivotIndex = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr,low,pivotIndex-1);
        deterministicQuickSort(arr,pivotIndex+1,high);
    }
}

void randomizedQuickSort(vector<int> &arr, int low, int high){
    if (low < high){
        int pivotIndex = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr,low,pivotIndex-1);
        randomizedQuickSort(arr,pivotIndex+1,high);
    }
}

int main(){
    vector<int> arr = {10,7,8,9,1,5};
    int n = arr.size();
    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    srand(time(0));

    clock_t start = clock();
    deterministicQuickSort(arr1,0,n-1);
    clock_t end = clock();

    double deterministicTime = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    randomizedQuickSort(arr2,0,n-1);
    end = clock();

    double randomizedTime = double(end-start)/CLOCKS_PER_SEC;

    cout << deterministicTime << " " << randomizedTime << endl;
    for (auto it: arr2) cout << it << " ";
    return 0;
}