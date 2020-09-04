#include<iostream>
using namespace std;

void print(int **arr,int row,int col)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int check(int **arr,int row,int col,int num)
{
    int i=0;
    int j=col-1;
    while(j>=0 && i<row){
        if(arr[i][j]==num){
            cout<<"Number found at row "<<i+1<<" and column "<<j+1<<"\n";
            return 1;
        }
        else if(arr[i][j]>num){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}

int main()
{
    int row,col;
    cout<<"Enter rows and columns of the 2-D array.\n";
    cin>>row>>col;
    cout<<"Enter the elements of the 2-D array which are sorted both along the rows and the columns.\n";
    int **arr = new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int [col];
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\n";
    print(arr,row,col);
    int num;
    cout<<"Enter the number to be searched.\n";
    cin>>num;
    if(!check(arr,row,col,num))
        cout<<"Number not found.\n";
    return 0;
}

