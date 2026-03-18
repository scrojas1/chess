#include "Notation.h"
#include <string>
#include <utility>
#include <iostream>


std::pair<int,int> notationToIndex(const std::string& notation){
    if(notation.length() != 2){
        std::cerr<<"ERROR: Invalid notation input"<<std::endl;
        return {-1,-1};
    }
    char file = notation[0];
    char rank = notation[1];
    int col = file-'a';
    int row = 8-(rank-'0');
    return{row,col};   

}

std::string indexToNotation(int row, int col){
    char rank = '8'-row;
    char file = 'a' + col;
    std::string notation;
    notation.push_back(file);
    notation.push_back(rank);
    return notation;

}