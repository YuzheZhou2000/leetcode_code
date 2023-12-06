#include <bits/stdc++.h>
/**
 * 扑克牌顺子
 */
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */
    bool IsContinuous(vector<int> &numbers)
    {
        // write code here
        // numbers是一个五位数 如果仅仅考虑到最大值和最小值的情况
        // 无法对重复的数字做出过滤
        // 因此我们引入一个vector做一个简单的hash来记录是不是访问过
        vector<int> recoder(14, 0);

        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (auto &i : numbers)
        {
            if (i == 0)
            {
                recoder[0]++;
            }
            else
            {
                minNum = min(minNum, i);
                maxNum = max(maxNum, i);
                if (recoder[i])
                {
                    // 有重复
                    return false;
                }
                else
                {
                    recoder[i] = 1;
                }
            }
        }
        // cout << "zero number: " << recoder[0] << " max: " << maxNum << " min: " << minNum << endl;
        // 需要保证不会有重复的数字
        if (maxNum - minNum <= 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    vector<int> res{13, 12, 11, 0, 1};
    Solution s;
    cout << "ans: " << s.IsContinuous(res);
    return 0;
}