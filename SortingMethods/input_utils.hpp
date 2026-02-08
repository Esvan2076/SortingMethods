#pragma once

#include <string>

#include "number.hpp"

void clearConsole();
void pause();
short transInputToShort(const std::string&);
int transInputToInt(const std::string&);
Number createNumber();