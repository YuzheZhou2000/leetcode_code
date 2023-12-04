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
## 面试题 5：替换空格
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
    ## 面试题 6: 从尾到头打印链表
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
## 面试题 7：重建二叉树
> 本题目为经典的二叉树问题，给定前序和中序遍历的数组，要求得到一个重建以后的原始二叉树
- 首先需要理解前序遍历和中序遍历的概念，对于前\中\后序遍历而言，这都是一种深度遍历的策略，不同的遍历方式是指对于中间根节点而言，访问的顺序是怎样的。  
因此在给定前序遍历和中序遍历以后，我们可以知道的是前序遍历的**第一个元素就是当前子树的根节点**， 然后根据这个根节点在中序遍历得到的数组中定位到本节点，那么这个节点向前一段就是左子树，向后一段就是右子树。由此可以得到一个两个子树中的节点唉两个遍历数组中的距离的区间位置，然后通过递归迭代进行重建即可。需要注意的是在递归遍历的过程中，两个不同的边界位置的确定。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param preOrder int整型vector
         * @param vinOrder int整型vector
         * @return TreeNode类
         */
        TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
            // write code here
            // 二叉树的重建  首先可以使用递归的方法解决
            int lenght = preOrder.size();
            if (lenght == 0) {
                return nullptr;
            }
            return bulidTree(preOrder, vinOrder, 0, lenght - 1, 0, lenght - 1);
        }

        // 通过递归得到二叉树
        TreeNode* bulidTree(vector<int>& preOrder, vector<int>& vinOrder, int star_per,
                            int end_per, int star_vin, int end_vin) {
            if (end_vin >= star_vin) {
                // 根节点肯定是前序遍历的第一个元素
                TreeNode* root = new TreeNode(preOrder[star_per]);

                // 下一步开始寻找根节点在中序遍历中的index
                int index = star_vin;
                for (; index < end_vin; index++) {
                    if (vinOrder[index] == preOrder[star_per]) {
                        break;
                    }
                }
                // 这时候得到了根节点在中序遍历中的index
                int len_left = index - star_vin;
                root->left = bulidTree(preOrder, vinOrder, star_per + 1, star_per + len_left,
                                    star_vin, index - 1);
                root->right = bulidTree(preOrder, vinOrder, star_per + len_left + 1, end_per,
                                        index + 1, end_vin);
                return root;
            }
            return nullptr;
        }
    };
    ```

- 法二： 在原有算法的基础上，因为上面代码我们在中序遍历的过程中，根节点是通过顺序遍历判断是否相同得到的，因此使用`hash`对原来的中序遍历序列进行索引的记录，在检索的过程中直接实现即可。
    ```cpp
    class Solution {
    public:
        TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
            // write code here
            // 二叉树的重建  首先可以使用递归的方法解决
            int lenght = preOrder.size();
            if (lenght == 0) {
                return nullptr;
            }
            // 引入hash进行加速，可以记录在中序遍历中 出现的位置
            unordered_map<int, int> indexMap;
            for (int i = 0; i < lenght; i++) {
                indexMap.emplace(vinOrder[i], i);
            }

            return bulidTree(indexMap, preOrder, vinOrder, 0, lenght - 1, 0, lenght - 1);
        }

        // 通过递归得到二叉树
        TreeNode* bulidTree(unordered_map<int, int>& indexMap, vector<int>& preOrder,
                            vector<int>& vinOrder, int star_per, int end_per, int star_vin, int end_vin) {
            if (end_vin >= star_vin) {
                // 根节点肯定是前序遍历的第一个元素
                TreeNode* root = new TreeNode(preOrder[star_per]);

                // 下一步开始寻找根节点在中序遍历中的index
                int index = indexMap[preOrder[star_per]];

                // 这时候得到了根节点在中序遍历中的index
                int len_left = index - star_vin;
                root->left = bulidTree(indexMap, preOrder, vinOrder, star_per + 1,
                                    star_per + len_left, star_vin, index - 1);
                root->right = bulidTree(indexMap, preOrder, vinOrder, star_per + len_left + 1,
                                        end_per, index + 1, end_vin);
                return root;
            }
            return nullptr;
        }
    };
    ```

## 面试题 9: 使用两个栈结构实现队列
> 本题目解决问题的关键在于理解队列的先进先出和栈的先进后出
- 因为栈和队列的最大的不同就在于`pop`的时候，一个是首先弹出最先进来的，一个是最后弹出最后进来的。  
因此只需要在pop或者push中的一个函数的操作中使用辅助结构进行处理即可。在这里我们使用第二个栈结构作为`pop`操作时的辅助容器。如果需要弹出元素，首先对元素逆序操作。从1转移到2中，然后再弹出。当然如果直接进行过转移操作，就不需要再次进行转移。
另外需要注意的时牛客网中的`O(1)`是伪命题

    ```cpp
    class Solution {
    public:
        void push(int node) {
            stack1.push(node);
        }

        int pop() {
            int res;
            //
            if (stack2.empty()) {
                // 如果第二个栈结构是空的，那么需要将第一个栈中的元素迁移到第二个栈中
                while (!stack1.empty()) {
                    /* code */
                    int tem = stack1.top();
                    stack2.push(tem);
                    stack1.pop();
                }
            }
            res = stack2.top();
            stack2.pop();
            return res;
        }

    private:
        stack<int> stack1;
        stack<int> stack2;
    };
    ```

## 面试题 11: 旋转数组的最小数字
> 首先在题目中给出了旋转数组的定义, 对于一个非递减数组，以一个点为中心将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组。因为涉及到**已经排序**，因此符合二分查找的定义，因此使用二分查找
- 在本题目中，难点在于如何更新左右两个边界的值，因为是一个非递减数组，也就是说在数组中可能存在相同的元素，因此在使用`while( )`进行判断的时候这里使用的判断条件是`right > left + 1`，也就是说，当left和right相邻的时候，直接给他返回，最后使用min选择使用哪一个。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param nums int整型vector
         * @return int整型
         */
        int minNumberInRotateArray(vector<int>& nums) {
            // write code here
            /**
             * 首先本题目作为一个二分查找的题目，由于说明了在旋转前是一个'非降序'数组
             * 那么就是说存在相同的情况
             *
             */
            int left = 0, right = nums.size() - 1;
            if (right == 0) {
                return 0;
            }
            while (left + 1 < right) {
                // 使用二分查找， 断开的条件为left和right是相邻的两个
                // 这时候只需要返回两个中的最小值就可以了
                // 但是需要注意的是left和right都不可以越界

                // 二分查找标配吗，计算中间点的索引
                int mid = left + (right - left) / 2;

                // 针对旋转数组的判断，需要定位到最小的元素
                if (nums[mid] < nums[right]) {
                    // 中间mid的索引落在了旋转以后的这个子序列上
                    right = mid;
                } else if (nums[mid] == nums[right]) {
                    // 中间的位置和子区间右边的节点
                    right--;
                } else {
                    left = mid + 1;
                }
            }

            return min(nums[left], nums[right]);
        }
    };

    ```
