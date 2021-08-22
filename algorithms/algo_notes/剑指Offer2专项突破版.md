[TOC]

# 整数和数组专题

## 【1】[剑指 Offer II 001. 整数除法](https://leetcode-cn.com/problems/xoh6Oh/)

【思路】

见代码。

【参考代码】

```c++
//
class Solution {
  public int divide(int dividend, int divisor) {
    //-2^31/ -1 = 2^31 溢出
    if(dividend == 0x80000000 && divisor == -1){
        return 0x7FFFFFFF; 
    }

    int negative = 2;//用于记录正数个数
    //由于负数转为正数 -2^31 -> 2^31 越界，所以采用正数转为负数
    if(dividend > 0){
        negative --;
        dividend = -dividend;
    }

    if(divisor > 0){
        negative --;
        divisor = -divisor;
    }

    //计算两个负数相除
    int result = 0;
    while(dividend <= divisor){
        int value = divisor;//统计减数
        int quotient = 1;//统计商
        while(value > 0xc0000000 && value + value >= dividend){
            //value > 0xc0000000 防止value*2溢出
            quotient += quotient;//如果可以用乘法 quotient*=2
            value += value;//如果可以用乘法 value*=2
        }

        result += quotient;
        dividend -= value;
    }
    return negative == 1 ? -result : result;
}
}
```

## 【2】[剑指 Offer II 002. 二进制加法](https://leetcode-cn.com/problems/JFETK5/)

【思路】
双指针, 让两个数的末位对齐, 两个指针 i, j均从各自字符串的末尾开始走。

定义一个string res 来存放结果, 一个int carry来记录每位的进位值, 初始值设为0。
算当前位置的数时, sum = a[i] + b[j] + carry, 每趟都要记得更新carry的值。

循环结束时, 由于低位的数字字符先加到了结果字符串中, 最后还需要 reverse 一次, 让位置恢复正常。

【参考代码】

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        std::string ret;
        int carry = 0;
        while(i >= 0 || j>= 0) {
            int add1 = (i >= 0) ? a[i--] - '0': 0;//计算第一位
            int add2 = (j >= 0) ? b[j--] - '0': 0;//计算第二位
            int sum = add1 + add2 + carry;//计算和
            carry = (sum >= 2) ? 1 : 0; //计算进位
            sum = (sum >= 2) ? sum - 2 : sum;
            ret.append(std::to_string(sum));
        }
        if (carry == 1) ret.append("1");
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};
```

## 【3】[剑指 Offer II 003. 前 n 个数字二进制中 1 的个数](https://leetcode-cn.com/problems/w3tCBm/)

【思路】

**最常规解法 计算整数 i 的二进制**

1的个数有一种高效的解法是每次用 i&(i-1)将整数 i 的最右边的 1 变成 0 整数 i 减去 1 那么它最右边 1 变成 0，如果它的右边还有 0 则右边所有的 0 都变成 1,而其左边所有的位保持不变。下面对 i 和 i-1 进行位与运算，相当于将其最右边的 1 变成 0 。

以二进制的1100为例，它减去1的结果是1011 1100和1011的位与运算的结果正好是 1000 二进制的1100最右边的1变为0结果刚好就是 1000

```c++
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 0; i <=n; ++i) {
            int j = i;
            while(j) {
                ret[i]++;
                j = j & (j-1);
            }
        }
        return ret;
    }
};
```


如果一个整数共有 k 位，那么它的二进制形式中可能有 O(k) 个 1 在上述代码中，while 循环的代码对每个整数将执行 O(k)次，因此时间复杂度是 O(nk)

**利用 i&(i-1)计算**
根据前面的分析可知，i&(i-1)将 i 的二进制中最右边的 1 变成 0，也就是说，整数 i 的二进制形式 1 的个数比 i&(i-1) 的二进制形式 1 的个数多 1 利用这个性质有如下代码

```c++
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 1; i <=n; ++i) {
            ret[i] = ret[i & (i - 1)] + 1;
        }
        return ret;
    }
};
```


时间复杂度是 O(n)

**利用 i/2 计算**
还有没有更好的思路呢？

有的，如果正整数 i 是一个偶数，那么 i 相当于将 i/2 左移一位的结果，因此偶数 i 和 i/2 的二进制形式 1 的个数是一样的
如果 i 是奇数，那么 i 相当于将 i/2 左移一位之后再将最右边的位设为 1 的结果，因此奇数 i 比 i/2 的二进制形式 1 的个数多 1 个
可以利用这个规律有如下代码

```c++
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 0; i <=n; ++i) {
            ret[i] = ret[i >> 1] + (i & 1);//右移1位相当于i/2
        }
        return ret;
    }
};
```


时间复杂度是 O(n)。



## 【4】[剑指 Offer II 004. 只出现一次的数字 ](https://leetcode-cn.com/problems/WGki4K/)

给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 

示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,100]
输出：100


提示：

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次

【思路】

一个整数无非是由 32 个 0 和 1 组成的，那么我们可以将数组中所有数字的同一位置的数位相加。

将出现三次的数字单独拿出来，那么这些出现了三次的数字，任意的某一位数位置之和能被三整除

理解下面两句话：

因此如果数组中所有数字的第 i 位数位相加之和能被三整除，那么只出现一次的数字的第 i 数位一定是零。

相反，如果数组中所有数字的第 i 位数位相加之和能被三除余一，那么只出现一次的数的第 i 位数一定是 1

这样只出现一次的任意第 i 个数为可以由数组中所有数字的第 i 位数字和推算出来。

当我们知道了一个整数任意的某一位是 0 和 1 之后，也就知道了这个整数的数值。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::vector<int> bitSum(32,0);
        for(int n : nums) {
            for (int i = 0; i < 32; ++i) {
                bitSum[i] += (n >> (31 - i)) & 1;
            }
        }
        int ret = 0;
        for(int i = 0; i < 32; ++i) {
            ret = (ret << 1) + bitSum[i] % 3;
        }
        return ret;
    }
};
```


