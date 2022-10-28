class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        // 只要判断连续三个位置都是0 就可以在中间位置中一朵花

        int count = 0;

        for(int i = 0 ; i < flowerbed.size(); i++)
        {
            // 考虑边界问题，比如 0 0 1 那么只能在第一个位置种上一朵花   1 0 0 最后一个位置种上一朵花
            // 也就是这里要考虑最后一个位置与第一个位置
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&(i == flowerbed.size() - 1 ||  flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                count++;// 种上一朵花
            }
        }

        return count >= n;

    }
};