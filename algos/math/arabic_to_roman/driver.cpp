#include "arabic_to_roman_num.hpp"

int main(int argc, const char * argv[])
{
  if (argc == 2 && argv[0] != NULL && argv[1] != NULL)
  {
    std::string arg2 = argv[1];
    if (arg2 == "-h")
    {
      a_to_r::print_about();
      return 0;
    }
  }

  a_to_r::print_input_instructions();

  while (1)
  {
    long num = a_to_r::get_arabic_num();
    if (num == 0)
    {
      a_to_r::print_quit_msg();
      return 0;
    }
    else
    {
      a_to_r::arabic_to_roman_num(num);  
    }
  }
  return 0;
}