举一反三
输入一个整数数组，数组中只有一个数字出现了 m 次，其他数字都出现了 n 次。请你找出那个唯一出现 m 的数字，那么假设 m 不能被 n 整除。

分析：这道题可以由第一道题举一反三而来，如果数组中所有数字的第 i 位数相加之和能被 n 整除，那么出现 m 次的数的第 i 数位一定是零，否则出现 m 次的数的第 i 位数一定是1。

 有一个 有限状态自动机 + 位运算 算法，这个后续看下。

## 【5】[005 最大单词长度乘积](https://leetcode-cn.com/problems/maximum-product-of-word-lengths/)

【思路】

C++/位运算/巧妙的使用整数 26 位比特存储字母；用整数的二进制数位记录字符串中出现的字符；

int 整型数二进制有 32 位，题目要求只要 26 位就可以表示出一个字符串中出现的字符，因此可以用一个 int 型整数记录某个字符字符串出现的字符，如果字符串中包含 ‘a’ 则这个整数最右边数位 1 如果包含 ‘b’ 则字符串中倒数第二位数位 1，以此类推，这样的好处就是在预处理的时候就能快速判断两个数是否有相同的位数（位运算&）

时间复杂度  O(n*n)

```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        std::vector<int> flags(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (char &c : words[i]) {
                flags[i] |= (1 << (c - 'a'));
            }
        }
        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((flags[i] & flags[j]) == 0) {
                    int prod = words[i].size()*words[j].size();
                    ret = max(ret, prod);
                }
            }
        }
        return ret;
    }
};
```



## 【6】[剑指 Offer II 006. 排序数组中两个数字之和](https://leetcode-cn.com/problems/kLl5u1/)

【思路】排序数组，直接使用双指针。

【代码】时间复杂度O（logn）

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while( i < j && numbers[i] + numbers[j] != target) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return {i,j};
    }
};
```

## 【7】三数之和为 0

### 题目链接：https://leetcode-cn.com/problems/3sum/

### 思路：

这道题，最直观的想法就是三重循环暴力，时间复杂度是 O(N^3)，那么显然是超时的。

那么我们如何进一步优化呢？

根据题解，找到的三元素不能重复复，可以想到：

- 如果要排序，保证重复出现的数字要在一起，并且时间复杂度为O(NlogN)。
- 可以在第二重循环的枚举中找到不小于当前第一个元素？
- 第三重循环找到不小于第二重循环的枚举元素。

可以发现，我们先是固定了第一个数 i 然后再去找其它两个数的（它们的和是 -i），那么可以将后面的两个数看成是一个数，那么问题就变成了：在有序数组 [i+1, len - 1] 这个范围内去寻找一个符合要求的数。

那么变成了双指针问题，而这个数的值不再是 mid ，而是两个边界 left 和 right 的和。

因为已经排序，所以指针移动的条件在：如果当前和大则移动右指针，否则移动左指针。如果值正好就是当前值。

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        std::vector<std::vector<int> >res;
        if (sz < 3) return res;
        std::sort(nums.begin(), nums.end());
        for (int i=0; i< sz - 2; ++i) {
            if (nums[i] > 0) return res;                //剪枝：已经排好序 后面的数更大相加不可能为0
            if (i > 0 && nums[i] == nums[i-1]) continue; //剪枝：已经排好序 如果当前数和前一个数相同 跳过
            int left = i + 1, right = sz -1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right --;   // 结果太大，那么右指针移动
                } else if (sum < 0) {
                    left++;     // 结果太小，那么左指针移动
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;//去重重复元素
                    while(left < right && nums[right] == nums[right-1]) right--;//去重重复元素
                    left ++;
                    right --;
                }
            }
        }
        return res;
    }
};
```



## 【8】[剑指 Offer II 008. 和大于等于 target 的最短子数组(典型的滑动窗口)](https://leetcode-cn.com/problems/2VG8Kg/)

【思路】双指针，滑动窗口。

子数组由数组中一个或连续的多个数字组成。一个子数组可以用两个指针表示。如果第 1 个指针 P1 指向子数组的第 1 个数字，第 2 个指针 P2 指向子数组的最后一个数字，那么子数组就是由这两个指针之间的所有数字组成的。 

