#pragma once
#include <string>

namespace a_to_r
{
  void print_about();
  void print_input_instructions();
  void print_roman(std::string &roman_num);
  long get_arabic_num();
  bool arabic_to_roman_num(long num);
  void print_quit_msg();
}
