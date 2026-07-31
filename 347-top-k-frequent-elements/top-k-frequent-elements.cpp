class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> vec;
        for(auto it:mp){
            vec.push_back(it);
        }
// imp part
        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
        });

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first); //might miss
        }
        return ans;
    }
};