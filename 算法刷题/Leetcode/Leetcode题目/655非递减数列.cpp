class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            // 比如  1 4 2 5  或者  4 2 5  nums[i] = 2 nums[i - 1] = 4
            if(nums[i] < nums[i - 1])
            {
                if(i == 1 || nums[i] >= nums[i - 2])
                {
                    // 尽量不修改 nums[i]  因为 提升nums[i] 容易造成后面的数字又变成降序
                    // 所以将nums[i - 1] 进行削减  保证了递增有序
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];// 第三种情况 3 4 2 5 只能改变2 提升为4 或者 5 不可以改变4 将为比2小的数字
                }

                count++;// 进行了一次修改
            }
        }

        return count <= 1;

    }
};