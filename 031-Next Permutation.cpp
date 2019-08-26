//Create By@ herongwei 2019/08/26
/*
【思路】
这道题让我们求下一个排列顺序，由题目中给的例子可以看出来，如果给定数组是降序，则说明是全排列的最后一种情况，则下一个排列就是最初始情况，可以参见之前的博客 Permutations。我们再来看下面一个例子，有如下的一个数组

1　　2　　7　　4　　3　　1

下一个排列为：

1　　3　　1　　2　　4　　7

那么是如何得到的呢，我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，然后我们再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：

1　　2　　7　　4　　3　　1

1　　2　　7　　4　　3　　1

1　　3　　7　　4　　2　　1

1　　3　　1　　2　　4　　7

 
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        int j = n-1;
        while(i>=0 && nums[i]>=nums[i+1])--i;
        if(i>=0){
            while(nums[j]<=nums[i]) --j;//从右到左找到第一个大于nums[i]的，包括顺序和逆序的情况
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());//直接翻转
    }
};
