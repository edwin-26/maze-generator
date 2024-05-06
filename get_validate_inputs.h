#ifndef GET_VALIDATE_INPUTS_H
#define GET_VALIDATE_INPUTS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <cgicc/Cgicc.h>

using namespace std;
using namespace cgicc;

void getAndValidateInputs();

int getAndValidateSize(const Cgicc &cgi);

#endif // GET_VALIDATE_INPUTS_H
