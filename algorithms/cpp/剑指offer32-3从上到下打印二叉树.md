利用双端队列的两端皆可添加元素的特性，设打印列表（双端队列） `tmp` ，并规定：

- 奇数层 则添加至 `tmp` **尾部** ，
- 偶数层 则添加至 `tmp` **头部** 。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return  {};
        std::vector<std::vector<int>> res;
        std::deque<TreeNode*>d;
        d.push_front(root);
        int odd = 0;
        while(!d.empty()) {
            int size = d.size();
            std::vector<int>v;
            while(size--) {
                if (odd %2 ==0) {
                    TreeNode* tmp = d.front();
                    d.pop_front();
                    v.emplace_back(tmp->val);
                    if (tmp->left) d.push_back(tmp->left);
                    if (tmp->right) d.push_back(tmp->right);
                } else {
                    TreeNode* tmp = d.back();
                    d.pop_back();
                    v.emplace_back(tmp->val);
                    if (tmp->right) d.push_front(tmp->right);
                    if (tmp->left) d.push_front(tmp->left);
                }
            }
            ++odd;
            res.emplace_back(v);
        }
        return res;
    }
};
```

