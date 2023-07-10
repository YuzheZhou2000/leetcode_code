



# 容器

## Vector

- 一维数组的初始化`vector < int > v = {1,2,3,4,5};`
- 二维数组的初始化 `vector<vector<bool>> visited(m, vector<bool>(n, false));`在这里创建了一个m*n的初始值全部为false的额二维数组
- 数组的倒置： reverse函数用于反转在[first,last)范围内的顺序（包括first指向的元素，不包括last指向的元素），reverse函数没有返回值。 `reverse(vi.begin(),vi.end());` 
- 寻找vector数组中的最大值的操作 `int max_ele = * max_element(vec.begin(), vec.end())`



## Set
- 查找 `find` 和`end()`进行比较: `tem.find(nums[i]) != tem.end()`
- 插入 使用`inset`操作
- `unordered_set` 背后的底层实现是一个哈希（散列）方法 

---
---

# 逻辑

## 循环
- 使用auto进行指定结构的遍历
```
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &dir : directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            /*
            code
            */
        }
```

# 运算

## 位运算

| 运算符      | 描述 |解释|
| :---:       |    :----:   |  :----:   |
|   &   |   按位与操作，按二进制位进行"与"运算。 |  全一为一，否则为零  |
| \|   |   按位或操作，按二进制位进行"或"运算。 |  全零为零，否则为一  |
| ^   |   按位异或操作，按二进制位进行"异或"运算。 |  不同为一，相同为零  |
| ~   |   取反运算。 |  直接取反  |
| <<   |  左移 |  将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）  |
| >>   |  右移 |  将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃  |

# 数据结构

## 并查集
