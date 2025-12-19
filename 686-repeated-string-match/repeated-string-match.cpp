class Solution {
public:
    bool solution(string &a, string &b) {
        string x = b + "#" + a;
        int n = x.size();

        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && x[i] != x[j]) {
                j = lps[j - 1];
            }

            if (x[i] == x[j]) {
                j++;
            }

            lps[i] = j;

            if (lps[i] == b.size()) {
                return true;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string tmp = a;
        int ans = 1;

        while (a.size() < b.size()) {
            a += tmp;
            ans++;
        }

        if (solution(a, b)) return ans;

        a += tmp;
        if (solution(a, b)) return ans + 1;

        return -1;
    }
};
