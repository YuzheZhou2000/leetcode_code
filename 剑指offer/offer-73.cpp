# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 首先需要确定二分查找的最大值和最小值
        int left  = 1;// 吃香蕉的速度最慢为每小时吃一根。
        int right = * max_element(piles.begin(),piles.end());
        int k = right;

        while (left < right)
        {
            int mid = left + (right - left)/2; // 代表当前吃饭的速度
            int nowHour = getH(piles, mid);
            
            if(nowHour <= h){
                // 吃的太快了 应该降速
                k = mid;
                right = mid;                
                
            }else{
                left = mid+1;
            }            
        }
        return k;
    }

    int getH(vector<int>& piles, int s){
        // 返回在吃香蕉的速度为s时候，需要的时间
        int size = piles.size();
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            if(piles[i]<=s){
                ans++;
            }else{
                ans += piles[i]/s;
                if(piles[i]*1.0/s != piles[i]/s){
                    ans ++;
                }
            }
        }  
        return ans;      
    }

};


int main(){
    vector < int > v ={1,1,1,999999999};
    int h = 10;
    Solution s;
    cout<<s.getH(v,h);
    return 0;
}