class Solution {
public:
    vector<int> partitionLabels(string s) {
            // 同一个字母最多出现在一个片段中
            // 等价于 任意字符串中的任意字母不在其他字符串中出现 
            // 标记一个字母的起始位置 然后找终止位置  确定最后出现位置

            // 那么，我们需要遍历字符串的所有字母  找到一个字母的最大终止位置，那么以这个字母的起始，终止位置就是一个片段

           int a[26] = {0};//   该数组用于记录每一个字母最后出现的位置
            // abcdaef
           for(int i = 0; i < s.size(); i++)
           {
               // 按照26个字母的顺序更新 字符串中每一个字母的最后出现位置
               a[s[i] - 'a'] = i;
           }
           // 那么a[0] 是a字母最后出现的位置  a[1] 是b字母最后出现的位置 a[2] 是c字母最后出现的位置
           vector<int> result;
           int start = 0;
           int end = 0;// 表示符合要求的片段的结束索引

            // S = "ababcbacadefegdehijhklij"
           for(int i = 0; i < s.size(); i++)
           {
               // 遍历字符串不断更新end
               if(end < a[s[i] - 'a'])
               {
                   end = a[s[i] - 'a'];
                   // 更新end  end这里是对照上面的a数组,从头开始
                   // 获取一个字母的最大位置 a数组已经记录了abcdef.. 顺序每一个字母的最后位置
               }

                // 第一次搜到a的时候，end被更新了一次  在第一个a到最后一个a之间的所有字母的end都不会更新
                // 这就导致搜索a最后位置的时候 i == end 这就是一个片段
                // 那么，如果a和a之间有个b 他的end比a的end大 那么很显然 end会更新  直到搜索到b的end
               if(i == end)
               {
                   result.push_back(i - start + 1);// 将该字母的长度push
                   start = i+ 1;// 下一个字母开始片段
               }
           }

           return result;
    }
};