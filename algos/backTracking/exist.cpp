#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool exist(vector<vector<char>>&, string);
  private:
    bool exist(vector<vector<char>>&, const char*, int, int); 
    int row;
    int col;
};

bool Solution::exist(vector<vector<char>>& board, string word) {
  row = board.size();
  col = board[0].size();
  cout << "row = " << row << " col = " << col << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (exist(board, word.c_str(), i, j)) return true; 
    }
  }
  cout << endl;
  return false;
}

bool Solution::exist(vector<vector<char>>& board, const char* c, int i, int j) {
  if ((i < 0) || (j < 0) || (i >= row) || (j >= col) || (board[i][j] == '$') || (*c != board[i][j])) {
    return false;
  }
  cout << board[i][j] << " row = " << i << " col = " << j << endl;
  if (*(c + 1) == '\0') return true;
  char temp = board[i][j];
  board[i][j] = '$';
  if (exist(board, c + 1, i - 1, j) ||  exist(board, c + 1, i, j + 1) || exist(board, c + 1, i + 1, j) || exist(board, c + 1, i, j - 1)) {
    return true;
  }
  board[i][j] = temp; 
  return false;
}

int main(int argc, const char* argv[]) {
  Solution S;
  string word = "ABCCED";
  vector<vector<char>> board = {
    {'A','B','C','E'}, 
    {'S','F','C','S'}, 
    {'A','D','E','E'}, 
  };
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << board[i][j] << ", ";
    }
    cout << endl;
  }
  cout << "Does the word exist: " << S.exist(board, word) << endl;
  return 0;
}
