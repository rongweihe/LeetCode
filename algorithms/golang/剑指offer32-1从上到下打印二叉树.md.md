```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) ([]int) {
  if root == nil {
      return []int{}
  }
  q := []*TreeNode{root}
  res := []int{}
  for i:=0; i<len(q); i++ {
    p := q[i]
    res = append(res, p.Val)
    if p.Left != nil {
      q = append(q, p.Left)
    }
    if p.Right != nil {
      q = append(q, p.Right)
    }
  }
  return res
}
```

