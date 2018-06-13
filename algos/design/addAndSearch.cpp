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

class WordDictionary {
  private:
    TrieNode* root;
    bool _find(const char*, TrieNode*);
    void _freeWordDictionary(TrieNode*);

  public:
    // Initialize your data structure here.
    WordDictionary();
    // Free all the memory allocated to the TrieNodes
    ~WordDictionary();
    // Adds a word into the data structure. 
    void addWord(string); 
    // Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
    bool search(string);
};

WordDictionary::WordDictionary() {
  root = new TrieNode;
}

WordDictionary::~WordDictionary() {
  _freeWordDictionary(root);
}

void WordDictionary::addWord(string word) {
  TrieNode* current = root; 
  for (int i = 0; i < word.size(); i++) {
    if(current->next[word[i] - 'a'] == NULL) {
      current->next[word[i] - 'a'] = new TrieNode();
    }
    current = current->next[word[i] - 'a'];
  }
  current->isEndOfWord = true;
}

bool WordDictionary::search(string word) {
  //cout << "Search word is " << word << endl;
  return _find(word.c_str(), root);
}

bool WordDictionary::_find(const char *w, TrieNode* root) {
  if (*w == '\0') { //For a string the end of string is always marked by '\0' character
    if (root->isEndOfWord) return true;    
    return false;
  }
  //cout << "Search word inside find is " << w << endl;
  if (*w == '.') {
    for (int i = 0; i < 26; i++) {
      if (root->next[i] == NULL) continue;
        if (_find(w+1, root->next[i])) return true;
    }
    return false;
  }
  else {
    return (root->next[*w - 'a'] != NULL && _find(w+1, root->next[*w - 'a']));
  }
}

void WordDictionary::_freeWordDictionary(TrieNode* r) {
  if (r == NULL) return; 
  for (int i = 0; i < (sizeof(r->next)/sizeof(TrieNode*)); i++) {
    if (r->next[i] != NULL) {
      _freeWordDictionary(r->next[i]);
      delete r->next[i];
    }
  }
  return;
}

int main(int argc, const char* argv[]) {
  WordDictionary dict;
  dict.addWord("abcd");
  dict.addWord("abcdefg");
  dict.addWord("bcd");
  dict.addWord("bcdefg");
  dict.addWord("c");
  dict.addWord("d");
  dict.addWord("ab");
  cout << "a..e exists : " << dict.search("a..e") << endl;
  cout << "abcd exists : " << dict.search("abcd") << endl;
  cout << ".bcd exists : " << dict.search(".bcd") << endl;
  cout << "..cd exists : " << dict.search("..cd") << endl;
  cout << "...d exists : " << dict.search("...d") << endl;
  cout << ".... exists : " << dict.search("....") << endl;
  cout << ".bc. exists : " << dict.search(".bc.") << endl;
  cout << ".. exists : " << dict.search("..") << endl;
  cout << ". exists : " << dict.search(".") << endl;
  cout << "..... exists : " << dict.search(".....") << endl;
  cout << "ab exists : " << dict.search("ab") << endl;
  return 0;
}

