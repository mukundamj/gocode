#include <iostream>
#include <vector>
#include <fstream>
#include "arabic_to_roman_num.hpp"

using namespace std;

namespace a_to_r
{
  void print_about()
  {
    string ABOUT = "";
    ABOUT += "\nThis program converts input numbers in Arabic format to Roman. To run\n";
    ABOUT += "\nthis program execute the command ./convert_arabic_to_roman. The program\n";
    ABOUT += "\nasks you to input a number >= 1 without commas in Arabic format, if the\n";
    ABOUT += "\nnumber is not in proper Arabic format the program will throw an error.\n";
    ABOUT += "\nAssumptions:\n";
    ABOUT += "\nRoman numerals only support whole numbers >= 1. For large numbers no\n";
    ABOUT += "\nspecial format like Apostrophus or Vinculum is used. The data type for\n";
    ABOUT += "\nthe input arabic number is long, on a compiler which allocates 4 bytes for\n"; 
    ABOUT += "\nlong this program can support a maximum value of 4,294,967,295.\n";
  
    cout << "\n################################################################\n";
    cout << ABOUT;
    cout << "\n################################################################\n";
    
    return;
  }
  
  void print_input_instructions()
  {
    cout << "\n################################################################\n";
    cout << "\nRunning the Program for converting Arabic number to Roman. Enter\n";
    cout << "\nthe Arabic number between 1 and 4,294,967,295(without commas). To\n";
    cout << "\nconver a list of Arbic numbers to Roman enter them them in space\n";
    cout << "\nseparated format. Enter 0 to quit the program\n";
    return;
  }
  
  void print_roman(string &roman_num)
  {
    if (roman_num.size() <= 100)
    { 
      cout << "The Roman number format for the input is : ";
      cout << roman_num << "\n";
    }
    else
    {
      cout << "The Roman number format has larger than 100 characters, hence writing\n";
      cout << "the output to the file roman_num.txt\n";
      ofstream file_to_write("roman_num.txt");
      if (file_to_write.is_open())
      {
        file_to_write << roman_num; 
        file_to_write.close();
        cout << "Completed writing to roman_num.txt\n";
      }
      else
      {
        cout << "Unable to open the file roman_num.txt for writing\n";
      }
    }
    return;
  }
  
  long get_arabic_num()
  {
    while (1)
    {
      long num;
      cin >> num;
      if (!cin || num < 0)
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cerr << "\nPlease enter a number between 1 and 4,294,967,295 without commas\n";
        cerr << "\nor 0 to quit\n";
      }
      else return num;
    }
  }
  
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
    
    print_roman(roman_num); 
    return true;
  }
  
  void print_quit_msg()
  {
    cout << "\nQuitting the program\n";
    cout << "\n################################################################\n";
    return;
  }
} //namespace a_to_r
