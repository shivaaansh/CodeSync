class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = 0, m = b.size();
        string s = "";
        int cnt = 0;
        while(n <= (m + a.size())) {
            s += a;
            cnt += 1;
            n = s.size();
            for(int i = 0; i < n; i++) {
                bool flag = false;
                if(s[i] == b[0] && (i+m-1) < n) {    
                    flag = true;
                    for(int j = 0; j < m; j++) {
                        if(s[i+j] != b[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag == true) {
                        return cnt;
                    }
                }
            }
        }
        return -1;
    }
};