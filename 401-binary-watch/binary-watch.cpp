class Solution {
public:
    vector<string> ans;

    void rec(int t, int hi, int mi, int h, int m,
             vector<int>& hours, vector<int>& mins,
             bool minuteStarted) {

        if (h > 11 || m > 59) return;

        if (t == 0) {
            string s = to_string(h) + ":";
            if (m < 10) s += "0";
            s += to_string(m);
            ans.push_back(s);
            return;
        }

        // pick hour LEDs (ONLY if we haven't started minutes)
        if (!minuteStarted) {
            for (int i = hi; i < hours.size(); i++) {
                rec(t - 1, i + 1, mi, h + hours[i], m,
                    hours, mins, false);
            }
        }

        // pick minute LEDs
        for (int i = mi; i < mins.size(); i++) {
            rec(t - 1, hi, i + 1, h, m + mins[i],
                hours, mins, true);
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        ans.clear();

        vector<int> hours = {8, 4, 2, 1};
        vector<int> mins  = {32, 16, 8, 4, 2, 1};

        rec(turnedOn, 0, 0, 0, 0, hours, mins, false);

        return ans;
    }
};
