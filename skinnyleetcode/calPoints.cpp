/*
 *  https://leetcode.com/problems/baseball-game/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::vector<int> valid;
        int sum = 0;
        //int last = 0;
        //int last1 = 0;
        //int last2 = 0;
        for(std::string op: ops) {
            int s = 0;
            if(op == "+") {
                if(valid.size() >= 2) {
                    s+=(valid[valid.size()-1] + valid[valid.size()-2]);
                    valid.push_back(s);
                }
                sum +=s;
            }
            else if(op == "D") {
                if(valid.size() >= 1) {
                    s = 2*valid.back();
                    
                    valid.push_back(s);
                }
                //if(last1>=0) s += (last1*2);
                //last2=last1;
                //last1=s;
                
                sum+=s;
            }
            else if(op == "C") {
                if(not valid.empty()) {
                    s=valid.back();
                    //printf("cancel %d\n", s);
                    valid.pop_back();
                }
                sum-=s;
            }
            else {
                s = stoi(op);
                valid.push_back(s);
                //last2=last1;
                //last1=s;
                sum+=s;
                
                
            }
            //printf("[%s %d] %d %d\n", op.c_str(), sum,s, valid.size());
        }
        return(sum);
    }
};