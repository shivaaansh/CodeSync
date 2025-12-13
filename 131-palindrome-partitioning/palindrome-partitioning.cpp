class Solution {    
public:
    vector<vector<int>> pal;
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> v;
    void f(int i, vector<string>str, string s, int n){
        if(i == n){            
            v.push_back(str);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (pal[i][j]) {
                str.push_back(s.substr(i, j - i + 1));
                f(j + 1, str, s,n);
                str.pop_back();
            }
        }  
    }
    
    vector<vector<string>> partition(string s) {
        //every palindrome substring by partitioning only 
        //constraints suggest recursion is possible
        //check every possibility ?
        //how?
       
        int n = s.length();
        pal.resize(n, vector<int> (n, 0));
        // pal[i-1][j+1]
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || pal[i+1][j-1])) {
                    pal[i][j] = 1;
                }
            }
        }
        vector <string> str;
        f(0,str, s, n);
        return v;
    }
};