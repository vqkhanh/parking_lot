// function_need_to_test.h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void close_files();
int write_line(string data);
int create_lots(string line, size_t index);
int parking(string line, size_t index);
int leave(string line, size_t index);
int parking_status();
int get_CM(string line);
int read_files(string str_in, string str_out);
