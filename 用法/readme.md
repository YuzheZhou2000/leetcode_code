



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

## Map
> `map`底层是一个红黑二叉树
- **查找** `find` 和`end` 函数
- **记数**使用`count()`函数直接返回当前容器中对应元素的个数
- **插入** 注意区分`insert`函数和`emplace`函数的区别

    记录常用的插入的方法：  
    `myMap.insert(pair<int, string>(1,“student_one”));`    
    `myMap.emplace(1, "student_one");`

## Unordered_map 
> unordered_map 容器底层采用的是**哈希表**存储结构，  
该结构本身不具有对数据的排序功能，所以此容器内部不会自行对存储的键值对进行排序。

## String
> 在C++中，我们依旧可以使用string容器来对字符串进行处理

- 将一个`int`类型的数据转化成`string`类型的数据可以使用函数`string src = to_string(num);`
- 从`string`字符串中截取一个指定长度的子串`auto pre = src.substr(star, len);`  
其中第一个参数表示开始截取的起始位置，第二个参数表示需要截取的字串长度

## Queue

### 定义：
- 最小堆：`priority_queue <type, vector<type>, greater<type> > name;`
- 最大堆：`priority_queue <type, vector<type>, less<int>> name;`

### 其他：
1. `unordered_map`使用的是STL中默认的哈希函数，而默认哈希函数只适用于基本数据类型（包括 string 类型），而不适用于自定义的结构体或者类。

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
```cpp
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &dir : directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            /*
            code
            */
        }
```

## 排序

### 快速排序
1. 快速排序基于分治的思想 首先确定起始点，然后进行遍历，划分两个子区间以后进行递归。代码示例可参见[快速排序](https://github.com/YuzheZhou2000/leetcode_code/blob/zyz_code/%E5%89%91%E6%8C%87offer/offer-76.cpp)

### 自定义排序
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
## 匿名函数
- 直接上例子
```
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (rank.count(x)) {
                return rank.count(y) ? rank[x] < rank[y] : true;
            }
            else {
                return rank.count(y) ? false : x < y;
            }
        });
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


# 符号说明

## `.` VS `->`
- A.B；    A为对象或者结构体； 点号（.）：左边必须为实体。
- A->B：A为指针，->是成员提取，A->B是提取A中的成员B，A只能是指向类、结构、联合的指针  
箭头（->）：左边必须为指针；



# 库函数的使用

## 数据类型的转化
1. 使用`atoi`函数将一个string类型的数据转化为int类型.需要注意的是string对象需要转换为C字符串
```cpp
string str = "-374832";
int val = atoi(str.c_str());
```