## 面试题 10: 斐波那契数列
> 尽管本题目为经典的递归例子，但是当`n`的取值很大时，由于存在很多重复计算，会导致计算超级超级超级超级慢，因此不能单纯的使用递归的方法解决本问题。具体来说，可以通过保留中间状态，用**自底向上**的方法解决。
- 递归的方法解决：直接递归可以很方便的理解，但是会导致时间复杂度超级超级高。很不推荐使用，**估计面试的时候写出来这个直接掉分把**
    ```cpp
    int Fibonacci(int n) {
        // write code here
        // 如果直接使用递归的解法，效果会超级超级慢，因为涉及到了很多无效的计算
        if (n <= 2) {
            return 1;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    ```
- 自底向上的方法，通过不断迭代替换前面两个变量的值，得到最后的结果。这么做的时间复杂度为$O(n)$。因为是一个`for()`的循环
    ```cpp

    int Fibonacci(int n) {
        if (n <= 2) {
            return 1;
        }
        long long val_2 = 1;
        long long val_1 = 1;
        long long ans = 2;
        for (int i = 2; i < n; i++) {
            ans = val_1 + val_2;
            val_2 = val_1;
            val_1 = ans;
        }
        return ans;
    }

    ```
- 时间复杂度为$O(log(n))$的解法
    - 根据矩阵的理论，转化为二维矩阵的幂运算，剑指offer说尽管时间复杂度小，但是不适合面试，就不写过程啦

### 补充：跳台阶
> 本题目和上一个斐波那契数列问题的思路完全一致，只需要控制好变量即可
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param number int整型
         * @return int整型
         */
        int jumpFloor(int number) {
            // write code here
            // 根据斐波那契数列的经验，我们知道直接使用递归会超级耗时
            // 因此采用使用中间变量记录的方法
            if (number <= 2) {
                return number;
            }

            // 通过观察可以发现规律，每一次都是上一层(再跳一个)+上上层(再跳两个)
            int val_2 = 1;
            int val_1 = 2;
            int ans;

            for (int i = 2; i < number; i++) {
                ans = val_2 + val_1;
                // 更新状态
                val_2 = val_1;
                val_1 = ans;
            }

            return ans;
        }
    };
    ```

#### 补充 的 补充
> 在前面一道题的基础上 继续增加难度，变成可以任意眺台阶，这时候其实根据规律可以发现是求等比数列的第n项，因此直接套用公式即可。
- 在这里需要注意的一点是，牛客网要求给出时间复杂度为$O(1)$的解法，这里对于2求幂的运算，可以使用位运算`>>`来解决。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param number int整型
         * @return int整型
         */
        int jumpFloorII(int number) {
            // write code here
            return 0x01 << (number - 1);
        }
    };
    ```
---

## 面试题：矩阵覆盖问题
> 本题目其实还是**斐波那契数列**问题，至于为什么是，只能说是通过找规律得到的。
- 还是通过增加3个变量的方式进行**这种解法其实是动态规划的思路**
    ```cpp
    class Solution {
    public:
        int rectCover(int number) {
            // 因为需要2* n的矩阵，因此矩阵的宽一直都是2  只是在长的维度上进行了改变
            if (number <= 2) {
                return number;
            }
            // 这里其实还是一个斐波那契数列问题
            int val_1 = 2;
            int val_2 = 1;
            int ans;

            for (int i = 2; i < number; i++) {
                ans = val_2 + val_1;
                val_2 = val_1;
                val_1 = ans;
            }
            return ans;

        }
    };
    ```
