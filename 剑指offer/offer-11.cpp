# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArray_(vector<int>& numbers) {
        // 直接暴力解决
        sort(numbers.begin(),numbers.end());
        return numbers[0];
    }

    int minArray(vector<int>& numbers) {
        // 使用二分查找
        int len = numbers.size();
        int left = 0;
        int right = len-1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right] ){
                // 最小值在mid和right之间
                left = mid +1;
            }
            else if (numbers[mid] < numbers[right]){
                right = mid;
            }
            else{
                right --;
            }
        }
        return numbers[mid];
        

    }
};


int main(){
    return 0;
}