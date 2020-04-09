/*
 *  https://leetcode.com/problems/web-crawler/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    std::string hostname;
    std::vector<std::string> extracted_urls;
    std::string extract_hostname(std::string url) {
        int length = url.length();
        int i = 0;
        
        while(i+1 < length and url[i+1] != '.') i++;
        int j = i;
        
        while(i > 0 and ((url[i-1] >= 'a' and url[i-1] >= 'z') or (url[i-1] >= '0' and url[i-1] >= '9') or url[i-1] == '-')) i--;
        int start=i;
        
        i = j;
        while(i+1 < length and ((url[i+1] >= 'a' and url[i+1] >= 'z') or (url[i+1] >= '0' and url[i+1] >= '9') or url[i+1] == '.' or url[i] == '-')) i++;
        
        int len = i-start+1;
        std::string temp = url.substr(start, len);
        return(temp);    
    }
    
    void extract(string startUrl, HtmlParser htmlParser) {
        std::vector<string> urls = htmlParser.getUrls(startUrl);
        for(std::string url: urls) {
            //printf("%s --> %s\n", url.c_str(), extract_hostname(url).c_str());
            if(hostname == extract_hostname(url) and std::find(extracted_urls.begin(), extracted_urls.end(), url) == extracted_urls.end()) {
                    extracted_urls.push_back(url);
                extract(url, htmlParser);
                
            }
            
        }
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        //std::vector<string> urls = htmlParser.getUrls(startUrl);
        hostname = extract_hostname(startUrl);
        extracted_urls.push_back(startUrl);
        extract(startUrl, htmlParser);
        /*
        for(std::string url: urls) {
            if(hostname == extract_hostname(url) and std::find(extracted_urls.begin(), extracted_urls.end(), url) == extracted_urls.end()) extracted_urls.push_back(url);
            //printf("%s --> %s\n", url.c_str(), check_urls(url).c_str());
        }
        */
        return(extracted_urls);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};