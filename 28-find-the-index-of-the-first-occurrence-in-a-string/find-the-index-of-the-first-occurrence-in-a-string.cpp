class Solution {
public:
    int solution(string &a, string &b) {
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
                return i - 2 * b.size();
            }
        }
        return -1;
    }

    int strStr(string a, string b) {
        if (b.empty()) return 0;
        return solution(a, b);
    }
};
