#include <bits/stdc++.h>
using namespace std;

/**
 * 复杂链表的复制
 */
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        // 因为存在一个随机指针指向一个随机位置

        // 使用哈西边记录前后两个链表的对应关系
        unordered_map<RandomListNode *, RandomListNode *> myMap;
        RandomListNode *PseudoHead = new RandomListNode(-1);
        if (pHead == nullptr)
        {
            return nullptr;
        }
        RandomListNode *sourcehead = pHead;
        RandomListNode *copyNode = new RandomListNode(pHead->label);
        PseudoHead->next = copyNode;
        myMap.emplace(pHead, copyNode);
        pHead = pHead->next;
        while (pHead != nullptr)
        {
            RandomListNode *tem = new RandomListNode(pHead->label);
            copyNode->next = tem;
            myMap.emplace(pHead, tem);
            copyNode = copyNode->next;
            pHead = pHead->next;
        }
        // 链接随机指针
        RandomListNode *copyTem = PseudoHead->next;
        while (sourcehead != nullptr)
        {
            /* code */
            if (sourcehead->random != nullptr)
            {
                copyTem->random = myMap[sourcehead->random];
            }
            sourcehead = sourcehead->next;
            copyTem = copyTem->next;
        }

        return PseudoHead->next;
    }
};
int main()
{
    return 0;
}