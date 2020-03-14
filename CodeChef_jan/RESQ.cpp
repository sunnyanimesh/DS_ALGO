#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int num;
        cin>>num;
        int diff = num  -1;
        for(int i= 2;i<=sqrt(num);i++){
            if(num%i == 0){
                int j = num /i;
                if(abs(j-i)<diff){
                    diff = abs(j-i);
                }
            }
        }
    cout<<diff<<endl;
    }
    return 0;
}