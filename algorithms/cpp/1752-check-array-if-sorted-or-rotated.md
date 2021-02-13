```c++
//把数组看成环检查是否存在非递减的数目
class Solution {
public:
    bool check(std::vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            if (nums[i] > nums[(i+1)%nums.size()]) { sum++;  }
        }
        return sum<=1;
    }
};
```

