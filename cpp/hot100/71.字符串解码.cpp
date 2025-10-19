class Solution {
public:
    string decodeString(string s) {
        if(s.empty()){
            return s;
        }
        if(isalpha(s[0])){
            return s[0] + decodeString(s.substr(1));
        }
        int i = s.find('[');
        int balance = 1;
        for(int j = i + 1; ;++j){
            if(s[j] == '['){
                ++balance;
            }
            else if(s[j] == ']'){
                --balance;
                if(balance == 0){
                    int k = stoi(s.substr(0, i));
                    string t = decodeString(s.substr(i + 1, j - i - 1));
                    string res;
                    while(k--){
                        res += t;
                    }
                    return res + decodeString(s.substr(j + 1));
                }
            }
        }
    }
};