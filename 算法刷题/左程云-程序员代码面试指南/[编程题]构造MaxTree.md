# [编程题]构造MaxTree


## 题目

对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，那么它就是树根。请证明这个方法的正确性，同时设计O(n)的算法实现这个方法。

给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。

## 思路

* 维持两个数组，一个保存每一个元素左边比自己大最多数的下标
* 另一个保存右边比自己大最多的数的下标
* 然后依次比较左数组和右数组  如果一个是-1 另一个是大于0的数  那么父亲节点就是大于等于0的那个数
* 如果两个都是-1 说明这个数就是二叉树的根节点  如果都是大于0的数字  选择其中一个比较小的数字作为根节点

## 代码
```cpp
class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
        // 思路：维持两个数组，一个保存每一个元素左边比自己大最多数的下标
        // 另一个保存右边比自己大最多的数的下标
        // 然后依次比较左数组和右数组  如果一个是-1 另一个是大于0的数  那么父亲节点就是大于等于0的那个数
        // 如果两个都是-1 说明这个数就是二叉树的根节点  如果都是大于0的数字  选择其中一个比较小的数字作为根节点
        vector<int> ret(n,-1);
        vector<int> lp(n,-1);
        vector<int> rp(n,-1);
        stack<int> s;// 设置单调栈

        for(int i = 0; i < n; i++)
        {
           // 从左边开始遍历
           // 使用单调栈 查找左边大最多的数字
            while(!s.empty() && A[i] > A[s.top()])
            {
                s.pop();// 将比自己小的数字直接pop出
            }
            
            // 找到一个比A[i] 大的数据
            if(!s.empty())
            {
                lp[i] = s.top();// 记录下比自己大的数据
            }
            s.push(i);// 下标入栈
        }
        
        // 清空单调栈
        while(!s.empty())
        {
            s.pop();// 出栈
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            // 从右边寻找比自己大的数据
            while(!s.empty() && A[i] > A[s.top()])
            {
                s.pop();
            }
            
            if(!s.empty())
            {
                rp[i] = s.top();
            }
            
            s.push(i);
        }
        
        
        for(int i = 0; i < n; i++)
        {
            // 遍历lp rp 比较每一个元素  去最大的元素 送入ret
            if(lp[i] >= 0 && rp[i] >= 0)
            {
                // 小的元素 
                ret[i] = A[lp[i]] < A[rp[i]] ? lp[i]:rp[i];
            }
           
            if(lp[i] >= 0 && rp[i] == -1)
            {
                // 其中一个是-1 直接选lp[i]
                ret[i] = lp[i];
            }
            else if(rp[i] >= 0 && lp[i] == -1)
            {
                ret[i] = rp[i];
            }
            
        }
        return ret;
    }
};

```

