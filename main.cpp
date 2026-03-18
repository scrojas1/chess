#include <iostream>
#include "Piece.h"
#include "Board.h"
#include "Notation.h"




int main(){
    Board board;
    board.printBoard();
    board.setupStartPosition();
    std::cout<<"Placing a rook at 4,2 and a queen at 5,1"<<std::endl;
    board.placePiece(4,2,PieceType::ROOK,PieceColor::BLACK);
    board.placePiece(5,1,PieceType::QUEEN,PieceColor::WHITE);
    board.printBoard();
    std::cout<<"Now moving the rook to the queens square"<<std::endl;
    board.movePiece(4,2,5,1);
    board.printBoard();
    auto [row, col] = notationToIndex("e2");
    std::cout << row << ", " << col << std::endl;

    std::string notation = indexToNotation(row, col);
    std::cout << notation << std::endl;
    return 0;
}

