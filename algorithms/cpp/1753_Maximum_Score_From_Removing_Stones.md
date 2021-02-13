```c++
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a+b<=c) return a+b;
        else if(a+c<=b) return a+c;
        else if(b+c<=a) return b+c;
        return (a+b+c)/2;
    }
};
```

