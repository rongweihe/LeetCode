**题目**  
Reverse bits of a given 32 bits unsigned integer. 
For example, given input 43261596 `(represented in binary as 00000010100101000001111010011100)`, return 964176192 (represented in binary as 00111001011110000010100101000000). 
Follow up: 
If this function is called many times, how would you optimize it? 

**题意** 

给你一个32位无符号整数，求出它的反向位`（即二进制的逆序得到的整数）`
 
**思路** 

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        int res = 0;
        int a[32] = {0},k = 0;

        while(n)
        {
            a[k++] = n % 2;
            n /= 2;//除以2
        }

        for (int i=0;i<32;i++)
            res = res * 2 + a[i];
        return res;
    }
};
```
**优化版**
`n&1 : n和1做“按位与”运算，1的二进制只有末位是1，所以n&1就是只保留n的末位（二进制）。同时n&1就表示了n的奇偶性。
|   :     如果存在于任一操作数中，二进制 OR 运算符复制一位到结果中。 `
例如： 
假设如果 A = 60，且 B = 13，现在以二进制格式表示，它们如下所示：
A = 0011 1100
B = 0000 1101
(A | B) 将得到 61，即为 0011 1101

```c++
#include <bits/stdc++.h>
using namespace std;
uint32_t n;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0;
        for (int i=0;i<32;i++)
        {
            res = (res << 1) | (n & 1);
            n = (n >> 1);
        }
        return res;
    }
}A;
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n)
    {
        cout<<A.reverseBits(n)<<endl;
    }
    return 0;
}
```
