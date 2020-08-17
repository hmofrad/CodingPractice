/*
 * https://leetcode.com/problems/maximum-frequency-stack/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class FreqStack {
public:
    std::map<int, int> freq;
    std::unordered_map<int, std::vector<int>> group;
    int maxFreq;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        if(freq[x] > maxFreq) maxFreq = freq[x];
        group[freq[x]].push_back(x);
    }
    
    int pop() {
        int x = group[maxFreq].back();  group[maxFreq].pop_back();
        if(group[maxFreq].empty()) { group.erase(maxFreq); maxFreq--; }
        freq[x]--;
        return x;
         
    }
};


class FreqStack1 {
public:
    std::unordered_map<int, std::vector<int>> x2freq;
    std::map<int, std::vector<int>> freq2x;
    FreqStack1() {
        
    }
    
    void push(int x) {
        int prev_freq = x2freq.count(x) ? x2freq[x].size() : 0;
        x2freq[x].push_back(x);
        int new_freq = x2freq[x].size();
        if(prev_freq) {
            auto it = std::find(freq2x[prev_freq].begin(), freq2x[prev_freq].end(), x);
            freq2x[prev_freq].erase(it);
        }
        freq2x[new_freq].push_back(x); 
    }
    
    int pop() {
        auto it = freq2x.rbegin();
        int prev_freq = it->first;
        it->second.pop_back();
        
        int x = it->second.back();
        int ret = x2freq[x].back();
        x2freq[x].pop_back();
        
        int new_freq = x2freq[x].size();
        
        
        if(new_freq) {
            freq2x[new_freq].push_back(x); 
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */