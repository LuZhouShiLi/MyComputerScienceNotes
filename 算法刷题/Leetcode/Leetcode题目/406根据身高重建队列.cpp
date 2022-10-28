class Solution {
public:

    static bool compare(const vector<int> a,const vector<int> b){
        if(a[0] == b[0])  return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      // 本题就是想让你将顺序恢复（原来的顺序是打乱的） 
      // 区间问题，有两个维度，如何确定一个维度，然后再按照另一个维度重新排列
      // 将身高按照从大到小的顺序进行排列，然后确定k维度
      sort(people.begin(),people.end(),compare);// 按照指定规则进行排序

      vector<vector<int>> que;// 重新开辟一个二维数组
      // 身高高的先插入
      for(int i = 0; i < people.size(); i++)
      {
          int position = people[i][1];// 取出排序后每一个区间的第二个元素：k
          // 将k插入指定位置  前面有k个人 
          que.insert(que.begin() + position,people[i]);
      }
      
      return que;


    }
};
