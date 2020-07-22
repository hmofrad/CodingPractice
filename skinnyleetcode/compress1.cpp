/*
 * https://leetcode.com/problems/string-compression/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    
    void modify(vector<char>& chars, int& j, int count) {
        std::vector<int> counts;
        while(count) {
            counts.push_back(count%10);
            count/=10;
        }
        std::reverse(counts.begin(), counts.end());
        for(int d: counts) { chars[j++]=d+'0'; }
    }
    
    int compress(vector<char>& chars) {
        if(chars.empty() or chars.size()==1) { return chars.size(); }
        int size = chars.size();
        int j = 0;
        char c = chars.front();
        int count = 1;
        for(int i = 1; i < size; i++) {
            if(chars[i] != c) {
                chars[j++]=c;
                if(count>1) { 
                    std::string s = to_string(count);
                    for(char c: s) { chars[j++] = c;}
                    //modify(chars, j, count); 
                }
                c=chars[i];
                count=1;
            }
            else { count++; }
        }
       
        chars[j++]=c;
        if(count>1) { 
            std::string s = to_string(count);
            for(char c: s) { chars[j++] = c;}
            //modify(chars, j, count); 
        }
        
        return j;
    }
};































class Solution0 {
public:
    int compress(vector<char>& chars) {
        uint32_t i = 0;
        uint32_t j = 1;
        uint32_t k = 0;
        int l = 0;
        while(i < chars.size()) {

            if(i+1 < chars.size()) {
                if(chars[i] == chars[i+1]) {
                    j++;
                }
                else {
                    chars[k] = chars[i];
                    k++;
                    if(j>1) {
                        int r = j%10;
                        while(j/10) {
                            r =  j%10;
                            chars[k] = '0'+j/10;
                            k++;
                            j = r;
                        }
                        chars[k] = '0'+r;
                        k++;
                    }
                    j=1;
                    l++;
                }
            }
            else {
               // printf("%d %d\n", j/10, j%10);
                chars[k] = chars[i];
                k++;
                if(j>1) {
                    int r = j%10;
                    while(j/10) {
                        r =  j%10;
                        chars[k] = '0'+j/10;
                        k++;
                        j = r;
                    }
                    chars[k] = '0'+r;
                    k++;
                }
                j = 0;
                l++;
            }
            i++;
        }

       // for(uint32_t m = k; m < chars.size(); m++) {
         //   chars[m] = '\0';
        //}
//for(auto c: chars) {printf("%c ", c);} printf("\n");
        return(k);    
    }
};