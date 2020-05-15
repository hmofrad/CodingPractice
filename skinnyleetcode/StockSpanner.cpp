/*
 *	https://leetcode.com/problems/online-stock-span/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 
class StockSpanner {
public:
    int day;
    std::map<int, std::vector<int>> db;
    std::vector<int> db1;
    StockSpanner() {
        //day=0;
    }

    std::stack<std::pair<int, int>> stack;
    
    int next(int price) {
        int w = 1;
        while(not stack.empty() and stack.top().first <= price) {
            w += stack.top().second;
            stack.pop();
        }
        stack.push({price, w});
        return w;
    }
    
    std::stack<int> prices, weights;
    int next0(int price) {
        int w = 1;
        while(not prices.empty() and prices.top() <= price) { prices.pop(); w+=weights.top(); weights.pop(); }
        prices.push(price);
        weights.push(w);
        return w;
    }
    
    int next1(int price) {
        int span = 0;
        db1.push_back(price);
        int size = db1.size();
        for(int i = size-1; i >= 0; i--) {
            if(db1[i] <= price) span++;
            else break;
        }
        return span;
    }
    
    int next2(int price) {
        int span = 0;
        auto lb = db.lower_bound(price);
        db[price].push_back(++day);
        if(lb != db.end()) {
            int today = day;
            for(auto it = db.begin(); it != lb; it++) {
                bool b = false;
                std::vector<int>& days = it->second;
                for(int i = days.size()-1; i >= 0; i--) {
                    int d = days[i];
                    if(day-d==1) { span++; today--; }
                    else { b=true; break; }
                }
                if(b) break;
            }    
        }
        return span ? span : 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */ 