class Solution {
public:
    void answer(int open,int close,vector<string>& result,string& k){
        if((open == 0) && (close==0)){
            result.push_back(k);
            return;
        }
        
        if(open < 0 || close < 0)return;
        if(close > open){
            k.push_back('(');
            answer(open-1,close,result,k);
            k.pop_back();
            k.push_back(')');
            answer(open,close-1,result,k);
            k.pop_back();   
        }
        else{
            k.push_back('(');
            answer(open-1,close,result,k);
            k.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string k = "";
        answer(n,n,result,k);
        return result;
        
    }
};