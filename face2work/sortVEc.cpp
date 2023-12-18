# include <bits/stdc++.h>
using namespace std;
/**
 * 使用快速排序解决本问题
*/
int mySort (vector<int> & vec, int star, int end){
    int flag = vec[star];
    while (star< end)
    {
        while(star< end && vec[end] >= flag){
            end--;
        }
        vec[star] = vec[end];
        while (star < end && vec[star] < flag)
        {
            /* code */
            star++;
        }
        vec[end] = vec[star];       
    }
    vec[star] = flag;
    

    return star;
}
void fastSort (vector<int> & vec, int star , int end){
    if (star >= end) return;
    int index = mySort(vec, star , end);
    fastSort(vec, star, index-1);
    fastSort(vec, index+1, end);  
}
vector<int> sortArray(vector<int>& nums) {
    fastSort(nums, 0 , nums.size()-1);
    return nums;
}
int main()
{
    vector<int> vec = {30, 21, 4, 33, 7, 9, 9, 1,2,3,4,5,6,222,1,2,3,120};
    cout << "source: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }

    cout << endl;
    vector <int> ans = sortArray(vec);

    cout << "sort: ";
    for (auto &i : ans)
    {
        cout << i << "  ";
    }
    return 0;
}