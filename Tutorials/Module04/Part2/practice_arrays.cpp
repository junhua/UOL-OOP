#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Matrix Calculator
class MatrixCalculator {
public:
    // Print matrix
    void printMatrix(const int matrix[][3], int rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 3; j++) {
                cout << setw(4) << matrix[i][j];
            }
            cout << endl;
        }
    }
    
    // Add matrices
    void addMatrices(const int a[][3], const int b[][3], int result[][3], int rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
    }
    
    // Multiply matrices
    void multiplyMatrices(const int a[][3], const int b[][3], int result[][3], int rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    
    // Calculate determinant (3x3 matrix)
    int determinant(const int matrix[][3]) {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
             - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
             + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }
};

// Image Processor
class ImageProcessor {
public:
    // Initialize image with default values
    void initializeImage(int image[][10], int rows, int cols, int value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                image[i][j] = value;
            }
        }
    }
    
    // Apply threshold filter
    void applyThreshold(int image[][10], int rows, int cols, int threshold) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                image[i][j] = (image[i][j] > threshold) ? 255 : 0;
            }
        }
    }
    
    // Apply blur filter
    void applyBlur(int image[][10], int rows, int cols) {
        int temp[10][10];
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                temp[i][j] = (image[i-1][j-1] + image[i-1][j] + image[i-1][j+1] +
                             image[i][j-1] + image[i][j] + image[i][j+1] +
                             image[i+1][j-1] + image[i+1][j] + image[i+1][j+1]) / 9;
            }
        }
        
        // Copy back to original image
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                image[i][j] = temp[i][j];
            }
        }
    }
    
    // Print image
    void printImage(const int image[][10], int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << setw(4) << image[i][j];
            }
            cout << endl;
        }
    }
};

// Game Board
class GameBoard {
public:
    // Initialize board
    void initializeBoard(char board[][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }
    
    // Make move
    bool makeMove(char board[][3], int row, int col, char player) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = player;
        return true;
    }
    
    // Check win
    bool checkWin(const char board[][3], char player) {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
                return true;
            }
        }
        
        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
        
        return false;
    }
    
    // Print board
    void printBoard(const char board[][3]) {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }
};

void testMatrixCalculator() {
    cout << "Matrix Calculator Test" << endl;
    cout << "====================" << endl;
    
    MatrixCalculator calc;
    
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matrix2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int result[3][3];
    
    cout << "Matrix 1:" << endl;
    calc.printMatrix(matrix1, 3);
    
    cout << "\nMatrix 2:" << endl;
    calc.printMatrix(matrix2, 3);
    
    cout << "\nMatrix Addition:" << endl;
    calc.addMatrices(matrix1, matrix2, result, 3);
    calc.printMatrix(result, 3);
    
    cout << "\nMatrix Multiplication:" << endl;
    calc.multiplyMatrices(matrix1, matrix2, result, 3);
    calc.printMatrix(result, 3);
    
    cout << "\nDeterminant of Matrix 1: " 
         << calc.determinant(matrix1) << endl;
}

void testImageProcessor() {
    cout << "\nImage Processor Test" << endl;
    cout << "===================" << endl;
    
    ImageProcessor proc;
    int image[10][10];
    
    // Initialize image
    proc.initializeImage(image, 10, 10, 128);
    
    // Create a pattern
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            image[i][j] = (i + j) * 10;
        }
    }
    
    cout << "Original Image:" << endl;
    proc.printImage(image, 10, 10);
    
    cout << "\nAfter Threshold:" << endl;
    proc.applyThreshold(image, 10, 10, 100);
    proc.printImage(image, 10, 10);
    
    // Reset image
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            image[i][j] = (i + j) * 10;
        }
    }
    
    cout << "\nAfter Blur:" << endl;
    proc.applyBlur(image, 10, 10);
    proc.printImage(image, 10, 10);
}

void testGameBoard() {
    cout << "\nGame Board Test" << endl;
    cout << "==============" << endl;
    
    GameBoard game;
    char board[3][3];
    
    game.initializeBoard(board);
    cout << "Initial Board:" << endl;
    game.printBoard(board);
    
    // Make some moves
    game.makeMove(board, 0, 0, 'X');
    game.makeMove(board, 1, 1, 'O');
    game.makeMove(board, 0, 1, 'X');
    game.makeMove(board, 2, 2, 'O');
    game.makeMove(board, 0, 2, 'X');
    
    cout << "\nAfter moves:" << endl;
    game.printBoard(board);
    
    if (game.checkWin(board, 'X')) {
        cout << "X wins!" << endl;
    } else if (game.checkWin(board, 'O')) {
        cout << "O wins!" << endl;
    } else {
        cout << "No winner yet" << endl;
    }
}

int main() {
    cout << "Array Practice Demo" << endl;
    cout << "================\n" << endl;
    
    testMatrixCalculator();
    testImageProcessor();
    testGameBoard();
    
    return 0;
}
