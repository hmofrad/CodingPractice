/*
 *  https://leetcode.com/problems/strobogrammatic-number-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    std::vector<std::string> dfs(int m, int n) {
        if(m==0) return {""};
        if(m==1) return {"0", "1", "8"};
        std::vector<std::string> temp = dfs(m-2, n);
        std::vector<std::string> ans;
        for(std::string t: temp) {
            if(m!=n) { ans.push_back("0"+t+"0"); }
            ans.push_back("1"+t+"1");
            ans.push_back("6"+t+"9");
            ans.push_back("8"+t+"8");
            ans.push_back("9"+t+"6");
        }
        return ans;
    }
    
    vector<string> findStrobogrammatic(int n) {
        //n=6;
        return dfs(n, n);
    }
    
    std::vector<std::string> combs;
    void backtrack(std::string& s, int index, std::string temp, int n) { 
        if(temp.length()==n) { 
            if(isStrobogrammatic(temp)) { combs.push_back(temp); }
            return; 
        }
        
        for(int i = 0; i < s.length(); i++) {
            temp.push_back(s[i]);
            if(temp.front()=='0' and n>1) {temp.clear(); continue;}
            
            backtrack(s, i, temp, n);
            temp.pop_back();
        }
    }
    vector<string> findStrobogrammatic2(int n) {
        std::string s = "01698";
        backtrack(s, 0, std::string(), n);
        
        //for(auto c: combs) {
        //    printf("%s\n", c.c_str());
        //}
        
        return combs;
    }
    
    
    
    bool isStrobogrammatic(string num) {
        std::unordered_map<char, char> digits = {{'0','0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int left = 0;
        int right = num.length()-1;
        while(left<=right) {
            char l = num[left];
            char r = num[right];
            if(digits.count(l)==0 or digits.count(r)==0) return false;
            if(l != digits[r]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    vector<string> findStrobogrammatic1(int n) {
        std::vector<std::string> ans;
        int start = (n-1) ? pow(10,n-1) : 0;
        int end = pow(10, n);
        for(int i = start; i < end; i++) {
            std::string t = to_string(i);
            if(isStrobogrammatic(t)) ans.push_back(t);
        }
        return ans;
    }
};