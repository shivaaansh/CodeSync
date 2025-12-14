class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;

        int prev = 0;  
        int maxi = 1;
        int op = -1;   

        for (int i = 1; i < n; i++) {
            int cur;
            if (arr[i] > arr[i-1]) cur = 1;
            else if (arr[i] < arr[i-1]) cur = 0;
            else cur = -1;

            if (cur == -1) {
                // equals reset window
                prev = i;
                op = -1;
            }
            else if (op == -1) {
                // first valid comparison
                op = cur;
            }
            else if (op == cur) {
                prev = i - 1;
                op = cur;
            }
            else {
                op = cur;
            }

            maxi = max(maxi, i - prev + 1);
        }
        return maxi;
    }
};
