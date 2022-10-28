# 剑指 Offer 49. 丑数

## 题目
&emsp;我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。


## 思路
&emsp;丑数只包含因子2,3,5,因此有“丑数 = 某较小丑数 x 某因子”

&emsp;丑数Xn+1只可能是以下三种情况之一：
    * Xn+1 = Xa * 2
    * Xn+1 = Xb * 3
    * Xn+1 = Xc * 5

丑数递推公式：下一个丑数就是这三种情况的最小值：

```Xn+1 = min(Xa x 2,Xb x 3, Xc x 5)```

## 代码
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0,b = 0,c = 0;
        int dp[n];
        dp[0] = 1;

        for(int i = 1; i < n; i++)
        {
            int n2 = dp[a] * 2;
            int n3 = dp[b] * 3;
            int n5 = dp[c] * 5;
            dp[i] = min(min(n2,n3),n5);

            if(dp[i] == n2) a++;
            if(dp[i] == n3) b++;
            if(dp[i] == n5) c++;

        }
        return dp[n - 1];
    }
};
```




