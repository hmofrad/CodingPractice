/*
 * https://leetcode.com/problems/multiply-strings/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.length();
        int size2 = num2.length();
        std::vector<int> prod(size1+size2);
        for(int i = size1-1; i>= 0; i--) {
            for(int j = size2-1; j>=0; j--) {
                prod[i+j+1]+=((num1[i]-'0')*(num2[j]-'0'));
            }
        }
        
        int carry = 0;
        for(int i = prod.size()-1; i>=0; i--) {
            int sum = prod[i]+carry;
            carry = sum/10;
            int remainder = sum%10;
            prod[i]=remainder;
        }
        std::string ans;
        for(int i = 0; i < prod.size(); i++) {ans.push_back(prod[i]+'0');}
        //printf("\n");
        //printf("%s\n", ans.c_str());
        while(not ans.empty() and ans.front()=='0') ans.erase(ans.begin());
        return ans.empty() ? "0" : ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    std::string add(std::string num1, std::string num2) {
        if(num2.length()>num1.length()) add(num2,num1);
        int carry = 0;
        int size1 = num1.length();
        int i1 = size1-1;
        int size2 = num2.length();
        int i2 = size2-1;
        while(i1>=0 and i2>=0) {
            int s = (num1[i1]-'0') + (num2[i2]-'0') + carry;
            carry = s/10;
            int r = s%10;
            num1[i1]=r+'0';
            i1--;
            i2--;
        }
        while(i1>=0) {
            int s = (num1[i1]-'0') + carry;
            carry = s/10;
            int r = s%10;
            num1[i1]=r+'0';
            i1--;
        }
        if(carry) { num1.insert(num1.begin(), 1, carry+'0'); }
        return num1;
    }
    std::string mult(std::string num1, int digit2) {
        if(digit2==0) return "0";
        int carry = 0;
        int size = num1.size();
        std::string ans;
        for(int i=size-1; i>=0; i--) {
            int digit1 = num1[i]-'0';
            int m = (digit1*digit2) + carry;
            carry=m/10;
            int r = m%10;
            ans.push_back(r+'0');
        }
        if(carry){ans.push_back(carry+'0');}
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply1(string num1, string num2) {
        if(num1.length()<num2.length()) multiply(num2, num1);
        
        int size = num2.length();
        std::string ans = mult(num1, num2[size-1]-'0');
        for(int i=size-2; i>=0; i--) {
            std::string temp = mult(num1, num2[i]-'0');
            if(temp=="0") continue;
            temp+=std::string(size-i-1,'0');
            ans = add(temp, ans);
        }
        
        return ans;
    }
};