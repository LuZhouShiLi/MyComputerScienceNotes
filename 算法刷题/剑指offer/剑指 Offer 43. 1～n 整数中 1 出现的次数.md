# 剑指 Offer 43. 1～n 整数中 1 出现的次数

## 题目
&emsp;输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

## 思路

```
https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/python3si-lu-dai-ma-10fen-zhong-jiang-qi-9btr/
```

## 代码

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        // 3101592 将数字拆分成 [a...][cur][b...]
        // cur是当前位
        long base = 1;
        int res = 0;

        while(base <= n)
        {
            // 计算a... cur... b...
            int a,cur,b;
            // 对于 3101 5 92  cur = 5
            // 将每一部分单独拿出来 这里举的例子base = 100
            a = n / base / 10;
            cur = (n / base) % 10;
            b = n % base;

            // 将当前位设置1 考察其他部分的变化范围
            if(cur > 1)
            {
                // [3101]5[92]
                // a: 0000 - 3101  b:00 - 99
                res += (a + 1) * base;
            }
            else if(cur == 1)
            {
                // 310 1 592
                // 第一部分 000-309   000-999
                // 第二部分 310   0- 592
                // 总个数：a * base + (b + 1)
                res += a * base + b + 1;
            }
            else{
                // cur < 1
                // 31 0 1592
                // 00-30 0000-9999
                // 总个数 a * base
                res += a * base;
            }
            // 统计更高一位
            base *= 10;
        }
        return res;
    }
};
```
