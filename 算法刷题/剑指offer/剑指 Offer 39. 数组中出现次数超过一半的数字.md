# 剑指 Offer 39. 数组中出现次数超过一半的数字

## 题目

&emsp;数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。你可以假设数组是非空的，并且给定的数组总是存在多数元素。

## 思路

&emsp;我们使用哈希映射（HashMap）来存储每一个元素以及出现的次数。对于哈希映射中的每一个键值对，键表示一个元素，值表示该元素出现的次数。
我们使用一个循环遍历数组nums并将数组中的每一个元素加入哈希映射中，在这之后，我们遍历哈希映射中的所有键值对，返回最大的键。我们同样也可以在遍历数组Nums时候使用打擂台的方法，维护最大值，这样就不用遍历哈希表。


## 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counts;// 定义一个哈希表
        int majority = 0, cnt = 0;// cnt代表最大次数 初始化0   Majority表示出现次数最多的数字

        for(int num:nums){
            // 统计每一种数字出现的次数
            ++counts[num];// 该数字出现的次数 + 1
            if(counts[num] > cnt)
            {
                majority = num;// 表示 次数超过一半的数字
                cnt = counts[num]; // 记录下最大次数
            }
        }
        return majority; 
    }
};

```
