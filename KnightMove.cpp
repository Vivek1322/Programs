#include<iostream>
using namespace std;
const int S=10;

void printBoard(int m[S][S],int n)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<m[i][j]<<"\t";
        cout<<endl;
    }
}

bool canPlace(int m[S][S],int n,int r,int c)
{
    ///new position must be on the chess board
    ///should not have been placed at that position earlier
    return
        r >= 0 && r < n &&
        c >= 0 && c < n &&
        m[r][c] == 0;
}

bool KnightMove(int m[S][S],int n,int row,int col,int moveNo)
{
    ///base case
    if(moveNo==n*n)
    {
        return true;
    }
    static int rowChange[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    static int colChange[] = {+1, +2, +2, +1, -1, -2, -2, -1};
    //static int rowChange[] = {-2,-2,-1,1,2,2,1,-1};
    //static int colChange[] = {-1,1,2,2,1,-1,-2,-2};
    for(int i=0;i<8;i++)
    {
        int newRow = row+rowChange[i];
        int newCol = col+colChange[i];
        if(canPlace(m, n, newRow, newCol))
        {
            m[newRow][newCol] = moveNo+1;
            bool check = KnightMove(m,n,newRow,newCol,moveNo+1);
            if(check)
                return true;
            m[newRow][newCol] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size of the board.\n";
    cin>>n;
    int m[S][S]={0};
    m[0][0]=1;
    bool success = KnightMove(m,n,0,0,1);
    if(success)
        printBoard(m,n);
    else
        cout<<"Can't solve the problem.\n";
    return 0;
}
