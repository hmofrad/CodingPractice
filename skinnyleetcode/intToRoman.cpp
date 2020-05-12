/*
 *	https://leetcode.com/problems/integer-to-roman/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> map({{1, "I"},  {2, "II"},  {3, "III"}, {4, "IV"}, {5, "V"},
                                        {6, "VI"}, {7, "VII"}, {8, "VIII"},{9, "IX"}, {10, "X"},
                                        {40, "XL"},{50, "L"},  {90, "XC"}, {100, "C"},{400, "CD"},
                                        {500, "D"},{900, "CM"},{1000, "M"}});
        
        
        std::vector<std::string> ans;
        int c = 0;
        std::string roman;
        while(num) {
            int i = map.size()-1;
            for(; i>= 0; i--) {
                if(map[i].first<=num) break;
            }
            roman+=map[i].second;
            num-=map[i].first;
        }
        //printf("%s\n", roman.c_str());
        return roman;
    }
};
