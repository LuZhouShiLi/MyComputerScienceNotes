class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 数组已经排好序  所以可以采用方向相反的双指针来寻找这两个数字
        // 两个指针分别指向最左边 以及  最右边
        // 如果两个指针指向的元素为定值  那就是我们想要的结果，两个指针指向的元素之和小于定值
        //将左边的指针移动一位，大于，将右边的指针移动一位

        // 所以这道题 就相当于 题目已经告诉你 存在最优解：l，r
        // 你设置左右指针的目的就是 移动他们到达l,r位置


        int l = 0, r = numbers.size() - 1;// 下标从一开始
        int sum = 0;

        while(l < r)
        {
            sum = numbers[l] + numbers[r];
            if(sum == target)
            {
                break;
            }
            if(sum < target)
            {
                l++;
            }
            if(sum > target)
            {
                r--;
            }
        }
        return vector<int>{l+1,r+1};
    }
};