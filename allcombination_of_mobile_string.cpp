class Solution {
public:
    map<string, char>mt;
    vector<string>ans;
    void recur(int idx, string& digits,string temp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        if(idx > digits.size()) return;
        string p = "";
        for(int j = 1;j <= 4; j++){
            if(idx - j + 1 >= 0){
                p = digits.substr(idx - j + 1, j);
                if(mt.count(p)){
                    temp += mt[p];
                    recur(idx + 1, digits, temp);
                    for(int k = 0; k < j; k++){
                        temp.pop_back();
                    }
                }
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        char val = 'a';
        for(int i = 2; i <= 9; i++){
            int len = 3;
            if(i == 7 or i == 9){
                len = 4; 
            }
            string c = to_string(i);
            string p = c;
            for(int j = 0; j < len; j++){
                    mt[p] = val;
                    p+=c;
                    val++;
            }
        }
        string temp ="";
        recur(0, digits, temp);
        return ans;
    }
};