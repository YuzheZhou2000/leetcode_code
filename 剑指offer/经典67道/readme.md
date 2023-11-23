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