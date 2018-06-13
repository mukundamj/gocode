#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    string numberToWords(int num);
  private:
    string get_string_for_3_digits(const string & s, vector<string> & words_0_to_99);
    string get_3_tail_digits(const string & s_num); 
};

string Solution::numberToWords(int num) {

  vector<string> words_0_to_99 = {"zero", "one", "two", "three", "four", "five", 
    "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eightteen", "nineteen", "twenty"
  };

  vector<string> prefix_twenty_to_ninety = {"twenty", "thirty", "fourty", "fifty",
    "sixty", "seventy", "eighty", "ninety"};  

  for(int i = 21; i <= 99; i++) {
    string units = (i % 10 == 0 ? "" : words_0_to_99[i % 10]);
    string digits = prefix_twenty_to_ninety[i/10 - 2];
    words_0_to_99.push_back(digits + " " + units);
  }

  if (num <= 99) {
    return words_0_to_99[num];
  }

  string s_num = to_string(num);
  vector<string> weights = {" ", " thousand ", " million ", " billion ", " trillion ",
    " zillion "
  };

  string ret;
  int w = 0;
  while (s_num.size()) {
    string tail = get_3_tail_digits(s_num);
    if (tail != "000") {
      ret = get_string_for_3_digits(tail, words_0_to_99) + weights[w] + ret;
    }
    w++;
    s_num.pop_back(); 
    s_num.pop_back(); 
    s_num.pop_back(); 
  }
  return ret;
}

string Solution::get_string_for_3_digits(const string & s, vector<string> & words_0_to_99) {
  string ret;
  ret = s[0] == '0' ? "" : words_0_to_99[s[0] - '0'] + " hundred";
  ret += " " + words_0_to_99[stoi(s.substr(1,2))];
  return ret;
}

string Solution::get_3_tail_digits(const string & s_num) {
  size_t len = s_num.size();
  if (len >= 3) {
    return s_num.substr(len - 3, 3);
  }
  else if (len == 2) {
    return "0" + s_num;
  }
  return "00" + s_num;
}

int main(int argc, const char * argv[]) {
  Solution S;
  //int num = 123456789;
  string input_str;
  while (getline(std::cin, input_str)) {
    int num = stoi(input_str); 
    printf("%s represented in words is: %s\n", input_str.c_str(), S.numberToWords(num).c_str());
  }
  return 0;
}

