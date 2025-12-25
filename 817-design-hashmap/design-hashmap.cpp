class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<list<pair<int,int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);

        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);

        for (auto &p : table[idx]) {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        
        
        table[idx].remove_if([&](auto &p) {
            return p.first == key;
        });
    }
};
