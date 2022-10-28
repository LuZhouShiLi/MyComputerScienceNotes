class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //  数组长度最小为1  不需要判空

        //  题目要求最少需要移除区间的个数  一般都是贪心算法
        // 也就是 要让互不重叠的区间个数最多  那么重叠的区间个数最少！
        
        // 保留不重叠的区间，如果选择的区间结尾越小，那么这个区间和其他区间相互重叠的可能性越小，不重叠个数越多
        
        int n = intervals.size();

        // 按照区间的结尾从小到大的顺序排序
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){return a[1] < b[1];});

        int removed = 0,prev = intervals[0][1];// 取出 第一个区间的结尾

        for(int i = 1; i < n; i++)
        {
            // 取出后面一个区间的开始  如果比第一个区间的结尾小  说明 重叠
          if(intervals[i][0] < prev)
          {
              removed++;
          }  
          else{
              prev = intervals[i][1];// 如果不重叠 更新prev
          }
        }
        return removed;

    }
};