
#pragma once
#include <string>
#include <utility>

std::pair<int,int> notationToIndex(const std::string& notation);

std::string indexToNotation(int row, int col);