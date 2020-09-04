#include<iostream>
using namespace std;
const int S = 10;

void printBoard(int m[S][S],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]==1)
                cout<<"Q ";
            else
                cout<<"- ";
        }
        cout<<endl;
    }
}

bool canPlace(int m[S][S],int n,int row,int col)
{
    ///checking on line
    for(int i=0;i<row;i++)
    {
        if(m[i][col]==1)
            return false;
    }
    ///checking across left diagonal
    int i=row;
    int j=col;
    while(i>=0 && j>=0)
    {
        if(m[i][j]==1)
            return false;
        i--;
        j--;
    }
    ///checking across right diagonal
    i=row;
    j=col;
    while(i>=0 && j<n)
    {
        if(m[i][j]==1)
            return false;
        i--;
        j++;
    }
    return true;
}

bool NQueen(int m[S][S],int n,int row,int col)
{
    ///base case
    if(row==n)
    {
        return true;
    }
    ///checking for each row
    for(int i=0;i<n;i++)
    {
        if(canPlace(m,n,row,i))
        {
            m[row][i]=1;
            bool check = NQueen(m,n,row+1,0);
            if(check)
                return true;
            m[row][i]=0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size of the chess board.\n";
    cin>>n;
    int m[S][S]={0};
    bool success = NQueen(m,n,0,0);
    if(success)
        printBoard(m,n);
    else
        cout<<"Can't solve.\n";
    return 0;
}

