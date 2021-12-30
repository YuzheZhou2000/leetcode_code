#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //������ 01.01. �ж��ַ��Ƿ�Ψһ
    bool isUnique(string astr)
    {
        // ʹ��λ��������������������Ĭ���ַ�����ֻ�����a-z 26�� Сд��ĸ��
        // һ��int���͵�����һ��Ϊ4�ֽ�32bit ��˿�����ȫ��ʾ26����ĸ
        int mark = 0; //mark��Ϊ���ֵļ�¼
        for (int i = astr.length() - 1; i >= 0; i--)
        {
            // �����ַ���

            // TODO 1 ���ȼ�����Ҫλ�Ƶľ���

            int move_bit = astr[i] - 'a';
            // ��1 �������� �����������
            if ((mark & (1 << move_bit)) != 0)
            {
                // ֮���ֹ� �ٴγ���
                return false;
            }
            else
            {
                //û�г��ֹ�
                mark = mark | (1 << move_bit);
            }
        }
        return true;
    }
    //������ 01.02. �ж��Ƿ�Ϊ�ַ�����
    bool CheckPermutation(string s1, string s2)
    {

        // ���ȱȽ������ַ����ĳ���
        if (s1.length() != s2.length())
        {
            return false;
        }
        // ʹ��map���ݽṹ
        map<char, int> recoder;
        map<char, int>::iterator iter;
        // ��¼s1�и����ַ����ֵ�Ƶ��
        for (int i = 0; i < s1.length(); i++)
        {
            iter = recoder.find(s1[i]);
            // ��ϣ���д����������
            if (iter != recoder.end())
            {
                iter->second++;
            }
            else
            { // ֮ǰû�д�����,ֱ������
                recoder[s1[i]] = 1;
            }
        }
        // ��s2���ַ����ֵ�����ɾ��
        for (int i = 0; i < s2.length(); i++)
        {
            iter = recoder.find(s2[i]);
            //s1�г��ֹ����ַ�
            if (iter != recoder.end())
            {
                if (iter->second == 0)
                { //s2�д��ַ����ֵĴ�������s1;
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
        // �жϹ�ϣ���Ƿ�Ϊ��
        if (recoder.empty())
        {
            return true;
        }
        return false;
    }
    //������ 01.03. URL��
    string replaceSpaces(string S, int length)
    {
        // ʹ��˫ָ��
        int str_len = S.length(); // Ŀ���ַ����ĳ���
        cout << "str_len" << str_len << endl;
        int index_slow = length - 1;  // ��ָ���ʾԭʼ�ַ���
        int index_fast = str_len - 1; //��ָ���ʾ����ַ���
        //�Ӻ���ǰ����
        for (; index_slow >= 0; index_slow--)
        {
            if (S[index_slow] != ' ')
            { //ֱ�Ӹ�ֵ��Ŀ�����
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

        // ����Ŀ���ַ������н�ȡ
        S = S.substr(index_fast + 1);
        return S;
    }
    //������ 01.04. ��������
    bool canPermutePalindrome(string s)
    {
        set<char> recoder;
        set<char>::iterator iter;
        for (int i = 0; i < s.length(); i++)
        {
            iter = recoder.find(s[i]);
            if (iter != recoder.end())
            { //�������д�����
                recoder.erase(s[i]);
            }
            else
            {
                recoder.insert(s[i]);
            }
        }
        if (s.length() % 2 == 0)
        { // ����Ϊż��
            return recoder.empty();
        }
        else
        { // ����Ϊ����
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
    //������ 01.05. һ�α༭
    bool oneEditAway(string first, string second)
    {
        if (first == second)
        { //��� û�иı�
            return true;
        }
        int cha = first.length() - second.length();
        // �ǵ�һ���ַ�����Զ���ڵڶ����ַ���
        if (cha < 0)
        {
            return oneEditAway(second, first);
        }
        else if (cha > 1)
        { // �����ַ������ĳ��ȴ���1 ����������
            return false;
        }
        else if (cha == 1) // �������ɾ�� firts ��һ��
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
        { // �޸�
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
    //������ 01.06. �ַ���ѹ��
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
    // ������ 01.07. ��ת����
    void rotate(vector<vector<int>> &matrix)
    {
        // ���⿼���һ���������˳ʱ����ת��ʮ��

        // ͨ��������֪˳ʱ����ת��ʮ�ȿ��Կ����������·�ת��Ȼ��Խ��߷�ת

        // ���ȵõ����������
        int len = matrix.size();

        // ������������С��2��ֱ�ӷ���
        if (len < 2)
        {
            return;
        }

        // �Ծ������Ƚ������·�ת
        for (int i = 0; i < len / 2; i++)
        {
            swap(matrix[i], matrix[len - i - 1]);
        }

        // Ȼ��Ծ�����жԽ��߷�ת
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
    // ������ 01.08. �����
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
    // ������ 01.09. �ַ�����ת
    bool isFlipedString(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        string s = s1 + s1;
        // �������ת�ַ���  һ��Ϊ�Ӵ�

        return s.find(s2) != -1;
    }
};

int main()
{
    string s1, s2;
    Solution demo;
    return 0;
}