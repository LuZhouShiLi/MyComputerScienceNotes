# 剑指 Offer 38. 字符串的排列

## 题目
&emsp;输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

## 思路

* 当x = len(c) - 1时，代表所有位都已经固定，则将当前组合c转换为字符串并加入res
* x从0开始，固定x,开始向后面遍历
* 初始化set，用于排除重复的字符，将第x位字符与后面的所有字符分别进行交换，并进入下层递归
  * 若c[i]在set中，代表其是重复字符，因此直接跳过该字符
  * 将c[i]加入set中，以便之后遇到重复字符然后去重
  * 固定字符，将字符c[i]和c[x]交换，即固定c[i]为当前位字符
  * 开启下层递归，调用dfs(x + 1),即开始固定第x + 1个字符
  * 还原交换，将字符c[i] 和c[x]交换
  
## 代码

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s,0);// 深度优先遍历  先从第0位开始遍历
        return res;
    }

private:
    vector<string> res;// 存储结果数组
    void dfs(string s,int x){

        // 这时候说明所有位已经固定，将当前组合c转化为字符串并加入res
        if(x == s.size() - 1)
        {
            res.push_back(s);// 添加排列方案
            return;
        }

        set<int> st;// 初始化一个set 用于排除重复的字符

        for(int i = x; i < s.size(); i++)
        {
            // 固定第i位 
            if(st.find(s[i]) != st.end())
            {
                // 当发现s[i] 存在时，说明下面的排列都是重复的  直接跳过s[i]
                continue;// 重复
            }

            // 如果set中没有s[i]元素，那么先插入set中
            st.insert(s[i]);  // 
            swap(s[i],s[x]); // 交换，将s[i]固定在第x位
            dfs(s,x + 1);// 之后  固定下一位字符  然后深度优先遍历
            swap(s[i],s[x]);// 还原交换
        }
    }
};

```

