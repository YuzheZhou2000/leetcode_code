#include <bits.stdc++>

using namespace std;
/*
����һ������?prices?������?prices[i]?���̵����?i?����Ʒ�ļ۸�

�̵������ڽ��д�����������Ҫ���?i?����Ʒ����ô����Եõ��� prices[j] ��ȵ��ۿۣ�
����?j?������?j > i?��?prices[j] <= prices[i]?��?��С�±�?�����û������������?j?��
�㽫û���κ��ۿۡ�

���㷵��һ�����飬�����е�?i?��Ԫ�����ۿۺ��㹺����Ʒ i?������Ҫ֧���ļ۸�

*/
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        // ��ȡ����ĳ���
        int length = prices.size();

        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j <= length; j++)
            {
                if (prices[j] < prices[i])
                {
                    // �ҵ�������ۿۣ�ֱ�Ӽ������ռ۸������ѭ��
                    prices[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return prices;
    }
    // ǿ��  ʹ�õ���ջ������� ����ʱ�临�Ӷ�

    vector<int> finalPrices(vector<int> &prices)
    {
        // ������鳤��
        int n = prices.size();
        // ����һ���µ�����
        vector<int> ans(n);
        // ��������ջ
        stack<int> st;
        // �������ԭ����
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                // ���ջ��Ԫ�ش��ڵ�ǰԪ��  ֱ�ӵ���
                st.pop();
            }
            // �������ջ�д�������  ֱ��ʹ��ԭ�ۼ�ȥջ����Ԫ�� ����ʹ��ԭ��
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            // ѹջ
            st.emplace(prices[i]);
        }
        return ans;
    }
};

int main()
{

    int a[5] = {8, 4, 6, 2, 3};
    vector<int> push(a, a + 5);

    return 0;
}
