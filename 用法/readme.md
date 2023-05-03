



# 容器

## Vector

- 二维数组的初始化 `vector<vector<bool>> visited(m, vector<bool>(n, false));`在这里创建了一个m*n的初始值全部为false的额二维数组


## Set
- 查找 `find` 和`end()`进行比较: `tem.find(nums[i]) != tem.end()`
- 插入 使用`inset`操作


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
