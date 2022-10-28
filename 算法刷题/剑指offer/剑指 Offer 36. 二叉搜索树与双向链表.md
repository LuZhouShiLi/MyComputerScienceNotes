# 剑指 Offer 36. 二叉搜索树与双向链表

## 题目
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

## 思路

* 中序遍历，先递归左子树dfs(cur->left);
* 当pre为空时，说明此时，此时正在访问链表的头节点head
* 保存cur：更新pre = cur,即节点cur是后继节点的pre
* 递归右子树，即dfs(cur.right);

## 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;// 空树
        // 递归
        dfs(root);
        // 连接 循环双向链表
        // pre指向尾节点
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *pre,*head;// 私有化两个指针：指向前驱节点，头节点
    void dfs(Node *cur)
    {
        // cur是当前节点
        if(cur == nullptr) return;
        // 中序遍历  先遍历左子树
        dfs(cur->left);

        // 左子树遍历完毕之后，左子树已经变成一个循环双向链表 链表尾部是一个最大值
        if(pre != nullptr)  pre->right = cur;// 连接根节点
        else head = cur;// 说明cur左侧没有节点了  说明cur为头节点
        cur->left = pre;// 指向前面的链表
        pre = cur;//更新前驱节点
        dfs(cur->right);// 递归遍历右子树
    }    
};

```


