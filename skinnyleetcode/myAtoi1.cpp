/*
 * https://leetcode.com/problems/string-to-integer-atoi/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    std::pair<bool, std::string> preprocess(std::string& s) {
        if(s.empty()) { return {false, std::string()}; }
        
        int len = s.length();
        int i = 0;
        while(i<len and s[i]==' ') { i++; }
        if(i==len) { return {false, std::string()}; }
        
        bool sign = true;
        if(s[i]=='+') { i++; }
        else if(s[i]=='-') { sign = false; i++; }
        if(i==len) { return {false, std::string()}; }
        
        while(i<len and s[i]==' ') { return {false, std::string()}; } 
        
        int j = i;
        while(i<len and (s[i]>='0' and s[i]<='9')) { i++; }                     
        std::string t = s.substr(j, i-j);
        if(t.empty()) { return {false, std::string()}; } 
        return {sign, t};
    }
    int myAtoi(string str) {
        if(str.empty()) { return 0; }
        bool sign=false;
        std::string s;
        std::tie(sign, s) = preprocess(str);
        //printf("%d %s\n", sign, s.c_str());
        if(s.empty()) { return 0; }
        std::reverse(s.begin(), s.end());

        int ans = sign ? s.back()-'0' : -(s.back()-'0');
        s.pop_back();
        while(not s.empty()) {
            int d = s.back()-'0'; s.pop_back();
            if(sign) {
                if((ans==INT_MAX/10 and d>INT_MAX%10) or (ans>INT_MAX/10)) { return INT_MAX; }
                ans = ans*10+d;
            }
            else {
                if((ans==INT_MIN/10 and -d<INT_MIN%10) or (ans<INT_MIN/10)) { return INT_MIN; }
                ans = ans*10-d;
            }
            
        }
        return ans;
    }
};


























class Solution0 {
public:
    bool is_digit(char c) {
        return c >= '0' and c <= '9';
    }
    bool is_zero(char c) {
        return c=='0';
    }
    bool is_space(char c) {
        return c == ' ';
    }
    bool is_sign(char c) {
        return c == '+' or c == '-';
    }
    std::pair<std::string, bool> pre_process(std::string str) {        
        int len = str.length();
        int i = 0;
        while(i<len and (is_space(str[i]))) i++;
        bool seen_zeros = false;
        while(i<len and is_zero(str[i])) {
            seen_zeros |= is_zero(str[i]);
            i++;
        }
        if(i==len) { return std::make_pair(std::string(), false); }
        if(seen_zeros and is_sign(str[i])) { return std::make_pair(std::string(), false); }
        bool sign= is_sign(str[i]) and str[i++] == '-' ? false : true;
        
        while(i<len and is_zero(str[i])) i++;
        if(i==len) { return std::make_pair(std::string(), false); }
        int j = i;
        while(i<len and is_digit(str[i])) i++;
        
        std::string t;
        if(i-j>=1) { t = str.substr(j,i-j); }
        else  { return std::make_pair(std::string(), false); }
        
        return std::make_pair(t, sign);
    }
    
    int str2int(std::string str, int v, int i, int len) {
        return i<len ? str2int(str, v*10 + (str[i]-'0'), i+1, len) : v;
    }
    //2147483647
    //-2147483648
   int str2int1(std::string str, bool sign) {
        int len = str.size();
        int value = 0; 
        if(len>0 and len<=10) {
            bool overflow = false;
            for(int i = 0; i < len; i++) {
                int d = str[i]-'0';
                //printf("%d %d %d %d %d\n",i,-d,-value, INT_MIN/10, INT_MIN%10) ;
                if((sign and (value>INT_MAX/10 or (value==INT_MAX/10 and d>(INT_MAX%10)))) or
                   (not sign and (value<INT_MIN/10 or (value==INT_MIN/10 and -d<(INT_MIN%10))))) {
                    value = sign ? INT_MAX : INT_MIN;
                    overflow = true;
                    break;
                }
                value*=10; value += sign ? d : -d;
            }
            //printf("? %d\n", overflow);
            //if(not overflow) value = sign ? value : -value;
       }
       else if(len>10) { value = sign ? INT_MAX : INT_MIN; }
       
        return value;
    }
    
    int myAtoi(string str) {
        //str="-2147483649";
        //int v = INT_MAX;
        //printf("%d\n", INT_MAX/10);
        //str="2147483800";
             //str="0-1";
        //str="0  123";
        //str="1095502006p8";

        std::string t;
        bool s = false;
        std::tie(t, s) = pre_process(str);
        //printf("%s %d\n", t.c_str() ,s);
        return str2int1(t, s);
        //printf("[%s] %d\n", t.c_str(), s);
        //return s ? str2int(t, 0, 0, t.length()) : -str2int(t, 0, 0, t.length());
    }
};