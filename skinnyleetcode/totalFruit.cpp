/*
 *  https://leetcode.com/problems/fruit-into-baskets/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        std::unordered_map<int, int> map;
        int i = 0;
        int j = 0;
        int mx = 0;
        int cnt = 0;
        for(i = 0; i < tree.size(); i++) {
            map[tree[i]]++;
            cnt++;
            
            while(map.size()>2) {
                map[tree[j]]--;
                if(map[tree[j]]==0) map.erase(tree[j]);
                j++;
                cnt--;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
    int totalFruit5(vector<int>& tree) {
        std::unordered_map<int, int> map;
        int i = 0;
        int j = 0;
        for(i = 0; i < tree.size(); i++) {
            map[tree[i]]++;
            if(map.size()>2) {
                map[tree[j]]--;
                if(map[tree[j]]==0) map.erase(tree[j]);
                j++;
            }
        }
        return i-j;
    }
    /*
    int totalFruit4(vector<int>& tree) {
        tree = {3,3,3,1,2,1,1,2,3,3,4};
        std::vector<std::pair<int,int>> temp;
        for(int t: tree) {
            if(temp.empty() or temp.back().first!=t) temp.push_back({t,1});
            else temp.back().second++;
        }
        std::unordered_map<int, std::pair<int,int>> s;
        int j = 0;
        int mx = 0;
        int sz = 0;
        int size = temp.size();
        for(int i = 0; i < size; i++) {
            if(s.size()<2) {
                sz += temp[i].second;
                s[j++]={i, temp[i]};
            }
            else if(s.count(temp[i])) {
                sz += temp[i].second;
            }
            else {
                mx = max(mx, sz);
                s[0].
            }
        }
        
        //for(auto t: temp) printf("%d %d\n", t.first, t.second);
        
        return mx;
    }
    */
    int totalFruit3(vector<int>& tree) {
        std::unordered_map<int, int> count;
        int i =0, j = 0;
        for(i = 0, j = 0; j < tree.size(); j++){
            count[tree[j]]++;
            if(count.size()>2) {
                if(--count[tree[i]]==0) count.erase(tree[i]);
                i++;
            }
        }
        return j-i;
    }
    
    int dfs(vector<int>& tree, int index, std::unordered_map<int,int> trees){
        int collected_fruits = 0;
        if(index == tree.size()) {
            for(auto& t: trees) collected_fruits+=t.second;
            return collected_fruits;
        }
        
        
        int tree_type = tree[index];
        if(trees.size()<2) {
            std::unordered_map<int,int> trees0(trees);
            trees[tree_type]++;
            collected_fruits=max(dfs(tree, index+1, trees0), dfs(tree, index+1, trees));
            //printf(">>3.\n");
        }
        else {
            if(trees.count(tree_type)) {
                trees[tree_type]++;
                collected_fruits=dfs(tree, index+1, trees);
            }
            else {for(auto& t: trees) collected_fruits+=t.second;}
        }
        printf("%d\n", collected_fruits);
        return collected_fruits;
    }
    int totalFruit2(vector<int>& tree) {
        tree = {3,3,3,1,2,1,1,2,3,3,4};
       // tree={0,0,1,1};
        //int ans = 0;
        //int ntrees = tree.size();
        //for(int i = 0; i < ntrees; i++) {
          //  ans = max(ans, dfs(tree, i, std::vector<int>(), std::vector<int>()));
        //}
        return dfs(tree, 0, std::unordered_map<int,int>());
    }
    int totalFruit1(vector<int>& tree) {
        //tree = {3,3,3,1,2,1,1,2,3,3,4};
        std::unordered_map<int, int> map1;
        for(int& t: tree) { map1[t]++; }
        
        std::map<int, std::vector<int>> map2;
        for(auto m: map1) {map2[m.second].push_back(m.first);}
        
        int ans = 0;
        int b = 0;
        for(auto it = map2.rbegin(); it != map2.rend(); it++) {
            int key = it->first;
            std::vector<int>& value = it->second;
            printf("%d %d\n", key, value.size());
            for(int i = 0; i < value.size() and b<2; i++, b++) {
                printf("%d %d %d\n", i, b, ans);
                ans += key;
            }
            if(b==2) break;
        }
        
        return ans;
    }
};