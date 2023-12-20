#include <bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2)
{
    int size1 = word1.size();
    int size2 = word2.size();
    vector<vector<int>> vec(size1 + 1, vector<int>(size2 + 1, 0));
    for (int i = 0; i <= size1; i++)
    {
        vec[i][0] = i;
    }
    for (int i = 0; i <= size2; i++)
    {
        vec[0][i] = i;
    }

    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                vec[i][j] = vec[i - 1][j - 1];
            }
            else
            {
                vec[i][j] = 1 + min(min(vec[i - 1][j - 1], vec[i - 1][j]), vec[i][j - 1]);
            }
        }
    }
    for (auto &i : vec)
    {
        for (auto &j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
    return vec[size1][size2];
}
int main()
{
    int dis = minDistance("", "11");
    cout << "dis: " << dis;

    return 0;
}