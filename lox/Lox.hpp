#include <iostream>
#include <fstream>


static bool hadError = false;

void report(int line, std::string& where, std::string& message);