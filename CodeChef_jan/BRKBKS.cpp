#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0) {
        int w[3];
        int s;
        cin>>s>>w[0]>>w[1]>>w[2];
    
       if(w[0]>w[2])
        reverse(w,w+3);

        int hits = 0;
        int curr_brks = 0;
        for(int &x:w){
            curr_brks += x;
            if(curr_brks>s){
                curr_brks = x;
                hits = hits + 1;

            }
            if(curr_brks <= s && (&x ==&w[2])){
                curr_brks = 0;
                hits ++;
            }
            
        }
        cout<<hits;

    }   
}