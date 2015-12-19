/*
    实现一个前缀树
    因为每个节点最多只有26个孩子，所以我们为每个节点设置一个大小为26的指针数组表示它的孩子
    另外还要用一个bool类型表示该节点是不是某个单词的末尾

    因为题目没有要求，所以代码中没有给出析构函数，要写也非常简单，每个点手动释放就可以了
*/
class TrieNode {
public:
    TrieNode* son_node[26];
    bool isWord;
    // Initialize your data structure here.
    TrieNode() {
        memset(son_node,0,sizeof(son_node));
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        root->isWord = true;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* pos = root;
        for(int i = 0;i < word.size();i++) {
            int slot = word[i] - 'a';
            if(pos->son_node[slot] == NULL)
                pos->son_node[slot] = new TrieNode();
            pos = pos->son_node[slot];
        }
        pos->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* pos = root;
        for(int i = 0;i < word.size();i++) {
            int slot = word[i] - 'a';
            if(pos->son_node[slot] == NULL)  return false;
            pos = pos->son_node[slot];
        }
        if(!pos->isWord)    return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* pos = root;
        for(int i = 0;i < prefix.size();i++) {
            int slot = prefix[i] - 'a';
            if(pos->son_node[slot] == NULL)  return false;
            pos = pos->son_node[slot];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
