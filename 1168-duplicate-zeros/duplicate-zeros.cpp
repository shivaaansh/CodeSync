class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        for (int x : arr) {
            if (x == 0) zeros++;
        }

        int i = n - 1;
        int j = n + zeros - 1;

        while (i >= 0) {
            if (j < n) {
                arr[j] = arr[i];
            }
            j--;

            if (arr[i] == 0) {
                if (j < n) {
                    arr[j] = 0;
                }
                j--;
            }
            i--;
        }
    }
};
