/*
 *  Problem: https://leetcode.com/problems/encode-and-decode-tinyurl/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    std::unordered_map<int, std::string> map;
    int i = 10;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        map[i] = longUrl;
        std::string shortUrl = "http://tinyurl.com/";
        shortUrl += std::to_string(i);
        i++;
        //printf("1.<%s> <%s> %d\n", longUrl.c_str(), shortUrl.c_str(), i);
        return(shortUrl);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int j = 0;
        for(j = shortUrl.length()-1; j >= 0; j--) {
            if(shortUrl[j] == '/') {
                break;
            }
        }
        std::string str = shortUrl.substr(j+1, shortUrl.length()-j);
        //printf("<%s> %d %d\n", str.c_str(), j, shortUrl.length());
        j = std::stoi(str);
        //int j = (int) ('0'-shortUrl.back());
        //printf("%d\n", j);
        std::string longUrl = map.find(j)->second;
        //printf("2.<%s> <%s> %d\n", longUrl.c_str(), shortUrl.c_str(), j);
        return(longUrl);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));