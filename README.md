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

- [494. 目标和](https://leetcode.cn/problems/target-sum/?favorite=2cktkvj) *0328*  本体可以使用 **回溯** 的方法解决，通过递归判断每一种情况，当运行到最后一个元素并添加了符号以后，通过判断所求的和与目标值是否一致来确定最终是不是res++ 
