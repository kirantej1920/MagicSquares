/*
 * =====================================================================================
 *
 *       Filename:  magicSquare.cpp
 *
 *    Description:  Generating the magic square 
 *
 *        Version:  1.0
 *        Created:  Friday 24 October 2014 01:52:33  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kiran Tej (kirantej1920@gmail.com), kirantej1920@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
using namespace std;

class MagicSquare {
    public:
    MagicSquare(int n) 
    { 
        num = n;
        magicSquare = new int* [num];
        for(int i = 0; i < num; i++)
        {   
            magicSquare[i] = new int[num];
        }
    }
    ~MagicSquare() 
    { 
        for(int i = 0; i < num; i++)
        {   
            delete[] magicSquare[i];
        }
        delete[] magicSquare;
    }
    void printMagicSquare(void) 
    {
        int LTRBDiagSum = 0;
        int LBRTDiagSum = 0;
        int *columnSum = new int[num];
        for(int row = 0; row < num; row++) 
        {
            int rowSum = 0;
            for(int col = 0; col < num; col++)
            {
                rowSum += magicSquare[row][col];
                if(row == col) LTRBDiagSum += magicSquare[row][col];
                if(row+col == num-1) LBRTDiagSum += magicSquare[row][col];
                columnSum[col] += magicSquare[row][col];
                cout << "\t" << magicSquare[row][col];
            }
            cout <<  " =>  " << rowSum << endl;
        }
        cout << "RTLB(" << LBRTDiagSum << ")";
        for(int i = 0; i < num; i++)
        {
            cout << "\\/";
            if(i != num-1) cout << "\t";
        }
        cout << "LTRB(" << LTRBDiagSum << ")";
        cout << endl;
        for(int i = 0; i < num; i++)
        {
            cout << "\t" << columnSum[i] ;
        }
        cout << endl;
        delete[] columnSum;
    }
    void getRowAndColumn(int& row, int& col, const int counter)
    {
        if(counter == 1) { col = num / 2; return;} // Initial condition to insert 0
        else if(row == 0 && (col == num / 2)) { row = num - 1; col++; return;}
        else if(col+1 == num && row == 0) { row++; return;}
        else if(col+1 == num) { col = 0; row--; return;}
        else if(row == 0) { row = num -1; col++; return;}
        else if((row!=0) && (col!=num-1) && magicSquare[row-1][col+1] != 0) { row++; return;}
        else { row--; col++; return;}
    }
    void computeMagicSquare(void)
    {
    // Printing Dummy Magic Square
    // Solution for magic square 
    // Step 1 : Placing 1 in the middle of the first  row 1st row of the matrix
        cout << "Printing matrix template:" << endl;
        printMagicSquare();
        int counter  = 1;
        int row = 0;
        int col = 0;
        while(counter <= num*num)
        {
            getRowAndColumn(row, col, counter);
            // cout << "Row = " << row << "Col = " << col << "Counter = " << counter << endl;
            if(row < 0 || row >= num || col < 0 || col >= num) cout << "Error in calculating Row/Column Row = " << row
                << "Column = " << col << endl;
            magicSquare[row][col] = counter++;
        }
        cout << "\n\nPrinting magicSquare: " << num << "*" << num << endl;
        printMagicSquare();
    }
    private:
    int **magicSquare;
    int num;
};
int main()
{
    int num = 0;
    cout << "Enter any odd number: ";
    cin >> num;
    cout << endl << endl;
    if(num % 2 == 0) {
        cout << "Even number not supported !! " << endl;
        return 1;
    }
    MagicSquare mSq(num);
    mSq.computeMagicSquare();
    return 0;
}
