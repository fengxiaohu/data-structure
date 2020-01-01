# Balanced binary tree

a binary tree in which the left and right subtrees of every node differ in height by no more than 1

top-down method:

主要思想是根据平衡二叉树的定义，从顶至底进行深度优先遍历，递归判断当前节点左右子树高度是否小于1.

获取树高度的方法可递归求出，参照如何求二叉树高度方法。

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
    if(root==null) return true;
    int RightHeight,LeftHeight;
    RightHeight=depth(root.right);
    LeftHeight=depth(root.left);
    return Math.abs(RightHeight-LeftHeight)<=1&&isBalanced(root.right)&&isBalanced(root.left);
    }
    private int depth(TreeNode root)
    {
        if(root==null) return 0;
        return Math.max(depth(root.left),depth(root.right))+1;
    }
}
```

