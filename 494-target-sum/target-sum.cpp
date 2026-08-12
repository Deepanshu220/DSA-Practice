class Solution {
private:
    int countSubsets(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int> (target + 1, 0));
        // base cases
        if (nums[0] <= target) 
            dp[0][nums[0]] = 1;
        
        for (int i = 0; i < n; i++){ 
            dp[i][0] = 1;
        }
        if (nums[0] == 0){
            dp[0][0] = 2;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (nums[i] <= j){
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = notTake + take;
            }
        }
        return dp[n - 1][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 != 0) return 0;
        int s1 = (sum + target) / 2;
        // count subsets with sum = s1
        return countSubsets(nums, s1);
    }
};