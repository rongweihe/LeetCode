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
二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，我们观察上面红色的数字都是升序的，由此我们可以观察出规律，如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了
【代码】

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
```

