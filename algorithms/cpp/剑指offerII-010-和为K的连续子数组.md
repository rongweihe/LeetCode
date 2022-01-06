
## 剑指 Offer II 010. 和为 k 的子数组
https://leetcode-cn.com/problems/QTMn0o/

给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2
解释: 此题 [1,1] 与 [1,1] 为两种不同的情况
示例 2 :

输入:nums = [1,2,3], k = 3
输出: 2

【思路】

思路就是前缀和

- O(1)时间复杂度算出一个子数组的所有数字之和。
- 在从头到尾扫描数组中的数字时求出前i个数字之和，并且将和保存下来。
- 数组的前i个数字之和为x，如果存在一个j(j<i)数组的前j个数字之和为x-k那么数组中第i+1个数字开始到j个数字结束的子数组之和为k
- 由于还需要计算子数组的个数，需要保存前i个数字之和，还要保存每个和出现的次数。这里用哈希表保存即可

以  输入:nums = [1,2,3], k = 3
输出: 2
举例
sum 的变化依次 1 3 6  而 mp.find(sum - k) 依次是 mp[1]=1; mp[3]=1;mp[6]=1;
初始化 mp[0]=1 所以正好 count = 2(mp[0] 和 mp[3])

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;//累加和
        int count = 0;//满足条件数
        std::unordered_map<int,int>mp{{0,1}};
        for(auto n : nums) {
            sum += n;
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum] ++;
        }
        return count;
    }
};

*/
```
