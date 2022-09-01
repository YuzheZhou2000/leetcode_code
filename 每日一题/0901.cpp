#include <bits.stdc++>

using namespace std;
/*
给你一个数组?prices?，其中?prices[i]?是商店里第?i?件商品的价格。

商店里正在进行促销活动，如果你要买第?i?件商品，那么你可以得到与 prices[j] 相等的折扣，
其中?j?是满足?j > i?且?prices[j] <= prices[i]?的?最小下标?，如果没有满足条件的?j?，
你将没有任何折扣。

请你返回一个数组，数组中第?i?个元素是折扣后你购买商品 i?最终需要支付的价格。

*/
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        // 获取数组的长度
        int length = prices.size();

        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j <= length; j++)
            {
                if (prices[j] < prices[i])
                {
                    // 找到了最低折扣，直接计算最终价格后跳出循环
                    prices[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return prices;
    }
    // 强化  使用单调栈解决问题 降低时间复杂度

    vector<int> finalPrices(vector<int> &prices)
    {
        // 获得数组长度
        int n = prices.size();
        // 创建一个新的数组
        vector<int> ans(n);
        // 创建单调栈
        stack<int> st;
        // 倒序遍历原数组
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                // 如果栈顶元素大于当前元素  直接弹出
                st.pop();
            }
            // 如果单调栈中存在数据  直接使用原价减去栈顶的元素 否则使用原价
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            // 压栈
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
