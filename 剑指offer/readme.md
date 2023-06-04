## About Work:

### [LeetCode 剑指offer](https://github.com/YuzheZhou2000/leetcode_code/tree/main/%E5%89%91%E6%8C%87offer)

| 题目      | 日期 |分类| 解题要点      |
| :---:       |    :----:   |  :----:   |          :---: |
| [剑指 Offer 03. 数组中重复的数字](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/description/)      | 2023年4月26日     | 数组| 题目直接使用set容器遍历存储每一个元素，当发现重复元素时，直接返回即可，在这里set起到一个存储已读元素的作用[AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-03.cpp)   |
| [剑指 Offer 04. 二维数组中的查找](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)   | 2023年4月26日      |矩阵、二叉树 | 将有序排列的数字构成的矩阵看作一个搜索二叉树，树根位置在左下角，分支遍历即可 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-04.cpp)  |
| [剑指 Offer 05. 替换空格](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)   | 2023年4月27日       |字符串 | 直接使用字符串逐个字符遍历即可 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-05.cpp)  |
| [剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)   | 2023年4月27日       |链表 | 倒叙打印链表的值，这里使用的递归遍历反向打印 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-06.cpp)  |
| [剑指 Offer 07. 重建二叉树](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)   | 2023年4月28日       |二叉树 | 根据前序和中序遍历数组构建新的二叉树，注意边界范围 使用递归即可 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-07.cpp)  |
| [剑指 Offer 09. 用两个栈实现队列](https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)   | 2023年4月28日       | 栈、队列的模拟 | 两个栈结构实现一个队列，注意栈结构的性质是先进后出，队列的性质是先进先出即可 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-09.cpp)  |
| [剑指 Offer 10- I. 斐波那契数列](https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/description/)   | 2023年5月2日       |递归、动态规划 | 斐波那契数列是一个典型得到递归问题，但是在本题中，如果使用简单的递归计算，会发现如果n过大，会发生运行超时的现象，因此考虑使用空间换时间的方法，使用**动态规划**解决，另外需要注意题目中的求模运算。 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-10-1.cpp)  |
| [剑指 Offer 10- II. 青蛙跳台阶问题](https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)   | 2023年5月2日       |动态规划 | 本题目思路和10-1完全一致，但是需要注意的是初始条件不一致，0层台阶可能的步数是 1 而不是 0  [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-10-2.cpp)  |
| [剑指 Offer 11. 旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)   | 2023年5月2日       |数组、二分查找、排序 | 本题最终目的是为了找到数组中的最小值，因此直接使用`sort`函数对数组进行排序返回最小值元素亦可以，但是时间会很多，面试也不能这么做，因此可以使用二分查找，通过判断中间元素和边界元素的大小进而确定最小的元素，具体代码见 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-11.cpp)  |
| [剑指 Offer 12. 矩阵中的路径](https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/description/)   | 2023年5月2日       |矩阵、回溯| 本题需要逐个检查每一个坐标点，对每一个进行回溯，目前还没有彻底理解，CY **TODO** [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-12.cpp)  |
| [剑指 Offer 13. 机器人的运动范围](https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/)   | 2023年5月3日       |矩阵、回溯、深度优先遍历| 本题可以看作是一个[剑指 Offer 12. 矩阵中的路径](https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/description/)中的简化版，因为本题种已经规定了起点是从（0，0）开始的，这里我们使用深度优先遍历算法解决，注意深度优先遍历种递归函数的边界条件，以及添加visited数组记录矩阵中的每一个元素是否被访问 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-13.cpp)  |
| [剑指 Offer 14- I. 剪绳子](https://leetcode.cn/problems/jian-sheng-zi-lcof/description/)   | 2023年5月4日       |动态规划| 也可以使用数学的方法解决 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-14-1.cpp)  |
| [剑指 Offer 15. 二进制中1的个数](https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/description/)   | 2023年6月4日       |位运算| 因为题目中已经给出**输入必须是长度为 32 的 二进制串**，因此使用按位操作，用二进制中的一个“1”进行逐个向左移位，然后和输入进行按位与运算后求和即可。 [AC代码](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-15.cpp)  |



[leetcode题目导航](https://leetcode.cn/problemset/all/?page=56)