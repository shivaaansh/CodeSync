class Trie {
public:
    vector<Trie*> temp;
    bool isEnd;
    Trie* root;

    Trie() {
        temp.resize(26, nullptr);
        isEnd = false;
        root = nullptr;
    }

    void insert(string word) {
        if(root == nullptr) {
            root = new Trie();
        }
        Trie* crw = root;
        for(char ch : word) {
            if(crw->temp[ch-'a'] == nullptr) {
                crw->temp[ch-'a'] = new Trie();
            }
            crw = crw->temp[ch-'a'];
        }
        crw->isEnd = true;
    }

    bool search(string word) {
        Trie* crw = root;
        if(!crw) return false;
        for(char ch : word) {
            if(crw->temp[ch-'a'] == nullptr) return false;
            crw = crw->temp[ch-'a'];
        }
        return crw->isEnd;
    }

    bool startsWith(string word) {
        Trie* crw = root;
        if(!crw) return false;
        for(char ch : word) {
            if(crw->temp[ch-'a'] == nullptr) return false;
            crw = crw->temp[ch-'a'];
        }
        return true;
    }
};
