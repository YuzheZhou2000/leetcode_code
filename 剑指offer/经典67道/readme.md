## 面试题 4： 二维数组中的查找

> 本题目要求从给定的二位数组中找到对应的元素，因为给定的二维数组每一行和每一列都是经过排序的，因此类比**搜索二叉树**的性质，从左下角或者右上角分别往留一个对角进行遍历即可。
- 法1：使用遍历的方法  
注意循环的条件，开始写的时候使用嵌套循环，是不对的，因为当内层循环结束的时候，外层循环进一个，内层循环会重新从起点开始，因此不能使用两个`for()`语句进行嵌套。正确的解决方法应该是将判断写成一个`while(xxx && xxx)`的形式。 这种的时间复杂度为$O(n+m)$
    ```cpp
    class Solution {
    public:
        /**
        * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
        *
        *
        * @param target int整型
        * @param array int整型vector<vector<>>
        * @return bool布尔型
        */
        bool Find(int target, vector<vector<int>>& array) {
            // write code here
            int row = array.size();
            if (row == 0) {
                return false;
            }
            int col = array[0].size();

            int i = row - 1;
            int j = 0;
            while (i >= 0 && j < col) {
                // 注意这里跳出循环的条件，我们从左下角开始遍历，到右上角结束
                if (array[i][j] == target) {
                    return true;
                } else if (array[i][j] > target) {
                    i--;
                } else {
                    j++;
                }
            }

            return false;
        }
    };
    ```
- 部分博主甚至提出了可以使用**二分查找**的方法来解决这个问题  
具体来说，对于每一行，使用二分查找，如果找不到，继续下一行，二分查找的时间复杂度为$O(log(n))$,因此在最坏的情况下的时间复杂度为$O(mlog(n))$,
    ```cpp
    class Solution {
        public:
            /**
            * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
            *
            *
            * @param target int整型
            * @param array int整型vector<vector<>>
            * @return bool布尔型
            */
            bool Find(int target, vector<vector<int>>& array) {
                int row = array.size();
                for (int i = 0; i < row; i++) {
                    bool tem = find_mid(target, array[i]);
                    if (tem == true) {
                        return true;
                    }
                }
                return false;
            }

            bool find_mid(int target, vector<int>& array) {
                // 二分查找怎么写  首先确定两个边界值
                int star = 0;
                int end = array.size() - 1;

                while (end >= star) {
                    /* code */
                    int mid = star + (end - star) / 2;
                    if (array[mid] == target) {
                        return true;
                    } else if (array[mid] > target) {
                        // 因为每一行是从左到右递增
                        end = mid - 1;
                    } else {
                        star = mid + 1;
                    }
                }
                return false;
            }
        };
    ```
## 面试题5：替换空格
> 对于本题目最直观的认识就是将一个字符串中的空格替换为`ascll`码中的`%20`,但是如果直接遍历字符串，进行替换，每次发现一个空格，都需要将后面所有的字符后移一个位置。因此需要探索一种新的更快速的解决方法。
- 如果将时间复杂度变为`O(n)`，那么将快速解决这个问题，首先遍历给定的字符串，统计空格出现的次数，每一个空格都需要被换成`%20`， 相比于原来的空格来说是增加了两个字符长度，因此在完成一遍遍历以后，我们就可以确定新的字符串的长度，然后从后向前进行复制即可。  
需要注意的是因为给的是一个`char *`类型的数据，因此可以直接使用下标索引进行访问每一个字符。
    ```cpp
    class Solution {
        public:
            void replaceSpace(char* str, int length) {
                int spaceCount = 0;
                for (int i = 0; i < length; i++) {
                    if (str[i] == ' ') {
                        spaceCount++;
                    }
                }
                // 在统计完成空格的个数以后，可以进行字符串的延长
                int newLength = length + spaceCount * 2;
                int i = length;
                int j = newLength;
                while (j >= 0) {
                    if (str[i] != ' ') {
                        str[j--] = str[i--];
                    } else {
                        i--;
                        // 首先需要对新的数组进行
                        str[j--] = '0';
                        str[j--] = '2';
                        str[j--] = '%';
                    }
                }
            }
        };
    ```
    ## 面试题6: 从尾到头打印链表
    > 要求是在不改变链表状态的情况下从尾到头打印链表
    - 首先我们能够想到的就是直接遍历一遍链表，将链表中的结果顺序存储在`vector`容器中，当完成一遍顺序遍历以后，就可以得到一个*从头到尾*的结果，然后再将`vector`进行逆序即可。这样做有点取巧的嫌疑。PS：逆序操作`reverse(res.begin(), res.end());`时间复杂度为`O(n)`，因此整体的时间复杂度也是`O(n)`。另外剑指offer中推荐使用stack栈结构解决本问题，其实站在高度上来看，使用栈结构的先进先出的特征，和使用vector首先存下来element以后反序输出，是一样的
        ```cpp
        class Solution {
            public:
                vector<int> printListFromTailToHead(ListNode* head) {
                    // 首先想到的就是直接顺序读取一遍链表，存储到数组中，然后将数组逆序即可。
                    vector<int> res;
                    ListNode* pHead = head;
                    while (pHead != nullptr) {
                        /* code */
                        res.push_back(pHead->val);
                        pHead = pHead->next;
                    }
                    reverse(res.begin(), res.end());
                    return res;
                }
            };
        ```
    - 法2：因为考虑到使用`reverse`可能会被认为是使用了库函数而导致的取巧，因此我们使用一种递归的方法解决本问题，具体来说，就是递归访问链表，这里需要注意的是递归的判断语句。
    ```cpp
    class Solution {
        public:
            vector<int> printListFromTailToHead(ListNode* head) {
                // 如果使用递归的解法解决这个问题
                vector<int> ans;

                getValofList(ans, head);

                return ans;
            }
            void getValofList(vector<int>& ans, ListNode* node) {
                if (node != nullptr) {
                    // 必须深度理解这个递归的写法
                    if (node->next != nullptr) {
                        getValofList(ans, node->next);
                    }
                    ans.push_back(node->val);
                }
            }
        };
    ```


- 解决git上传失败
    ```python
    git config --global --unset http.proxy 
    git config --global --unset https.proxy
    ```
