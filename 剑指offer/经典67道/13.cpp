#include <bits/stdc++.h>
using namespace std;
/**
 * 调整数组是的奇数位于偶数前面
 */
class Solution
{
public:
    // 如果使用双指针的方法，虽然可以实现奇数和偶数的交换
    // 但是这是一种类似于快排的方式，会导致数据的而不稳定
    void reOrderArray(vector<int> &array)
    {
        int len = array.size();
        if (len == 0)
            return;
        // 两个指针分别记录 目标是index_1 全部位于index_2的前面
        int index_1 = find_1(array, 0);
        int index_2 = find_2(array, 0);
        cout <<"index_1:"<<index_1<<endl;
        cout <<"index_2:"<<index_2<<endl;
        while(index_1 != -1 && index_2 != -1){
            if(index_1>index_2){
                // 这个奇数在这个偶数的后面
                swap(array[index_1], array[index_2]);
                index_1 = find_1(array, index_1);
                index_2 = find_2(array,index_2);                  
                
            }else{
                // 如果满足条件 继续寻找奇数
                index_1 = find_1(array, index_1+1);      
            }   
        }
        
        return;
    }
    int find_1(vector<int> &array, int index){
        int len = array.size();
        while(index < len){
            if((array[index] & 0x01) == 1){
                // 是一个奇数
                return index;
            }
            index++;
        }
        // 后面没有奇数了
        return -1;
    }
    int find_2(vector<int> &array, int index){
        int len = array.size();
        while(index < len){
            if((array[index] & 0x01) == 0){
                // 是一个奇数
                return index;
            }
            index ++;
        }
        // 后面没有奇数了
        return -1;
    }
   
    void NewreOrderArray(vector<int> &array){
        int len = array.size();
        if(len == 0){
            return;
        }

        // 类比冒泡排序，从后向前冒泡
        for(int i =0;i<len;i++){
            // 如果是一个奇数 那么就开始冒泡
            if(array[i] & 0x01){
                for(int j = i;j>0;j--){
                    if((array[j-1] &0x01) == 0){
                        swap(array[j-1], array[j]);
                    }
                    else{
                        break;
                    }
                }
            }
        }

    }


};

int main()
{
    vector<int> ans = {1,2,3,4,5,6};
    Solution s;
    s.NewreOrderArray(ans);
    for(auto & i : ans){
        cout<<i<<"   ";
    }
    return 0;
}