class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        int c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='-'){
                if(c==k){
                    ans.push_back('-');
                    c=0;
                }
                ans.push_back(toupper(s[i]));
                c++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;      
    }
};