/*
 *  https://leetcode.com/problems/complex-number-multiplication/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    std::pair<int, int> convert(std::string num) {
        int i = 0;
        std::string real;
        while(num[i]!='+') {
            real += num[i];
            i++;
        }
        std::string image;
        i++;
        while(num[i]!='i') {
            image += num[i];
            i++;
        }
        return(std::make_pair(stoi(real), stoi(image)));
        
    }
    
    std::string mult(int a_r, int a_i, int b_r, int b_i) {
        int t1 = a_r * b_r;
        int t2 = a_r * b_i;
        int t3 = a_i * b_r;
        int t4 = a_i * b_i;
        
        int t5 = t1 + t4*-1;
        int t6 = t2 + t3;    
        std::string out = to_string(t5)+'+'+to_string(t6)+'i';
        return(out);
    }
    
    string complexNumberMultiply(string a, string b) {
        int a_r = 0;
        int a_i = 0;
        std::tie(a_r, a_i) = convert(a);
        
        int b_r = 0;
        int b_i = 0;
        std::tie(b_r, b_i) = convert(b);
        
        //printf("[%d %d] [%d %d]\n", a_r, a_i, b_r, b_i);
        //std::string res;
        return(mult(a_r, a_i, b_r, b_i));
    }
};