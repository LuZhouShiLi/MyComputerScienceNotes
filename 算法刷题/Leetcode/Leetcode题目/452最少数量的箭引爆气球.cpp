class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 最少 一般使用贪心算法
        // 找出 最多区间重叠个数：这些重叠区间都有公共区间

        if(points.size() == 1)
        {
            return 1;
        }

        // 将数组的所有区间按照左端点进行排序
        sort(points.begin(),points.end());

        int res = 1;
        int pre = points[0][1]; // 拿出第一个区间的右端点

        for(int i = 1; i < points.size(); i++)
        {
            // 将第二个区间的左端点与第一个区间的右端点进行比较
            if(pre < points[i][0])
            {
                // 说明不重叠
                res++; 
                pre = points[i][1];  // 更新为第二个区间的右端点
            }
            else
            {
                // 如果重叠
                // 最终的目的是找出所有区间的公共区间
                // 我们可以看到题目给出的例子 x = 6 引爆[2,8] [1,6] 公共区间 [2,6]
                // x = 11 引爆[7,12] [10,16]  公共区间即为[10,12]
                // [10,12] 与 [2,6] 没有公共区间

                // 那么更新公共区间  [第二个区间的左端点，pre]
                // 在看上面的例子 更新的公共区间左端点都是第二个区间的左端点（小于第一个区间的右端点 说明交叉，作为左端点）
                // 但是 对于右端点 有可能是第一个区间的右端点 有可能是第二个区间的右端点  选取最小的！
                pre = min(pre,points[i][1]);
            }
        }

        return res;

    }
};