class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int freq[100001]={0}, p=0;
        for(int x: potions){
            freq[x]++;
            p=max(x, p);
        }
        partial_sum( freq, freq+p+1, freq);
        const int n=spells.size(), m=potions.size();
        vector<int> result(n, 0);
        
        for (int i=0; i<n; i++) {
            const int spell=spells[i];
            const long long k = (success+spell-1)/spell;
            if (k<=p) {
                result[i]=m-(k>=1?freq[k-1]:0);
            }
        }       
        return result;
    }
};