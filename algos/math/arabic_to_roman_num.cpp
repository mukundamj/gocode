/*
  Assumptions:
  Roman numerals only support whole numbers >= 1
  For large numbers no special format like Apostrophus or Vinculum is used. The
  data type for the input arabic number is long, on a compiler which allocates 4 
  bytes for long this program can handle a maximum value of 4,294,967,295.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool arabic_to_roman_num(long num)
{
  vector<string> units = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

  string roman_num;
  int place = 1;

  while (num)
  {
    int rem = num % 10;
    if (place == 1)
    {
      roman_num = units[rem];
    }
    
    if (place == 10)
    {
      roman_num = tens[rem] + roman_num;
    }

    if (place == 100)
    {
      roman_num = hundreds[rem] + roman_num;
    }

    if (place == 1000)
    {
      for (; num; num--)
      {
        roman_num = "M" + roman_num;
      }
    }
    num /= 10;
    place *= 10;
  }
  
  cout << "The Roman number format for the input is :\n";
  cout << roman_num << "\n";
  return true;
}

int main(int argc, const char * argv[])
{
  string ABOUT = "";
  ABOUT += "\nThis program converts input numbers in Arabic format to Roman. To run\n";
  ABOUT += "this program execute the command ./arabic_to_roman_num. The program will\n";
  ABOUT += "ask you to input a number >= 1 without commas in Arabic format, if the\n";
  ABOUT += "number is not in proper arabic format the program will throw an error.\n";
  ABOUT += "\n";
  ABOUT += "Assumptions:\n";
  ABOUT += "Roman numerals only support whole numbers >= 1. For large numbers no\n";
  ABOUT += "no special format like Apostrophus or Vinculum is used. The data type for\n";
  ABOUT += "the input arabic number is long, on a compiler which allocates 4 bytes for\n"; 
  ABOUT += "long this program can support a maximum value of 4,294,967,295.\n";


  if (argc == 2 && argv[0] != NULL && argv[1] != NULL)
  {
    string arg2 = argv[1];
    if (arg2 == "-h")
    {
      cout << "################################################################\n";
      cout << ABOUT;
      cout << "\n################################################################\n\n";
      return 0;
    }
  }

  cout << "\n";
  cout << "################################################################\n";
  cout << "\nRunning the Program for converting Arabic number to Roman\n";
  cout << "\nEnter the Arabic number(without commas) to be converted to Roman\n";
  cout << "Enter 0 to quit the program\n";

  while (1)
  {
    long num;
    cin >> num;
    if (!cin || num < 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      cerr << "Please enter a valid Arabic number. The input cannot contain\n";
      cerr << "any number other than 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 and the \n";
      cerr << "number should be >= 1 \n";
    }
    else if (num == 0)
    {
      cout << "\nQuitting the program\n";
      cout << "################################################################\n";
      return 0;
    }
    else
    {
      arabic_to_roman_num(num);  
    }
  }
  return 0;
}
