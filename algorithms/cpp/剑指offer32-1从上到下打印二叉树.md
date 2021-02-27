官方思路：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/mian-shi-ti-32-i-cong-shang-dao-xia-da-yin-er-ch-4/

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
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<int> vec;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* p = q.front(); q.pop();
            vec.push_back(p->val);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        return vec;
    }
};
```

