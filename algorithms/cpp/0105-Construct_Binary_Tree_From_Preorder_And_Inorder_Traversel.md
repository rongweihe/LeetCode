

### 思路见代码

```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Create By @herongwei 2021/02/21
【题目描述】
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
【思路】
1、合法性判断;
2、分别储存前序中序的两个端点
3、创建根节点，根节点肯定是前序遍历的第一个数
4、找到中序遍历根节点所在位置
5、对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
   利用上述这点，对二叉树节点进行归并
6、递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点

细节

在中序遍历中对根节点进行定位时，一种简单的方法是直接扫描整个中序遍历的结果并找出根节点，但这样做的时间复杂度较高。
我们可以考虑使用哈希表来帮助我们快速地定位根节点。对于哈希映射中的每个键值对，键表示一个元素（节点的值），
值表示其在中序遍历中的出现位置。在构造二叉树的过程之前，我们可以对中序遍历的列表进行一遍扫描，就可以构造出这个哈希映射。
在此后构造二叉树的过程中，我们就只需要 O(1)的时间对根节点进行定位了。

*/
class Solution {
public:
    TreeNode* myBuildTree(vector<int>& pre,vector<int>& vin, int start_pre, int end_pre, int start_in, int end_in) {
        if (start_pre > end_pre) {
            return nullptr;
        }//合法性
        int pre_root = start_pre;
        int in_root = idx[pre[pre_root]];// 前序遍历中的第一个节点就是根节点
        TreeNode* root = new TreeNode(pre[pre_root]);//先把根节点建立出来
        
        int left_subtree_size = in_root - start_in;// 得到左子树中的节点数目
        
        root->left  = myBuildTree(pre, vin, start_pre+1, start_pre+left_subtree_size, start_in, in_root-1);// 递归地构造左子树，并连接到根节点
        root->right = myBuildTree(pre, vin, start_pre+left_subtree_size+1, end_pre, in_root+1, end_in);// 递归地构造右子树，并连接到根节点
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //合法性判断
        int len = inorder.size();
        if(len==0) return nullptr;
        for (int i=0; i<len; ++i) {
            idx[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, len-1, 0, len-1);
    }
private:
    std::unordered_map<int, int> idx;
};
```

**复杂度分析**

时间复杂度：O(n)，其中 n 是树中的节点个数。

空间复杂度：O(n)，除去返回的答案需要的 O(n)空间之外，我们还需要使用 O(n)的空间存储哈希映射，以及 O(h)（其中 h 是树的高度）的空间表示递归时栈空间。这里 h < n，所以总空间复杂度为 O(n)。
