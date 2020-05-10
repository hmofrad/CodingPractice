/*
 *	https://leetcode.com/problems/shortest-word-distance-iii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int size = words.size();
        int mindist = INT_MAX;
        int i1 = -1;
        int i2 = -1;
        for(int i = 0; i < size; i++) {
            std::string& word = words[i];
            if(word == word1) i1 = i;
            if(word == word2) {i1= (word1==word2) ? i2 : i1; i2=i;}
            if(i1!=-1 and i2!=-1) mindist = min(mindist,abs(i1-i2));
            //printf("i=%d i1=%d i2=%d min=%d\n", i, i1, i2, mindist);
        }
        return mindist;
    }
    int shortestWordDistance2(vector<string>& words, string word1, string word2) {
        //if(words.size()==2) return 1;
        int size = words.size();
        std::vector<int> pos1;
        std::vector<int> pos2;
        for(int i = 0; i < size; i++) {
            std::string& word = words[i];
            if(word == word1) pos1.push_back(i);
            if(word == word2) pos2.push_back(i);
        }
        
        
        int i1 = 0;
        int s1 = pos1.size();
        int i2 = 0;
        int s2 = pos2.size();
        int mindiff = INT_MAX;
        while(i1 < s1 and i2 < s2) {
            int diff = abs(pos1[i1]-pos2[i2]);
            mindiff = diff ? min(diff, mindiff) : mindiff;
            
            if(pos1[i1]<pos2[i2]) i1++;
            else if(pos1[i1]>pos2[i2]) i2++;
            else if((i1+1<s1) and pos1[i1+1] < pos2[i2]) i1++;
            else i2++;
        }
        
        return mindiff;
    }
    int shortestWordDistance1(vector<string>& words, string word1, string word2) {
        int size = words.size();
        std::vector<int> pos1;
        std::vector<int> pos2;
        for(int i = 0; i < size; i++) {
            std::string& word = words[i];
            if(word == word1) pos1.push_back(i);
            if(word == word2) pos2.push_back(i);
        }
        
        int mindiff = INT_MAX;
        for(int i = 0; i < pos1.size(); i++) {
            for(int j = 0; j < pos2.size(); j++) {
                int diff = abs(pos1[i]-pos2[j]);
                if(diff==0) continue;
                mindiff = min(diff, mindiff);
            }
        }    
        return mindiff==INT_MAX ? 1 : mindiff;
    }
};