#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    int l = low, r = mid + 1, k = l;
    vector<int> temp(nums.size());
    while(l <= low && r <= high){
        if(nums[l] < nums[r]){temp[k++] = nums[l++];}
        else{temp[k++] = nums[r++];}
    }
    while(l <= mid){temp[k++] = nums[l++];}
    while(r <= high){temp[k++] = nums[r++];}
    for(int i = low; i <= high; i++){
        nums[i] = temp[i];
    }
}

void mergeSort(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

int main(){
    //Merge Sort Recursive
    vector<int> nums = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    mergeSort(nums, 0, nums.size() - 1);
    cout << "Recursively Merge Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    return 0;
}