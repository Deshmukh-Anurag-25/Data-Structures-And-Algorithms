#include<vector>
using namespace std;

int partition(vector<int>& nums, int low, int high){
    int pivot = nums[low];
    int i = low, j = high;

    while(i < j){
        while(i <= high-1 && nums[i] <= pivot) i++;
        while(j >= low+1 && nums[j] > pivot) j--;

        if(i < j) swap(nums[i], nums[j]);
    }

    swap(nums[low], nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int low, int high){
    if(low >= high) return;
    else{

        int pivotIdx = partition(nums, low, high);

        quickSort(nums, low, pivotIdx-1);
        quickSort(nums, pivotIdx+1, high);
    }
}