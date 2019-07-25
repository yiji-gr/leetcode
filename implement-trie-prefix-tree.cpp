//  2019年7月25日 
//  leetcode第208题 https://leetcode-cn.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    /** Initialize your data structure here. */
    int num = 26;
   struct TreeNode{
       TreeNode* child[26];
       int count;
       int is_end = false;
   };
    TreeNode *tree = new TreeNode();
    
    Trie() {
    }
    
    TreeNode* create(){
        TreeNode *node = new TreeNode();
        for(int i = 0; i < num; ++i)
            node->child[i] = NULL;
        return node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *tmp = tree;
        for(int i = 0; i < word.length(); ++i){
            char ch = word[i];
            
            if(tmp->child[ch - 'a'] == NULL){
                TreeNode *node = create();
                tmp->child[ch - 'a'] = node;
            }
            tmp = tmp->child[ch - 'a'];
            tmp->count += 1;
            
            if(i == word.length() - 1)
                tmp->is_end = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *tmp = tree;
        for(int i = 0; i < word.length(); ++i){
            char ch = word[i];
            
            if(tmp->child[ch - 'a'] == NULL)
                return false;
            if(i == word.length() - 1)
                if(!tmp->child[ch - 'a']->is_end)
                    return false;
            tmp = tmp->child[ch - 'a'];
        }
        return true;
    }
    
    // void dfs(TreeNode *tree){
    //     TreeNode *tmp = tree;
    //     for(int i = 0; i < 26; ++i){
    //         if (tmp->child[i] != NULL){
    //             char c = '0' + (i + 1);
    //             cout << c << " ";
    //             dfs(tree->child[i]);
    //         }
    //     }
    // }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *tmp = tree;
        for(int i = 0; i < prefix.length(); ++i){
            char ch = prefix[i];
            if(tmp->child[ch - 'a'] == NULL)
                return false;
            tmp = tmp->child[ch - 'a'];
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
