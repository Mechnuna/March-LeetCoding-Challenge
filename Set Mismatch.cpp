class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>nums2(2);
        int sum = nums.size() * (nums.size() + 1) / 2;
        vector<bool> presence(nums.size()+1);
        for (int num : nums) {
            sum -= num;
            if (presence[num]) nums2[0] = num;
            presence[num] = true;
        }
        nums2[1] = sum + nums2[0];
        return nums2;
    }
};