# 剑指 Offer 61. 扑克牌中的顺子

## 题目

&emsp;从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。


## 思路
 三件事

 * 首先将数组进行排序
 * 统计数组中0的个数
 * 最后统计排序之后的数组中相邻数字之间空缺的总数
 * 判断0的个数是否大于或者等于空缺总数

## 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());// 排序

        int king = 0;
        int gap = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                ++king;// 统计0的个数
            }

            if(i > 0 && nums[i] != 0 && nums[i] == nums[i - 1])
            {
                return false;// 遇到相同的数字
            }

            if(i > 0 && nums[i - 1] != 0 && nums[i] > nums[i - 1] + 1)
            {
                gap += nums[i] - nums[i - 1] - 1;// 计算空缺 记得减一
            }
        }


        return king >= gap;//判断0的个数是否大于空缺个数
    }
};

```
