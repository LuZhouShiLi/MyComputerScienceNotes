# 剑指 Offer 66. 构建乘积数组

## 题目

&emsp;给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。



## 思路

```https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/```

* 初始化一个数组和原数组一样，b[0] = 1,声明一个辅助变量tmp = 1
* 计算b[i]的下三角各个元素的乘积，直接乘入b[i]
* 计算b[i]的上三角各元素的乘积，记为tmp,并乘入b[i]
* 返回b


## 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();
        if(length == 0)
        {
            return {};
        }
        vector<int> b(length,1); // 声明一个长度为length的向量 初始值都是1
        b[0] = 1;
        int tmp  = 1;

        // 自上而下计算下三角矩阵
        // 
        for(int i = 1; i < length; i++)
        {
            b[i] = b[i - 1] * a[i - 1];
        }

        for(int i = length -2; i >= 0; i--)
        {
            tmp *= a[i + 1];// 必须声明一个临时变量进行存储 不可以是 b[i] *= a[i+1]  
            b[i] *= tmp;
        }
        return b;
    }
};
```

