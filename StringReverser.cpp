//
// Created by nizan on 22/01/2020.
//

#include "StringReverser.h"
#include <algorithm>

string StringReverser::solve(string str) {
    reverse(str.begin(), str.end());
    return str;
    

}