#include "Game.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iomanip>

Game::Game() : m_nGridRows(k_nGridRowsDefault), m_nGridColumns(k_nGridColumnsDefault), m_iTorpedoesRemaining(k_nMaxTorpedoes) {
    srand(time(NULL));
    reset();
}

void Game::reset() {
    for (int i = 0; i < m_nGridRows; ++i) {
        for (int j = 0; j < m_nGridColumns; ++j) {
            a_cGrid[i][j] = '~';
        }
    }
    placeBoat();
}

void Game::placeBoat() {
    m_iRowBoat = rand() % m_nGridRows;
    m_iColumnBoat = rand() % m_nGridColumns;
    a_cGrid[m_iRowBoat][m_iColumnBoat] = 'V';
}

void Game::run() {
    while (m_iTorpedoesRemaining > 0) {
        printGrid();
        std::tuple<int, int> coord = promptForGridCoord();
        fireTorpedo(coord);
        if (isOnTarget(std::get<0>(coord), std::get<1>(coord))) {
            showSunk();
            std::cout << "You have sunk the Battle Boat!\n";
            break;
        }
        --m_iTorpedoesRemaining;
    }
    if (m_iTorpedoesRemaining == 0) {
        std::cout << "You have exhausted all torpedoes!\n";
        printGrid(true); // Show the boat
    }
}

void Game::fireTorpedo(const std::tuple<int, int>& coordinates) {
    int row = std::get<0>(coordinates);
    int col = std::get<1>(coordinates);
    if (isOnTarget(row, col)) {
        a_cGrid[row][col] = 'X';
    } else if (isCloseToTarget(row, col)) {
        std::cout << "Close miss! Try again.\n";
    } else {
        std::cout << "Miss!\n";
    }
}

bool Game::isOnTarget(int iRow, int iColumn) {
    return iRow == m_iRowBoat && iColumn == m_iColumnBoat;
}

bool Game::isCloseToTarget(int iRow, int iColumn) {
    return std::abs(iRow - m_iRowBoat) <= 1 && std::abs(iColumn - m_iColumnBoat) <= 1;
}

void Game::showSunk() {
    a_cGrid[m_iRowBoat][m_iColumnBoat] = 'X';
}

std::tuple<int, int> Game::promptForGridCoord() {
    int row, col;
    std::cout << "Enter coordinates (row col): ";
    std::cin >> row >> col;
    return std::make_tuple(row, col);
}

void Game::printGrid(bool bShowBoat) {
    std::cout << "Grid:\n";
    for (int i = 0; i < m_nGridRows; ++i) {
        for (int j = 0; j < m_nGridColumns; ++j) {
            if (!bShowBoat && a_cGrid[i][j] == 'V') {
                std::cout << "~ ";
            } else {
                std::cout << a_cGrid[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
