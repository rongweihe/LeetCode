求 root 的最大深度，那么就需要求出 left 的最大深度，以及 right 的最大深度。
把 root 替换成 left 或 right 又会再重复上面的步骤。 递归实现。

代码

```c++ 
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
```