# 剑指 Offer 59 - I. 滑动窗口的最大值

## 题目
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

## 思路

* 遍历给定数组中的元素，如果队列不为空且当前考察的元素大于等于队尾元素，则将队尾元素移除，直到队列为空或者当前考察元素小于新的队尾元素
* 当队首元素的下标小于滑动窗口的左侧边界Left表示队首元素已经不再属于滑动窗口，将其从队首元素移除
* 由于数组下标从0开始，因此当窗口的右边界right + 1>= k,意味着窗口已经形成。此时队首元素就是该窗口内的最大值。

## 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        if(nums.length == 0)
        {
            return new int[0];
        }
        
        // 窗口个数
        int[] res = new int[nums.length - k + 1];
        LinkedList<Integer> queue = new LinkedList<>();

        // 遍历数组中元素， right表示滑动窗口右边界
        for(int right = 0; right < nums.length; right++)
        {
            // 如果队列不为空 并且当前的元素大于或者等于队尾元素 将队尾元素移除
            // 直到 队列为空  或者当前的元素小于新的队尾元素
            while(!queue.isEmpty() && nums[right] >= nums[queue.peekLast()]){
                queue.removeLast();
            }

            // 存储元素下标
            queue.addLast(right);

            // 计算窗口左侧边界
            int left = right - k + 1;
            

            //当队首元素的下标小于滑动窗口左侧边界Left
            // 表示队首元素已经不再滑动窗口内部 将其从队首中移除

            if(queue.peekFirst() < left)
            {
                queue.removeFirst();
            }

            // 下边从0开始 所以当right + 1 >= k 说明滑动窗口已经形成  队首元素就是窗口的最大值
            if(right + 1 >= k)
            {
                res[left] = nums[queue.peekFirst()];// 将队首元素存储到res中
            }

        }
        return res;
    }
}

```




