/*
 * https://leetcode.com/problems/bulls-and-cows/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string getHint(string secret, string guess) {
        std::vector<int> count(10);
        int size = secret.size();
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0; i < size; i++) {
            if(secret[i]==guess[i]) bulls++;
            else {
                int ds = secret[i]-'0';
                int dg = guess[i]-'0';
                if(count[ds]<0) cows++;
                if(count[dg]>0) cows++;
                count[ds]++;
                count[dg]--;
            }
        }
        
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
    
    
    string getHint3(string secret, string guess) {
        std::vector<int> count(10);
        for(char c: secret) {int d = c-'0'; count[d]++;}
        int bulls = 0;
        for(int i = 0; i < guess.size(); i++) {
            if(guess[i]==secret[i]) {
                int d = guess[i]-'0';
                count[d]--;
                bulls++;
            } 
        }
        int cows = 0;
        for(int i = 0; i < guess.size(); i++) {
            if(guess[i]!=secret[i]) {
                int d = guess[i]-'0';
                if(count[d]>0) {
                    count[d]--;
                    cows++;
                }
            }
        }
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
    
    string getHint2(string secret, string guess) {
        //secret="1122";
        //guess="2211";
        secret="1123";
        guess="0111";
        //secret="11";
        //guess="10";
        std::unordered_map<char, std::unordered_set<int>> secret_map;
        std::unordered_map<char, std::unordered_set<int>> guess_map;
        
        for(int i = 0; i < secret.size(); i++) secret_map[secret[i]].insert(i);
        for(int i = 0; i < guess.size(); i++) guess_map[guess[i]].insert(i);
        
        int bulls = 0;
        
        for(auto m: secret_map) {
            char key = m.first;
            std::unordered_set<int>& values_s = m.second;
            if(guess_map.count(key)==0) continue;
            std::unordered_set<int>& values_g = guess_map[key];
            for(int s: values_s) {
                if(values_g.count(s)) {bulls++;}
            }
        }
        
        
        int cows = 0;
        for(auto m: guess_map) {
            char key = m.first;
            std::unordered_set<int>& values_g = m.second;
            if(secret_map.count(key) == 0) continue;
            std::unordered_set<int>& values_s = secret_map[key];
            int size = values_s.size();
            for(int g: values_g) {
                if(size and values_s.count(g)==0) {cows++; size--;}
            }
        }
        
        
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    string getHint1(string secret, string guess) {
            int bulls = 0;
    int cows = 0;
    int n = secret.size();
    std::vector<int> counts(10);
    
    for(int i = 0; i < n; i++) {
        int digit = secret[i] - '0';
        counts[digit]++;
    }

    //for(auto c : counts)
    //    printf("%d ", c);
    //printf("\n");
    
    
    for(int i = 0; i < n; i++) {
        int digit = guess[i] - '0';
        if(secret[i] == guess[i]) {
            bulls++;
            counts[digit]--;
        }
    }

    //for(auto c : counts)
    //    printf("%d ", c);
    //printf("\n");

    
    for(int i = 0; i < n; i++) {
        int digit = guess[i] - '0';
        if(secret[i] != guess[i]) {
            if(counts[digit] > 0) {
                cows++;
                counts[digit]--;
            }
        }
    }
    
    //for(auto c : counts)
    //    printf("%d ", c);
    //printf("\n");
    
    
    std::string cipher = std::to_string(bulls) + 'A' + std::to_string(cows) + 'B';

    return(cipher);
    }
};