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

