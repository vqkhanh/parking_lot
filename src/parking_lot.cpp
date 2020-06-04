#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

#define CM_CR "create_parking_lot"
#define CM_PR "park"
#define CM_LV "leave"
#define CM_ST "status"
#define EMPTY_STR " "

fstream f2;

void write_line(string data){
	f2 << data;
}

void get_CM(string line){
	int32_t index = line.find(EMPTY_STR);
		//int32_t search_index2 = line.find(CM_PR);

		if(index != -1){
			string str = line.substr(0,index);
			//cout << str;
			//cout << line.at(line.length() - 1);
			if(str == CM_CR){
				//cout << "create ";
 				string ch = line.substr(index, line.length() - 1);
				string str_out = "Created parking lot with ";
				str_out += ch;
				str_out += " lots";
				cout << str_out;
				write_line(str_out);
			}else if(str == CM_PR){
				//cout << "park ";
			}else if(str == CM_LV){
				//cout << "leave ";
			}
		}else{
			if(line == CM_ST){
				//cout << "status";
			}
		}
}

void read_input(){
	fstream f;
	f.open("input.txt", ios::in);

	//fstream f2;
	f2.open("output.txt", ios::out);
 
	string data;
 
	string line;
	while (!f.eof())
	{
		getline(f, line);
		int32_t index = line.find(CM_CR);
		//int32_t search_index2 = line.find(CM_PR);
		//if(index != -1){
		//	cout << line.at(line.length() - 1);
			get_CM(line); 
		//}
		//cout << search_index;

		//cout << search_index2;
		//data += line;
	}
 
	f.close();
 
	//cout << data;
	//cout << CM_CRE;
}
 
int main()
{
	read_input();
	write_file();
}
