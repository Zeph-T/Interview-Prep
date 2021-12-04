class Node{
    public:
        unordered_map<char,Node*>m;
        bool isTerminal;
        char data;
        Node(char ch){
            this->data = ch;
            isTerminal = false;
        }
};



class StreamChecker {
public:
    string completed = "";
    Node*root;

    void insert(string word){
        Node* temp = root;
        for(int i=word.size() - 1  ; i >= 0 ; i--){
            char ch = word[i];
            if(temp->m.count(ch)==0){
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    StreamChecker(vector<string>& words) {
        root = new Node('\0');
        for(string word : words){
            insert(word);
        }
    }
    
    

    
    bool query(char letter) {
        completed += letter;
        Node* temp = root;
        for(int i=completed.size()-1;i>=0;i--){
            char ch = completed[i];
            if(!temp or temp->m.count(ch) == 0)return false;
            temp = temp->m[ch];
            if(temp and temp->isTerminal)return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */