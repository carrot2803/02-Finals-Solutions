#include <iostream>
using namespace std;

// const int rows = 90, cols = 130; hard to display on my screen
const int rows = 9, cols = 12;

struct Cell{
    int red, green, blue; 
    char symbol;
};

Cell createCell(int red, int green, int blue, char symbol){
    return {red, green, blue, symbol};
}

void initFlag(Cell flag[][cols], int rows, int cols){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(i == j || i + 4 == j)
                flag[i][j] = createCell(0, 0, 0, '-');
            else if(i > j || i + 4 < j)
                flag[i][j] = createCell(255, 255, 0, '*');
            else
                flag[i][j] = createCell(255, 255, 255, '#');
}

void print(Cell flag[][cols], int rows, int cols){    
    cout << "  ";   // Print the column numbers on top
    for (int j = 0; j < cols; j++) 
        cout << j % 10 << " ";
    cout << endl;

    for (int i = 0; i < rows; i++) { // Print the flag with row numbers on the side
        cout << i % 10 << " "; // print the row number (use modulus to keep it single digit) for padding
        for (int j = 0; j < cols; j++) 
            cout << flag[i][j].symbol << " ";
        cout << endl;
    }
}

int main() {
    Cell flag[rows][cols];

    initFlag(flag, rows, cols);
    print(flag, rows, cols);

    return 0;
}
