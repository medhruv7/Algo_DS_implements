struct Trie{
    Trie* next[26];
    bool is_leave = false;
};

void build(Trie* root,string s){
    Trie* cur = root;
    for(int i = 0;i < s.length(); ++i){
        if(root->next[s[i] - 'a'] == NULL){
            root->next[s[i] - 'a'] = new Trie();
        }
        if(i == s.length() - 1){
            root->next[s[i] - 'a']->is_leave = true;
        }
        root = root->next[s[i] - 'a'];
    }
    root = cur;
}

bool search(Trie* root,string s){
    Trie* cur = root;
    for(int i = 0;i < s.length(); ++i){
        if(root->next[s[i] - 'a'] == NULL) return false;
        else{
            root = root->next[s[i] - 'a'];
        }
    }
    bool leaf = root->is_leave;
    root = cur;
    return leaf;
}

void dfs(Trie* root){
    for(int i = 0;i < 26; ++i){
        if(root->next[i] != NULL){
            dfs(root->next[i]);
        }
    }
}
