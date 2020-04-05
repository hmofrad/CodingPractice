/*
 *  https://leetcode.com/problems/unique-email-addresses/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

std::string filter(std::string email) {
        std::string raw;
        int m = email.length();
        int i = 0;
        int j = 0;
        bool end = false;
        for(i = 0; i < m; i++) {
            if(email[i] == '@') {i++; break;}
            else if(email[i] == '.') {
                int len = i-j;
                raw += email.substr(j, len);
                j = i+1;
            }
            else if(email[i] == '+') {
                int len = i-j;
                raw += email.substr(j, len);
                i++;
                while(email[i] != '@') i++;
                j = i+1;
                //printf("%d %d %c\n", i, j, email[i]);
                if(email[i] == '@') {end = true; break;}
            }            
        }
        
        //printf("%d %d\n", i, j);
        if(not end) {
            int len = i-j;
            raw += email.substr(j, len);
        }
        
        raw += email.substr(i, m-i);
        return(raw);
    }
    



std::string filter1(std::string email) {
    int m = email.length();
    std::vector<bool> status(m);
    int i = 0;
    while(i<m) {
        //printf("%d\n", i);
        if(email[i] == '@') {
            while(i<m) {
                status[i++] = 1;
            }
            break;
        }
        else if(email[i] == '.') {
            status[i] = 0;
            i++;
        }
        else if(email[i] == '+') {
            status[i++] = 0;
            while(email[i] != '@') {
            //while(email[i] != '+' and email[i] != '@') {
                    status[i++] = 0;
            }

            //if(email[i] == '+') {
            //    status[i++] = 0;
            //}
            
            //j = i+1;
            //printf("%d %d %c\n", i, j, email[i]);
            //if(email[i] == '@') {i++; end = true; break;}
        }
        else {
            status[i] = 1;
            i++;
        }
    }
    std::string raw;
    for(i = 0; i < m; i++) {
        if(status[i])
            raw += email[i];
    }
    
    return(raw);
} 
 
 
int numUniqueEmails(vector<string>& emails) {
    std::unordered_map<std::string, int> my_map;
    for(auto email: emails) {
        std::string temp = filter(email);
        printf("%s --> %s\n", email.c_str(), temp.c_str());
        my_map[temp]++;
    }
    
    for(auto m: my_map) {
        printf("%s %d\n", m.first.c_str(), m.second);
    }
    
    return(my_map.size());
}

int main() {
std::vector<std::string> strs = {"fg.r.u.uzj+o.pw@kziczvh.com","r.cyo.g+d.h+b.ja@tgsg.z.com","fg.r.u.uzj+o.f.d@kziczvh.com","r.cyo.g+ng.r.iq@tgsg.z.com","fg.r.u.uzj+lp.k@kziczvh.com","r.cyo.g+n.h.e+n.g@tgsg.z.com","fg.r.u.uzj+k+p.j@kziczvh.com","fg.r.u.uzj+w.y+b@kziczvh.com","r.cyo.g+x+d.c+f.t@tgsg.z.com","r.cyo.g+x+t.y.l.i@tgsg.z.com","r.cyo.g+brxxi@tgsg.z.com","r.cyo.g+z+dr.k.u@tgsg.z.com","r.cyo.g+d+l.c.n+g@tgsg.z.com","fg.r.u.uzj+vq.o@kziczvh.com","fg.r.u.uzj+uzq@kziczvh.com","fg.r.u.uzj+mvz@kziczvh.com","fg.r.u.uzj+taj@kziczvh.com","fg.r.u.uzj+fek@kziczvh.com"};
int r = numUniqueEmails(strs);
return(0);
}