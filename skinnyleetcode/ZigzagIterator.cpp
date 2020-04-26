/*
 *  https://leetcode.com/problems/zigzag-iterator/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class ZigzagIterator {
public:
    int nvectors;
    std::vector<std::vector<int>> vectors;
    std::vector<int> indices;
    int last = 0;
    bool empty = false;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        nvectors = 2;
        vectors.resize(nvectors);
        for(int i = 0; i < nvectors; i++) {
            if(i==0) vectors[i] = v1;
            if(i==1) vectors[i] = v2;
        }
        indices.resize(nvectors);
    }

    int next() {
        int v = -1;
        if(hasNext()) {
            int& index = indices[last];
            std::vector<int>& vector = vectors[last];
            last = (last+1)%nvectors;
            v = vector[index++];
        }
        return v;
    }

    bool hasNext() {
        int ntimes = 0;
        while(not empty) {
            int& index = indices[last];
            std::vector<int>& vector = vectors[last];
            if(index < vector.size()) return true;
            last = (last+1)%nvectors;
            ntimes++;
            if(ntimes == nvectors) empty = true;
        }
        
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */