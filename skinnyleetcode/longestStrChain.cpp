/*
 *  Problem: https://leetcode.com/problems/longest-string-chain/
 *  Compile: g++ -o longestStrChain longestStrChain.cpp -std=c++11 -g -Wall -fsanitize=address && ./longestStrChain
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int abs(int a, int b) {
    return(((a-b) > 0) ? (a-b) : (b-a));
}

bool isPredecessor(std::string str1, std::string str2) {
    int diff = abs(str1.length(), str2.length());
    if((diff == 0) or (diff > 1)) return(false);
    
    std::vector<int> map1(26, 0);
    for(auto c: str1) {
        map1[c-'a']++;
    }
    
    std::vector<int> map2(26, 0);
    for(auto c: str2) {
        map2[c-'a']++;
    }
    
    diff = 0;
    for(uint32_t i = 0; i < 26; i++) {
        diff += abs(map1[i], map2[i]);
        if(diff > 1) {
            break;
        }
    }
    
    return(diff == 1);
}

 int longestStrChain1(std::vector<std::string>& words) {
     std::sort(words.begin(), words.end(), [](std::string a, std::string b) {return a.length() > b.length(); });
     for(auto w: words) {printf("%s ", w.c_str());} printf("\n");
    int max_len = 0; 
    for(uint32_t i = 0; i < words.size(); i++) {
        printf("w[%d]=%s: ", i, words[i].c_str());
        std::string w = words[i];
        int k = 0;
        uint32_t l = i;
        int m = 0;
        while((l < words.size()-1) and words[l].length() == words[l+1].length()) {l++; m++;}
        //l++;
        printf("%d %d\n", l, m);
        while((l < words.size()-1) and words[i].length() == words[l+1].length() - 1) {l++; k++;}
        printf("%d %d\n", l, k);
        
        //for(uint32_t k 
        while(k >= 0) {
            printf("%d-%d:", k, m);
            int len = 1;
            for(uint32_t j = i+1+m; j < words.size(); j++) {
                if(isPredecessor(w, words[j])) {
                    printf("%s ", words[j].c_str());
                    len++;
                    w = words[j];
                }
                //printf("[%s %s] --> %d\n", words[i].c_str(), words[j].c_str(), isPredecessor(words[i], words[j]));    
            }
            printf("%d\n", len);
            k--;
            if(len > max_len) {
                max_len = len;
            }
        }
    }
    return(max_len);
}

 int longestStrChain(std::vector<std::string> words) {
    sort(words.begin(),words.end(), [](std::string a, std::string b) {return a.length() > b.length(); });
    int m = words.size();
    std::vector<int> dp(m+1, 1);
	int index = 0;
	for(int i = 1; i < m; i++){
		for(int j = 0; j < i; j++){
			if(isPredecessor(words[j], words[i])){
				dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
			}
		}
		if(dp[index] < dp[i]){
			index = i;
		}
	}
    return dp[index];
}




int main(int argc, char **argv){
std::vector<std::string> words = {"kwigbkfeqp","tpiufntqzo","blmwegckaplqwjpo","uiesdrhcbvbbk","przuvuo","kntmjgnqbxlwh","glac","uz","qqhw","gdtunmaw","neymepxl","eqtxh","qz","bek","xgadqztq","cicgtxs","grakdthb","kwigbkfeqop","uqyqhjqwegizcx","kewiygbkfejqop","tufntz","gulamac","sluiobdm","ujdyugagn","fuyz","eth","vzxiobwgyhrdkh","ikfjaivyvreql","jimpyin","cuotmvfqzizu","tkopssxh","gmwmzsowjf","nel","zo","kntmmjgnqbxtlwh","cyuicglbdtxwsu","vjrenjwntklm","uevrxuklobce","tkaopssxh","rwkedydnadd","uqyqhjqdwegizcx","ouethhse","zcmmrtilpti","tmfuxxyk","honyw","nyepl","qqhqwix","mjhg","gdtwunmaw","kigbkfeqp","wnyhsm","oeqatxhree","qyqhjqweizcx","xadqztq","wqnyghsmt","ndozeaylmetnpxlj","przuvuhob","wqnlyghnqsmtt","tkossxh","qyqhjqwix","epwcjxytvt","bexk","ga","em","zojodbw","gulmac","cizocgw","suibdm","nvcyutywhus","bwjofkuchx","f","pdtwv","dzohajcodbw","kuc","tpawplvfzlx","mg","re","oh","wciqob","el","wciqo","mftmgv","grakkdthtbd","cnbnyvuhmrj","odqphbhkf","oeqatxhre","sqzrlhs","bwsjofvkuptchx","xdqztq","tmv","kewigbkfejqop","faepomn","bdwwnalubrvxtdgu","cotmfqziz","lvzl","dmqz","hdmqz","gdigs","ujdyugag","mepjqbuvdku","g","kigbkeqp","oegqataxhree","zscinzobcgtwdwhn","fuaepwobimn","qf","cusotmvfqziknzu","qvroffuk","rweydnadd","zoow","meqcfzkbnrb","tpaplvzlx","zscinzocgwdwhn","zcmmrtilpt","ndeaymenpxlj","jimpn","wofkuchx","tkaopsssxh","vodwqphbhkfx","faepwoimn","gzenkasrciui","nyhm","tpufntqzo","ovqeyvxfdll","tufntzo","gmyrmf","vxobwgrdkh","faepwobimn","przujvuhobk","vzxobwgyrdkh","ksszdumgko","kewiylgbkfejqop","rey","vo","qqfe","moyddffrwwyzk","qzwsbnuejvsi","vodwqpzhbhjkfx","r","vttpoelti","sqzrlehhs","tpiuftntqzo","qfe","qyvsrofgnfuk","evxuklce","wiqo","prpzuujvuaxhkobk","gy","vnjxkjvmz","qroffuk","qqhwi","przuvuhobk","mfttmgvj","moydfrwzk","jibmpuyin","pwcytvt","eqtxhre","gcdtwunmaw","wfkucx","ryedhy","vttpolti","qyqhqwix","kutkavldvvqvp","el","tmfuxxyku","tplvzlx","gdtu","z","ksg","xmgadqzptq","qcqfre","zcmmrtiklpti","hobxltexk","vburq","funyz","kc","vjrenjwntklqm","wqnlyghnqsmt","sibdm","vodwqpzhbhkfx","zsnv","pouegzfyk","arci","vzxobwgyhrdkh","fetoesaot","riyedhy","cyuicgtxsu","gdtua","gchdtwgwunmaw","cuotmvfqziz","obltexk","epwcytvt","scinzocgw","ptwv","jimpuyin","uevrxukloce","tkqaopsssxh","pdtwdv","fetsaot","cyuicgldtxsu","przujvuaxhkobk","wciqoxb","gdtuna","lvzlx","ytpawcplvfzlx","uyugag","ksszdumugiko","bm","pgdmigs","grakdthtbd","uyz","zscinzobcgwdwhn","oeqataxhree","qzsbnuvs","gznkarciui","zoodw","jimpin","tqksugh","zuvo","tmgv","gdmigs","sluibdm","nvcxyzwyutywhus","bwsjofkuchx","fetsat","kgbeqp","neymenpxlj","vzxobwgrdkh","tpawcplvfzlx","qbzwsbnuejvsi","przuvuho","wqnlyguhnqsmtt","ujhadylujgaazgsn","axuelrnnnwhg","qbzwsbnuejvsmoi","qzsbnuvsi","yugag","bwsjofvkupchx","mqz","gchdtwunmaw","kntmmjgnqbxlwh","xfpt","vvburq","moydfrwk","qksgh","faepoimn","odwqphbhkfx","ryey","gchdtwwunmaw","uiesdrhcvbbk","qyqhjqwicx","yilxbltwwxh","jrenjwntkm","gzenkarciui","moyddffrhwwyezk","tqksugvhr","oveyvxfl","agmyrmf","scinzocgwdn","neymenpxl","gonpxzngjv","rwkeydnadd","zohjodbw","bdwwnalubvxtdgu","jrenjwntk","ovqheyvxubfdtll","qcqfqrezof","znkarcii","b","qzsnuvs","ndzeaylmenpxlj","tossxh","fetsa","przujvuxhkobk","ovqeyvxubfdll","tpufntzo","cuicgtxs","mv","vbur","moyddffrhwwyzk","yilxcbltwwxh","eqtxhe","zow","qbzwsbnuejvsoi","nvczwyutywhus","cyquicglbdtxwsu","evxukce","axuelrnnwhg","aci","ouemthhqse","wfkuchx","bwsjofvkmuptchx","mfjhg","bwsjofvkuchx","qffu","qyqhjqwegizcx","rzuvuo","uvo","qh","qvsrofgfuk","neymepl","mepjqybuvdku","sqzrlehs","cnbnyvumrj","qcqfqrezoif","gyrm","przujvuhkobk","cuotmvfqzinzu","gym","ujdylujgaagn","thdmmqz","honw","odwqphbhkf","ksszgko","qbzwsbnuejvsmvoi","m","gtu","qyvsrofgfuk","uqqyqhjqdwegizcx","obtexk","hobltexk","ftmgv","bwsjofvkmuptchxy","taynfxo","tqksugvhrc","jibmpduyin","vxue","zuvuo","gonpxzngv","gmpwamzsowjf","rwednadd","zv","tosh","pqdtwdv","zcmmrtsiklpti","tkqaopesssxh","ovqeyvxbfdll","gac","gsqzrlehhs","znv","cuotmvfqziknzu","ryedy","vnjoxkjvmz","pouegnzfyk","evrxuklce","ujdyujgagn","tmfnuxxyku","semj","xmgadvqzptq","cnnyvmrj","gonpxzvngjv","meqczkbnrb","bwofkuchx","fuvnyz","znarci","moydffrwzk","kwigbkfejqop","wqnyghnsmt","uiesdrehcbvobbk","qcqfreo","zohajodbw","nvcxyzwyutywhuhs","scinzocgwdwn","ksyszdumugiko","qfu","mjg","zsnuvs","eqth","ccgtxs","pgdmidtgs","rwednad","lel","cusotmvfqzwiknzu","znkarciui","o","qzsbnuevsi","veodwqpzhbhjkfx","jrenjwntklm","gmwamzsowjf","ndeymenpxlj","moydffrwwzk","nvczyutywhus","dzohajodbw","ujadylujgaazgsn","nvcytywhus","qcqfrezo","mfttmgv","tqksugvh","qksg","njxkjvmz","udyugag","qffuk","ksszdugko","wkuc","tmfxxyk","qqh","sbdm","rwedna","ovqheyvxubsfdtll","ndzeaymenpxlj","neyepl","qf","xgadqzptq","redna","pougzfyk","zarci","mftbtmgvj","taplvzlx","uiesdrhcbvobbk","ovqeyvxfdl","qcqfrezof","qvrofgfuk","scizocgw","mftbtmgvdj","rsgwmsted","ovqheyvxubfdll","oveyvxfdl","m","wi","znkarci","ikfjaivyvrql","pgdmidgs","btexk","cuotmfqziz","xdqzq","jimp","qqhqwi","lvz","ilojawyersju","wnyhm","gsqzrlenhhs","bu","wkucx","bdm","lsel","tpawplvzlx","ai","kntmmjognqbxtlwh","hkonyw","vxuce","zsnvs","qyqhjqweicx","nyel","cyuicgtxs","qzsbnuejvsi","ujadylujgaagsn","thdmqz","ilojawyersu","uevirxuklobce","qrffuk","zoodbw","sem","cyuicgldtxwsu","wnyhsmt","prpzujvuaxhkobk","uesdrhcvbbk","vhvburq","ndzeaylmetnpxlj","ksszdgko","scinzocgwd","cyuicgltxsu","ptw","mplaxm","scinzocgwdwhn","ytpawcplvifzlx","evxuce","bur","kigbeqp","ksszdumugko","cnnyvumrj","toh","kewiylgbkfejqfop","gulac","pugzfyk","nvcyzwyutywhus","ouemthhse","wqnyghnqsmt","b","ujdylujgagn","tlvzlx","pgidmidtgs","eqatxhre","gmyrm","dqzq","oveyvxl","vttpoeltci","gk","wqnyhsmt","zcmmrtsitklpti","iaxuelrnnnwhg","gdtunma","ujadylujgaagn","tqksgh","moydffrwwyzk","mfftbtmgvdj","wio","fetosaot","grakdthtb","nxmrvm","evrxukloce","ikfjaivyrql","tosxh","grakkbdthtbd","epwcxytvt","blmwegckaplwjpo","qcqfe"};
//{"x","pxvaurr","cfgg","pxvaurnrr","cvbts","jplhf","zjplhjf","jlh","zjplhjtf","cvts","cvt","jplh","gkexf","bluw","pblieumgw","pblieugw","clvlbpts","clvbpts","h","gukexasf","blu","cv","v","exf","pxvaurrr","zjplhf","gukexaf","cf","pbliugw","xaur","cfgsg","bphxe","pxvaur","u","pblireumgw","lu","gukexf","cfg","cvbpts","xur","xf","kexf","ur","pxaur","pbluw","pbliuw","jh"};
//{"ddgpj","oopwqq","ooq","oopq","iwdkeoqqtd","iwdkeoqqt","oopwq","t","wdoqqt","vcw","ddgpjy","ddpj","njpci","njci","ft","q","wdkeoqqt","dqq","qq","ni","eihk","ebiihzke","eihzke","eik","eiihzke","dqqt","eihzk","vw","ddp","oq","wdeoqqt","nci","doqqt","vft"};
    //{"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    //{"a","b","ba","bca","bda","bdca"};
    int l = longestStrChain(words);
    printf("%d\n", l);
    return(0);
}