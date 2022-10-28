# 剑指 Offer 48. 最长不含重复字符的子字符串

## 题目
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

## 思路

* 设状态数组dp,dp[j]代表以字符s[j]为结尾的“最长不重复子字符串”的长度
* 转移方程：固定右边界j,设字符s[j]左边距离最近的相同字符为s[i],即s[i] = s[j]
* 当i < 0，即s[j]左边无相同字符，则dp[j] = dp[j - 1] + 1；当dp[j - 1] < j - i, 说明字符s[i]在子字符串dp[j - 1]区间之外，则dp[j] = dp[j - 1] + 1;当dp[j - 1] >= j - i,说明字符s[i]在字符串dp[j - 1]区间之内，则dp[j]的左边界由s[i]决定，即dp[j] = j - i;

* 返回max(dp)

## 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> dic = new HashMap<>();// 定义一个哈希表
        int res = 0,tmp = 0;

        for(int j = 0; j < s.length(); j++)
        {
            int i = dic.getOrDefault(s.charAt(j),-1);// s.charAt(j)获得的是当前位置的字符，然后从哈希表中查找该字符上一次出现的位置
            // 将该字符位置存入哈希表
            dic.put(s.charAt(j),j);// 更新哈希表

            // 计算当前位置和上一次出现的位置之差 和tmp（tmp是前一个字符的最长子字符串长度）进行比较
            // 这里进行更新当前字符的最长子字符串长度
            if(tmp < j -i)
            {
                tmp = tmp + 1;
            }
            else
            {
                tmp = j - i;
            }
            // 更新res
            res = Math.max(res,tmp);// max(dp[j - 1],dp[j])
        }
        return res;
    
    }
}

```
