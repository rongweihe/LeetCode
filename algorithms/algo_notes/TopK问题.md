
## 剑指 Offer 40. 最小的k个数

最小的k个数 - 大顶堆解法 https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

思路：
- 保持堆的大小为K，然后遍历数组中的数字，遍历的时候做如下判断：
- 若目前堆的大小小于K，将当前数字放入堆中。
- 否则判断当前数字与大根堆堆顶元素的大小关系，如果当前数字比大根堆堆顶还大，这个数就直接跳过；
- 反之如果当前数字比大根堆堆顶小，先poll掉堆顶，再将该数字放入堆中。
```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        std::vector<int> vec;
        if (k == 0) return vec;// 排除 0 的情况
        std::priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec.push_back(Q.top());
            Q.pop();
        }
        return vec;
    }
};
```
## 347. 前 K 个高频元素
https://leetcode-cn.com/problems/top-k-frequent-elements/

思路见代码

```c++
class Solution {
public:
    class MyCom {
        public:
            bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
                return lhs.second > rhs.second;
            }
    };
    // 小顶堆
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;//统计元素频率mp<num[i], 对应出现的次数>
        for (auto n : nums) {
            mp[n]++;
        }
        //对频率排序
        //定义一个小顶堆 存储元素pair类型 大小K
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, MyCom> pri_que;
        //用固定大小为K小顶堆扫描所有值
        for (const auto & m : mp) {
            pri_que.push(m);
            if (pri_que.size() > k) { 
                // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }
        std::vector<int> res(k);
        for (int i = k - 1; i >= 0; --i) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }//按 任意顺序 返回答案。
        return res;
    }
};
```
## 215.第K大元素 https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

```c++
int findKthLargest(vector<int>&nums, int k) {
  priority_queue<int, vector<int>, greater<int>>Q;
  for(auto& n : nums) {
    Q.push(n);
    if(Q.size() > k) Q.pop();
  }//建立一个大根堆，做 k - 1k−1 次删除操作后堆顶元素就是我们要找的答案
  return Q.top();
}
//手写最大堆排序
class Solution {
public:
    void makeHeapify(std::vector<int>&nums, int i, int heap_size) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heap_size && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heap_size && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            makeHeapify(nums, largest, heap_size);
        }
    }
    void buildMaxHeap(std::vector<int>&nums, int heap_size) {
        for (int i = heap_size / 2; i >= 0; --i) {
            makeHeapify(nums, i, heap_size);
        }//从叶子节点开始堆化
    }
    int findKthLargest(vector<int>&nums, int k) {
        int heap_size = nums.size();
        buildMaxHeap(nums, heap_size);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heap_size;
            makeHeapify(nums, 0, heap_size);
        }
        return nums[0];
    }
};
```
