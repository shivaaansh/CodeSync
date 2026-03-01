class Solution {
public:
    int Mod = 1e9 + 7;

    long long power(long long base, long long exp, int Mod) {
        long long ans = 1;
        base %= Mod;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % Mod;
            }
            base = (base * base) % Mod;
            exp /= 2;
        }

        return ans;
    }

    string makeBinary(int n) {
        string s; 
        while (n > 0) {
            s.push_back('0' + (n % 2));
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int makeNumber(string s) {
        long long n = 0;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            n = (n * 2 + (s[i] - '0')) % Mod;   
        }

        return n;
    }

    int concatenatedBinary(int n) {
        string s;

        for (int i = 1; i <= n; i++) {
            s += makeBinary(i);
        }

        return makeNumber(s);
    }
};