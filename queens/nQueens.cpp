

#include <iostream>
#include <vector>

using namespace std;
int board[12][12];
int numSolutions;
int size;

void clearBoard(int row){
    for(int i = row; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = 0;
        }
    }
}

bool isValid(int row, int col){
    int i = row-1;
    int j = col;
    if(row == 0){       // First row is always empty, so it is always valid.
        return true;
    }
    while(i >= 0){      // If there is queen above the space, it is not valid.
        if(board[i][col] == 1){
            return false;
        }
        i--;
    }
    i = row;            // checks diagonal.
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    i = row;
    j = col;
    while(i >= 0 && j < size){      // checks other diagonal.
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
return true;
}
   
// This loops through the rows and sees if they are valid. If valid a queen is place and moves onto the
// next row.
void checkRow(int row){
   for(int i = 0; i < size; i++){
    clearBoard(row);                        // Board (current row and below) is cleared every time to get rid of old solutions.
    if(isValid(row,i) && row == size -1){
        numSolutions++;
        continue;
    }
    else if(isValid(row,i)){
        board[row][i] = 1;
        checkRow(row+1);
        continue;
    }
    else{
        continue;
    }
   }
}

int nQueens(int n)
{
    size = n;
    numSolutions = 0;
    checkRow(0);
    return numSolutions;
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}