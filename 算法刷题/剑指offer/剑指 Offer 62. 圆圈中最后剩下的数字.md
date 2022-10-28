# 剑指 Offer 62. 圆圈中最后剩下的数字

## 题目

0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

## 思路

* 创建一个list 模拟环形链表
* 将元素全部添加到list中
* 每次取m步。删除元素，注意取余操作


## 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        // 创建一个环形链表模拟圆圈
        ArrayList<Integer> list = new ArrayList<>(n);
        for(int i = 0; i < n; i++)
        {
            list.add(i);
        }
        int idx = 0;
        while(n > 1)
        {
            idx = (idx + m - 1) % n;// 每次走M步 取余 因为是环形
            list.remove(idx);
            n--;
        }
        return list.get(0);
    }
}

```
