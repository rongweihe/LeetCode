## 题目 

https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/

给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 思路

参考卡神思路：https://programmercarl.com/0112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.html#%E9%80%92%E5%BD%92

代码

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathRet.clear();
        path.clear();
        if (!root) return pathRet;
        path.push_back(root->val);
        dfs(root, sum - root->val);
        return pathRet;
    }
private:
    std::vector<vector<int>> pathRet;
    std::vector<int> path;
    void dfs(TreeNode* cur, int sum) {
        if (!cur->left && !cur->right && sum == 0) {
            pathRet.push_back(path);
            return;
        }
        if (!cur->left && !cur->right) {
            return;
        }
        if (cur->left) {
            path.push_back(cur->left->val);
            sum -= cur->left->val;
            dfs(cur->left, sum);
            sum += cur->left->val;
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            sum -= cur->right->val;
            dfs(cur->right, sum);
            sum += cur->right->val;
            path.pop_back();
        }
        return;
    }
};
```
