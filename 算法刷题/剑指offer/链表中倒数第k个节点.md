# 剑指Offer 22.链表中倒数第K节点

## 题目
![图 2](../../images/39e4384980ff7c855aa1bc647669cbb3f2c3b87ac520dd09e75b08ecdc7c400e.png)  

## 思路
* 初始化一个前指针former和一个后指针latter，两个指针都指向头节点head
* 前指针先向前走K步，（结束之后，双指针former和latter间相距k步）
* 之后两个指针同时进行移动，former和latter都向前走一步，直到former指向空，那们此时Latter和尾节点相差k - 1步，也就是指向倒数第k个节点。

## 代码
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode former = head;
        ListNode latter = head;

        // 第一个指针先走k步
        for(int i = 0; i < k; i++)
        {
            if(former == null)
            {
                return null;
            }
            former = former.next;
        }

        // 那么第一个指针与第二个指针相差k步 因为此时第一个指针former在 k + 1位置  latter还在第一个位置

        // 当第一个指针跳出之后  former指向空 那么latter和former相差k步，那们也就是和尾部节点相差k - 1步
        while(former != null)
        {
            // 将第一个指针移动到链表尾部
            former = former.next;
            latter = latter.next;
        }
        return latter;
    }
}
```


