#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<int> sta;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(')
        {
            sta.emplace(0);
        }
        else if (s[i] == ')')
        {
            if (sta.empty())
                return false;
            if (sta.top() == 0)
            {
                sta.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '[')
        {
            sta.emplace(1);
        }
        else if (s[i] == ']')
        {
            if (sta.empty())
                return false;
            if (sta.top() == 1)
            {
                sta.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '{')
        {
            sta.emplace(2);
        }
        else if (s[i] == '}')
        {
            if (sta.empty())
                return false;
            if (sta.top() == 2)
            {
                sta.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            continue;
        }
    }
    return sta.empty();
}
int main()
{
    string s = "([)]";
    bool ans = isValid(s);
    cout << "ans: " << ans;
}