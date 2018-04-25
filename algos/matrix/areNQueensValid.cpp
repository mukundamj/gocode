#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
  This program will take a N x N chess board with queens marked on it as input 
  and determines if all the queens are safe. This program has not been thoroughly
  tested. There is a related problem on leetcode.com which requires us to find
  all combinations of possible safe positions for N queens on N x N chess board
*/
class Solution {
  public:
    bool are_n_queens_valid(vector<vector<char>> & chess_board);

  private:
    void mark_not_allowed_cells(int row, int col, set<pair<int, int>>& 
      not_allowed_cells, int board_size);
};

bool Solution::are_n_queens_valid(vector<vector<char>> & chess_board) {
  int board_size = chess_board[0].size();
  vector<bool> queen_rows(board_size, false);
  vector<bool> queen_cols(board_size, false);
  //Initially I thought of using unordered_set<pair<int, int>> for not_allowed_cells
  //but found out that c++ doesn't allow it because a hash of pair<int, int> doesn't 
  //make sense
  set<pair<int, int>> not_allowed_cells;
  vector<pair<int, int>> queen_positions;
  
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      if (chess_board[i][j] == 'q') {
        queen_positions.emplace_back(i, j);
        if (queen_rows[i] == true || queen_cols[j] == true) return false;
        else queen_rows[i] = queen_cols[j] = true;
        mark_not_allowed_cells(i, j, not_allowed_cells, board_size);
      }
    }
  }

  for (auto pos : queen_positions) {
    set<pair<int, int>>::iterator it_set;
    it_set = not_allowed_cells.find(pos);
    if (it_set != not_allowed_cells.end() && *it_set != pos) return false;
  }    

  return true;
}

void Solution::mark_not_allowed_cells(int row, int col, set<pair<int, int>>& 
  not_allowed_cells, int board_size) 
{
  int _row = row, _col = col;
  while (_row >= 0 && _col >= 0) {
    not_allowed_cells.emplace(_row--, _col--);
  }

  _row = row; _col = col;
  while (_row < board_size && _col < board_size) {
    not_allowed_cells.emplace(_row++, _col++);
  }
  
  _row = row; _col = col;
  while (_row < board_size && _col >= 0) {
    not_allowed_cells.emplace(_row++, _col--);
  }

  _row = row; _col = col;
  while (_row >= 0 && _col < board_size) {
    not_allowed_cells.emplace(_row--, _col++);
  }

  return;
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<vector<char>> chess_board
  {
    {'.', '.', '.', '.'},
    {'.', 'q', '.', '.'},
    {'.', '.', '.', 'q'},
    {'q', '.', '.', '.'},
  };

  cout << "Are n queens valid? " << S.are_n_queens_valid(chess_board) << endl;  
  return 0;
}
