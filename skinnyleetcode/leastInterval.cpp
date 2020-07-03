/*
 * https://leetcode.com/problems/task-scheduler/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool is_done(std::vector<int>& map) {
        for(int i = 0; i < 26; i++) {
            if(map[i]) { return false; }
        }
        return true;
    }
    int leastInterval(vector<char>& tasks, int n) {
        int ntasks = tasks.size();
        std::vector<int> freqs(26);
        for(char t: tasks) {freqs[t-'A']++;}
        std::sort(freqs.begin(), freqs.end());
        int fmax = freqs[25];
        int idle = (fmax-1)*n;
        
        for(int i = 24; i>=0 and idle; i--) {
            printf("%d %d %d\n", idle, freqs[i], fmax-1);
            idle -= min(fmax-1, freqs[i]);
        }
        idle = idle < 0 ? 0 : idle;
        
        return idle+ntasks;
    }
};