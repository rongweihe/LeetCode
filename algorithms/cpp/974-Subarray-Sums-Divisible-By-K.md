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

