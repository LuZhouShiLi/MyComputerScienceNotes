# 剑指Offer27.二叉树的镜像

## 题目

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

## 思路

&emsp;我们从根节点开始，递归地对树进行遍历，并从叶子节点先开始翻转得到镜像，如果当前遍历得到的节点root的左右子树都已经翻转得到镜像，那么我们就只需要交换两个子树的位置即可。


## 代码

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
    public TreeNode mirrorTree(TreeNode root) {
        if(root == null)
        {
            return null;
        }

        // 递归遍历左右子树 从叶子节点先开始翻转得到镜像
        TreeNode leftRoot = mirrorTree(root.right);
        TreeNode rightRoot = mirrorTree(root.left);
        
        // 以root为根节点的左右子树都已经翻转得到镜像，那么我们只需要交换两颗子树的位置

        root.left = leftRoot;
        root.right = rightRoot;
        return root;
    }
}

```

