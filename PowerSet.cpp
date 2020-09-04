#include<iostream>
using namespace std;

void subsequence(char in[],char op[],int i, int j)
{
    if(in[i]=='\0'){
        op[j]='\0';
        cout<<op<<",";
        return;
    }
    op[j]=in[i];
    subsequence(in,op,i+1,j+1);
    op[j]='\0';
    subsequence(in,op,i+1,j);
}

int main()
{
    char ch[10];
    cin>>ch;
    char op[10];
    subsequence(ch,op,0,0);
    return 0;
}
