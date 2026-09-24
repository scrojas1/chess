#pragma once
#include "Piece.h"

class Piece;

class Board{
    public:
        Board();
        ~Board();
        void initBoard();
        void printBoard() const;

        void placePiece(int row, int col, Piece* piece);
        void movePiece(int startRow, int startCol, int targetRow, int targetCol);
        void setupStartPosition();    
    private:
        Piece* board[8][8];

};

