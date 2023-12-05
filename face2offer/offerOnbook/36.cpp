# include <bits/stdc++.h>
/**
 *  数字在升序数组中出现的次数
*/
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int GetNumberOfK(vector<int>& nums, int k) {
        // write code here
        // 属于是二分查找的拓展算法 因为题目中给出来了nums是一个已经排好序的非降序数组
        int star = -1, end = -1;
        
        // 使用二分查找分别定位k在nums数组中左右出现的下标

        // 首先定位左边的下标
        int left = 0, right = nums.size()-1;

        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == k){
                // 尽管这时候我们找到了 但是在这个题目中我们需要找到的是最左边的
                if (mid == 0 || (nums[mid-1] != k && mid >0 )){
                    star = mid;
                    break;
                }else{
                    right = mid-1;
                }
            }
            else if (nums[mid] > k){
                right = mid-1;
            }else{
                left = mid +1;
            }
        }

        // 继续定位右边
        left = 0;
        right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == k){
                if (mid == nums.size()-1 || (mid<nums.size()-1 && nums[mid+1] != k)){
                    // 这时候算是找到了目标的有边界
                    end = mid;
                    break;
                }else{
                    left = mid +1;
                }
            }else if (nums[mid] >k){
                right = mid-1;
            }else{
                left = mid +1;
            }
        }
        if (star == -1){
            return 0;
        }


        return end - star+1;
    }
};

int main(){
    // int i = 3 + ((5-3)>>1);
    // cout <<i<<endl;
    vector <int> ans = {1,2,3,4,4,9};
    Solution s;
    int a = s.GetNumberOfK(ans, 5);
    cout <<"ans: "<<a<<endl;

    return 0;
}