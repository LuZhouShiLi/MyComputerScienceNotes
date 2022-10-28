class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 限制购买次数 那么最大利润其实就是正向的差值为正最大的那两个数的差值
        // // 如何获取差值最大的那两个数  双重循环  pass 时间复杂度太高   N/A
        // for(int i = 0; i < prices.size(); i++)
        // {
        //     for(int j = i + 1; j < prices.size(); j++)
        //     {
        //         int t = prices[j] - prices[i];
        //         max_value = max(max_value,t); 
        //     }
        // }

        int min_value = 1e9;
        int max_value = 0;

        // 假设在第i天卖出股票，那么最大利润差一定是在[0,i - 1] 之间的最低点买入，
        // 那么遍历数组，找出每个卖出时机的最大差值  然后选取最大值

        // 也就是遍历数组，对于每一个I ,我都向前寻找历史最小值，然后相减 获取差值 将该差值与最大差值进行比较
        // 要注意，对于这个历史最小值，不是每一次遍历到i都要把前面i - 1个数字都要遍历一遍
        // 而是从一开始就比较  记录并更新这个历史最小值
        for(int i = 0; i < prices.size(); i++)
        {
            // [2,5,1,3]
            // 可以看到 这个历史最小值 都是从头开始遍历的 逐步更新的
            if(prices[i] < min_value)
            {
                min_value = prices[i];
            }
            else if(prices[i] - min_value > max_value)
            {
                // 当前价格 大于历史最小值  更新最大利润
                max_value = prices[i] - min_value;// 更新最大利润
                // 所以 我们可以看到 即使这个历史最小值 更新为1 
                // 下一步 3 - 1 = 2 但是 2 < max_value  也就是他不会更新最大利润
            }
        }



        
         return max_value;



    }
};