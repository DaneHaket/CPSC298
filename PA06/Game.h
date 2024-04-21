#if !defined(GAME_H)
#define GAME_H

#include <tuple>
#include <vector>
#include <iostream>

class Game {
public:
    static const int k_nGridRowsDefault = 4;
    static const int k_nGridColumnsDefault = 5;
    static const int k_nMaxTorpedoes = (k_nGridRowsDefault * k_nGridColumnsDefault) / 2;

private:
    char a_cGrid[k_nGridRowsDefault][k_nGridColumnsDefault];
    int m_nGridRows;
    int m_nGridColumns;
    int m_iRowBoat;
    int m_iColumnBoat;
    int m_iTorpedoesRemaining;

public:
    Game();
    void run();
    void fireTorpedo(const std::tuple<int, int>& coordinates);
    void printGrid(bool bShowBoat = false);
    void placeBoat();
    bool isOnTarget(int iRow, int iColumn);
    bool isCloseToTarget(int iRow, int iColumn);
    void showSunk();
    std::tuple<int, int> promptForGridCoord();
    void reset();
};

#endif // GAME_H