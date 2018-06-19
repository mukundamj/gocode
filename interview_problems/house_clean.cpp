/*
  Assume that you have a robot which has the following robot class

  class robot {
    bool move_front();
    void turn_right();
    void turn_left();
  }

  The move function tries to move the cleaning robot by 1 step, if there is any obstruction
  because of which the cleaning robot couldn't move the function returns false else
  it returns true. The turn right/left function turns the root by 90 degrees in
  clockwise/anticlockwise deirection.

  The objective is to clean the entire house using those functions. You can assume that
  the house is made up of uniform grids, a move function will move the robot by 1 grid.
  Assume that the house has all kinds of usual obstructions like furniture, walls etc.  

  Calculate the time complexity and think about scaling problem.
*/

#include <iostream>
#include <vector>

using namespace std;

class robot {
  public:
    robot();
    void clean_the_house(vector<vector<char>> &house);

  private:

    void dfs_scan(vector<vector<char>> &house);

    /*
    When this method is called the robot will move by 1 step and returns a true.
    If the robot couldn't move because of an obstruction the move function will
    return false. In the real world use case move function need not have house
    layout as input argument, a sensor in the robot can detect collision and
    abort the move whenever there is a collision
    */
    
    bool move_front(vector<vector<char>> &house);
    bool move_back();

    //When this function is called the robot will turn right by 90 deg
    void turn_right();

    //When this function is called the robot will turn left by 90 deg
    void turn_left();

    //This is the reference initial direction of the robot. It's initialized to
    //(1, 0) indicating the +ve x-axis. When the turn_right() or turn_left()
    //method is called the direction is appropriately adjusted
    int direction_idx;

    vector<pair<int, int>> directions;
    
    pair<int, int> current_pos;
};

robot::robot()
{
  directions.push_back(make_pair(1, 0));
  directions.push_back(make_pair(0, -1));
  directions.push_back(make_pair(-1, 0));
  directions.push_back(make_pair(0, 1));
  
  direction_idx = 0; //Corresponding to (1, 0)

  /*
  In the real world use case the current pos need not be set, the position where
  it starts can be considered at (0, 0) co-ordinate and with reference to this
  all the scanning can be done
  */
  current_pos = pair<int, int>(2, 2);
}

bool robot::move_front(vector<vector<char>> &house)
{
  pair<int, int> new_pos;
  new_pos.first = current_pos.first + directions[direction_idx].first;
  new_pos.second = current_pos.second + directions[direction_idx].second;
  if (house[new_pos.first][new_pos.second] == 'w') return false;
  current_pos = new_pos;
  return true;
}

bool robot::move_back()
{
  pair<int, int> new_pos;
  new_pos.first = current_pos.first - directions[direction_idx].first;
  new_pos.second = current_pos.second - directions[direction_idx].second;
  current_pos = new_pos;
  return true;
}


void robot::turn_right()
{
  direction_idx = (direction_idx + 1) % 4;
}

void robot::turn_left()
{
  direction_idx = (direction_idx == 0) ? 3 : (direction_idx - 1);
}

void robot::clean_the_house(vector<vector<char>> &house)
{
  printf("r = %d, c = %d ", current_pos.first, current_pos.second);
  house[current_pos.first][current_pos.second] = 'c';
  if (move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_right();
  if (move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_right();
  if (move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_right();
  if (move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_right();
  return;
}

void robot::dfs_scan(vector<vector<char>> &house)
{
  printf("r = %d, c = %d ", current_pos.first, current_pos.second);
  if (house[current_pos.first][current_pos.second] == 'c')
  {
    cout << "\n";
    return;
  }

  house[current_pos.first][current_pos.second] = 'c';
  turn_left();
  if(move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_right();
  if(move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_right();
  if(move_front(house))
  {
    dfs_scan(house);
    move_back();
  }

  turn_left();
  return;
}

int main(int argc, const char* argv[])
{
  robot my_robot;
  /*
  In the below matrix 'w' means wall, robot cannot go through the wall. The move
  function will return false if the robot hits the wall, 'd' means dirty, once
  the floor is cleaned the 'd' will be replaced with 'c' meaning clean
  */
  vector<vector<char>> house = {
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
    {'w', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'w', 'w', 'd', 'w', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'w', 'w', 'd', 'w', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'w', 'w', 'd', 'w', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'w', 'w', 'd', 'w', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'w'},
    {'w', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'w'},
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
  };

  cout << "House before cleaning looks like this\n"; 

  for (int i = 0; i < house.size(); i++)
  {
    for (int j = 0; j < house[0].size(); j++) 
    {
      printf("%c ", house[i][j]);
    }
    printf("\n");
  }

  my_robot.clean_the_house(house);
  cout << "House cleaning completed and the cleaned house looks like this\n"; 
  for (int i = 0; i < house.size(); i++)
  {
    for (int j = 0; j < house[0].size(); j++) 
    {
      printf("%c ", house[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
