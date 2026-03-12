class Solution {
public:

    int dpFun(vector<int>& nums, int idx, bool prev, int curr, vector<vector<vector<int>>>& dp){
        if(idx >= nums.size()){
            return curr;
        }
        if(dp[idx][curr][prev] != -1){
            return dp[idx][curr][prev];
        }
        if(prev){
            return dp[idx][curr][prev] = dpFun(nums, idx+1, false, curr, dp);
        }else{
            return dp[idx][curr][prev] = max(dpFun(nums, idx+1, true, curr+nums[idx], dp), dpFun(nums, idx+1, false, curr, dp));
        }
    }

    int rob(vector<int>& nums) {
        int sum = 0;
        for(auto i :nums){
            sum += i;
        }
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(sum+1, vector<int>(2, -1)));//0 = false, 1 = true
        return dpFun(nums, 0, false, 0, dp);
    }
};