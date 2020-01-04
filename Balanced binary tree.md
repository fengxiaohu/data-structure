# Balanced binary tree

a binary tree in which the left and right subtrees of every node differ in height by no more than 1

## top-down method:

主要思想是根据平衡二叉树的定义，从顶至底进行深度优先遍历（DFS），递归判断当前节点左右子树高度是否小于1.

获取树高度的方法可递归求出，参照如何求二叉树高度方法。

- 从顶至底DFS，以每个节点为根节点，递归判断是否是平衡二叉树：
  若所有根节点都满足平衡二叉树性质，则返回 True ；
  若其中任何一个节点作为根节点时，不满足平衡二叉树性质，则返回False。

最差情况下算法时间复杂度为O（N^2）

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

## Bottom up

对二叉树做深度优先遍历DFS，递归过程中：
终止条件：当DFS越过叶子节点时，返回高度0；
返回值：
从底至顶，返回以每个节点root为根节点的子树最大高度(左右子树中最大的高度值加1max(left,right) + 1)；
当我们发现有一例 左/右子树高度差 ＞ 1 的情况时，代表此树不是平衡树，返回-1；
当发现不是平衡树时，后面的高度计算都没有意义了，因此一路返回-1，避免后续多余计算。
最差情况是对树做一遍完整DFS，时间复杂度为 O(N)。



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
        if(depth(root) != -1) return true;
        else return false;
        
    }
    private int depth(TreeNode root)
    {
        if(root == null)return 0;
        int left_height = depth(root.left);
        int right_height = depth(root.right);
        if(left_height==-1)return -1;
        if(right_height==-1)return -1;
        if(Math.abs(right_height-left_height)<2)
        return Math.max(left_height,right_height)+1;
        else
        return -1;
        
    }
}
```

