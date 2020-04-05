/*
 *  https://leetcode.com/problems/iterator-for-combination/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class CombinationIterator {
public:
    std::vector<std::string> combinations;
    int k;
    int i;
    int s;
    
    void combination(string characters, std::string str, int start, int length) {
        if(str.size() == length) combinations.push_back(str);
        else {
            int m = characters.size();
            for(int i = start; i < m; i++) {
                //str += characters[i];
                combination(characters, str+characters[i], i+1, length);
                //str.pop_back();
            }
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        i = 0;
        k = combinationLength;
        
        combination(characters, "", 0, k);
        s = combinations.size();
        //for(std::string comb: combinations) {
        //    printf("%s\n", comb.c_str());
        //}
    }
    
    string next() {
        std::string ret;
        if(i < s) {
            ret = combinations[i];
            i++;
        }

        return(ret);
    }
    
    bool hasNext() {
        return(i<s);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */