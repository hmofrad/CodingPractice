/*
 * https://leetcode.com/problems/minimum-cost-to-hire-k-workers/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    struct comp{
        bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
            return (double) a.second/a.first < (double) b.second/b.first;
        }
    };
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int size = quality.size();
        std::vector<std::pair<int, int>> workers;
        for(int i = 0; i < size; i++) {
            workers.push_back({quality[i], wage[i]});
        }
        
        std::sort(workers.begin(), workers.end(), [](std::pair<int, int> a, std::pair<int, int> b) { return (double) a.second/a.first < (double) b.second/b.first;  } );
        
        //std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> pq;
        
        //std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        std::priority_queue<int> pq;
        double ans = INT_MAX;
        double sum = 0;
        for(std::pair<int, int>& worker: workers) {
            sum += worker.first;
            pq.push(worker.first);
            
            if(pq.size()>K) {sum -=pq.top(); pq.pop();}
            if(pq.size()==K) ans = min(ans, (double) sum* (double) worker.second/worker.first);
        }
        
        return ans;
    }
    double mincostToHireWorkers1(vector<int>& quality, vector<int>& wage, int K) {
        int size = quality.size();
        double ans = INT_MAX;
        for(int i = 0; i < size; i++) {
            double ratio = (double) wage[i]/quality[i];
            std::vector<double> prices(size);
            int k = 0;
            for(int j = 0; j < size; j++) {
                double price = ratio*quality[j];
                if(price>=wage[j]) prices[k++]=price;
            }
            
            if(k>=K) {
                std::sort(prices.begin(), prices.begin()+k);
                double cost = 0;
                for(int j = 0; j < K; j++) cost+=prices[j];
                ans = min(ans, cost);
            }
        }
        return ans;
    }
};