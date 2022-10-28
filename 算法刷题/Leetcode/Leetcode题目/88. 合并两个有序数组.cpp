class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;// 合并之后的数组下标
        // 从后面开始 将较大的数字放到数组后面

        // nums1 与 nums2 都是非递减的数组 那么从后面开始比较
        // 每次就会将较大的数字拿出来
        // 1 2 3 0 0 0     2 5 6
        m--;
        n--;  // 数组长度
         while(m >= 0 && n >= 0)
         {
             // 3 与 2 进行比较开始向后移动位置
             // 2 最终会移动到3的位置
             if(nums1[m] > nums2[n])
             {
                 nums1[pos] = nums1[m];
                 pos--;
                 m--;
             }
             else
             {
                 nums1[pos] = nums2[n];
                 pos--;
                 n--;
             }
         }
         // 上面的循环结果 一定是 m < 0 或者n < 0 
         // m < 0 说明nums1 的数都比nums2 的大 导致nums1全部往后移动了m个单位
         // n < 0 说明 nums2 合并完毕！ nums2 的数字都比num1大
         while(n >= 0)
         {
             nums1[pos] = nums2[n];
             pos--;
             n--;
         }
    }
};