#include<iostream>
using namespace std;

void printArr(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cyclicSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){

        int ele = arr[i];
        int pos = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < ele){
                pos++;
            }
        }
 
        if(pos == i){
            continue;
        }
 
        while(ele == arr[pos]){
            pos++;
        }
 
        if(pos != i){
            swap(ele, arr[pos]);
        }
 
        while(pos != i){

            pos = i;
 
            for(int j = i + 1; j < n; j++){
                if(arr[j] < ele){
                    pos++;
                }
            }
 
            while(ele == arr[pos]){
                pos++;
            }
 
            if(ele != arr[pos]){
                swap(ele, arr[pos]);
            }
        }
    }
}

int main(){

    int n = 9;
    int nums[n] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Before Sorting : " << endl;
    printArr(nums, n);

    cyclicSort(nums, n);

    cout << endl << "After Sorting : " << endl;
    printArr(nums, n);

    return 0;
}