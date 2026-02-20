class Solution {
public:
    int countBinarySubstrings(string s) {
        int z = 0, o = 0;
        int last = -1, count = 0;
        for(char c : s) {
            if(c == '0') {
                if(last == 1) z = 0;
                z++;
                last=0;
            } else {
                if(last == 0) o=0;
                o++;
                last=1;
            }
            if((last==1 && z >= o) || (last==0 && o >= z)) count++;
        }
        return count;
    }
};