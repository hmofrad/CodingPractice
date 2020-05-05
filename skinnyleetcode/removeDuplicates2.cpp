/*
 *	https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        std::stack<int> st;
        int len = s.length();
        for(int i = 0; i < s.length(); i++) {
            if(i==0 or s[i] != s[i-1]) st.push(1);
            else if(++st.top() == k) {
                st.pop();
                s.erase(i-k+1,k);
                i-=k;
            }
        }
        return s;
    }
    
    string removeDuplicates3(string s, int k) {
        int len = s.length();
        std::vector<int> count(len);
        count[0]=1;
        for(int i = 0; i < s.length(); i++) {
            //printf("%d %c %d\n", i, count[i], s.length());
            if(i==0 or s[i] != s[i-1]) count[i]=1;
            else {
                count[i]=count[i-1]+1;
                if(count[i]==k) {
                    s.erase(i-k+1, k);
                    i-=k;
                }
            }
        }
        return s;
    }
    string removeDuplicates1(string s, int k) {
        std::string t = s;
        do {
           // printf("%s %s\n", s.c_str(), t.c_str());
            s = t;
            int len = s.length();
            std::vector<bool> deleted(len);
            std::string temp;
            int j = 0;
            int i = 1;
            //while(j < len and deleted[j])j++;
            for(; i < len; i++) {
                if(s[i]!=s[j] or i-j==k) {
                    int l = i-j;
                    if(l==k) { for(int m = j; m < i; m++) deleted[m]=true; }
                    j=i;
                }
            }
            int l = i-j;
            if(l==k) { for(int m = j; m < i; m++) deleted[m]=true; }
            
            
            t.clear();
            for(int i = 0; i < len; i++) {
                //printf("%d %d\n", i, deleted[i]==false);
                if(not deleted[i]) {
                    t.push_back(s[i]);
                }
            }
        } while(s!=t);
        return t;
    }
};