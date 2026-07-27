class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0) return;
        k=k%nums.size();
        if(k==0) return;
        int temp[k];
        for(int i=0;i<k;i++){
            temp[i]=nums[nums.size()-k+i];
        }
        for(int i=nums.size()-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};