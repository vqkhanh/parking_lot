//
//  parking_lot.h
//  tets
//
//  Created by Vo Khanh on 6/5/20.
//  Copyright © 2020 khanhvo. All rights reserved.
//

#ifndef parking_lot_h
#define parking_lot_h


#endif /* parking_lot_h */

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