## 面试题 15: 二进制中1的个数
> 本题目中是给定一个十进制的数字，需要求出给定数字的二进制形式中有多少个"1"
- 看到二进制，首先需要想到的就是**位运算**，在本题目中，可以通过遍历给定数字的二进制形式中的每一个数位是0/1进行求得结果。  
但是本题目需要注意的有以下几点：
    - 如果给出的是一个**负数**，因为题目中给出了是使用补码的形式给出，那么第一个位置上会是1，在向右移位的过程中会一直补1
    - 这个题目中的一个技巧就是，当一个二进制数字，和它本身减1以后的数字按位取与以后，得到的就正好是删除了最靠近右侧的一个1以后的结果。因此我们可以根据这个特点来完成。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param n int整型
         * @return int整型
         */
        int NumberOf1(int n) {
            // write code here
            // 题目的整体思路就是根据给定数字的二进制形式
            // 进行循环遍历
            int ans = 0;
            while (n) {
                ans++;
                n = (n - 1) & n;
            }
            return ans;
        }
    };
    ```    

## 面试题 16：数值的整数次方
> 题目中仅仅说出了数值整数次方，因此我们需要考虑到的坑包括第一个**数值** ，这可能有正数、负数和0，都需要综合考虑。另外在指数位置上的整数次方，也可能是正数、负数和0.这些都是我们需要分情况进行讨论，并且在代码涉及到的point。
- 首先对于不使用库函数进行次方的计算，想到的第一个解决方法就是不断循环。但是考虑到指数计算的特点，我们可以通过两个相同的指数乘起来直接变成
**2倍**来解决。
- 另外对于计算来说，由于在本题目中涉及到了`double`类型的数据，那么在判断相等的时候，如果直接使用`==`可能会出现错误，因为`double`类型在小数点位置上是粗糙的，因此我们使用了相减后通过阈值判断是不是取$0$。
    ```cpp
    class Solution {
    public:
        double Power(double base, int exponent) {
            // 在本题目中，需要知道底数base是一个doubel类型的数据，因此
            // 需要讨论base的情况
            if (fabs(base - 0.0) < 1e-6) {
                // 如果底数是0，那么我们直接返回
                return 0.0;
            }
            if (exponent == 0) {
                return 1.0;
            }
            bool sign = false;
            if (exponent < 0) {
                sign = true;
            }
            exponent = abs(exponent);
            // 开始正式计算逻辑 -- 递归
            double ans = myPower(base, exponent);
            if (sign) {
                ans = 1 / ans;
            }
            return ans;
        }
        double myPower(double base, int exponent) {
            // 首先使用位运算判断
            if (exponent == 1) {
                return base;
            }
            while (exponent) {
                if ((exponent & 0x01) == 0x01) {
                    // 是一个记述

                    return base * myPower(base, exponent >> 1) * myPower(base, exponent >> 1);
                } else {
                    return myPower(base, exponent >> 1) * myPower(base, exponent >> 1);
                }
            }
            return 0.0;
        }
    };

    ```
## 面试题：数组位置奇偶调整
> 在本题目中，涉及到一个数组位置的调整，需要足以题目中的要求，奇数和偶数的相对位置不能够发生改变。
- 如果使用双指针的算法，可以看作是一种选择排序的变体，所以这是一种**不稳定**的排序算法。会和题目的要求发生冲突，因此不能使用
- 退一步，我们可以使用基于**冒泡排序**的思想，如果发现了需要调整的，就通过冒泡传递，这样保证了数据前后顺序的稳定性。
    ```cpp
    class Solution {
    public:
        void reOrderArray(vector<int>& array) {
            int len = array.size();
            if (len == 0) {
                return;
            }

            // 类比冒泡排序，从后向前冒泡
            for (int i = 0; i < len; i++) {
                // 如果是一个奇数 那么就开始冒泡
                if (array[i] & 0x01) {
                    for (int j = i; j > 0; j--) {
                        if ((array[j - 1] & 0x01) == 0) {
                            swap(array[j - 1], array[j]);
                        } else {
                            break;
                        }
                    }
                }
            }
            return;

        }
    };
    ```
## 面试题: 链表中倒数第k个结点
> 本题目为经典的链表类型题目，首先需要知道由于链表和线性结构的不同，每一个节点的内存都是互相没有相邻的，因此需要通过指针联系在一起
- 由于题目的要求是寻找**倒数**第k个节点，因此首先想到的方法就是先通过一次遍历的到这个链表中所有元素的个数，然后反推倒数第k个是正数第 *?* 个。 但是这样会多遍历一次，可以采用的做法是**双指针**首先让快指针前进k个单位，然后两个指针同时移动，当快指针走到结尾的时候，慢指针真好指在目标接待你
    - 但是这个问题也是有坑的，就是快指针在向前走的时候，需要知道是不是走到最后了，就是题目给的测试用例可能存在k很大，但是实际上链表长度并不长的情况。
    ```cpp
    class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

            /***
             *
             * 因为是倒数第K个节点，因此我们如果首先遍历一遍，
             * 得到总长度然后基于总长度，进行计算。这样的时间复杂度可能会高一些
             * 因此我们采用双指针的方法进行。
             *
             */

            if (pListHead == nullptr) {
                return nullptr;
            }

            // 要求倒数第k个节点，我们首先让快指针向后移动k个节点
            ListNode* pFast = pListHead;
            ListNode* pSlow = pListHead;
            for (int i = 0; i < k; i++) {
                pFast = pFast->next;
                if (pFast == nullptr && i + 1 < k) {
                    return nullptr;
                }
            }
            while (pFast != nullptr) {

                pFast = pFast->next;
                pSlow = pSlow->next;

            }
            return pSlow;
        }
    };
    ```
## 面试题 24: 反转链表
> 本题目考察了基础的链表操作，反转链表需要保证的是指针不能是野指针，使用三个指针记录
- 注意的是原来的头结点需要把next置为null 否则循环引用
    ```cpp
    /**
     * struct ListNode {
     *  int val;
     *  struct ListNode *next;
     *  ListNode(int x) : val(x), next(nullptr) {}
     * };
     */
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param head ListNode类
         * @return ListNode类
         */
        ListNode* ReverseList(ListNode* head) {
            // write code here
            if (head == nullptr) {
                return head;
            }
            ListNode* p_next = head;
            ListNode* p_cur = nullptr;
            ListNode* p_tem = head;
            while (p_next != nullptr) {
                p_tem = p_next->next;
                p_next->next = p_cur;
                p_cur = p_next;
                p_next = p_tem;
            }
            return p_cur;
        }
    };

    ```
## 面试题 25： 合并两个有序的链表
> 本题目为经典的链表操作类型题目，首先需要明确的是操作的**空间复杂度**，因为需要的时间复杂度为$O(1)$,所以需要原地操作
- 一个可以考虑的点在于使用伪头节点，可以简化链表中的操作，每一次比较之后选择使用哪一个链表中的第一个元素插入到新得到的链表之中。另外最后判断是不是存在还有节点没有被比较的情况。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param pHead1 ListNode类 
         * @param pHead2 ListNode类 
         * @return ListNode类
         */
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
            // write code here
            // 因为空间复杂度要求为O（1），因此需要在原链表上直接进行操作
            ListNode * p_curr_1 = pHead1;
            ListNode * p_curr_2 = pHead2;
            if(pHead1 == nullptr)
                return pHead2;
            if (pHead2 == nullptr)
                return pHead1;

            ListNode * p_ans = new ListNode(0);
            ListNode * p_curr = p_ans;

            // 开始合并操作 是递增序列
            while(p_curr_1 != nullptr && p_curr_2 != nullptr){
                cout <<"1: "<<p_curr_1->val << "     2: "<<p_curr_2->val<<endl;
                if (p_curr_1->val < p_curr_2->val){
                    p_curr->next = p_curr_1;            
                    p_curr_1 = p_curr_1->next;
                }else{
                    p_curr->next = p_curr_2;
                    p_curr_2 = p_curr_2->next;
                }
                p_curr = p_curr->next;
            }
            if (p_curr_1 != nullptr){
                p_curr->next = p_curr_1;
            }
            if(p_curr_2 != nullptr){
                p_curr->next = p_curr_2;
            }
            return p_ans->next;
        }
    };
    ```
