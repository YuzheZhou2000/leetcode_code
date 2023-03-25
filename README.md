# leetcode_code

## about author : hitszer cs-cv

- [我的CSDN博客](https://blog.csdn.net/qq_43528044)

- [我的WX](z1060856152)

- 尽量会保持更新记录，一起加油


## about work:

- [0320](https://leetcode.cn/problems/two-sum/?favorite=2cktkvj): *1. 两数之和* 在数组查询过程中为了降低时间复杂度，可以通过引入 **map** 的方式，学习标准库下map的基本操作 方法： 空间换时间  map查找

- [0321](https://leetcode.cn/problems/add-two-numbers/?favorite=2cktkvj): *2. 两数相加* 其中 **链表** 中每个节点存储了一位数字，在本题中要注意的是加法运算可能存在进位，在每次求和过程中需要考虑进位，另外作为加数的两个链表长度可能不一致。最后使用new新建节点即可 方法： 模拟
 
- [0322](https://leetcode.cn/problems/longest-substring-without-repeating-characters/?favorite=2cktkvj): *3. 无重复字符的最长子串* 首先需要区别的是最长子串还是最共子序列，子串需要保证连续性。本题中可以使用双指针进行窗口的滑动，在查找过程中使用set数据结构存储 方法：双指针 滑动窗口

- [0323](https://leetcode.cn/problems/median-of-two-sorted-arrays/?favorite=2cktkvj): *4. 寻找两个正序数组的中位数* 涉及到log，因此使用二分查找 **难题**

- [0324](https://leetcode.cn/problems/longest-palindromic-substring/): *5. 最长回文子串* 给定字符串，求最长的回文子串，使用**动态规划**的方法进行求解，dp[i][j]二维数字记录从i到j的子串是否为回文序列，这里需要注意的是循环的写法，外层循环循环记录等待判断的子串长度L，内层循环记录子串的开始索引即可。

- [0325](https://leetcode.cn/problems/daily-temperatures/?favorite=2cktkvj): *739. 每日温度* 本题目是一个**单调**问题，可以首先开辟一个长度和输入数组一样的数组，存储比当前节点更大的第一个元素，从右往左遍历扫描,可以通过跳转降低时间复杂度

- [0326](https://leetcode.cn/problems/palindromic-substrings/?favorite=2cktkvj) 
