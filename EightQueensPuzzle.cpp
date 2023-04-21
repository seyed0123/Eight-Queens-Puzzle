#include <iostream>
#include<algorithm>
#include <windows.h>

using namespace std;

// Initialize a 8x8 chessboard as a global 2D array
int chessBoard[9][9]={};

// Initialize a variable to keep track of the number of solutions found
int numberOfResults=0;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
// A helper function to remove a queen from the chessboard
void del(int queenNumber)
{
	for(int i=1;i<=8;i++)
	{
	    for(int j=1;j<=8;j++)
	    {
	        if(chessBoard[i][j]==queenNumber)
	        {
                chessBoard[i][j]=0;
	        }
	    }
	}
}

// A function to print the current chessboard
void print()
{
	for(int i=1;i<=8;i++)
	{
	cout<<endl;
	    for(int j=1;j<=8;j++)
	    {
            if(chessBoard[i][j]==1) {
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                cout << "\u2655"<< flush;
            }
            else {
                SetConsoleTextAttribute(console, FOREGROUND_GREEN);
                cout << "▢"<< flush;
            }
            SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
            cout<<' '<< flush;
	    }
	}
	cout<<"\n\n\n\n\n";
}

// A helper function to mark the diagonals of a new queen
void gen9diagonal(const int row,const int column,int queenNumber)
{
	for(int i=row,j=column;i>=1&&j>=1;i--,j--)
	{
		if(chessBoard[i][j]==0)
	    {
            chessBoard[i][j]=queenNumber;
	    }
	}
	for(int i=row,j=column;i<=8&&j<=8;i++,j++)
	{
		if(chessBoard[i][j]==0)
	    {
            chessBoard[i][j]=queenNumber;
	    }
	}
	for(int i=row,j=column;i>=1&&j<=8;i--,j++)
	{
		if(chessBoard[i][j]==0)
	    {
            chessBoard[i][j]=queenNumber;
	    }
	}
	for(int i=row,j=column;i<=8&&j>=1;i++,j--)
	{
		if(chessBoard[i][j]==0)
	    {
            chessBoard[i][j]=queenNumber;
	    }
	}
}

// A helper function to mark the horizontal and vertical of a new queen
void gen9direct(const int row,const int column,int queenNumber)
{
	for(int i=row,j=1;j<=8;j++)
	{
		if(chessBoard[i][j]==0)
	    {
            chessBoard[i][j]=queenNumber;
	    }
	}
	for(int i=1,j=column;i<=8;i++)
	{
		if(chessBoard[i][j]==0)
	    {
            chessBoard[i][j]=queenNumber;
	    }
	}
}

// The main recursive function that generates all the solutions
void gen(int queenNumber)
{
	int row=queenNumber;

    // If all the queens are placed, print the chessboard and return
	if(row>8)
    {
        numberOfResults++;
        print();
        return;
	}

    // Place a new queen in an empty cell and mark its attacking squares
    for(int column=1;column<=8;column++)
    {
        if(chessBoard[row][column]==0)
        {
            gen9direct(row,column,queenNumber+1);
            gen9diagonal(row,column,queenNumber+1);
            chessBoard[row][column]=1;
            gen(queenNumber+1);
            chessBoard[row][column]=0;
            del(queenNumber+1);
        }
    }
}

// The main function that initializes the chessboard and calls the gen function
int main()
{
	gen(1);
	cout<<"\n\n\n\n\n\n\n\n"<<numberOfResults;
}