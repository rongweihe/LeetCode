## BAT 常见十大面试算法整理初稿

**Author：https://github.com/rongweihe**

**Date：2019-04-09**

## 目录

[TOC]

# 问题【1】十大排序算法

###### 十大排序算法总结图

![十大排序算法总结图.PNG](https://i.loli.net/2019/04/11/5caf4bdcca035.png)

## 【1】冒泡排序

过程演示如下：
![](https://img-blog.csdnimg.cn/img_convert/2419b9aeeed52b1841c7240369932fc6.png)

下面代码中 `std::swap` 函数的源代码如下，可以看到有三个赋值操作:

```c++
template<class T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
```

```c++
void BubbleSort(int a[],int len){
    if(len <=1 ) {  return; }
    for(int i=0; i<len; ++i) {
        bool flag = false; //设定一个标记，若为false，则表示此次循环没有进行交换，也就是待排序列已经有序，排序已经完成。
        for(int j=0; j< len-i-1; ++j){
            if(a[j] > a[j+1]){   // 交换
                std::swap(a[j], a[j+1]);
                flag = true;   //表示有数据交换
            }
        }
        if(!flag) {   break;  }      //没有数据交集，提前退出
    }
    for (int i=0; i<len; ++i) {
        std::cout<<a[i]<<" ";
    }
}
```
另一种写法：
```c++
void BubbleSort(std::vector<int> &nums, int n) {
	if (n <= 1) return;
	bool is_swap;
	for (int i = 1; i < n; ++i) {
	    is_swap = false;
	    for (int j = 1; j < n - i + 1; ++j) {
		if (nums[j] < nums[j-1]) {
		    std::swap(nums[j], nums[j-1]);
		    is_swap = true;
		}
	    }
	    if (!is_swap) break;
	}
}
```

测试

```c++
int main() {
    int a[] = {34,66,2,5,95,4,46,27};
    BubbleSort(a,sizeof(a)/sizeof(int)); //cout => 2 4 5 27 34 46 66 95
    return 0;
}
```



## 【2】插入排序 

![](https://img-blog.csdnimg.cn/img_convert/501e151912911a38f122bb6d35d3e86a.png)

```c++
//插入排序：分为已排序和未排序 初始已排序区间只有一个元素 就是数组第一个 遍历未排序的每一个元素在已排序区间里找到合适的位置插入 并保证数据一直有序
void InsertSort(std::vector<int> &nums,int n) {
    if (n <= 1) return;
    for(int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums [j-1]; --j) {
            std::swap(nums[j],nums[j-1]);
        }
    }
}
```

测试

```c++
int main() {
    std::vector<int> nums = {4,6,5,3,2,1};
    InsertSort(nums,6);//cout => 1,2,3,4,5,6
    return 0;
}
```



## 【3】选择排序

![](https://img-blog.csdnimg.cn/img_convert/89ac014a09d70efa94bf3b525d7cd60a.png)

```c++
/*分已排序区间和未排序区间。每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾*/
void SelectSort(std::vector<int> &nums, int n) {
    if (n <= 1) return;
    int mid;
    for (int i = 0; i < n - 1; ++i) {
        mid = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mid]) {
                mid = j;
            }
        }
        std::swap(nums[mid],nums[i]);
    }
}
```

测试

```c++
int main() {
    std::vector<int> nums = {4,6,5,3,2,1};
    SelectSort(nums,6);//cout => 1,2,3,4,5,6
    return 0;
}
```
【时间,空间复杂度/是否稳定？】

首先，选择排序空间复杂度为 O(1)，是一种原地排序算法。选择排序的最好情况时间复杂度、最坏情况和平均情况时间复杂度都为 O(n )。你可以自己来分析看看。

那选择排序是稳定的排序算法吗？答案是否定的，选择排序是一种不稳定的排序算法。从图中，你可以看出来，选择排序每次都要找剩余未排序元素中的最小值，并和前面的元素交换位置，这样破坏了稳定性

【思考】冒泡排序和插入排序的时间复杂度都是 O(n )，都是原地排序算法，为什么插入排序要比冒泡排序更受欢迎呢？

【思路】冒泡排序不管怎么优化，元素交换的次数是一个固定值，是原始数据的逆序度。插入排序是同样的，不管怎么优化，元素移动的次数也等于原始数据的逆序度。但是，从代码实现上来看，冒泡排序的数据交换要比插入排序的数据移动要复杂，冒泡排序需要3 个赋值操作，而插入排序只需要 1 个。把执行一个赋值语句的时间粗略地计为单位时间，处理相同规模的数，插入排序比冒泡排序减少三倍的单位时间！

## 【4】快排

![](https://img-blog.csdnimg.cn/img_convert/b9b005a3f17299c44e8acb94cfc2ccb2.png)

手撕快排讲解：https://www.bilibili.com/video/BV1mE411M7SH

```c++
//快速排序：先找到一个枢纽；在原来的元素里根据这个枢纽划分 比这个枢纽小的元素排前面；比这个枢纽大的元素排后面；两部分数据依次递归排序下去直到最终有序
void QuickSort(int a[],int left,int right){
    if (left >= right) { return ; }
    int piv = a[left];
    int L=left,R=right;
    while( L<R ) {
        while(L<R && a[R]>=piv){ --R; } //从右向左找到第一个比 piv 小的元素 和最左边的进行替换
        if(L<R) { a[L++] = a[R]; }      //改成替换而不是交换 避免了不必要的交换
        while(L<R && a[L]<=piv){ ++L; } //从左向右找到第一个比 piv 大的元素 和最右边的进行替换
        if(L<R) { a[R--] = a[L]; }
    }
    a[L]=piv; //当 left 和right 会和之后，即找到了枢纽的位置时，再赋值回枢纽的值
    quickSort(a,left,L-1);//以L为中间值，分左右两部分递归调用
    quickSort(a,L+1,right);
}
```

测试

```c++
int main() {
    int a[] = {0,34,66,2,5,95,4,46,27};
    QuickSort(a, 0, sizeof(a)/sizeof(int));
    for(int i=0; i<=8; ++i) {
        std::cout<<a[i]<<" "; // print => 0 2 4 5 27 34 46 66 95
    }
    std::cout<<endl;
    return 0;
}
```

另一个写法
```C++
void QuickSort(std::vector<int> &nums,int l,int r) {
    if (l + 1 >= r) return;
    int first = l, last = r - 1 ,piv = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= piv) last--;//右指针 从右向左扫描 将小于piv的放到左边
        nums[first] = nums[last];
        while (first < last && nums[first] <= piv) first++;//左指针 从左向右扫描 将大于piv的放到右边
        nums[last] = nums[first];
    }
    nums[first] = piv;//更新piv
    quick_sort(nums, l, first);//递归排序
    quick_sort(nums, first + 1, r);
}
```

## 【5】归并排序

![](https://img-blog.csdnimg.cn/img_convert/f13bf55cb8c94e7d3d6fbc9ca0271f94.png)


```c++
/*
归并排序是一个稳定的排序算法
归并排序的时间复杂度任何情况下都是 O(nlogn)
归并排序不是原地排序算法
用两个游标 i 和 j，分别指向 A[p…q] 和 A[q+1…r] 的第一个元素。
比较这两个元素 A[i] 和 A[j]，如果 A[i]<=A[j]，我们
就把 A[i] 放入到临时数组 tmp，并且 i 后移一位，否则将 A[j] 放入到数组 tmp，j 后移一位。
*/
void mergeCount(int a[],int L,int mid,int R) {
    int *tmp = new int[L+mid+R];
    int i=L;
    int j=mid+1;
    int k=0;
    while( i<=mid && j<=R ) {
        if(a[i] < a[j])
            tmp[k++] = a[i++];
         else
            tmp[k++] = a[j++];
    }
    ///判断哪个子数组中有剩余的数据
    while( i<=mid )
        tmp[k++] = a[i++];
    while( j<=R)
        tmp[k++] = a[j++];
    /// 将 tmp 中的数组拷贝回 A[p...r]
    for(int p=0; p<k; ++p)
        a[L+p] = tmp[p];
    delete tmp;
}
void mergeSort(int a[],int L,int R) {
    ///递归终止条件 分治递归
    /// 将 A[L...m] 和 A[m+1...R] 合并为 A[L...R]
    if( L>=R ) { return; }
    int mid = L + (R - L)/2;
    mergeSort(a,L,mid);
    mergeSort(a,mid+1,R);
    mergeCount(a,L,mid,R);
}
```

测试

```c++
int main() {
    int a[] = {0,34,66,2,5,95,4,46,27};
    mergeSort(a, 0, sizeof(a)/sizeof(int));
    for(int i=0; i<=8; ++i) {
        std::cout<<a[i]<<" "; // print => 0 2 4 5 27 34 46 66 95
    }
    std::cout<<endl;
    return 0;
}
```



## 【6】堆排序

```c++
/*
优点：O(nlogn)，原地排序，最大的特点：每个节点的值大于等于(或小于等于)其子树节点
缺点：相比于快排，堆排序数据访问的方式没有快排友好；数据的交换次数要多于快排。
*/
void buildHeap(int a[], int n) {
    for(int i=n/2; i>=1; --i) {
    heapify(a, n, i);
    }
}
void heapify(int a[], int n, int i) {
  while (1) {
   		int maxPos = i;
   		if (i*2 <=n && a[i] < a[i*2]) { maxPos = i*2; }
   		if (i*2+1 <=n && a[maxPos] < a[i*2+1]) { maxPos = i*2+1; }
   		if (maxPos == i) break;
   		std::swap(a[i], a[maxPos]);
   		i = maxPos;
   }
}
```

###### 【7】桶排序

```c++
void bucketSort(std::vector<int>& nums) {
    if (nums.empty()) return ;
    int low = *std::min_element(nums.begin(), nums.end());
    int high = *std::max_element(nums.begin(), nums.end());
    int n = high - low + 1;
    std::vector<int> buckets(n);
    std::vector<int> res;
    for (auto x : nums) ++buckets[x - low];
    for (int i = 0; i < n; ++i) { //实现了按桶下标从小到达输出
        for (int j = 0; j < buckets[i]; ++j) { //重复的输出
            res.push_back(i + low);
        }
    }
    for (int i=0; i<res.size(); ++i) {
        std::cout<<res[i]<<" ";
    }
}
```

###### 【8】计数排序

```c++
/*
计数排序只能用在数据范围不大的场景中，如果数据范围 k 比要排序的数据 n 大
很多，就不适合用计数排序了。而且，计数排序只能给非负整数排序，如果要排序的数据是其他
类型的，要将其在不改变相对大小的情况下，转化为非负整数。
*/
void countSort(int *a,int n){
    int maxV=a[0];
    for(int i=1; i<n; ++i){
        maxV=max(maxV,a[i]);
    }
    int c[maxn];
    memset(c,0,sizeof(c));
    for(int i=0; i<n; ++i){
        c[a[i]]++;
    }
    for(int i=1; i<=maxV; ++i){
        c[i]+=c[i-1];
    }
    int r[maxn];
    memset(r,0,sizeof(r));
    // 计算排序的关键步骤，有点难理解
    /*
    我们从后到前依次扫描数组 A。比如，当扫描到 3 时，我们可以从数组 C 中取出下标为 3 的值
    7，也就是说，到目前为止，包括自己在内，分数小于等于 3 的考生有 7 个，也就是说 3 是数
    组 R 中的第 7 个元素（也就是数组 R 中下标为 6 的位置）。当 3 放入到数组 R 中后，小于等
    于 3 的元素就只剩下了 6 个了，所以相应的 C[3] 要减 1，变成 6。
    计数排序只能用在数据范围不大的场景中，如果数据范围 k 比要排序的数据 n 大
    很多，就不适合用计数排序了。而且，计数排序只能给非负整数排序，如果要排序的数据是其他
    类型的，要将其在不改变相对大小的情况下，转化为非负整数。
    */
    for(int i=n-1; i>=0; --i){
        int index = c[a[i]]-1;
        r[index]=a[i];
        c[a[i]]--;
    }
    for(int i=0; i<n; ++i){
        a[i]=r[i];
    }
}
```

###### 【9】基数排序

```c++
/*
基数排序对要排序的数据是有要求的，需要可以分割出独立的“位”来比较，而
且位之间有递进的关系，如果 a 数据的高位比 b 数据大，那剩下的低位就不用比较了。除此之
外，每一位的数据范围不能太大，要可以用线性排序算法来排序，否则，基数排序的时间复杂度
就无法做到 O(n) 了。
基数排序相当于通过循环进行了多次桶排序
*/
int getDigit(int x,int d){
    int t[]={1,1,10,100};
    return (x/t[d])%10;
}
void lsdRadixSort(int *a,int begin,int end,int d){
    const int radix = 10;
    int c[maxn];
    int bucket[maxn];
    for(int k=1; k<=d; ++k){
        memset(c,0,sizeof(c));
        for(int i=begin; i<=end; ++i){
            c[getDigit(a[i],k)]++;//计算i号桶里要放多少数
        }
        for(int i=1; i<radix; ++i) c[i]+=c[i-1];
        // 把数据依次装入桶（注意：装入时的分配技巧）
        for(int i=end; i>=begin; --i){
            int j=getDigit(a[i],k);//求出关键码的第k位的数值， 例如：576的第3位是5
            bucket[c[j]-1]=a[i];//放入对应的桶中(count[j]-1)表示第k位数值为j的桶底索引
            --c[j];//当前第k位数值为j的桶底边界索引减一
        }
        for(int i=begin,j=0;i<=end;++i,++j){// 从各个桶中收集数据
            a[i]=bucket[j];
        }
    }
}
```

#### 问题【2】: URL 翻转

URL 翻转例如将 www.baidu.com 转化成 www.udiab.moc
思路：以 . 为间隔分割单词，将每部分的单词翻转即可 时间复杂度O(n),空间复杂度O(1) 

```c++
void partialReverse(string &s)
{
    int i=0,begin,end;
    while(s[i]){
        if(s[i]!='.'){
            begin = i;//找到.的开始
            while(s[i] && s[i]!='.')i++;
            i--;
            end = i;//结尾
        }
        while(begin<end) swap(s[begin++],s[end--]);//将每部分的单词翻转即可
        i++;
    }
    cout<<"翻转之后的URL为"<<s<<endl;
}
```

#### 问题【3】:最长公共子串+最长公共子序列

时间复杂度O(n^2),空间复杂度O(m*n) 最长公共子串是最长公共子序列的严格版。要求
是连续的，所以如果X[i-1] == Y[j-1]，则更新最大值 其它情况不更新。 

最长公共子序列 样例输入：ABCDGH ACDFHR 样例输出 4(ACDH) 

最长公共子串 样例输入：
ABCDGH ACDFHR 样例输出 2(CD) 

```c++
//最长公共子序列
int longCommonSubseq(string &X, string &Y, int m,int n ){
    int L[m+1][n+1];
    for (int i=0; i<=m; ++i){
        for (int j=0; j<=n; ++j){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}
//最长公共子串
int longCommonSubstr(string &X, string &Y,int m,int n){
    int L[m+1][n+1];
    int ret = 0;
    for (int i=0; i<=m; ++i){
        for (int j=0; j<=n; ++j){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
                ret = max(L[i][j], ret);
            }
            else L[i][j] = 0;
        }
    }
    return ret;
}
```

#### 问题【4】:括号匹配 

思路：定义一个char类型的栈，
循环一遍，遇到左括号的入栈，遇到右括号比较此时栈顶元素是否对应 的左括号，
即判断是否匹配，匹配则弹出栈元素，直到最后栈元素为空说明整个括号匹配，否
则不匹配。 时间复杂度O(n),空间复杂度O(1) 

样例输入： [({})] ()[]{} ([)] 样例输出：1 1 0 

```c++
bool isStrMatch(string &s){
    int len = s.size();
    std::stack<char>sta;
    for(int i=0; i<len; ++i){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') sta.push(s[i]);
        else if(sta.size()>0 && ( (s[i]==')' && sta.top()=='(') || (s[i]=='}' && sta.top()=='{') || (s[i]==']' && sta.top()=='[')))
            sta.pop();
        else return false;
    }
    return sta.size() == 0;
}
```

#### 问题【5】求最大连续子数组和 

思路：定义三个变量，
curSum表示当前的累加和；ret表示当前这段区间临时最大值；maxSum表示所有
ret 的最大值，也就是最后的结果。 时间复杂度O(n),空间复杂度O(1) 

```c++
int maxSubSum(int *a){
    int ret    = INT_MIN;
    int curSum = 0;
    int maxSum =INT_MIN;
    int minSum =INT_MIN;
    for(int i=0; i<n; ++i){
        minSum = max(minSum,a[i]);//全部为负数的情况取最大的那个负数
        curSum +=a[i];
        if(curSum > ret){
            ret = curSum;
            maxSum = max(maxSum,ret);
        }
        if(curSum < 0)
            curSum = 0;
    }
    if(maxSum == INT_MIN) maxSum = minSum;
    printf("连续最大子数组和为=%d\n",maxSum);
}
```

#### 问题【6】手写C各种函数

```c++
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
//把 src 所指向的字符串复制到 dest，注意：dest定义的空间应该比src大。
char* strcpy(char *dest,const char *src)
{
    char *ret = dest;
    assert(dest!=NULL);//优化点1：检查输入参数
    assert(src!=NULL);
    while(*src!='\0')
        *(dest++)=*(src++);
    *dest='\0';//优化点2：手动地将最后的'\0'补上
    return ret;
}
//考虑内存重叠的字符串拷贝函数 优化的点
char* strcpy(char *dest,char *src)
{
    char *ret = dest;
    assert(dest!=NULL);
    assert(src!=NULL);
    memmove(dest,src,strlen(src)+1);
    return ret;
}
//把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
char* strcat(char *dest,const char *src)
{
    //1. 将目的字符串的起始位置先保存，最后要返回它的头指针
    //2. 先找到dest的结束位置,再把src拷贝到dest中，记得在最后要加上'\0'
    char *ret = dest;
    assert(dest!=NULL);
    assert(src!=NULL);
    while(*dest!='\0')
        dest++;
    while(*src!='\0')
        *(dest++)=*(src++);
    *dest='\0';
    return ret;
}
//把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
//该函数返回值如下：
//如果返回值 < 0，则表示 str1 小于 str2。
//如果返回值 > 0，则表示 str1 大于 str2。
//如果返回值 = 0，则表示 str1 等于 str2。
int strcmp(const char *s1,const char *s2)
{
    assert(s1!=NULL);
    assert(s2!=NULL);
    while(*s1!='\0' && *s2!='\0')
    {
        if(*s1>*s2)
            return 1;
        else if(*s1<*s2)
            return -1;
        else
        {
            s1++,s2++;
        }
    }
    //当有一个字符串已经走到结尾
    if(*s1>*s2)
        return 1;
    else if(*s1<*s2)
        return -1;
    else
        return 0;
}
//在字符串 str1 中查找第一次出现字符串 str2 的位置，不包含终止符 '\0'。
char* strstr(char *str1,char *str2)
{
    char* s = str1;
    assert(str1!='\0');
    assert(str2!='\0');
    if(*str2=='\0')
        return NULL;//若str2为空，则直接返回空
    while(*s!='\0')//若不为空，则进行查询
    {
        char* s1 = s;
        char* s2 = str2;
        while(*s1!='\0'&&*s2!='\0' && *s1==*s2)
            s1++,s2++;
        if(*s2=='\0')
            return str2;//若s2先结束
        if(*s2!='\0' && *s1=='\0')
            return NULL;//若s1先结束而s2还没结束，则返回空
        s++;
    }
    return NULL;
}
//模拟实现memcpy函数 从存储区 str2 复制 n 个字符到存储区 dst。
void* memcpy(void* dest, void* src, size_t num)
{
    void* ret = dest ;
    size_t i = 0 ;
    assert(dest != NULL ) ;
    assert(src != NULL) ;
    for(i = 0; i<num; i++)
    {
        //因为void* 不能直接解引用，所以需要强转成char*再解引用
        //此处的void*实现了泛型编程
        *(char*) dest = *(char*) src ;
        dest = (char*)dest + 1 ;
        src = (char*) src + 1 ;
    }
    return ret ;
}
//考虑内存重叠的memcpy函数 优化的点
void* memmove(void* dest, void* src, size_t num)
{
    char* p1 = (char*)dest;
    char* p2 = (char*)src;
    if(p1<p2)//p1低地址p2高地址
    {
        for(size_t i=0; i!=num; ++i)
            *(p1++) = *(p2++);
    }
    else
    {
        p1+=num-1;
        p2+=num-1;
        for(size_t i=0; i!=num; ++i)
            *(p1--) = *(p2--);
    }
    return dest;
}
```

#### 问题【7】字符串中找出出现次数最少的第一个字符，写完存到Hashmap里面

思路： HashMap
时间复杂度O(n),空间复杂度O(1)

```c++
String str = "aaaaaaaaabbbbbbbbbbbbbbbbbbbbbcccddddddddeffg";
char[] charArray = str.toCharArray();
Map<Character,Integer> map = new HashMap<Character,Integer>();
for(char c : charArray)
{
    if(map.containsKey(c))
    {
        map.put(c, map.get(c)+1);
    }
    else
    {
        map.put(c, 1);
    }
}

Set<Entry<Character, Integer>> entrySet = map.entrySet();
Comparator<Entry<Character, Integer>> cr = new Comparator<Map.Entry<Character,Integer>>()
{
    @Override
    public int compare(Entry<Character, Integer> o1, Entry<Character, Integer> o2)
    {
        if(o1.getValue() < o2.getValue())
        {
            return 1;
        }
        else if(o1.getValue() == o2.getValue())
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
};
List<Entry<Character, Integer>> list = new ArrayList<Entry<Character, Integer>>(entrySet);
Collections.sort(list, cr);
Entry<Character, Integer> e = list.get(list.size()-1);
System.out.println("出现次数最少的字符:::"+e.getKey());
System.out.println("出现次数:::"+e.getValue());
```

#### 问题【8】最长无重复子串 

思路： HashMap + 滑动窗口
时间复杂度O(n),空间复杂度O(n)

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
```

#### 问题【9】IP合法性判断 

```c++
bool isIpFormatRight(char *ipAddress)
{
    //判断IP地址是否合法
    int a,b,c,d;
    if ((sscanf(ipAddress,"%d.%d.%d.%d",&a,&b,&c,&d)==4)
            &&(a>=0&&a<=255)
            &&(b>=0&&b<=255)
            &&(c>=0&&c<=255)
            &&(d>=0&&d<=255))
    {
        puts("合法");
    }
    puts("不合法");
}
```

#### 问题【10】求一个 数二进制 1 位数

思路：把一个整数减去1，再和原整数做与运算，会把该整数左右边的一个1变为0.因此该整数的二进制表示中有多少个1，就可以进行多少次这样的操作。运算次数与输入n的大小无关，只与n中1的个数有关。如果n的二进制表示中有k个1，那么这个方法只需要循环k次即可。

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0)
        {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};
```



