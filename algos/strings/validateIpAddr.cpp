#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string validIPAddress(string IP) {
      int size = IP.size();
      string ret = "Neither";
      size_t pos1 = 0;
      size_t pos2; 
      int chunk = 0;
      if (size >= 15 && size <= 39) {
        while (chunk <= 8) {
          pos2 = IP.find(':', pos1);
          string str = IP.substr(pos1, pos2 - pos1);
          if (!(str.size() >= 1 && str.size() <= 4)) break;
          else {
            string::iterator it = str.begin();
            while (it != str.end()) {
              cout << "chunk = " << chunk << " " << str << " " << *it << endl;
              //if (!((*it >= 48 && *it <= 57) || (*it >= 65 && *it <= 70) || (*it >= 97 && *it <= 102))) return ret = "Neither";
              if (!((*it >= '0' && *it <= '9') || (*it >= 'A' && *it <= 'F') || (*it >= 'a' && *it <= 'f'))) return ret = "Neither";
              ++it;
            }
            ++chunk;
          }
          if (pos2 == string::npos) break;
          pos1 = pos2 + 1;
        }
        if (chunk == 8 && pos2 == string::npos) return ret = "IPv6";
      }

      pos1 = 0;
      chunk = 0;
      if (size >= 7 && size <= 15) {
        while (chunk <= 4) {
          pos2 = IP.find('.', pos1);
          string str = IP.substr(pos1, pos2 - pos1);
          if (!(str.size() >= 1 && str.size() <= 3))  break;
          else {
            string::iterator it = str.begin();
            if ((str.size() == 3 || str.size() == 2) && *it == 48) break;
            cout << "chunk = " << chunk << " " << str << endl;
            int num = 0;
            while (it != str.end()) { 
              //if (!(*it >= 48 && *it <= 57)) return ret = "Netiher"; 
              if (!(*it >= '0' && *it <= '9')) return ret = "Netiher";
              num = num * 10 + (*it++ - 48);
            }
            cout << "num: " << num << endl;
            if (!(num >= 0 && num <= 255)) break;
            ++chunk;
          }
          if (pos2 == string::npos) break;
          pos1 = pos2 + 1;
        }
        if (chunk == 4 && pos2 == string::npos) return ret = "IPv4";
      }

      return ret;
    }
};

int main(int argc, const char * argv[]) {
  Solution S;
  if (argc != 2) {
    cout << "Insufficient args" <<  endl;
    exit;
  }
  string IP(argv[1]);
  cout << S.validIPAddress(IP) << endl;
  return 0;
}

