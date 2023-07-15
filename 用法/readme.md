



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

## 变量初始化

1. 直接使用 `=` 进行初始化
    `int a = 10;`
2. 在初始化时候使用 `()` 进行初始化
    `int a(10);`
3. 对于类的构造函数，可以在函数名称的第一行通过 `:` 引导进行初始化操作
    
    举例如下：
    ```    
        class Student
        {
            public:
            Student(int, int);
            protected:
            const int a;
            int &b;
        };
        Student::Student(int i, int j):a(i), b(j)
        {
            
        }
    ```

    说明：
    > 有的数据成员需要在构造函数调入之后、函数体执行之前，就进行初始化，比如引用数据成员、常量数据成员、对象数据成员。  
    冒号初始化是在给数据成员分配内存空间时、进入函数体之前就进行初始化，也就是说，初始化这个数据成员时函数体还未执行。  
    对于在函数体内的初始化，是在所有的数据成员被分配好内存空间后才进行的。
    
    使用场景：
    > 1：初始化const成员  
    2：初始化引用成员  
    3：当调用基类的构造函数，而它拥有一组参数时  
    4：当调用成员类的构造函数，而它拥有一组参数时。

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

## 自定义排序
1. 使用sort函数对STL中的自定义数据结构可以通过cmp实现自定义排序,示例代码如下:
```
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);
        ...
    }

    /*
    在C++中，类成员函数不能直接作为std::sort的比较函数。
    您可以将compare函数声明为static成员函数或定义为类的外部函数
    */
    static bool comp(const vector<int> interval1, const vector<int> interval2)
    {// 比较函数 类内使用必须是静态的
        return interval1[0] < interval2[0];
    }
};
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

- 使用按位异或可以用于判断数字的奇数或者偶数
- 使用右移1可以实现更快的除以2 example:  `{10 >> 2} = {10 / 2}` 

# 数据结构

## 并查集
