/*
 *  https://leetcode.com/problems/campus-bikes/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

    struct Node {
        int worker_index;
        int bike_index;
        std::pair<int, int> worker_pos;
        std::pair<int, int> bike_pos;
        int manhattan_dist;
    };
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        std::vector<struct Node> data;
        int numworkers = workers.size();
        int numbikes = bikes.size();
        for(int i = 0; i < numworkers; i++) {
            for(int j = 0; j < numbikes; j++) {
                struct Node node = {i, j, {workers[i][0], workers[i][1]}, {bikes[j][0], bikes[j][1]}, abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1])};
                data.push_back(node);
            }
        }
        for(auto d: data) {
            printf("%d %d %d\n", d.worker_index, d.bike_index, d.manhattan_dist);
        }
        printf("\n");
        std::sort(data.begin(), data.end(), [](const struct Node node1, const struct Node node2) {
            if(node1.manhattan_dist < node2.manhattan_dist) return true;
            else if(node1.manhattan_dist > node2.manhattan_dist) return false;
            else if(node1.worker_index < node2.worker_index) return true;
            else if(node1.worker_index > node2.worker_index) return false;
            else if(node1.bike_index < node2.bike_index) return true;
            else return false;});
        
        for(auto d: data) {
            printf("%d %d %d\n", d.worker_index, d.bike_index, d.manhattan_dist);
        }
        printf("\n");
        std::vector<int> ans(numworkers, -1);
        std::set<int> b;
        for(int i = 0; i < data.size(); i++) {
            int worker_index = data[i].worker_index;
            int bike_index = data[i].bike_index;
            int dist = data[i].manhattan_dist;
            printf("1.i=%d w_i=%d b_i=%d d_i=%d a_i=%d b_c_i=%d\n", i, worker_index, bike_index, dist, ans[worker_index], b.count(bike_index));
            if(ans[worker_index] == -1 and b.count(bike_index)==0) {
                b.insert(bike_index);
                ans[worker_index] = bike_index;
            }
            printf("2.i=%d w_i=%d b_i=%d d_i=%d a_i=%d b_c_i=%d\n", i, worker_index, bike_index, dist, ans[worker_index], b.count(bike_index));
            if(b.size() == numworkers) break;
        }
        return ans;
    }


int main() {
    vector<vector<int>> workers = {{0,0},{1,1},{2,0}}, bikes = {{1,0},{2,2},{2,1}};
    vector<int> a = assignBikes(workers, bikes);
    for(auto v: a) printf("%d ", v);  printf("\n");
    return 0;
    
}