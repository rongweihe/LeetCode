思路
1、之字打印二叉树，设置 odd 变量表示当前需要打印的是那一层。
2、如果是奇数层，从队列头部打印数据，从尾部加入数据，并且从左子树开始添加。
3、如果是偶数层，从队列尾部打印数据，从头部加入数据，并且从右子树开始添加。
4、每次打印数据，只需要打印未添加子树节点前的队列数据，这样在添加子树节点的时候不会对结果造成影响。

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
  if root == nil {
    return nil
  }
  list := list.New()
  list.PushBack(root)
  odd := 0
  var res [][]int
  for list.Len() >0 {
    var tmp []int
    size := list.Len()
    if odd % 2 ==0 {
      for i:=0; i<size; i++ {
        node := list.Remove(list.Front()).(*TreeNode)
        tmp = append(tmp, node.Val)
        if node.Left != nil {
          list.PushBack(node.Left)
        }
        if node.Right != nil {
          list.PushBack(node.Right)
        }
      }
    } else {
      for i:=0; i<size; i++ {
        node := list.Remove(list.Back()).(*TreeNode)
        tmp = append(tmp, node.Val)
        if node.Right != nil {
          list.PushFront(node.Right)
        }
        if node.Left != nil {
          list.PushFront(node.Left)
        }
      }
    }
    odd ++
    res = append(res, tmp)
  }
  return res
}
```

