#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (unsigned int x=0; x<word.size(); x++) {
            int i = word[x] - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (unsigned int x=0; x<word.size(); x++) {
            int i = word[x] - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto &a : prefix) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie tri;
    tri.insert("lintcode");
    cout<<tri.search("code")<<endl; // return false
    cout<<tri.startsWith("lint")<<endl; // return true
    cout<<tri.startsWith("linterror")<<endl; // return false
    tri.insert("linterror");
    cout<<tri.search("lintcode")<<endl; // return true
    cout<<tri.startsWith("linterror")<<endl; // return true
    return 0;
}
