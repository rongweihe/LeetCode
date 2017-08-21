[link]  https://leetcode.com/problems/image-smoother/description/  

[661]  
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.  
Example 1:  
Input:  
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],  
 [0, 0, 0],  
 [0, 0, 0]]  
Explanation:  

For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0  

For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0  

For the point (1,1): floor(8/9) = floor(0.88888889) = 0  

Note:  

The value in the given matrix is in the range of [0, 255].  

The length and width of the given matrix are in the range of [1, 150].  

[solution]  
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    vector<vector<int>> ans(M);
    int sum = 0,cnt=0;
    int row = M.size();
    int col= M[0].size();
    for( int i = 0; i < row; ++i)
    {
        for( int j = 0; j < col; ++j)
        {
            sum =cnt = 0;
            for( int ii= i-1; ii<= i+1; ++ii )
            {
                for( int jj= j-1; jj <= j+1; ++jj )
                {
                    if( ii< 0 || jj < 0 || ii >= row|| jj >= col) continue;
                    sum += M[ii][jj];
                    cnt++;
                }
            }
            ans[i][j] = sum / cnt;
        }
    }
        return ans;
    }
};



