Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

**复杂度：**

时间复杂度：O(n)

空间复杂度：O(n)

```c++
//同余定理：两个数模K的结果相等, 其差能被K整除
class Solution {
public:
  int subarraysDivByK(vector<int>& A, int K) {
  	int sum = 0, res = 0;
    std::unordered_map<int,int> mp{{0,1}};
    for (int &e : A) {
    	sum += e;
        int mod = (sum%K + K) %K;
        if (mp.count(mod)) {
            res += mp[mod];
        }
        mp[mod]++;
    }
    return res;
  }
};
```

