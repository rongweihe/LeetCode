【题目】LeetCode 33 Search in Rotated Sorted Array

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`).

 You are given a target value to search. If found in the array return its index, otherwise return -1.

 You may assume no duplicate exists in the array.

 【思路】

分情况讨论，对于数组[0 1 2 4 5 6 7] 共有下列七种旋转方法：

0　　1　　2　　 **4　　5　　6　　7**

7　　0　　1　　 **2　　4　　5　　6**

6　　7　　0　　 **1　　2　　4　　5**

5　　6　　7　　 **0　　1　　2　　4**

**4　　5　　6　　7**　　0　　1　　2

**2　　4　　5　　6**　　7　　0　　1

**1　　2　　4　　5**　　6　　7　　0

然后，再看每一种情况中，target在左边还是在右边，其中第一种情况还可以直接判断target有可能不在数组范围内。

【代码】

```c++
class Solution
{
public:
    int Search(vector<int>&nums,int target)
    {
        int size=nums.size();
        if(size==0)
            return -1;
        int start=0;
        int end=size-1;
        int mid=0;
        while(start <= end )
        {
            mid = start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>nums[end])
            {
                if(target>=nums[start] && target<nums[end])
                {
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
            else
            {
                if(target>nums[mid]&&target<=nums[end])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1
    }
};
```

