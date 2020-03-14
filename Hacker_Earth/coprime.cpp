#include<bits/stdc++.h>

using namespace std;
int gcd(int,int);
int getcoprime(int n){
    int i,j,max=1;
    
    for(i=n-2;i>0;i--)
    {
        int c= gcd(n,i);
        if(c==1)
        {
            break;
        }

    }
    
return i;
} 

int gcd(int x,int y)
{
    int rem=x%y;
    if(rem==0)
    return y;
    
    else
    return gcd(y,rem);
}
int main()
{
    for(int i=3;i<1000;i++){
        int j = getcoprime(i);
        if(i%2 == 0 && j !=(i -3)){
            cout<<i<<" : "<<j <<endl;
        }else if(i%2 !=0 && j!=(i-2)){
            cout<<i<<" : "<<j <<endl;
        }
    }
    
}
