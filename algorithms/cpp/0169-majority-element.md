```c++
class Solution {
public:
    //nums看做一个进攻部队序列
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];              //谁占领基地
        int cnt = 1;                    //占领基地军队数
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != ret) {         //有人来打
                cnt--;                  //当前占领者死掉一个
                if(cnt == 0) {          //没占领者了
                    cnt = 1;            //新军接管
                    ret = nums[i];
                }
            }
            else                        //补充部队
                cnt++;
        }
        return ret;
    }
};
```

**复杂度分析**

时间复杂度：O(n)。Boyer-Moore 算法只对数组进行了一次遍历。

空间复杂度：O(1)。Boyer-Moore 算法只需要常数级别的额外空间。
