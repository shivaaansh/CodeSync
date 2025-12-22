class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = idx-1, j = idx;
        cout << idx;
        while(i >= 0 && j < arr.size() && k != 0) {
            if(abs(arr[i] - x) <= abs(arr[j] - x)) {
                i--;
            }else {
                j++;
            }
            k--;
        }
        while(i >= 0 && k != 0) {
            i--; k--;
        }
        while(j < arr.size() && k != 0) {
            j++; k--;
        }
        vector<int> v(arr.begin()+i+1, arr.begin()+j);
        return v;
    }
};