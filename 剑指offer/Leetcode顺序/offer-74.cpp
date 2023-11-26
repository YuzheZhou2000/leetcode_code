#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 本题要求对重叠区间进行合并
        vector<vector<int>> ans;

        // 首先 对区间进行排序 按照右区间升序排列 自定义一个排序函数
        sort(intervals.begin(), intervals.end(), compare);
        sort(intervals.begin(), intervals.end(), comp);
        

        int size = intervals.size();
        int star = intervals[0][0];
        int end = intervals[0][1];
        for(int i =1;i<size;i++){
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (left <= end){
                // 后一个区间的左边界小于等于前一个的右边界
                end = max(right,end);
            }else{
                // 两个区间直接没有重叠
                vector<int> tem = {star,end};
                ans.push_back(tem);
                star = left;
                end = right;
            }
        }
        vector<int> tem = {star,end};
        ans.push_back(tem);


        return ans;
    }

    /*
    在C++中，类成员函数不能直接作为std::sort的比较函数。
    您可以将compare函数声明为static成员函数或定义为类的外部函数
    */
    // // 自定义比较函数，按区间的第二个元素进行升序排序
    static bool compare(const vector<int> interval1, const vector<int> interval2)
    {
        // 比较函数 自定义时候必须是静态的
        return interval1[1] < interval2[1];
    }
    static bool comp(const vector<int> interval1, const vector<int> interval2)
    {
        // 比较函数 自定义时候必须是静态的
        return interval1[0] < interval2[0];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> vec = {{1, 4}, {2, 3}};


    
    auto res = s.merge(vec);


    for (auto interval : res)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    int a = max(109,2);
    cout<<a<<endl;
    

    return 0;
}
