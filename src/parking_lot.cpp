//
//  parking_lot.cpp
//  tets
//
//  Created by Vo Khanh on 6/5/20.
//  Copyright © 2020 khanhvo. All rights reserved.
//

#include "parking_lot.h"

#define CM_CR "create_parking_lot"
#define CM_PR "park"
#define CM_LV "leave"
#define CM_ST "status"
#define EMPTY_STR " "
#define FULL_STR "\nSorry, parking lot is full"
#define STATUS_TITLE "\nSlot No. Registration No."
#define CREATE_LOT_STR "\nAllocated slot number: "
#define CREATE_NUM_LOT_STR "Created parking lot with"
#define PRICE 10
#define EX_PRICE 10
#define REGULAR_HOURS 2
#define INPUT_STR "input.txt"
#define OUPUT_STR "output.txt"

fstream fi;
fstream fo;

unsigned int nLots = 0;

struct lot{
    bool status;
    string carName;
};

lot *lots;

// close files
void close_files(){
    if (fi.is_open()) {
     fi.close();
    }
    if (fo.is_open()) {
        fo.close();
    }
}

// write a line
void write_line(string data){
    fo << data;
}

// create lots
int create_lots(string line, size_t index){
    string ch = line.substr(index);
    string str_out = CREATE_NUM_LOT_STR;
    str_out += ch;
    str_out += " lots";
    nLots = stoi(ch);
    lots = new lot[nLots];
    write_line(str_out);
    for(int i = 0; i < nLots; i++){
        lots[i].status = false;
    }
    return 0;
}

// write paking line
int parking(string line, size_t index){
    if(nLots == 0){
          write_line(FULL_STR);
      }else{
          string res_str = line.substr(index + 1);
          int i = 0;
          for(; i < nLots; i++){
              if(lots[i].status == false){
                  lots[i].status = true;
                  lots[i].carName = res_str;
                  string str_out = CREATE_LOT_STR;
                  str_out += to_string(i + 1);
                  write_line(str_out);
                  break;
              }
          }
          if(i == nLots){
               write_line(FULL_STR);
          }
      }
    return 0;
}

// write leave status
int leave(string line, size_t index){
    size_t l_index = line.rfind(EMPTY_STR);
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
    return 0;
}

// write status parking area
int parking_status(){
    write_line(STATUS_TITLE);
    for(int i = 0; i < nLots; i++){
        if(lots[i].status == true){
            string str_out = "\n";
            str_out += to_string(i + 1);
            str_out += " ";
            str_out += lots[i].carName;
            write_line(str_out);
         }
    }
    return 0;
}

// get commands from file
int get_CM(string line){
    size_t index = line.find(EMPTY_STR);
    string str = line.substr(0,index);
    if(index != string::npos){
        if(str == CM_CR){
            create_lots(line, index);
        }else if(str == CM_PR){
            parking(line, index);
        }else if(str == CM_LV){
            leave(line, index);
        }
    }else{
        if(line == CM_ST){
            parking_status();
        }else{
            return -1;
        }
    }
    return 0;
}

// Read open input.txt, ouput.txt, read input
int read_files(string str_in, string str_out){
    try {
        fi.open(str_in, ios::in);
        if (fi.fail()) {
            return -1;
        }
        fo.open(str_out, ios::out);
        if (fo.fail()) {
            fi.close();
            return -2;
        }
        string line;
        while (!fi.eof())
        {
            getline(fi, line);
            get_CM(line);
        }
        close_files();
        return 0;
    }catch(int e){
        close_files();
        return 1;
    }
}
 
int main(int argc, const char * argv[])
{
    read_files(INPUT_STR, OUPUT_STR);
    if(lots){
        delete[] lots;
    }
    return 0;
}
