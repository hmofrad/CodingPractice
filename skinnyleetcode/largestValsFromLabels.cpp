/*
 *  https://leetcode.com/problems/largest-values-from-labels/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void my_sort(vector<int>& values, vector<int>& labels) {
        int size = values.size();
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                if(values[i]<values[j]) {
                    std::swap(values[i], values[j]);
                    std::swap(labels[i], labels[j]);
                }
            }
        }
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        //my_sort(values, labels);
        int size = values.size();
        std::vector<std::pair<int, int>> pairs;
        for(int i = 0; i < size; i++) {
            pairs.push_back({values[i], labels[i]});
        }
        std::sort(pairs.begin(), pairs.end(), [](std::pair<int, int> a, std::pair<int, int> b) {return a.first > b.first;});

        int sum = 0;
        int count = 0;
        
        std::unordered_map<int, int> map;
        for(int i = 0; i < size; i++) {
           // printf(">%d %d %d %d\n", i, values[i], labels[i], count);
            if(count == num_wanted) break;
            if(map.count(pairs[i].second) == 0 or map[pairs[i].second] < use_limit) {
                map[pairs[i].second]++;
                sum += pairs[i].first;
                count++;
            }
        }
        
        return sum;
    }
};