## 面试题 26： 树的子结构
> 本题考查的是树的子结构，想到两个树之间的匹配，首先应考虑使用递归解法
- 我们这里想到的算法是**迭代**遍历和**递归**匹配相结合的方法。首先利用队列递归层次遍历树结构，遍历每一个节点，对每一个节点都是和目标进行递归匹配。

    - TODO： 可以考虑在遍历原来大的二叉树的时候，也使用递归的方法，好像复杂度会低一些？
    ```cpp
    class Solution {
    public:
        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
            // 首先写一个遍历 对原来树结构中的每一个节点进行遍历
            // 如果通过迭代的方式写一个针对大的子树的遍历
            bool ans = false;
            if (pRoot1 == nullptr || pRoot2 == nullptr) {
                return ans;
            }
            queue<TreeNode*> qtree;
            qtree.emplace(pRoot1);
            while (!qtree.empty()) {
                // 如果子树不是空的
                int size = qtree.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* tem = qtree.front();
                    qtree.pop();
                    if (tem->left != nullptr)
                        qtree.emplace(tem->left);
                    if (tem->right != nullptr)
                        qtree.emplace(tem->right);

                    // 针对当前节点 进行匹配
                    // TODO
                    ans = machTree(tem, pRoot2);
                    if (ans == true) {
                        return ans;
                    }
                }
            }
            return ans;
        }
        bool machTree(TreeNode* p1, TreeNode* p2) {
            // 递归判断两个子树是不是相同的
            if (p1 != nullptr && p2 != nullptr) {
                if (p1->val == p2->val)
                    return machTree(p1->left, p2->left) && machTree(p1->right, p2->right);
                else
                    return false;
            } else if (p2 == nullptr) {
                return true;
            } else {
                return false;
            }
        }
    };

    ```
