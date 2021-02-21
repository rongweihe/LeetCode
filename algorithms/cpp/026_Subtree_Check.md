思路见代码

```c++
class Solution {
  public:
  	bool isSubStructure(TreeNode* A, TreeNode* B) {
      if (A == nullptr || B == nullptr) {
        return false;
      }
      return isSubtreeWithRoot(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right,B);
    }
  	bool isSubtreeWithRoot(TreeNode* A, TreeNode* B) {
      if (B == nullptr) {	return true;	}//子树分支短先匹配完
      if (A == nullptr) {	return false;	}
      if (A->val != B->val) {	return false;	}
      return isSubtreeWithRoot(A->left, B->left) && isSubtreeWithRoot(A->right, B->right);
    }
};
```

![image-20210221164359994](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/LeetCode/image-20210221164359994.png)