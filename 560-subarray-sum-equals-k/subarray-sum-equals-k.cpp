class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        long long currSum = 0;
        int count = 0;
        
        for(int num : nums) {
            currSum = currSum+num;
            count = count+prefix[currSum - k];
            prefix[currSum]++;
        }      
        return count;
    }
};