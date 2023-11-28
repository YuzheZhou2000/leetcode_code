# include <bits/stdc++.h>
using namespace std;
/**
 * 顺时针打印矩阵
*/#include <iostream>
class Solution {
  public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        // 通过维护左上角和右下角的下标来实现顺时针遍历
        int star_x = 0, star_y = 0;
        int end_x = matrix.size() - 1;
        if (end_x == -1) {
            return ans;
        }
        int end_y = matrix[0].size() - 1;
        while (star_x <= end_y && star_y <= end_y) {       
            // 分四个方向打印一圈   
            int i = star_x;
            int j = star_y;

            if (i<= end_x){
            // 1. 左到右
            while (j <= end_y) {
                //cout << "a: " << matrix[i][j] << endl;
                ans.push_back(matrix[i][j++]);
            }
            }
            // 2. 上到下
            i = star_x + 1;
            j = end_y;         
            while (i < end_x) {
                //cout << "b: " << matrix[i][j] << endl;
                ans.push_back(matrix[i++][j]);
            }
            // 3. 右到左
            if (end_x  > star_x) {
                i = end_x;
                j = end_y;  
                while (j >= star_y) {
                   // cout << "c: " << matrix[i][j] << endl;
                    ans.push_back(matrix[i][j--]);
                }
            }
            // 4. 下到上
            if (star_y < end_y) {
                i = end_x - 1;
                j = star_y;
                while (i > star_x) {
                    // cout << "d: " << matrix[i][j] << endl;
                    ans.push_back(matrix[i--][j]);
                }
            }
            star_x++;
            star_y++;
            end_x--;
            end_y--;
        }
        return ans;
    }
};
int main(){
    return 0;
}