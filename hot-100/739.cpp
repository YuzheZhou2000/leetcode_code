#include <bits/stdc++.h>

using namespace std;

class Solution
{
    /*
    给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
    其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
    如果气温在这之后都不会升高，请在该位置用 0 来代替。
    */
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int len = temperatures.size();
        vector<int> res(len);
        res[len - 1] = len - 1;
        if (len <= 1)
        { // 如果数组的长度小于1 直接返回
            return res;
        }
        for (int i = len - 2; i >= 0; i--)
        {
            int j = i + 1;
            // 开始寻找大于的数字
            if (temperatures[j] > temperatures[i])
            {
                res[i] = j;
            }

            else
            {
                if (res[j] == j)
                {
                    // j后面已经没有更大的数字了
                    res[i] = i;
                }
                else
                {
                    // 不等于0的时候要判断是不是比它大的数比现在的数字大
                    while (temperatures[res[j]] <= temperatures[i])
                    {
                        if(j == res[j]){
                            break;
                        }
                        j = res[j];
                        
                    }

                    j =res[j];

                    if (temperatures[j] > temperatures[i])
                    {
                        res[i] = j;
                    }
                    else
                    {
                        res[i] = i;
                    }
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            cout << temperatures[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < len; i++)
        {
            res[i] = res[i]-i;
            cout << res[i] << " ";
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> tem = {55,38,53,81,61,93,97,32,43,78};
    s.dailyTemperatures(tem);

    return 0;
}