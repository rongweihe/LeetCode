二维数组的查找

```c++
/* 思路
* 矩阵是有序的，从右上角来看，向下数字递增，向左数字递减，
* 因此从右上角开始查找，当要查找数字比右上角数字小时。左移
* 要查找数字比右上角数字大时，下移
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = 0, col = matrix[0].size() - 1;
        while(row <= matrix.size() - 1 && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {    col--;    }
            else {    row++;    }
        }
        return false;
    }
};
```

