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
  cout << "Search word is " << word << endl;
  return _find(word.c_str(), root);
}

bool WordDictionary::_find(const char *w, TrieNode* root) {
  if (*w == '\0') { //For a string the end of string is always marked by '\0' character
    if (root->isEndOfWord) return true;    
    return false;
  }
  cout << "Search word inside find is " << w << endl;
  if (*w == '.') {
    for (int i = 0; i < 26; i++) {
      if (root->next[i] == NULL) continue;
      return _find(w+1, root->next[i]);
    }
  }
  else {
    return _find(w+1, root->next[*w - 'a']);
  }
}

void WordDictionary::_freeWordDictionary(TrieNode* r) {
  if (r == NULL) return; 
  for (int i = 0; i < (sizeof(r->next)/sizeof(TrieNode*)); i++) {
    if (r->next[i] != NULL) {
      _freeWordDictionary(r->next[i]);
      free(r->next[i]);
    }
  }
  return;
}

int main(int argc, const char* argv[]) {
  WordDictionary dict;
  string keyWord, word;
  while (1) {
    cout << "Enter keyWord" << endl;
    cin >> keyWord;
    if (keyWord != "add" && keyWord != "search") {
      cout << "keyWord should be add or search" << endl;
      continue;
    }
    if (keyWord == "add") {
      cout << "Enter the word to be added" << endl;
      cin >> word;
      cout << "Adding " << word << " to dictionary" << endl;
      dict.addWord(keyWord);
    }
    else if (keyWord == "search") {
      cout << "Enter the word to be searched" << endl;
      cin >> word;
      cout << "Does the word exists in dictionary : " << dict.search(word) << endl;
    }
  }
  return 0;
}

