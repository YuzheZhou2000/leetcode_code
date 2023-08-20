# include <bits/stdc++.h>

using namespace std;

/*
    首先题目给出的是一个自然数顺序排列的字符串，需要的是返回给定位数对应的数字
    本题目肯定需要分情况进行讨论
    1. 一位、两位、三位...



*/

class Solution {
public:
    int findNthDigit(int n) {
        // 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
        long base = 9,digits = 1;
        while (n - base * digits > 0){
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // 计算真实代表的数字是多少
        int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数的第n个数字
        if (idx == 0)idx = digits;
        long number = 1;
        for (int i = 1;i < digits;i++)
            number *= 10;
        number += (idx == digits)? n/digits - 1:n/digits;

        // 从真实的数字中找到我们想要的那个数字
        for (int i=idx;i<digits;i++) number /= 10;
        return number % 10;
    }
};




int main(){
    return 0;
}