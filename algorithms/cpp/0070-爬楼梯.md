

```c++
class Solution {
public:
    int climbStairs(int n) {
        n += 1;
        if (n<=1) return n;
        int f0 = 0, f1 = 1, sum = 0;
        for(int i = 2; i <= n; i++) {
            sum = (f0 + f1);
            f0 = f1;
            f1 = sum;
        }
        return sum;
    }
};
```

