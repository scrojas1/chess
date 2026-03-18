#pragma once
#include "Piece.h"

class Board{
    public:
        Board();
        ~Board();
        void initBoard();
        void printBoard() const;

        void placePiece(int row, int col, PieceType type, PieceColor color);
        void movePiece(int startRow, int startCol, int targetRow, int targetCol);
        void setupStartPosition();    
    private:
        Piece* board[8][8];

};