指针 P1 和 P2 初始化的时候指向数组的第 1 个元素，如果两个指针之间的子数组所有数字之和大于或等于 K，那么把 指针 P1 往右移动，相当于缩小窗口，因为都是正整数，相当于子数组长度减少一，相当于减少数组之和，因为目标是求和大于等于 k 的最小子数组，所以可以一直缩小，知道满足条件。，

当如果两个指针之间的子数组所有数字之和小于或等于 K，那么把 指针 P2 往右移动，相当于扩大窗口，相当于在后面新增一个元素，相当于增加子数组的和。

这里需要说明一点，因为数组中为正数所以可以这么做，如果有负数则不可以。

【代码】

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int max_len = INT_MAX;//设置初始最小值
        for(int right = 0; right < nums.size(); ++right) {
            sum += nums[right];//累加和,扩大窗口
            while(left <= right && sum >= target) {
                max_len = min(max_len, right - left + 1);
                sum -= nums[left++];//窗口左边缩小
            }
        }
        return max_len == INT_MAX ? 0 : max_len;
    }
};
```

# 【9】[剑指 Offer II 009. 乘积小于 K 的子数组](https://leetcode-cn.com/problems/ZVAVXX/)

【思路】：和第八题一样，都是双指针，滑动窗口。

唯一不同的是，由于目标是是求所有数字乘积小于 k 的子数组的个数，一旦向右移动指针 P1 到某个位置时子数组的乘积小于 k，就不需要再向右移动指针 p1 了。 

【代码】如下，时间复杂度 O(n)。

```c++
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int prod = 1;
        for(int right = 0; right < nums.size(); ++right) {
            prod *= nums[right];
            while(left <= right & prod >= k) {
                prod /= nums[left++];
            }
            count += (right-left) >= 0 ? (right - left + 1) : 0;
        }
        return count;
    }
};
```



# 【9】[剑指 Offer II 010. 和为 k 的子数组](https://leetcode-cn.com/problems/QTMn0o/)

【思路】

思路就是前缀和
1、O(1)时间复杂度算出一个子数组的所有数字之和。
2、在从头到尾扫描数组中的数字时求出前i个数字之和，并且将和保存下来。
3、数组的前i个数字之和为x，如果存在一个j(j<i)数组的前j个数字之和为x-k那么数组中第i+1个数字开始到j个数字结束的子数组之和为k
4、由于还需要计算子数组的个数，需要保存前i个数字之和，还要保存每个和出现的次数。这里用哈希表保存即可。

以 

输入:nums = [1,2,3], k = 3
输出: 2
举例
sum 的变化依次 1 3 6
而 mp.find(sum - k) 依次是 mp[1]=1; mp[3]=1;mp[6]=1;
初始化 mp[0]=1
所以正好 count = 2(mp[0] 和 mp[3])。

【代码】

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        std::unordered_map<int,int>mp{{0,1}};
        for(auto n : nums) {
            sum += n;//1,3,6
            if (mp.find(sum - k) != mp.end()) count += mp[sum - k];
            mp[sum] ++;//mp[1]=1; mp[3]=1;mp[6]=1;
        }
        return count;
    }
};
```

# 【10】[剑指 Offer II 011. 0 和 1 个数相同的子数组](https://leetcode-cn.com/problems/A1NYOS/)

【思路】

分析：只要把这道题题目稍微修改下就能复用面试题 10 的解法《剑指offer 2 面试题10》 书中算法C++实现。首先把输入的 0 全部替换成 -1，那么题目就是求含有相同数量的 -1 和 1的最长连续子数组的长度。含有相同数量的 -1 和 1 的连续子数组的和为 0，所以原题目变为求和为 0 的最长连续子数组的长度。

为什么可以这样呢？

**如果数组中前 i 个数字之和为 m，前  j 个数字之和也是 m，那么从第 i+1 到 j 之间的和就是 0 。**

区别：解法与面试题 10 如出一辙，只说下区别：

- 哈希表的键还是存前缀和，但是值存的是最小的 i，即若有多个相同前缀和只存最小的 i，因为这样可以保证求得是最长连续子数组的长度；
- mp[0] = -1，即前缀和为 0 时存的索引应该是 -1，代表空的连续子数组。 

路径压缩(针对前缀和数组,但 hash 还是要空间) 空间复杂度 O(n) 时间复杂度 O(n)。

【代码】

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int,int>mp{{0,-1}};
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
```

# 【11】[剑指 Offer II 012. 左右两边子数组的和相等](https://leetcode-cn.com/problems/tvdfij/)

【思路】

用总的数组和 total，减去当前数组和 sum，如果差等于当前数组和减去当前值（sum-nums[i]）,则找到该坐标i；否则输出 -1；

【代码】

```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int all_sum = 0;
        for (int i : nums) {
            all_sum += i;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum - nums[i] == all_sum - sum) {
                return i;
            }
        }
        return -1;
    }
};
```

