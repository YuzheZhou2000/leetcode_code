# 0831

1. stack 队列的基本操作
> 栈的基本操作：
        top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
        push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
        push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
        pop()：弹出栈顶元素。
        size()：返回栈中元素的个数。
        empty()：在栈中没有元素的情况下返回 true。
        emplace()：用传入的参数调用构造函数，在栈顶生成对象。
        swap(stack<T> & other_stack)：将当前栈中的元素和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同。对于 stack 对象有一个特例化的全局函数 swap() 可以使用。
2. vector数组的初始化
    
    - 不带参数的构造函数初始化
    
    - 带参数的构造函数初始化
    - 通过数组地址初始化
    - 通过同类型的vector初始化
    - 通过insert初始化
    - 通过copy函数赋值
    
``` 
Met 1:

//初始化一个size为0的vector
vector<int> abc;

Met 2:

//初始化size,但每个元素值为默认值
vector<int> abc(10);    //初始化了10个默认值为0的元素
//初始化size,并且设置初始值
vector<int> cde(10，1);    //初始化了10个值为1的元素

Met 3:

int a[5] = {1,2,3,4,5};
//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
vector<int> b(a, a+5);

Met 4:

vector<int> a(5,1);
//通过a初始化
vector<int> b(a);

Met 5:

//insert初始化方式将同类型的迭代器对应的始末区间（左闭右开区间）内的值插入到vector中
vector<int> a(6,6);
vecot<int> b;
//将a[0]~a[2]插入到b中，b.size()由0变为3
b.insert(b.begin(), a.begin(), a.begin() + 3);

int a[6] = {6,6,6,6,6,6};
vector<int> b;
//将a的所有元素插入到b中
b.insert(b.begin(), a, a+6);

//在b开始位置处插入6个6
b.insert(b.begin(), 6, 6);

Met 6:

vector<int> a(5,1);
int a1[5] = {2,2,2,2,2};
vector<int> b(10);

/*将a中元素全部拷贝到b开始的位置中,注意拷贝的区间为a.begin() ~ a.end()的左闭右开的区间*/
copy(a.begin(), a.end(), b.begin());

//拷贝区间也可以是数组地址构成的区间
copy(a1, a1+5, b.begin() + 5);
```

# 0901

## 单调栈

-  定义

    单调栈即满足单调性的栈结构。与单调队列相比，其只在一端进行进出

