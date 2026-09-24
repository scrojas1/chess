#include <iostream>
#include "Board.h"


Board::Board(){
    initBoard();    
}
Board::~Board(){
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            if(this->board[row][col] != nullptr){
                delete this->board[row][col];
                this->board[row][col] = nullptr;

            }
        }
    }
}

void Board::initBoard(){
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            this->board[row][col] = nullptr;
        }
        
    }
    
}

void Board::printBoard() const{
    for (int row = 7; row >= 0; row--)
    {
        std::cout<< row << " ";
        for (int col = 0; col < 8; col++)
        {
            if(this->board[row][col] == nullptr){
                std::cout<<". ";
            }
            else{
                std::cout<<this->board[row][col]->getSymbol()<<" ";
            }
            //std::cout<<board[row][col];
        }
        std::cout<<std::endl;
    }
    std::cout<<"  a b c d e f g h"<<std::endl;
}

void Board::placePiece(int row, int col, Piece* piece){
    if(this->board[row][col] != nullptr){
        delete this->board[row][col];
    }
    this->board[row][col] = piece;
}

void Board::movePiece(int startRow, int startCol, int targetRow, int targetCol){
    
    if(startRow < 0 || startCol < 0 || targetCol < 0 || targetRow < 0 || startRow > 7 ||
    startCol > 7 || targetCol > 7 || targetRow > 7){
        std::cerr<<"ERROR: Invalid position"<<std::endl;
        return;
    }

    if(board[startRow][startCol] == nullptr){
        //if no piece, throw error
        std::cerr<<"ERROR: No piece at "<< startRow << "," << startCol<<std::endl;
        return;
    }
    if(board[targetRow][targetCol] != nullptr){
        //if piece at destination, delete it
        delete board[targetRow][targetCol];
        board[targetRow][targetCol] = nullptr;
    }
    board[targetRow][targetCol] = board[startRow][startCol];
    board[startRow][startCol] = nullptr;
}

void Board::setupStartPosition(){


    PieceType lineup[8] = {PieceType::ROOK,PieceType::KNIGHT,PieceType::BISHOP,PieceType::QUEEN,
        PieceType::KING,PieceType::BISHOP,PieceType::KNIGHT,PieceType::ROOK};
    
    for(int row = 0; row < 8; row++){
        board[1][row] = new Piece(PieceType::PAWN, PieceColor::WHITE);
        board[6][row] = new Piece(PieceType::PAWN, PieceColor::BLACK);
        board[0][row] = new Piece(lineup[row],PieceColor::WHITE);
        board[7][row] = new Piece(lineup[row], PieceColor::BLACK);
    }

}