## 面试题 27： 二叉树的镜像
> 本题目需要对二叉树的左右子树进行一个翻转操作，其实也就是调换左/右两个子树的位置，为了实现真实的镜像，可以从顶向下以递归的方法进行。
- 牛客网说存在空间复杂度为$O(1)$的实现方法，其实也就是直接在原来的数据结构上进行修改，而不是用额外的辅助空间。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param pRoot TreeNode类
         * @return TreeNode类
         */
        TreeNode* Mirror(TreeNode* pRoot) {
            // write code here
            // 本科找实习的面试的第一轮的第一道面试题目
            // 使用递归的方法进行，可以简单快速的完成本工作
            if (pRoot == nullptr) {
                return nullptr;
            }
            TreeNode* temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
            pRoot->left = Mirror(pRoot->left);
            pRoot->right = Mirror(pRoot->right);
            return pRoot;
        }
    };
    ```
## 面试题 29: 顺时针打印矩阵
> 本题目的重点在于循环的判断
- 需要注意的是，我们的算法是将顺时针打印看成是**四个边界线**的分别输出。但是可能存在的一个大问题就是如果矩阵不是一个标准的正方形。那么可能在最后一个循环打印后，只留下了一行或者一列数据，这时候比如添加判断语句。否则是不可以的哦~

    ```cpp
    #include <iostream>
    class Solution {
    public:
        vector<int> printMatrix(vector<vector<int> > matrix) {
            vector<int> ans;
            // 通过维护左上角和右下角的下标来实现顺时针遍历
            int star_x = 0, star_y = 0;
            int end_x = matrix.size() - 1;
            if (end_x == -1) {
                return ans;
            }
            int end_y = matrix[0].size() - 1;
            while (star_x <= end_y && star_y <= end_y) {       
                // 分四个方向打印一圈   
                int i = star_x;
                int j = star_y;

                if (i<= end_x){
                // 1. 左到右
                while (j <= end_y) {
                    //cout << "a: " << matrix[i][j] << endl;
                    ans.push_back(matrix[i][j++]);
                }
                }
                // 2. 上到下
                i = star_x + 1;
                j = end_y;         
                while (i < end_x) {
                    //cout << "b: " << matrix[i][j] << endl;
                    ans.push_back(matrix[i++][j]);
                }
                // 3. 右到左
                if (end_x  > star_x) {
                    i = end_x;
                    j = end_y;  
                    while (j >= star_y) {
                    // cout << "c: " << matrix[i][j] << endl;
                        ans.push_back(matrix[i][j--]);
                    }
                }
                // 4. 下到上
                if (star_y < end_y) {
                    i = end_x - 1;
                    j = star_y;
                    while (i > star_x) {
                        // cout << "d: " << matrix[i][j] << endl;
                        ans.push_back(matrix[i--][j]);
                    }
                }
                star_x++;
                star_y++;
                end_x--;
                end_y--;
            }
            return ans;
        }
    };
    ```
## 面试题 30 ： 包含min函数的栈
> 本题目的要求是实现一个能够得到栈中所含最小元素的 min 函数 ，属于是在原来已有的`stack`库函数功能的基础上添加附加功能。
- 我们的策略是使用一个辅助的栈结构，在每一次`push`的时候，新的辅助栈结构保存对应的最小的元素，因此可以理解为辅助栈其实是真实`value`的另一个最小表示。通过表示最小的`value`实现min函数功能。
    ```cpp
    class Solution {
    public:
        stack<int> sta;
        stack<int> minSta;
        void push(int value) {
            sta.push(value);
            // 通过辅助栈 维护辅助栈对应的元素正好是当前元素以及之前所有元素中最小的元素。
            if (minSta.empty()) {
                minSta.push(value);
            } else {
                int ans = minSta.top() < value ? minSta.top() : value;
                minSta.push(ans);
            }
        }
        void pop() {
            minSta.pop();
            sta.pop();
        }
        int top() {
            int ans = sta.top();
            return ans;
        }
        int min() {
            int ans = minSta.top();
            return ans;
        }
    };
    ```
- 学到了一种很 ***骚*** 的操作，就是使用一个栈结构，但是每次压入最小值和真实值两个元素，其实就是两个栈合二为一。没有什么创新点，只是想法值得借鉴学习。算是打开新思路吧。

## 面试题 32：从上往下打印二叉树
> 从上到下打印二叉树，就是一种层序遍历的过程，二叉树的层序遍历，使用**队列**数据结构完成。
- 使用队列，完成每一层的遍历
    ```cpp
    /*
    struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) :
                val(x), left(NULL), right(NULL) {
        }
    };*/
    class Solution {
    public:
        vector<int> PrintFromTopToBottom(TreeNode* root) {
            // 从上到下打印二叉树 其实就是层次遍历
            queue<TreeNode*> que;
            vector<int> ans;

            if (root == nullptr) {
                return ans;
            }
            que.emplace(root);

            while (!que.empty()) {
                /* code */
                int size = que.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* temp = que.front();
                    if (temp->left != nullptr) {
                        que.emplace(temp->left);
                    }
                    if (temp->right != nullptr) {
                        que.emplace(temp->right);
                    }
                    que.pop();
                    ans.push_back(temp->val);
                }
            }
            return ans;
        }
    };
    ```

## 面试题 33：二叉搜索树的后序遍历
> 本题目要求判断给定的序列是不是二叉搜索树的后序遍历数组
- 首先需要知道什么是**后序遍历**，也就是二叉树根据**左子树->右子树->根节点** 的顺序进行遍历，那么根据二叉搜索树序列的定义，我们可以知道如果满足，应该是(左)(右)(根),以此为依据进行递归判断即可。
    ```cpp
    class Solution {
    public:
        bool VerifySquenceOfBST(vector<int> sequence) {
            // 能想到的结果就是判断左右两侧是不是都是
            // 因为根节点肯定是在最后一个位置上的
            if (sequence.size() == 0) {
                return false;
            }
            return myjudgeBST(sequence, 0, sequence.size() - 1);
        }
        bool myjudgeBST(vector<int> seq, int star, int end) {
            int i = star;
            for (; i < end; i++) {
                if (seq[i] > seq[end]) {
                    break;
                }
            }
            // 此时i位置为大于end的位置
            int j = i;
            for (; j < end; j++) {
                if (seq[j] < seq[end]) {
                    return false;
                }
            }
            // 讲道理此时j应该已经走到了end的位置

            // 下面递归开始判断左右子树是不是后序遍历

            bool left = true, right = true;
            if (i > star) {
                left = myjudgeBST(seq, star, i - 1);
            }
            if (i < end) {
                right = myjudgeBST(seq, i, end - 1);
            }
            return (left && right);
        }
    };
    ```
## 面试题 34: 二叉树中和为某一值的路径
> 再判断路径问题中，首先可以想到这是一个递归问题，需要遍历每一个节点，并保存root->叶子节点每一条路径上的和，根据这个和判断是不是目标所求
- 因此我们第一反应想到的方法就是使用 **前序遍历** 的方法，并使用一个额外数组保存路径上的所有元素的值和和。但是没有考虑到删除一个元素，因为我们的参数中写的是一个`vector<int> vec`,而不是一个`vector<int>& vec`，这说明是一个 **浅拷贝** ,因此需要考虑不满足以后的弹出。
    ```cpp
    class Solution
    {
    public:
        /**
        * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
        *
        *
        * @param root TreeNode类
        * @param target int整型
        * @return int整型vector<vector<>>
        */
        vector<vector<int>> ans;
        vector<vector<int>> FindPath(TreeNode *root, int target)
        {
            // write code here
            vector<int> vec;
            if (root == nullptr){
                return ans;
            }
            MyFindPath(vec, 0, root, target);

            return ans;
        }
        void MyFindPath(vector<int> vec, int sum, TreeNode *root, int targer)
        {
            sum += root->val;
            
            vec.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {
                // 到了叶子节点
                if (sum == targer)
                    ans.push_back(vec);
                return;
            }
            if (root->left != nullptr)
                MyFindPath(vec, sum, root->left, targer);
            if (root->right != nullptr)
                MyFindPath(vec, sum, root->right, targer);
            
        }
        
        
        // 考虑进一步优化，直接使用值传递的方法会导致内存很大，因此改写递归函数
        void MyFindPath_v2(vector<int>& vec, int sum, TreeNode *root, int targer)
        {
            if (root == nullptr)
                return;
            sum += root->val;
            
            vec.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {
                // 到了叶子节点
                if (sum == targer)
                    ans.push_back(vec);            
            }
            if (root->left != nullptr)
                MyFindPath(vec, sum, root->left, targer);
            if (root->right != nullptr)
                MyFindPath(vec, sum, root->right, targer);
            // vec pop
            vec.pop_back();
        }

    };
    ```
## 面试题 35： 复杂链表的复制
> 这里题目给出了复杂链表的复制，要求必须是一个 **深拷贝** ，因此不可以再原数组的直接返回。
- 综合链表的性质，每一个节点的地址都是随机的，使用的是 **指针** 将不同的链表串联再一起，因此这道题目的关键在于如何根据待复制的原始链表，将新链表的随机指针同时复制。

    - 法一、使用一个hash记录<原始节点、复制节点>的映射关系，根据原始链表找到对应的下一个随机指针指向的节点后，根据`map`中存储的地址定位到新的链表中的节点，进而实现随机指针的串联。
    ```cpp
    class Solution {
    public:
        RandomListNode* Clone(RandomListNode* pHead) {
            // 因为存在一个随机指针指向一个随机位置

            // 使用哈西边记录前后两个链表的对应关系
            unordered_map<RandomListNode*, RandomListNode*> myMap;
            RandomListNode* PseudoHead = new RandomListNode(-1);
            if (pHead == nullptr) {
                return nullptr;
            }
            RandomListNode* sourcehead = pHead;
            RandomListNode* copyNode = new RandomListNode(pHead->label);
            PseudoHead->next = copyNode;
            myMap.emplace(pHead, copyNode);
            pHead = pHead->next;
            while (pHead != nullptr) {
                RandomListNode* tem = new RandomListNode(pHead->label);
                copyNode->next = tem;
                myMap.emplace(pHead, tem);
                copyNode = copyNode->next;
                pHead = pHead->next;
            }
            // 链接随机指针
            RandomListNode* copyTem = PseudoHead->next;
            while (sourcehead != nullptr) {
                cout << "val: "<<sourcehead->label<<endl;
                /* code */
                if (sourcehead->random != nullptr) {
                    copyTem->random = myMap[sourcehead->random];
                }
                sourcehead = sourcehead->next;
                copyTem = copyTem->next;
            }

            return PseudoHead->next;
        }
    };
    ```
    - 法二、在剑指offer书中给出的另一种做法是将复杂的问题简单化。我们可以在原始链表的基础上继续在每一个节点后面添加一个新的节点。然后根据原始节点的指向，修改新的节点指向。最后将新节点**其实就是偶数位置上的节点**从整体中分离出来，得到的就是最后的复制的结果。TODO 这种思路没有实现，但是觉得可能比原来的难写一些，如果后面有机会再写吧。
## 面试题 36： 搜索二叉树变成双向链表
> 搜索二叉树中每一个节点都带了两个指针，正好指向两个子树，而双向链表中正好前后两个指针，因此再数据结构层次上是可行的。
- 具体里思路有点复杂，需要理顺
    1. 首先作为一个具有排序的双向链表，对标的正好是搜索二叉树的中序遍历，因此使用递归的方法完成中序遍历，在此基础上进行指针指向的迁移。
    2. 将二叉树结构看作[左子树-根节点-右子树], 那么其实就是左子树最后一个第一个节点和根节点相连，根节点作为右子树前面的第一个节点和右子树最左边的节点相连。
    3. 因此推理一个实现的方法。首先使用一个全局变量记录上一个节点(也就是每一次递归进入一个的root节点)，因为是全局的，因此可以看作是外层递归中的上一个节点。
    4. 改变指针的指向，root的左指针指前一个全局前序节点，前序节点的右指针指向root。
    ```cpp
    class Solution {
    public:
        TreeNode* perNode; // 代表的是前一个节点，因为要变为双向链表
        TreeNode* Convert(TreeNode* pRootOfTree) {
            // 如果最基础的解法，就是通过中序遍历得到一个排序序列，然后构建双向链表
            // 然而本题目需要的是空间复杂度为O(1)的算法，因此我们考虑使用递归解法
            if (pRootOfTree == nullptr) {
                return pRootOfTree;
            }
            TreeNode* ans = pRootOfTree;
            // 双向链表的开头的第一个节点就二叉搜索树最左侧的节点
            while (ans->left) {
                ans = ans->left;
            }
            inorder(pRootOfTree);
            return ans;
        }
        void inorder(TreeNode* root) {
            if (root == nullptr ) {
                // 如果是空的  直接返回
                return;
            }
            inorder(root->left);
            root->left = perNode;
            if (perNode != nullptr) {
                perNode->right = root;
            }
            perNode = root;
            inorder(root->right);
        }
    };
    ```
## 面试题 38: 字符串的排列 
> [牛客网链接](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=23291&ru=%2Fpractice%2Ffe6b651b66ae47d7acce78ffdd9a96c7&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&sourceUrl=) 这道题目为字符串的所有可能的排列，其实就是一个给定字符串的全排列问题
- 我们想到的就是使用递归的方法，从左到右对字符串尝试左右的可能性。其中使用到了一个关键的函数`swap`用于交换字符串中指定索引的两个字符。
    - 其中的一个坑在于给定的字符串可能会存在相同的两个字符，这时候可以从两个不同的角度来解决这个问题。  
    1. TODO:在交换的时候引入`visit`数组用于标识是不是访问过这个字母(题干中给出了只存在大写和小写字母)  
    2. 使用`set`首先保存所有结果，借助于容器实现相同结果的过滤。
    ```cpp
    class Solution {
    public:
        /**
        * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
        *
        *
        * @param str string字符串
        * @return string字符串vector
        */
        unordered_set<string> ans;

        vector<string> Permutation(string str) {
            /**
            * 这个题目中存在的一个大坑就是可能会有重复的元素
            * 这时候如果将两个元素看成了一个, 会导致重复
            */
            // write code here
            vector<string> anss;
            int size = str.size();
            if (size == 0) {
                return anss;
            }
            // 使用递归的方法解决

            myPer(str, 0, size - 1);

            for (auto& i : ans) {
                anss.push_back(i);
            }
            sort(anss.begin(), anss.end());
            return anss;
        }
        void myPer(string& str, int star, int end) {
            if (star == end) {
                // cout << str << endl;
                int j;
                // cin >> j;
                ans.emplace(str);
                return;
            }
            for (int i = star; i <= end; i++) {
                // 当前元素和每一个元素进行交换，可以得到当前位置的所有组合情况
                swap(str[star], str[i]);
                myPer(str, star + 1, end);
                // 然后换回来
                swap(str[star], str[i]);
            }
            return;
        }
    };
    ``` 


---
## 面试题 39：超过一半的数组
> 数组中出现次数超过一般的数字，可以首先进行一个**排序**，然后根据排序结果，中间的肯定是出现次数超过一般的元素。
```cpp
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        int size = numbers.size();
        sort(numbers.begin(), numbers.end());
        return numbers[size >> 1];
    }
};
```
- 如果直接首先进行排序，然后返回中间元素，虽然可以解决本题目，但是不是效率最高的解决方案。这里我们使用一种神奇的叫做 **摩尔排序**的方法。依据是一定存在大于一半的元素，因此这个元素肯定可以和其他元素抵消。
    ```cpp
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // 排序算法的时间复杂度至少为排序的时间复杂度，因此可能时间长，尝试减低
        // 使用一种叫做摩尔投票的方法
        int count = 0, num = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (count == 0) {
                num = numbers[i]; // 当前记录的
                count = 1;
            } else {
                if (num == numbers[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return num;
    }
    ```
## 面试题 40： 最小的k个数
> 本题目想要求的最小的k个数字，我们拿到题目的第一反应就是首先堆数组进行排序，然后选择其中最小的k个数字。
- 然而如果直接使用排序算法进行，时间复杂度最小的情况下也是一个$O(nlongn)$的情况，不满足题目中要求的时间复杂度为$O(nlogk)$的要求。那么什么时候时间复杂度为$O(nlogk)$呢，我们可以知道优先队列的`pop()`和`emplace()`的时间复杂度都是$logk$，因此我们可以构建一个只有k个节点的优先队列，通过遍历给定数组中的每一个元素，来得到最后的结果数组。在完成后直接将优先队列的元素转移到vector中即可。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param input int整型vector
         * @param k int整型
         * @return int整型vector
         */
        vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
            // write code here
            // 要求空复杂度为O(n) 时间复杂度为O(nlogk)
            // 因此考虑使用最大堆,堆顶保留最大的元素

            vector<int> ans;
            priority_queue<int> que;
            for (auto& i : input) {
                if (que.size() < k) {
                    que.emplace(i);

                } else {
                    if (!que.empty()) {
                        if (que.top() > i) {
                            que.pop();
                            que.emplace(i);
                        }
                    }
                }
            }
            while (!que.empty()) {
                ans.push_back(que.top());
                que.pop();
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };
    ```
## 面试题 42： 连续子数组的最大和
> 本题目为求给定一个子数组的最大和，因为数组中有负数的存在，因此起点可能不一样
- 因此我们使用动态规划的方法，保存 一个最大值
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param array int整型vector
         * @return int整型
         */
        int FindGreatestSumOfSubArray(vector<int>& array) {
            // write code here
            int ans = INT_MIN;
            int size = array.size();
            vector<int> dp(size);
            if (array.size() < 1) {
                return ans;
            }
            dp[0] = array[0];
            ans = max(dp[0], ans);
            for (int i = 1; i < size; i++) {
                dp[i] = max(dp[i - 1] + array[i], array[i]);
                ans = max(dp[i], ans);
            }
            return ans;
        }
    };
    ```
- 然而在上述方法中，我们使用了额外的`dp`数组来维护每一个index下的最大值，题目中给出了额外的要求说是需要使用空间复杂度为$O(1)$，也就是说不允许使用额外的空间。这时候考虑到的优化策略就是将`dp`数组优化掉。这时候我们采用的策略是直接在原来的数组空间上进行修改。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param array int整型vector
         * @return int整型
         */
        int FindGreatestSumOfSubArray(vector<int> &array)
        {
            // write code here
            int ans = INT_MIN;
            int size = array.size();
            if (array.size() < 1)
            {
                return ans;
            }
            // dp[0] = array[0];
            ans = max(array[0], ans);
            for (int i = 1; i < size; i++)
            {
                array[i] = max(array[i - 1] + array[i], array[i]);
                ans = max(array[i], ans);
            }
            return ans;
        }
    };
    ```
- 第三种策略就是引入一个新的int类型的变量，使用两个int来保存中介结果。
    ```cpp
        int FindGreatestSumOfSubArray(vector<int>& array) {
            // write code here
            int ans = INT_MIN, maxNum = INT_MIN;
            int size = array.size();
            if (array.size() < 1) {
                return ans;
            }
            // dp[0] = array[0];
            // ans = max(array[0], ans);
            maxNum = array[0];
            ans = max(maxNum, ans);
            for (int i = 1; i < size; i++) {
                if (maxNum + array[i] > array[i]) {
                    maxNum = maxNum + array[i];
                } else {
                    maxNum = array[i];
                }
                ans = max(maxNum, ans); 

            }
            return ans;
        }
    ```
## 面试题 43： 整数中1的的出现次数
> 整数中1出现的次数，作为一道经典的递归题目。可以通过递归的解决。
- 具体来说，首先分离出最高位和其他位数，然后最高位置分为两种：1/其他；剩余的位数算一个。剩余的第三种考虑最高位置引导的其他。
    ```cpp
    class Solution {
    public:
        int NumberOf1Between1AndN_Solution(int n) {
            if (n <= 0)
                return 0;
            if (n < 10)
                return 1;

            int high = n;
            int pow = 1;
            int ans;
            while (high >= 10) {
                // 注意这里的判断，当到了最后一位后，直接停止
                // 这种设计可以保存最高位的数字
                high /= 10;
                pow *= 10;
            }
            // 此时高位数字可以理解为higt
            // 接下来计算低位数字
            int low = n - high * pow;
            if (high == 1) {
                // 如果最高位置是1 ，那么1的次数就是以后的所有字符+1....
                ans = low + 1;
            } else {
                // 如果最高位置不是1 ， 那么1的次数就是pow
                ans = pow;
            }
            return ans + NumberOf1Between1AndN_Solution(low) + high *
                NumberOf1Between1AndN_Solution(pow - 1);
        }
    };
    ``` 
## 面试题 45:  把数组排成最小的的数字
> [牛客网连接](https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)  
本题目的输入是一个int类型的数字数组，需要得到经过数字拼接后得到的最小的大数
- 第一点我们需要想到的是如果直接对int类型的进行拼接，那么可能面临的问题就是**溢出**。针对这个问题的关键解法就是首先将int类型的数组转化成一个string类型的数组。
- 在得到一个string类型的数组之后，可以通过自定义排序来实现在数组内部的排序。  
需要注意的一个关键点就是对string数组的排序，如果`cmp`函数写在了class内部，那么需要使用`static`修饰，以消除函数参数中的第一个指针。
```cpp
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return string字符串
     */
    string PrintMinNumber(vector<int>& numbers) {
        // write code here
        // 由于两个数组直接拼接，可能会导致int类型的数据数值溢出
        // 所以首先将int类型的数据转化为string
        vector<string> vecStr;
        for(int i = 0; i<numbers.size(); i++){
            string tem = to_string(numbers[i]);
            vecStr.push_back(tem);
        }
        // 现在得到的是一个string的数组，下一步可通过自定义排序
        // 对数组位置进行调整。 那么需要明确的就是这个排序规则
        sort(vecStr.begin(), vecStr.end(), cmp);
        string ans;
        for (int i = 0; i<vecStr.size(); i++){
            ans += vecStr[i];
        }
        return ans;
    }
    static bool cmp (const string vecStr1, const string vecStr2){
        string str1 = vecStr1 + vecStr2;
        string str2 = vecStr2 + vecStr1;
        return str1 < str2;
    }
};
```
- 除此之外，在本题目中，可以使用 **匿名函数** 实现对string数组的快速排序
`sort(temp.begin(), temp.end(), [](const string& a, const string& b) {return a + b < b + a; });`

## 面试题 49 丑数
> [牛客链接](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&&tqId=11186&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)本题目可以看作是一道经典的 **迭代** 类的题目。
- 首先需要明确丑数的定义；
- 使用 **三指针** 的方法解决。

```cpp
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param index int整型
     * @return int整型
     */
    int GetUglyNumber_Solution(int index) {
        // write code here
        if (index <= 0) {
            return 0;
        }
        if (index == 1) {
            return 1;
        }
        // 正式逻辑  计算2 3 5 的组合
        // 开辟一个数组，记录0-index中的丑数
        vector<int> ans(index + 1, 0);
        ans[1] = 1;
        // 开始的时候三个不同的因子都是从1开始加 这时候
        int index_two = 1, index_three = 1, index_five = 1;

        for (int i = 2; i <= index; i++) {
            // 需要明白的一点是因为index_2/3/5是++，因此其实就是可以看作是遍历前面的所有可能
            // for循环中，每一次循环其实都是获得了一个最新的丑数
            // 下面的判断是不是相等的逻辑 是为了防止重复
            int minNum = min(min(ans[index_two] * 2, ans[index_three] * 3),
                             ans[index_five] * 5);
            if (minNum == ans[index_two] * 2) {
                index_two++;
            }
            if (minNum == ans[index_three] * 3) {
                index_three++;
            }
            if (minNum == ans[index_five] * 5) {
                index_five++;
            }
            ans[i] = minNum;
        }

        return ans[index];
    }
};
```


## 面试题 50： 第一个只出现一次的字符
> [牛客网链接](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&&tqId=11187&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)首先需明确本题目设定的输入 **第一个** 只出现一次的字符
- 因此选择的策略是首先遍历一遍整个字符串，记录每一个字符出现的次数。然后第二次遍历的选择出第一个只出现一次的字符即可。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param str string字符串
         * @return int整型
         */
        int FirstNotRepeatingChar(string str) {
            // write code here
            int size = str.size();
            // 且字符串只有字母组成
            unordered_map<char, int> myMap;
            for (int i = 0; i < size; i++) {
                char tem = str[i];
                // 在map数据结构中的查找操作
                auto iter = myMap.find(tem);
                if (iter != myMap.end()) {
                    // 找到了
                    iter->second ++;
                } else {
                    myMap.emplace(tem, 1);
                }
            }

            // 遍历maMap 找到第一个第二个元素是1的即可，
            for (int i = 0; i < size; i++) {
                auto iter = myMap.find(str[i]);
                if (iter->second == 1) {
                    return i;
                }
            }
            return -1;

        }
    };
    ```
- 补充：因为题目中给出了附加信息  **字符串中只包含了大小写字母** 因此我们可以使用一个256长度的`vector<int>(256)`来作为一个简易化的哈希表，进而节省空间复杂度。
    ```cpp
    int FirstNotRepeatingChar(string str) {
        // write code here
        int size = str.size();
        // 且字符串只有字母组成
        // 这里使用是一个recoder记录 因为string中的字符串是最多只有256种可能
        // 这是根据c++中char的数据类型决定的
        vector<int> recorder(256, 0);
        for (int i = 0; i < size; i++) {
            recorder[str[i]]++;
        }

        // 遍历maMap 找到第一个第二个元素是1的即可，
        for (int i = 0; i < size; i++) {
            if (recorder[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
    ```
## 面试题 51: 数组中的逆序对
> [牛客网链接](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&&tqId=11186&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)首先需要知道应该如何解决本题目，逆序对的含义说白了就是从数组中任意选出两个数字，其中位于前面的数字在数值上大于后面的数字
- 在明确了含义以后，可以进行算法分析
    - 首先想到的就是使用暴力所有的方法，对于每一个元素，都向后看一次，判断和他成对的逆序对有多少，这样的话时间复杂度为$O(n^2)$；
    - 然而面试官可能会提醒我们还有更加省时的方法，要求时间复杂度为O(nlog(n))。这时候我们要想到的是 **归并排序** 的时间复杂度正好为O(nlog(n)), 那么能不能通过修改归并排序，来完成本题目。答案是可以的。
    - 我们通过分组，判断每一个小组内部的排序数字，然后对每一个小组内部进行排序，然后因为每一个分组是一个排序数组，因此可以根据这个数组的有序性，进行统计两个子序列中存在的逆序数。
    ```cpp
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param index int整型
         * @return int整型
         */
        int GetUglyNumber_Solution(int index) {
            // write code here
            if (index <= 0) {
                return 0;
            }
            if (index == 1) {
                return 1;
            }
            // 正式逻辑  计算2 3 5 的组合
            // 开辟一个数组，记录0-index中的丑数
            vector<int> ans(index + 1, 0);
            ans[1] = 1;
            // 开始的时候三个不同的因子都是从1开始加 这时候
            int index_two = 1, index_three = 1, index_five = 1;
    
            for (int i = 2; i <= index; i++) {
                // 需要明白的一点是因为index_2/3/5是++，因此其实就是可以看作是遍历前面的所有可能
                // for循环中，每一次循环其实都是获得了一个最新的丑数
                // 下面的判断是不是相等的逻辑 是为了防止重复
                int minNum = min(min(ans[index_two] * 2, ans[index_three] * 3),
                                ans[index_five] * 5);
                if (minNum == ans[index_two] * 2) {
                    index_two++;
                }
                if (minNum == ans[index_three] * 3) {
                    index_three++;
                }
                if (minNum == ans[index_five] * 5) {
                    index_five++;
                }
                ans[i] = minNum;
            }
    
            return ans[index];
        }
    };
    ```
---


# 解决git上传失败
    ```python
    git config --global --unset http.proxy 
    git config --global --unset https.proxy
    # 配置代理转发ip
    git config --global http.proxy http://127.0.0.1:7890 
    ```
