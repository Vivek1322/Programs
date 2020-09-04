#include<iostream>
using namespace std;

void printSudoku(int m[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(i%3==0 || j%3==0)
            {
                cout<<"\t";
            }
            cout<<m[i][j];
        }
        cout<<"\n";
    }
}

bool canPlace(int m[9][9],int row,int col,int val)
{
    ///checking row and column
    for(int i=0;i<9;i++)
    {
        if(m[row][i]==val || m[i][col]==val)
            return false;
    }
    ///Checking sub-matrices
    int rowStart = (row/3)*3;
    int colStart = (col/3)*3;
    for(int a=rowStart;a<rowStart+3;a++)
    {
        for(int b=colStart;b<colStart+3;b++)
        {
            if(m[a][b]==val)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int m[9][9], int i, int j)
{
    ///Base case
    if(i==9)
    {
        return true;
    }
    ///end of row
    if(j==9)
    {
       solveSudoku(m,i+1,0);
    }
    ///already containing a number
    if(m[i][j]!=0)
    {
        solveSudoku(m,i,j+1);
    }
    for(int k=1;k<=9;k++)
    {
        if(canPlace(m,i,j,k))
        {
            m[i][j]=k;
            bool check = solveSudoku(m,i,j+1);
            if(!check)
            {
                m[i][j]=0;
            }
            else
                return true;
        }
    }
    return false;
}

int main()
{
    int m[9][9]={0};
    cout<<"Enter the elements of the array.\n";
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>m[i][j];
    cout<<"The sudoku you entered is as follows:-\n";
    printSudoku(m);
    try
    {
        if(solveSudoku(m,0,0))
            printSudoku(m);
        else
            throw "Can't solve the given sudoku :(\n";
    }
    catch(char *str)
    {
        cout<<str;
    }
    return 0;
}
