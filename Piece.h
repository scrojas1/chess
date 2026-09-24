
#pragma once
#include "Board.h"

class Board;


enum class PieceType{
    NONE,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum class PieceColor{
    NONE,
    WHITE,
    BLACK
};

class Piece{
    public:
        Piece(PieceType type, PieceColor color);
        PieceType getType() const;
        PieceColor getColor() const;
        char getSymbol() const;
        bool isMoveValid(int startRow, int startCol, 
        int targetRow, int targetCol, const Board& board);
    private:
        PieceType type;
        PieceColor color;
};

