/*
 * https://leetcode.com/problems/validate-ip-address/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution0 {
public:
    string validIPAddress(string IP) {
        if(count(IP.begin(),IP.end(),'.')==3) {
            // in case of 0.0.0., getline will stop on the last .
            // so we have to check manually
            if(IP[IP.size()-1]=='.') return "Neither"; 
            string token;
            stringstream s(IP); //convert the given string into stream for using getline function;
            while(getline(s,token,'.')) {
                if(token.length()==0 || token.length()>3) return "Neither";
                if(token[0]=='0' && token.length()!=1) return "Neither";
                for(char ch : token) if(!isdigit(ch)) return "Neither";
                if(stoi(token)>255) return "Neither";
            }
            return "IPv4";
        }
        else if(count(IP.begin(),IP.end(),':')==7) {
            if(IP[IP.size()-1]==':') return "Neither"; // same as above
            string token;
            stringstream s(IP);
            while(getline(s,token,':')) {
                if(token.length()==0 || token.length()>4) return "Neither";
                for(char ch : token) if(!isxdigit(ch)) return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};
 
class Solution {
public:
    
    std::tuple<std::vector<std::string>, std::vector<char>> tokenize(std::string IP, char seperator) {
        std::vector<std::string> octets;
        std::vector<char> separators;
        int len = IP.length();
        int i = 0, j = 0;
        for(; i < len; i++) {
            char c = IP[i];
            if(c == seperator) {
                int l = i-j;
                std::string token = IP.substr(j, l);
                j=i+1;
                octets.push_back(token);
                separators.push_back(c);
            }
        }
        if(j<len) {
            int l = i-j;
            std::string token = IP.substr(j, l);
            octets.push_back(token);
        }
        return {octets, separators};
    }
    
    
    std::string ipv4(std::string IP) {
        std::vector<std::string> octets;
        std::vector<char> separators;
        std::tie(octets, separators) = tokenize(IP, '.');
        
        if(octets.size()!=4 or separators.size()!=3) { return "Neither"; }
        
        for(std::string& octet: octets) {
            if(octet.empty()) { return "Neither"; }
            int num = stoi(octet);
            if((octet.front()=='0' and octet.size()>1) or octet.size()>3 or num>255) { return "Neither"; }
        }
        
        return "IPv4";
    }
    
    
    std::string ipv6(std::string IP) {
        std::vector<std::string> octets;
        std::vector<char> separators;
        std::tie(octets, separators) = tokenize(IP, ':');
        
        if(octets.size()!=8 or separators.size()!=7) { return "Neither"; }
        
        bool first_octet = true;
        for(std::string& octet: octets) {
            if(octet.empty()) { return "Neither"; }
            else if(first_octet) {
                if(octet.front()=='0') { return "Neither"; }
                first_octet = false;
            }
            else if(octet.length()>4) { return "Neither"; }
        }
       
        return "IPv6";
    }
    
    bool quick_validation_v4(std::string IP, char separator) {
        for(char c: IP) {
            if(not((c>='0' and c<='9') or c==separator)) { return false; }
        }
        return true;
    }
    bool quick_validation_v6(std::string IP, char separator) {
        for(char c: IP) {
            if(not((c>='0' and c<='9') or (c>='a' and c<='f') or (c>='A' and c<='F') or c==separator)) { return false; }
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        //IP="12.0.0.4";
        //IP="2001:0db8:85a3:0:0:8A2E:0370:7334";
        //printf("?   %s <%c> <%c>\n", IP.c_str(), IP[0], IP[1]);
        if(IP.empty()) { return "Neither"; }
        bool v4 = quick_validation_v4(IP, '.');
        bool v6 = quick_validation_v6(IP, ':');
        if(not v4 and not v6) { return "Neither"; }
        //printf("%d %d\n", v4, v6);
        std::string type = "Neither";
        if(v4) {
            if(IP.length()<16) { type = ipv4(IP); }
        }
        else  { 
            if(IP.length()<40) { type = ipv6(IP); }
        }
        return type;
    }
};