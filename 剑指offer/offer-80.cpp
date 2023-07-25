#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        makeSet(n, 1, 0, k, temp);
        return ans;
    }
    void makeSet(int n, int s, int num, int k, vector<int> temp)
    {
        if (s > n)
        {
            return;
        }
        if (num == k)
        {
            ans.push_back(temp);
            return;
        }

        makeSet(n, s+1; num; k, temp);

        temp.push_back(s);
        makeSet(n, s+1; num+1; k, temp);

    }
};

int main()
{
    return 0;
}