class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> fre(26,0);
        int l=0;
        int len=0;
        int c=0;
        for(int r=0;r<s.size();r++){
            fre[s[r]-'A']++;
            c=max(c,fre[s[r]-'A']);
            while(r-l+1-c>k){
                fre[s[l]-'A']--;
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};