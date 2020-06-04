//
//  main.cpp
//
//  Created by Vo Khanh on 6/4/20.
//  Copyright © 2020 khanhvo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

#define CM_CR "create_parking_lot"
#define CM_PR "park"
#define CM_LV "leave"
#define CM_ST "status"
#define EMPTY_STR " "
#define FULL_STR "Sorry, parking lot is full"
#define PRICE 10
#define EX_PRICE 10
#define REGULAR_HOURS 2

fstream f2;
unsigned int nLots = 0;

typedef struct lot{
    bool status;
    string carName;
};

lot *lots;

void write_line(string data){
    f2 << data;
}

void get_CM(string line){
    int32_t index = line.find(EMPTY_STR);
    string str = line.substr(0,index);
    if(index != -1){
        if(str == CM_CR){
            string ch = line.substr(index);
            string str_out = "Created parking lot with";
            str_out += ch;
            str_out += " lots";
            nLots = stoi(ch);
            lots = new lot[nLots];
            write_line(str_out);
            for(int i = 0; i < nLots; i++){
                lots[i].status = false;
            }
        }else if(str == CM_PR){
            if(nLots == 0){
                write_line(FULL_STR);
            }else{
                string res_str = line.substr(index + 1);
                int i = 0;
                for(; i < nLots; i++){
                    if(lots[i].status == false){
                        lots[i].status = true;
                        lots[i].carName = res_str;
                        string str_out = "\nAllocated slot number: ";
                        str_out += to_string(i + 1);
                        write_line(str_out);
                        break;
                    }
                }
                if(i == nLots){
                     write_line("\nSorry, parking lot is full");
                }
            }
        }else if(str == CM_LV){
            int32_t l_index = line.rfind(EMPTY_STR);
            string str_middle = line.substr(index + 1,l_index - index - 1);
            string res_str = line.substr(l_index + 1);
            int i = 0;
            for(; i < nLots; i++){
               if(lots[i].status == true && str_middle.compare(lots[i].carName) == 0){
                   lots[i].status = false;
                   lots[i].carName = "";
                   string str_out = "\nRegistration number ";
                   str_out += str_middle;
                   str_out += " with Slot Number ";
                   str_out += to_string(i + 1);
                   str_out += " is free with Charge ";
                   int times =  stoi(res_str);
                   int charge = (times <= REGULAR_HOURS) ? PRICE : (PRICE + ((times - REGULAR_HOURS) * EX_PRICE));
                   str_out += to_string(charge);
                   write_line(str_out);
                   break;
               }
            }
            if(i == nLots){
                string str_out = "\nRegistration number ";
                str_out += str_middle;
                str_out += "  not found";
                write_line(str_out);
            }
        }
    }else{
        if(line == CM_ST){
            write_line("\nSlot No. Registration No.");
            for(int i = 0; i < nLots; i++){
                if(lots[i].status == true){
                    string str_out = "\n";
                    str_out += to_string(i + 1);
                    str_out += " ";
                    str_out += lots[i].carName;
                    write_line(str_out);
                 }
            }
        }
    }
}

void read_input(){
    fstream f;
    f.open("ip.txt", ios::in);
    if (f.fail()) {
        // file could not be opened

    }else{
     
    }
    //fstream f2;
    f2.open("output.txt", ios::out);
 
    string data;
 
    string line;
    while (!f.eof())
    {
        getline(f, line);
        get_CM(line);
    }
    f.close();
}
 
int main(int argc, const char * argv[])
{
    read_input();
    return 0;
}

