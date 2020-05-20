/*
 *	https://leetcode.com/problems/hexspeak/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    string toHexspeak(string num) {
        long num1 = stol(num);
        std::unordered_map<int, char> map({{0,'O'}, 
                                           {1,'I'},
                                           {10,'A'},
                                           {11,'B'},
                                           {12,'C'},
                                           {13,'D'},
                                           {14,'E'},
                                           {15,'F'}});
        
        std::string hex;
        while(num1) {
            int r = num1%16;
            if(r>1 and r<10) return "ERROR";
            num1/=16;
            hex.push_back(map[r]);
        }
        std::reverse(hex.begin(), hex.end());
        return hex;
    }
};