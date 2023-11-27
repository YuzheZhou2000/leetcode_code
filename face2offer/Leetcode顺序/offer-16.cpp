#include<bits/stdc++.h>

using namespace std;

// 本题目重点在于计算给定数字的整数次方 特别强调了不能使用库函数
class Solution {
public:
    double myPow(double x, int n) {
        // 使用分治的方法，将高次幂进行迭代

        if(n>=0)
            return quickPow( x, n);
        else
            return 1.0/quickPow( x, n);

    }
    double quickPow(double x,int n){
        if(n == 0){
            return 1;
        }

        double y = quickPow(x,n/2);
        if(n%2 == 0){
            return y*y;
        }else{
            return y*y*x;
        }


    }
};

int  main(){
    return 0;
}