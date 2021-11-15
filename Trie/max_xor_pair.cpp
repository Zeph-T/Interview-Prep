class node{
    public:
    node* left; // 1
    node* right; // 1
};


class trie{
    node* root;
    public:
    trie(){
        root = new node();
    }
    
    void insert(int n){
        node* curr = root;
        for(int i=31;i>=0;i--){ // the max depth of the tree will be 32 since, at max there are 32 bits, can be converted to 64 if dealing with long long
            int bit = (n >> i) & 1;
            if(bit ==0){
                if(curr->left == NULL){ // if the bit is not present, create the node and move forward else, just move
                    curr->left = new node();
                }
                curr = curr->left;
            }else{
                if(curr->right == NULL){
                    curr->right = new node();
                }
                curr = curr->right;
            }
        }
    }
    
    int maxXORHelper(int value){
        int current_ans = 0;
        node* temp = root;
        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1; // check the left or right node is present or not, to get max xor, we need a flip bit,if the flip bit is present, we got to that node, else we go to the other node
            if(bit == 0){
                if(temp->right != NULL){
                    temp = temp->right;
                    current_ans += (1 << j);
                }
                else{
                    temp = temp->left;
                }
            }else{
                if(temp->left != NULL){
                    temp = temp->left;
                    current_ans += (1 << j);
                }else{
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }
    
    int maxXOR(vector<int>nums){
        int ans = 0;
        for(int num : nums){
            this->insert(num);
            ans = max(ans ,maxXORHelper(num) );
        }
        return ans;
    }
    
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie Trie;
        return Trie.maxXOR(nums);
    }
};