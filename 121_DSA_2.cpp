#include <iostream>
using namespace std;
#define N 8

class KnightTour {
private:
    int board[N][N];
    int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    
    void initializeBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = -1;
            }
        }
    }

    
    bool isValidMove(int x, int y) {
        return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
    }

    bool solveKnightTour(int x, int y, int moveCount) {
        if (moveCount == N * N) {  
            return true;
        }

    
        for (int i = 0; i < 8; i++) {
            int nextX = x + moveX[i];
            int nextY = y + moveY[i];

            if (isValidMove(nextX, nextY)) {
                board[nextX][nextY] = moveCount;  

                
                if (solveKnightTour(nextX, nextY, moveCount + 1)) {
                    return true;
                }

                
                board[nextX][nextY] = -1;
            }
        }

        return false;  
    }

public:
    KnightTour() {
        initializeBoard();
    }

    
    bool startTour(int startX, int startY) {
        board[startX][startY] = 0; 

        if (solveKnightTour(startX, startY, 1)) {
            printBoard();
            return true;
        } else {
            cout << "No solution found." << endl;
            return false;
        }
    }


    void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    KnightTour knightTour;
    int startX = 0, startY = 0;  

    if (knightTour.startTour(startX, startY)) {
        cout << "Knight's Tour completed successfully!" << endl;
    }

    return 0;
}
