#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 找出只出现一次的 我直接hashmap
        unordered_map<int, int> myMap;

        int len = nums.size();
        for (auto num : nums)
        {
            if (myMap.find(num) == myMap.end())
            {
                //cout <<"num: "<<num << " "<<1<<endl;
                myMap.emplace(num, 1);
            }
            else{
                //cout <<"num: "<<num << " "<<3<<endl;
                auto tem = myMap.find(num);
                tem->second = 3;
                //myMap.emplace(num,3);
            }
        }

        for (auto it : myMap){
            //cout <<"it: "<<it.first << " "<<it.second<<endl;
            if(it.second == 1){
                return it.first;
            }
        }
        return 0;
    }
};
int main()
{
    return 0;
}