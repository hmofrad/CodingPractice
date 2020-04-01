/*
 *  https://leetcode.com/problems/reduce-array-size-to-the-half/solution/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    int minSetSize1(vector<int>& arr) {
        int m = arr.size();
        std::unordered_map<int, int> arr2freq;
        for(int a: arr) {
            arr2freq[a]++;
        }
        
        std::vector<int> counts;
        for(auto a: arr2freq) {
            counts.push_back(a.second);
        }
        std::sort(counts.begin(), counts.end());
        int n = counts.size();
        int sets = 0; 
        int count = 0;          
        for(int i = n-1; i>=0; i--) {
            count += counts[i];
            sets++;
            if(count >= m/2) break;
        }
        return(sets);
        
    }
    
    int minSetSize(vector<int>& arr) {
        int m = arr.size();
        std::unordered_map<int, int> arr2freq;
        for(int a: arr) {
            arr2freq[a]++;
        }

        std::map<int, std::vector<int>> freq2arr;
        for(auto a: arr2freq) {
            freq2arr[a.second].push_back(a.first);
        }

        
        int h = (m%2) ? m/2 + 1 : m/2;
        int count = 0;
        int set = 0;
        for(auto rit = freq2arr.rbegin(); rit != freq2arr.rend(); rit++) {
            for(int i = 0; i < rit->second.size(); i++) {
                count += rit->first;
                set++;
                if(count>=h) break;
            }
            if(count>=h) break;
        }
        return(set);
        
    }
    
};