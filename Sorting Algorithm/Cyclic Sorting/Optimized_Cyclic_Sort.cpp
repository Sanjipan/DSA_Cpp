#include<iostream>
using namespace std;

void printArr(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void optimized_cyclic_sort(int arr[], int n){

    int i = 0;
    while(i < n){
        int correct = arr[i] - 1 ;
        if(arr[i] != arr[correct]){
            swap(arr[i], arr[correct]) ;
        }
        else{
            i++ ;
        }
    }
}

int main(){

    int n = 9;
    int nums[n] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Before Sorting : " << endl;
    printArr(nums, n);

    optimized_cyclic_sort(nums, n);

    cout << endl << "After Sorting : " << endl;
    printArr(nums, n);

    return 0;
}