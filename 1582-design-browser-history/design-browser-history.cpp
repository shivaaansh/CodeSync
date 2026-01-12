struct Node {
    string name;
    Node* prev;
    Node* next;
    Node(string name) {
        this->name = name;
        prev = NULL;
        next = NULL;
    }
};
class BrowserHistory {
public:
    Node* root;
    Node* cur;
    BrowserHistory(string homepage) {
        root = new Node(homepage);
        cur = root;
    }
    
    void visit(string url) {
        Node* node = new Node(url);
        cur->next = node;
        node->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        while(steps-- && cur != root) {
            cur = cur->prev;
        }
        return cur->name;
    }
    
    string forward(int steps) {
        while(steps-- && cur != NULL && cur->next != NULL) {
            cur = cur->next;
        }
        return cur->name;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */