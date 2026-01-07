
class MagicDictionary {
public:
    unordered_set<string> st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s : dictionary) {
            st.insert(s);
        }
    }
    
    bool search(string sw) {
        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            bool flag = 0;
            for(int j = 0; j < sw.size(); j++) {
                char temp = sw[j];
                sw[j] = ch;
                if(ch != temp && st.find(sw) != st.end()) {flag = 1;}
                sw[j] = temp;
            }
            if(flag) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */