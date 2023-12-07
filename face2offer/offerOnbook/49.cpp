#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        // 如果我使用一个set来记录呢
        unordered_set<int> mySet;
        bool ans = true;
        int index = 0;
        for (int i = 0; i < length; i++)
        {
            if (mySet.find(numbers[i]) != mySet.end())
            {
                mySet.emplace(numbers[i]);
            }
            else
            {
                duplication[0] = numbers[i];
                ans = false;
                return ans;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}