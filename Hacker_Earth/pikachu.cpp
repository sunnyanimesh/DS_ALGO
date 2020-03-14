#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char s[n],t[n];
    cin>>s>>t;
    int total_days = 0;
    for(int i=0;i<n;i++){
        int in = (int)s[i];
        int out = (int)t[i];
        if(out>=in+13){
            total_days += ((out- (in+13))+1);
        }
        else if(out>in){
            total_days += (out - in);
        }
        else{
            
        }
        cout<<"total days : "<<total_days<<endl;        

    }

    cout<<total_days;
    return 0;
}