# 剑指 Offer 45. 把数组排成最小的数

## 题目
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

## 思路
&emsp;字符串排序问题，设数组nums中任意两个数字的字符串为x和y,则排序的判断规则是：

* x + y > y + x,则x大于y
* x + y < y + x, 则x 小于y

然后将数字列表转换为字符串数组，使用快速排序对字符串数组进行排序，（排序的主要目的其实就是将高位的数字尽可能变小，大的数字放在低位上），最后将字符串数组中的字符串拼接成一个数字字符串。

## 代码

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        // 将数字转化为字符串并保存
        for(int i = 0; i < nums.size(); i++)
        {
            strs.push_back(to_string(nums[i]));
        }
        // 快速排序 
        quickSort(strs,0,strs.size() - 1);
        // 将最小的组合  放进字符串
        string res;
        for(string s:strs)
        {
            res.append(s);
        }
        return res;
    }

private:
    void quickSort(vector<string>& strs,int l,int r)
    {
        if(l >= r)
        {
            return;
        }
        int i = l,j = r;
        while(i < j)
        {
            // 比较字符串大小  找到jl < lj停止  
            // 为什么和l 因为l是数字的最大位！
            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j)
            {
                j--;
            }
            
            // il > li 停止  找到数值大的 放后面
            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j)
            {
                i++;
            }
            // 交换 使得高位数字变小  低位数字变大  总体变小
            swap(strs[i],strs[j]);
        }

        swap(strs[i],strs[l]);
        quickSort(strs,l,i - 1);
        quickSort(strs,i + 1, r);

    }

};
```
