# include<bits/stdc++.h>
using namespace std;
/*

646. �������

����?n?�����ԡ�?��ÿһ�������У���һ���������Ǳȵڶ�������С��

���ڣ����Ƕ���һ�ָ����ϵ�����ҽ���?b < c?ʱ������(c, d)?�ſ��Ը���?(a, b)?���档������������ʽ������һ����������

����һ�����Լ��ϣ��ҳ��ܹ��γɵ���������ĳ��ȡ��㲻��Ҫ�õ����е����ԣ���������κ�˳��ѡ�����е�һЩ���������졣


*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // ����  �Զ�������ʽ��������Խ������� 
        // ����ʽ�����յڶ���Ԫ�ش�С�����������
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int cur = INT_MIN;
        
        // ���Ա�ʾ���Ľ��
        int res = 0;

        for (int i = 0; i < pairs.size();i++){
            // ���Ѿ����������������б���
            if(pairs[i][0]>cur){
                // ע����ж�������ѡ��  ��λ�ں�������Ե�һ������Ҫ����ǰһ�����Եĵڶ�������
                res++;
                cur = pairs[i][1];
            }
        }
        return res;
    }
};
int main(){

    return 0;
}