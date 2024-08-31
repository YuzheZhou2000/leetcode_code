# include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1){
            return 0;
        }
        int ans = -1;
        int left = 0;
        int right = height.size()-1;
        while (left < right)
        {
            ans = max(ans, min(height[left], height[right]) * (right-left));
            if (height[left] < height[right]){
                left ++;
            }else{
                right--;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int ans = s.maxArea(vec);
    cout << "ans: "<<ans;
    return 0;
}