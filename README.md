# leetcode_code

## About Author : Hitszer cs-cv

- [我的CSDN博客](https://blog.csdn.net/qq_43528044)

- [我的WX](z1060856152)

- 尽量会保持更新记录，一起加油


## About Work:

### [LeetCode 热题 HOT 100](https://leetcode.cn/problem-list/2cktkvj/)

- [1. 两数之和](https://leetcode.cn/problems/two-sum/?favorite=2cktkvj): *0320* 在数组查询过程中为了降低时间复杂度，可以通过引入 **map** 的方式，学习标准库下map的基本操作 方法： 空间换时间  map查找

- [2. 两数相加](https://leetcode.cn/problems/add-two-numbers/?favorite=2cktkvj): *0321* 其中 **链表** 中每个节点存储了一位数字，在本题中要注意的是加法运算可能存在进位，在每次求和过程中需要考虑进位，另外作为加数的两个链表长度可能不一致。最后使用new新建节点即可 方法： 模拟
 
- [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/?favorite=2cktkvj): *0322* 首先需要区别的是最长子串还是最共子序列，子串需要保证连续性。本题中可以使用双指针进行窗口的滑动，在查找过程中使用set数据结构存储 方法：双指针 滑动窗口

- [4. 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/?favorite=2cktkvj): *0323* 涉及到log，因此使用二分查找 **难题**

- [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/): *0324* 给定字符串，求最长的回文子串，使用**动态规划**的方法进行求解，dp[i][j]二维数字记录从i到j的子串是否为回文序列，这里需要注意的是循环的写法，外层循环循环记录等待判断的子串长度L，内层循环记录子串的开始索引即可。

- [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/?favorite=2cktkvj): *0325* 本题目是一个**单调**问题，可以首先开辟一个长度和输入数组一样的数组，存储比当前节点更大的第一个元素，从右往左遍历扫描,可以通过跳转降低时间复杂度

- [647. 回文子串](https://leetcode.cn/problems/palindromic-substrings/?favorite=2cktkvj): *0325* 回文串问题和[无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/?favorite=2cktkvj)问题相似，使用**动态规划**的思路解决问题，首先定义动态方程，每一个单独的字符都是一个回文串，然后循环。有两个字符构成的子串，仅需要保证两个数字一样即可。大于三个字符的使用动态规划的转移方程即可。需要注意的是循环遍历的写法，外层循环子串长度L，内层循环起始位置i，即可

- [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/?favorite=2cktkvj): *0326*  使用**递归**的方法，直接创建一棵新的二叉树即可。

- [538. 把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/?favorite=2cktkvj) *0327*  本题首先需要理解累加树的属性，累加树每一个节点的值在二叉搜索树中，可以直接表示为通过**右-中-左**进行递归遍历即可。

- [494. 目标和](https://leetcode.cn/problems/target-sum/?favorite=2cktkvj) *0328*  本题可以使用 **回溯** 的方法解决，通过递归判断每一种情况，当运行到最后一个元素并添加了符号以后，通过判断所求的和与目标值是否一致来确定最终是不是res++ 

- [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/?favorite=2cktkvj) *0416*  本题应采用 **滑动窗口** 的方法来解决问题，由于是异位词，所以不考虑顺序，如果使用hash map 顺序和操作不方面，这里用到的技巧是，由于题目给出所有的字符都是小写字母，所以可以根据acsll码值，更改为数组表示，数组长度为26（字母的个数）。每滑动一次，前面的-1，后面的+1，判断是否一致，即可。本题目的两个**收获**是: vector的插入需要的函数时emplace_back, 不可以直接emplace，需要牢记。另一个时只涉及到字母是，可以使用线性表数组，这样的查找效率更高更快。 

- [437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii/?favorite=2cktkvj) *0417*  本题目使用**二叉树**的递归遍历，由于路径的奇起点是二叉树上的任意节点，因此遍历每一个节点作为起点，方向是从父节点到子节点，因此遍历即可，需要注意的是中间记录和的参数如果使用int类型可能**溢出**，因此需要改用long long 类型。

- [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/?favorite=2cktkvj) *0418*   本题使用首先将题目抽象为**0-1背包问题**的变体，进而是用动态规划的方式求解，注意动态规划dp方程的定义和转移方程的描述即可。具体代码见[cpp文件](https://github.com/YuzheZhou2000/leetcode_code/blob/main/416.cpp)，本题中可以重新复习**二维数组 的创建**  `vector<vector<bool>> dp(len, vector<bool>(targetSum + 1, false));`

