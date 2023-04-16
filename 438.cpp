#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // step 1: 创建容器
        vector<int> output; // 返回结果
        vector<int> vec_p(26, 0);
        vector<int> vec_s(26, 0);

        int len_s = s.size();
        int len_p = p.size();
        if (len_s < len_p)
        {
            return output;
        }

        // step 2: 首先处理第一个前排
        for (int i = 0; i < len_p; i++)
        {
            // 小写字母a的acsll码为97
            vec_p[p[i] - 97]++;
            vec_s[s[i] - 97]++;
        }
        if (vec_p == vec_s)
        {
            output.emplace_back(0);
        }

        // step 3: 开始滑动

        for (int i = 0; i < len_s - len_p; i++)
        {
            vec_s[s[i] - 97]--;
            vec_s[s[i + len_p] - 97]++;
            if (vec_p == vec_s)
            {
                int idx = i+1;
                output.emplace_back(idx);
            }
        }

        return output;
    }
};

int main()
{
    cout << "zhouyzuhe" << endl;
    Solution c;
    vector<int> res = c.findAnagrams("zhouyuzheou", "ou");

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    return 0;
}