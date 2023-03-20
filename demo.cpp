# include<bits/stdc++.h>

using namespace std;

class Solution_11_16 {
public:
    // func 1: over time
    bool isIdealPermutation(vector<int>& nums) {
        int len = nums.size();
        // first get the golbal Reverse order num
        int global = 0;
        
        for (int i = 0; i < len;i++){
            for (int j = i+1; j < len;j++){
                if(nums[j] < nums[i]){
                    global++;
                }
            }
        }
        // seconde record the local Reverse order num
        int local = 0;
        for (int i = 0; i < len - 1;i++){
            if(nums[i]>nums[i+1]){
                local++;
            }
        }
        return global == local;
    }

    // func 2: if there is val  is not local reserve turn false otherwise retun true
    bool isIdealPermutation2(vector<int>& nums) {
        int len = nums.size();
        if(len<3){
            return true;
        }
        // bulid a vector record the min value of the last n
        vector<int> min_vals(len - 2, INT_MAX);
        int min_val = nums[len - 1];
        for (int i = len - 3; i >= 0;i--){
            // min_val = min_val < nums[i] ? min_val : nums[i];
            // min_vals[i] = min_val;
            if(nums[i]>min_val){
                return false;
            }else{
                min_val = min_val < nums[i+1] ? min_val : nums[i+1];
            }
        }
        return true;
    }
};

class Solution_11_17 {
public:
    // direct search over the time... fuck
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        int num = words.size();
        int leng = s.size();
        for (int i = 0; i < num;i++){
            string tem_str = words[i];
            if(tem_str.size()>leng){
                continue;
            }
            int j = 0;
            int k = 0;
            while(k < tem_str.size() && j<leng){
                if(tem_str[k]!=s[j]){
                    j++;
                }else{
                    k++;
                    j++;
                }
            }
            if(k==tem_str.size()){
                res++;
            }
            
        }
        return res;
    }
    /*
    在朴素方法的匹配的过程中，对于每一个需要匹配的字符 t[j]t[j]t[j]，
    我们都需要将字符串 sss 中的指针 iii 在当前位置不断往后移动直至找到字符 
    s[i]s[i]s[i] 使得 s[i]=t[j]s[i] = t[j]s[i]=t[j]，或者移至结尾，
    我们现在考虑能否加速这个过程——如果我们将字符串 sss 中的全部的字符的位置按照对应的字符进行存储，
    令其为数组 pos\textit{pos}pos，其中 pos[c]\textit{pos}[c]pos[c] 
    存储的是字符串 sss 中字符为 ccc 的从小到大排列的位置。那么对于需要匹配的字符 t[j]t[j]t[j] 
    我们就可以通过在对应的 pos\textit{pos}pos 数组中进行「二分查找」来找到第一个大于当前 iii 指针的位置，
    若不存在则说明匹配不成功，否则就将指针 iii 直接移到找到的对应位置，并将指针 jjj 后移一个单位，
    这样就加速了指针 iii 的移动
    */
    
    int numMatchingSubseq_2(string s, vector<string>& words) {
        // 创建辅助数组，使用空间换时间
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size();i++){
            //s 中每个字符出现的位置写在pos数组中
            pos[s[i] - 'a'].push_back(i);
        }

        int res = words.size();

        for(auto &w : words){// 创建新的迭代器
            if(w.size() > s.size()){
                // 待匹配的字符串长于目标字符串 直接寄
                res--;
                continue;
            }
            int p = -1;
            for(char c :w){
                // 遍历当前带查询序列
                auto &ps = pos[c - 'a'];// ps 记录了当前字符在s中出现的位置
                // 注意新函数作用：  找到大于目标值的的第一个元素
                auto it = upper_bound(ps.begin(), ps.end(), p); // 二分查找的内置函数
                if(it == ps.end()){
                    // 没找到
                    res--;
                    break;
                }
                p = *it;
            }

        }
        return res;
    }
};

class Solution_11_18 {
public:
    static bool cmp (vector<int> a,vector<int> b){
        return a[1] > b[1];
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 基本思路，使用sort自定义比较函数


    }
};


class Solution_11_23 {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i = lowLimit;i<=highLimit;i++){
            // 循环遍历

            int tem = i;
            int num = 0;
            while(tem){
                num += tem % 10;
                tem = tem / 10;
            }
            count[num]++;            
            res = max(res, count[num]);
        }
        return res;
    }
};


int main(){
    // Solution s;
    // int len = 5;
    // vector<int> num_tmp(len,len-1);
    // cout << num_tmp.size()<<num_tmp[0];
    // int a = 10;
    string a = "zhouyzuhe";
    cout << a.size();

    return 0;
}