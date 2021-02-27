算法流程：

- 特例处理： 当根节点为空，则返回空列表 [] ；
- 初始化： 打印结果列表 res = [] ，包含根节点的队列 queue = [root] ；
- BFS 循环： 当队列 queue 为空时跳出；
  - 新建一个临时列表 tmp ，用于存储当前层打印结果；
  - 当前层打印循环： 循环次数为当前层节点数（即队列 queue 长度）；
  - - 出队： 队首元素出队，记为 node；
    - 打印： 将 node.val 添加至 tmp 尾部；
    - 添加子节点： 若 node 的左（右）子节点不为空，则将左（右）子节点加入队列 queue ；
    - 将当前层结果 tmp 添加入 res 。
      返回值： 返回打印结果列表 res 即可。

链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/mian-shi-ti-32-ii-cong-shang-dao-xia-da-yin-er-c-5/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
     	std::vector<vector<int>> res;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
          	int size = q.size();
          	std::vector<int> tmp;
          	for (int i=0; i<size; ++i) {
              TreeNode* p = q.front(); q.pop();
              tmp.push_back(p->val);
              if (p->left) q.push(p->left);
              if (p->right) q.push(p->right);
            }
          	res.emplace_back(tmp);
        }
        return res;
    }
};
```

