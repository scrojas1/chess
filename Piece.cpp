#include <iostream>
#include "Piece.h"



Piece::Piece(PieceType type, PieceColor color){
    this->color = color;
    this->type = type;
}

PieceType Piece::getType() const {
    return this->type;
}

PieceColor Piece::getColor() const{
    return this->color;
}

char Piece::getSymbol() const{
    char res;
    switch (this->type)
    {
    case PieceType::PAWN:
        res = 'p';
        break;
    case PieceType::KNIGHT:
        res = 'n';
        break;
    case PieceType::BISHOP:
        res = 'b';
        break;
    case PieceType::ROOK:
        res = 'r';
        break;
    case PieceType::QUEEN:
        res = 'q';
        return toupper(res);
    }
    return res;

}

bool Piece::isMoveValid(int startRow, int startCol, int targetRow,
    int targetCol, const Board& board){
    
    int direction = (color == PieceColor::WHITE) ? -1 : 1;
    int deltaRow = targetRow - startRow;
    int deltaCol = targetCol - startCol;

    switch (this->type)
    {
    case PieceType::PAWN:
        if(targetRow == startRow + direction && startCol == targetCol){
            return true;
        }
        break;
    case PieceType::ROOK:
        if(deltaRow == 0 || deltaCol==0){
            return true;
        }
        break;
    case PieceType::BISHOP:
        if(abs(deltaRow) == abs(deltaCol)){
            return true;
        }
        break;
    case PieceType::KNIGHT:
        if((abs(deltaRow) == 1 && abs(deltaCol) == 2) ||
        (abs(deltaRow) == 2 && abs(deltaCol)== 1)){
            return true;
        }
        break;
    case PieceType::QUEEN:
        if(abs(deltaRow) == abs(deltaCol) || (deltaRow == 0 || deltaCol==0)){
            return true;
        }
        break;
    case PieceType::KING:
        if(abs(deltaRow) <= 1 && abs(deltaCol) <= 1){
            return true;
        }
        break;
        
    default:
        break;
    }
    return false;
     }
