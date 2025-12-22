class Solution {
    public int countBinarySubstrings(String s) {
        int zeros=0, ones=0;
        int last=-1,count=0;
        for(char c:s.toCharArray()) {
            if(c == '0') {
                if(last == 1) zeros=0;
                zeros++;
                last=0;
            } else {
                if(last == 0) ones=0;
                ones++;
                last=1;
            }
            if((last==1 && zeros >= ones) || (last==0 && ones >= zeros)) count++;
        }
        return count;
    }
}