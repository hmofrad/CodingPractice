/*
 *  https://leetcode.com/problems/goat-latin/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    std::vector<std::string> string2vec(std::string S) {
        std::vector<std::string> ans;
        int size = S.length();
        int i = 0;
        int j = 0;
        while (i < size) {
            if(S[i] == ' ') {
                int len = i-j;
                std::string temp = S.substr(j, len);
                ans.push_back(temp);
                j=i+1;
            }
            i++;
        }
        int len = i-j;
        std::string temp = S.substr(j, len);
        ans.push_back(temp);
        return(ans);
    }
    
    void string2goatlatin(std::string& str, int index) {
        if(str.length() == 0) return;
        
        if(not(str[0] == 'a' or str[0] == 'e' or str[0] == 'i' or str[0] == 'o' or str[0] == 'u'
              or str[0] == 'A' or str[0] == 'E' or str[0] == 'I' or str[0] == 'O' or str[0] == 'U'))  {
            char temp = str[0];
            str.erase(0, 1);
            str += temp;
        }
        str += "ma";
        std::string temp(index, '\0');
        for(int i = 0; i < index; i++) {
            temp[i] = 'a';
        }
        str += temp;
    }
    
    std::string vector2string(std::vector<std::string> strs) {
        std::string str;
        int size = strs.size();
        for(int i = 0; i < size; i++) {
            str += strs[i] + " ";
        }
        str.erase(str.length()-1, 1);
        return(str);
    }
    
    std::string toGoatLatin(string S) {
        std::vector<std::string> strs = string2vec(S);
        
        //for(std::string str: strs) printf("%s ", str.c_str()); printf("\n");
        
        int size = strs.size();
        for(int i = 0 ; i < size; i++) {
            string2goatlatin(strs[i], i+1);
        }
        
        return(vector2string(strs));
    }
};