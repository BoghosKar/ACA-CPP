#include <iostream>
#include "../include/pieces.h"
#include "../include/king.h"
#include "../include/queen.h"
#include "../include/bishop.h"
#include "../include/knight.h"
#include "../include/rook.h"
#include "../include/pawn.h"

int main()
{
   Pieces* king = new King();
   Pieces* queen = new Queen();
   Pieces* bishop = new Bishop();
   Pieces* knight = new Knight();
   Pieces* rook = new Rook();
   Pieces* pawn = new Pawn();

    const int numPieces = 6;
    Pieces* pieces[numPieces] = {king, queen, bishop, knight, rook, pawn};

    for (int i = 0; i < numPieces; i++)
    {
        pieces[i]->stats();
    }

    for (int i = 0; i < numPieces; i++)
    {
        delete pieces[i];
    }


    std::cout << "Press Enter to close" << std::endl;
    std::cin.get();
    return 0;
};