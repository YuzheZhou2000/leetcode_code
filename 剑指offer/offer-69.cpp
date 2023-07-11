#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 查找山峰数组的顶部 因为给定的数组是一个完成排序的有序数组（先增后减
        // 因此考虑使用二分查找

        int len = arr.size();

        int left = 0;
        int right = len-1;
        int mid = 0;

        while (left <= right)
        {
            // 确定二分查找的中间位置
            mid = left + (right-left)/2;

            // 判断中间点的位置

            if(arr[mid]> arr[mid-1] && arr[mid] > arr [mid+1]){
                break;
            }
            else if(arr[mid] > arr[mid-1] && arr[mid] <= arr[mid +1]){
                left = mid;
            }else{
                right = mid;
            }

        }
        return mid;        

    }
};

int main(){

    return 0;
}