/*
 * https://leetcode.com/problems/add-binary/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.length();
        int bl = b.length();
        if(al<bl) { return addBinary(b, a); }
        int len = max(al, bl);
        int i = len-1;
        int j = bl-1;
        int c = 0;
        std::string s;
        while(i>=0 or j>=0) {
            c += (a[i--]=='1') ? 1 : 0;
            c += (j>=0 and b[j--]=='1') ? 1 : 0;
            s.push_back((c%2)+'0');
            c/=2;
        }
        if(c) { s.push_back(c+'0'); }
        std::reverse(s.begin(), s.end());
        return s;
    }
    
    string addBinary1(string a, string b) {
        std::string ans;
        int la = a.length();
        int ia = la-1;
        int lb = b.length();
        int ib = lb-1;
        char c = '0';
        while(ia>=0 and ib>=0) {
            int s = (a[ia--]-'0') + (b[ib--]-'0') + (c-'0');
            c = s/2+'0';
            s %= 2;
            ans.push_back(s+'0');
        }
        
        while(ia>=0) {
            int s = (a[ia--]-'0') + (c-'0');
            c = s/2+'0';
            s %= 2;
            ans.push_back(s+'0');
        }
        
        while(ib>=0) {
            int s = (b[ib--]-'0') + (c-'0');
            c = (s/2)+'0';
            s %= 2;
            ans.push_back(s+'0');
        }
        //printf("%c\n", c);
        if(c=='1') { ans.push_back('1'); }
        
        std::reverse(ans.begin(), ans.end());
        
        return a.empty() ? b : b.empty() ? a : ans;
    }
    
    int binary_to_long(std::string& s) {
        unsigned long long int len = s.length();
        unsigned long long int v = 0;
        unsigned long long int p = 1;
        for(int i = len-1; i >= 0; i--) {
            v += (s[i]-'0')*p;
            p <<= 1;
        }
        return v; 
    }
    
    std::string int_to_binary(unsigned long long int v) {
        std::string s;
        char r = '0';
        while(v) {
            r = (v%2) ? '1' : '0';
            v/=2;
            s.push_back(r);
        }
        std::reverse(s.begin(), s.end());
        return s.empty() ? "0" : s;
    }
    
    string addBinary0(string a, string b) {
        return int_to_binary(binary_to_long(a) + binary_to_long(b));
    }
    

};