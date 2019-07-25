//  2019年7月25日 
//  leetcode第208题 https://leetcode-cn.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    /** Initialize your data structure here. */
    struct TreeNode{
        TreeNode* child[26];    //  前缀树 在本题中元素仅包含 a-z 26个小写字母
        int end = false;        //  到当前节点是否是一个完整的单词
    };
    
    TreeNode *tr;
    
    Trie() {
        tr = new TreeNode();
    }
    
    TreeNode* create(){
        TreeNode* tree = new TreeNode();
        for(int i = 0; i < 26; ++i)
            tree->child[i] = nullptr;
        return tree;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* t = tr;
        for(auto ch: word){
            if(t->child[ch - 'a'] == nullptr)
                t->child[ch - 'a'] = create();
            t = t->child[ch - 'a'];
        }
        t->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* t = tr;
        for(auto ch: word){
            if(t->child[ch - 'a'] == nullptr)
                return false;
            t = t->child[ch - 'a'];
        }
        return t->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* t = tr;
        for(auto ch: prefix){
            if(t->child[ch - 'a'] == nullptr)
                return false;
            t = t->child[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
