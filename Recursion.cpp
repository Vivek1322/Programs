#include<bits/stdc++.h>

using namespace std;

int multiply(int m, int n){
    if(n==0)
        return 0;
    return m+multiply(m,n-1);
}

int countZeros(int x){
    if(x==0)
        return 0;
    if(x%10!=0){
        return 0+countZeros(x/10);
    }
    return 1+countZeros(x/10);
}

float geosum(float n, int k){
    if(k==0){
        return 0;
    }
    return n + geosum(n*1/2, k-1);

}

float geo(int k){
    return geosum(1,k);
}

bool checkPalindrome(string s, int start, int end){
    if(start==end)
        return true;
    if(s[start]==s[end]){
        if(checkPalindrome(s,start+1,end-1))
            return true;
    }
    return false;
}

bool palindrome(string s){
    if(s.length()==0 || s.length()==1){
        return true;
    }
    if(checkPalindrome(s, 0, s.length()-1))
        return true;
    return false;
}

int main(){
//    int m,n;
//    cin>>m>>n;
//    int ans = multiply(m,n);
//    cout<<ans<<endl;

//    int x;
//    cin>>x;
//    int zero = countZeros(x);
//    cout<<zero<<endl;

//    int k;
//    cin>>k;
//    float sum = geo(k);
//    cout<<sum<<endl;

    string s;
    cin>>s;
    if(palindrome(s))
        cout<<"Palindrome string.\n";
    else
        cout<<"Not a palindrome string.\n";
    return 0;
}
