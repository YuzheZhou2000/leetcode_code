#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //面试题 01.01. 判定字符是否唯一
    bool isUnique(string astr)
    {
        // 使用位运算解决【根据题中描述默认字符串中只会出现a-z 26个 小写字母】
        // 一个int类型的数据一般为4字节32bit 因此可以完全表示26个字母
        int mark = 0; //mark作为出现的记录
        for (int i = astr.length() - 1; i >= 0; i--)
        {
            // 遍历字符串

            // TODO 1 首先计算需要位移的距离

            int move_bit = astr[i] - 'a';
            // 对1 进行左移 并进行与操作
            if ((mark & (1 << move_bit)) != 0)
            {
                // 之出现过 再次出现
                return false;
            }
            else
            {
                //没有出现过
                mark = mark | (1 << move_bit);
            }
        }
        return true;
    }
    //面试题 01.02. 判定是否互为字符重排
    bool CheckPermutation(string s1, string s2)
    {

        // 首先比较两个字符串的长度
        if (s1.length() != s2.length())
        {
            return false;
        }
        // 使用map数据结构
        map<char, int> recoder;
        map<char, int>::iterator iter;
        // 记录s1中各个字符出现的频率
        for (int i = 0; i < s1.length(); i++)
        {
            iter = recoder.find(s1[i]);
            // 哈希表中存在这个数据
            if (iter != recoder.end())
            {
                iter->second++;
            }
            else
            { // 之前没有此数据,直接新增
                recoder[s1[i]] = 1;
            }
        }
        // 将s2中字符出现的依次删除
        for (int i = 0; i < s2.length(); i++)
        {
            iter = recoder.find(s2[i]);
            //s1中出现过本字符
            if (iter != recoder.end())
            {
                if (iter->second == 0)
                { //s2中此字符出现的次数大于s1;
                    return false;
                }
                else
                {
                    if (iter->second == 1)
                    {
                        recoder.erase(iter);
                    }
                    else
                    {
                        iter->second--;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        // 判断哈希表是否为空
        if (recoder.empty())
        {
            return true;
        }
        return false;
    }
    //面试题 01.03. URL化
    string replaceSpaces(string S, int length)
    {
        // 使用双指针
        int str_len = S.length(); // 目标字符串的长度
        cout << "str_len" << str_len << endl;
        int index_slow = length - 1;  // 慢指针表示原始字符串
        int index_fast = str_len - 1; //快指针表示结果字符串
        //从后向前遍历
        for (; index_slow >= 0; index_slow--)
        {
            if (S[index_slow] != ' ')
            { //直接赋值，目标后移
                S[index_fast--] = S[index_slow];
            }
            else
            {
                S[index_fast--] = '0';
                S[index_fast--] = '2';
                S[index_fast--] = '%';
            }
        }
        // okk

        // 最后对目标字符串进行截取
        S = S.substr(index_fast + 1);
        return S;
    }
    //面试题 01.04. 回文排列
    bool canPermutePalindrome(string s)
    {
        set<char> recoder;
        set<char>::iterator iter;
        for (int i = 0; i < s.length(); i++)
        {
            iter = recoder.find(s[i]);
            if (iter != recoder.end())
            { //集合中有此数据
                recoder.erase(s[i]);
            }
            else
            {
                recoder.insert(s[i]);
            }
        }
        if (s.length() % 2 == 0)
        { // 长度为偶数
            return recoder.empty();
        }
        else
        { // 长度为奇数
            if (recoder.size() == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    //面试题 01.05. 一次编辑
    bool oneEditAway(string first, string second)
    {
        if (first == second)
        { //相等 没有改变
            return true;
        }
        int cha = first.length() - second.length();
        // 是第一个字符串永远长于第二个字符串
        if (cha < 0)
        {
            return oneEditAway(second, first);
        }
        else if (cha > 1)
        { // 两个字符串相差的长度大于1 不满足提议
            return false;
        }
        else if (cha == 1) // 插入或者删除 firts 多一个
        {
            int start_long = 0;
            while (start_long < second.length())
            {
                if (first[start_long] == second[start_long])
                {
                    start_long++;
                }
                else
                {
                    return first.substr(start_long + 1) == second.substr(start_long);
                }
            }
            return true;
        }
        else
        { // 修改
            int start_long = 0;
            while (start_long < first.length())
            {
                if (first[start_long] == second[start_long])
                {
                    start_long++;
                }
                else
                {
                    return second.substr(start_long + 1) == first.substr(start_long + 1);
                }
            }
            return true;
        }
        return false;
    }
    //面试题 01.06. 字符串压缩
    string compressString(string S)
    {
        int len = S.length();
        if (len == 0)
        {
        }
        for (int i = 0; i < len; i++)
        {
        }
    }
    // 面试题 01.07. 旋转矩阵
    void rotate(vector<vector<int>> &matrix)
    {
        // 本题考查对一个矩阵进行顺时针旋转九十度

        // 通过分析可知顺时针旋转九十度可以看作是先上下翻转，然后对角线反转

        // 首先得到矩阵的行数
        int len = matrix.size();

        // 如果矩阵的行数小于2，直接返回
        if (len < 2)
        {
            return;
        }

        // 对矩阵首先进行上下翻转
        for (int i = 0; i < len / 2; i++)
        {
            swap(matrix[i], matrix[len - i - 1]);
        }

        // 然后对矩阵进行对角线翻转
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
    // 面试题 01.08. 零矩阵
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // 面试题 01.09. 字符串轮转
    bool isFlipedString(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        string s = s1 + s1;
        // 如果是旋转字符串  一定为子串

        return s.find(s2) != -1;
    }
};

int main()
{
    string s1, s2;
    Solution demo;
    return 0;
}