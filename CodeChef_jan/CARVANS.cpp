#include<bits/stdc++.h>

using namespace std;

int main(){
    int t =0;
    cin>>t;
    while(t-- > 0){
        int num;
        cin>>num;
        int arr[num];
        int curr_speed = 10000;
        cin>>curr_speed;
        int total =1 ;
        for(int i=0;i<num-1;i++){
            int spd;
            cin>>spd;
            if(spd< curr_speed){
               total++;
               curr_speed = spd;     
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
