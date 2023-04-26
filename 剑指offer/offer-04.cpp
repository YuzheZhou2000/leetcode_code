# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 可以讲二维矩阵看作是二叉树
        int row = matrix.size();
        if(row == 0){
            return false;
        }
        int col = matrix[0].size();
        int i = row-1; 
        int j = 0;
        
        while (i>=0 && j<col)
        {
            if (matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                i--;
            }else{
                j++;
            }
        }
        return false;
        

    } 
};

int main(){

    return 0;
}