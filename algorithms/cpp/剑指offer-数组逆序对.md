### 归并排序

预备知识

「归并排序」是分治思想的典型应用，它包含这样三个步骤：

分解：
解决： 使用归并排序递归地排序两个子序列
合并： 把两个已经排好序的子序列 [l, m][l,m] 和 [m + 1, r][m+1,r] 合并起来
在待排序序列长度为 11 的时候，递归开始「回升」，因为我们默认长度为 11 的序列是排好序的。

思路

那么求逆序对和归并排序又有什么关系呢？关键就在于「归并」当中「并」的过程。我们通过一个实例来看看。假设我们有两个已排序的序列等待合并，分别是 L = \{ 8, 12, 16, 22, 100 \}L={8,12,16,22,100} 和 R = \{ 9, 26, 55, 64, 91 \}R={9,26,55,64,91}。一开始我们用指针 lPtr = 0 指向 LL 的首部，rPtr = 0 指向 RR 的头部。记已经合并好的部分为 MM。


L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = []
     |                          |
   lPtr                       rPtr
我们发现 lPtr 指向的元素小于 rPtr 指向的元素，于是把 lPtr 指向的元素放入答案，并把 lPtr 后移一位。


L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = [8]
        |                       |
      lPtr                     rPtr
这个时候我们把左边的 88 加入了答案，我们发现右边没有数比 88 小，所以 88 对逆序对总数的「贡献」为 00。

接着我们继续合并，把 99 加入了答案，此时 lPtr 指向 1212，rPtr 指向 2626。


L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = [8, 9]
        |                          |
       lPtr                       rPtr
此时 lPtr 比 rPtr 小，把 lPtr 对应的数加入答案，并考虑它对逆序对总数的贡献为 rPtr 相对 RR 首位置的偏移 11（即右边只有一个数比 1212 小，所以只有它和 1212 构成逆序对），以此类推。

我们发现用这种「算贡献」的思想在合并的过程中计算逆序对的数量的时候，只在 lPtr 右移的时候计算，是基于这样的事实：当前 lPtr 指向的数字比 rPtr 小，但是比 RR 中 [0 ... rPtr - 1] 的其他数字大，[0 ... rPtr - 1] 的其他数字本应当排在 lPtr 对应数字的左边，但是它排在了右边，所以这里就贡献了 rPtr 个逆序对。

利用这个思路，我们可以写出如下代码。

 复杂度分析

记序列长度为 nn。

时间复杂度：同归并排序 O(n \log n)O(nlogn)。
空间复杂度：同归并排序 O(n)O(n)，因为归并排序需要用到一个临时数组。 

```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        if (nums.size()) {
            mergeS(nums, 0, nums.size()-1, ret);
        }
        return ret;
    }
    void mergeS(vector<int>& data, int L, int R, int &num) {
        if (L >= R) return;
        int M = L + (R - L) / 2;
        mergeS(data, L, M, num);
        mergeS(data, M+1, R, num);
        mergeC(data, L, M, R, num);
    }
    void mergeC(vector<int>& data, int L, int M, int R, int &num) {
        std::vector<int>arr(R-L+1,0);
        int i = L, j = M + 1, k = 0;
        while(i <= M && j <= R) {
            if (data[i] <= data[j]) { arr[k++] = data[i++]; }
            else { arr[k++] = data[j++]; num += (M - i + 1); }
        }
        while(i <= M) { arr[k++] = data[i++]; }
        while(j <= R) { arr[k++] = data[j++]; }
        for (int p=0; p<k; ++p) { data[L+p] = arr[p]; }
    }
};
```

