/*
 *	https://leetcode.com/problems/rabbits-in-forest/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*For rabits with same colors, the answers must be the same. However, when the total amount of that same answer exceeds 'that answer + 1', there must be a new color. (say [3,3,3,3,3], the first four 3s indicates 4 rabits with the same color. The 5th 3 must represent a new color that contains 4 other rabits). We only calculate the amount of rabits with the same color once. Hashmap is used to record the frequency of the same answers. Once it exceeds the range, we clear the frequency and calculate again.*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        std::unordered_map<int, int> map;
        int count = 0;
        for(int a: answers) {
            if(a==0) count++;
            else {
                if(map[a]==0) count += (a+1);
                map[a]++;
                if(map[a]==a+1) map[a]=0;
            }
        }
        
        return count; 
    }
    int numRabbits1(vector<int>& answers) {
        if(answers.empty()) return 0;
        std::sort(answers.begin(), answers.end());
        int size = answers.size();
        int s = (answers[0]+1);
        for(int a: answers) printf("%d ", a); printf("\n");
        for(int i = 1; i < size; i++) {
            printf("a[%d]=%d, %d\n", i, answers[i], s);
            //if(answers[i]==0) s++;
            //else 
                if(answers[i]+answers[i-1]+1>s) { s+= (answers[i]+1); }
        }
        return s;
    }
};