#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int n)
    {

        // 首先确定最大的一个数字
        int max = pow(10, n);

        vector<int> res;

        for (int i = 1; i < max; i++)
        {
            res.push_back(i);
        }
        return res;
    }
};

int main()
{
    int max = pow(10, 2);
    cout << max << endl;

    return 0;
}