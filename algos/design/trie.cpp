#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class TrieNode {
  public:
    TrieNode(bool);
    TrieNode* next[26];
    bool isEndOfWord;
};

TrieNode::TrieNode(bool b = false) {
  isEndOfWord = b;
  memset(next, 0, sizeof(next));
}

class Trie {
  private:
    TrieNode* root;
    TrieNode* _find(string);
    void _freeTrie(TrieNode*);
  public:
    Trie();
    ~Trie();
    void insert(string);
    bool search(string);
    bool startsWith(string);
};

Trie::Trie() {
  root = new TrieNode;
}

Trie::~Trie() {
  cout << "In trie descructor" << endl;
  _freeTrie(root);
}

void Trie::insert(string word) {
  TrieNode* current = root; 
  for (int i = 0; i < word.size(); i++) {
    if(current->next[word[i] - 'a'] == NULL) {
      current->next[word[i] - 'a'] = new TrieNode();
    }
    current = current->next[word[i] - 'a'];
  }
  current->isEndOfWord = true;
}

bool Trie::search(string word) {
  TrieNode* lastNode = _find(word);
  if (lastNode != NULL && lastNode->isEndOfWord) return true;
  return false;
}

bool Trie::startsWith(string prefix) {
  TrieNode* lastNode = _find(prefix);
  if (lastNode != NULL) return true;
  return false;
}

TrieNode* Trie::_find(string word) {
  TrieNode* current = root;
  for (int i = 0; i < word.size(); i++) {
    if (current->next[word[i] - 'a'] == NULL) return NULL;
    current = current->next[word[i] - 'a'];
  }
  return current;
}

void Trie::_freeTrie(TrieNode* r) {
  if (r == NULL) return; 
  for (int i = 0; i < (sizeof(r->next)/sizeof(TrieNode*)); i++) {
    if (r->next[i] != NULL) {
      _freeTrie(r->next[i]);
      free(r->next[i]);
    }
  }
  return;
}

int main() {
  Trie dict;
  dict.insert("abcd");
  dict.insert("abcdefg");
  dict.insert("bcd");
  dict.insert("bcdefg");
  dict.insert("c");
  dict.insert("d");
  cout << "abcd exists : " << dict.search("abcd") << " abcdefg exists : " << dict.search("abcdefg") << " ab exists : " << dict.search("ab") << " abc as prefix exists : " << dict.startsWith("abc") << endl;
  return 0;
}

