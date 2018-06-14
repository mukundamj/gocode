/*
  Assume that you have a robot which has the following robot class

  class robot {
    bool move();
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
