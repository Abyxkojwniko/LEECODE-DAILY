class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 == 1) return false;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for(char c : s){
            if(pairs.count(c)){
                if(stk.empty() || stk.top() != pairs[c]){
                    return false;
                }
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};