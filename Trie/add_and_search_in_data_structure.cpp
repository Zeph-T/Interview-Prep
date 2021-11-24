
class Node{
    public :
    char data;
    unordered_map<char,Node*>m;
    bool isTerminal;
    Node(char d){
        data = d;
        isTerminal = false;
    }
    friend class WordDictionary;
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
        Node* temp= root;
        for(char ch : word){
            if(temp->m.count(ch) == 0){
                Node* newNode = new Node(ch);
                temp->m[ch] = newNode;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        return searchWord(word,temp,0);
    }
    
    bool searchWord(string word,Node* node, int pos){
        if(pos == word.size())return node->isTerminal;
        
        if(word[pos] != '.'){ // if the char is not dot, the process is the same
            if(node->m.count(word[pos]) > 0){
                return searchWord(word,node->m[word[pos]],pos+1);
            }else{
                return false;
            }
        }
        
        for(auto child : node->m){ // we have to generate all the possible iterations
            if(searchWord(word,child.second,pos+1))return true;
        }
        return false;
        
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */