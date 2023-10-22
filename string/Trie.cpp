struct trie{
    struct node{
        node *nxt[26];
        int cnt, sz;
        node():cnt(0),sz(0){
            memset(nxt,0,sizeof(nxt));
        }
    };
    node *root;
    void init(){root = new node();}
    void insert(const string& s){
        node *now = root;
        for(auto i:s){
            now->sz++;
            if(now->nxt[i-'a'] == NULL){
                now->nxt[i-'a'] = new node();
            }
            now = now->nxt[i-'a'];
        }
        now->cnt++;
        now->sz++;
    }
};