#include <iostream>
#include <fstream> 
//ifstream, ofstream and fstream file stream classes are derived directly or 
//indirectly from istream i.e. cin and ostream i.e cout

using namespace std;

int main(int argc, const char * argv[]) {
  if (argc != 3 || isdigit(stoi(argv[1])) || isdigit(stoi(argv[2]))) {
    printf("Invalid number of arguments.\nThe syntax is "); 
    printf("./test_file_generator.cpp <max num> <debug level 1 or 2 or 3>\n");
    exit(0);
  }
 
  int debug_level = stoi(argv[2]); 
  enum debug_level : int
  {
    LEVEL_1 = 1,
    LEVEL_2 = 2,
    LEVEL_3 = 3,
  };
  ofstream test_file_to_write("test_file_for_int_to_words.txt", ios::out | ios::trunc);

  //As an alternative the test_file_to_write stream can be declared and opened as below
  //In the above method the constructor will automatically call the open method but in
  //the below method construcor and open method are called explicitly

  //ofstream test_file_to_write;
  //test_file_to_write.open("test_file_for_int_to_words.txt", ios::out | ios::trunc);

  //Writing to the file
  if (test_file_to_write.is_open()) {
    for (int i = 0; i < stoi(argv[1]); i++) {
      test_file_to_write << i << "\n";
    }
    test_file_to_write.close();
  }
  else {
    cout << "Unable to open the file test_file_for_int_to_words.txt for writing\n";
  }

  ifstream test_file_to_read("test_file_for_int_to_words.txt", ios::in);

  //As an alternative the test_file_to_read stream can be declared and opened as below
  //In the above method the constructor will automatically call the open method but in
  //the below method construcor and open method are called explicitly

  //ifstream test_file_to_read;
  //test_file_to_read.open("test_file_for_int_to_words.txt", ios::in);

  //Reading from the file and printing only if debug level is >= 2
  if (debug_level >= debug_level::LEVEL_2) {
    if (test_file_to_read.is_open()) {
      string line;
      while (getline(test_file_to_read, line)) {
        cout << line << "\n";
      }
      test_file_to_read.close();
    }
    else {
      cout << "Unable to open the file test_file_for_int_to_words.txt for reading\n";
    }
  }

}
