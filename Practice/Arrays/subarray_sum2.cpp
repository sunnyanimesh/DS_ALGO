#include<bits/stdc++.h>

using namespace  std;

int main(){
int t;
int n,s;
cin>>t;
while(t-->0){
    cin>>n>>s;
    int arr[n];
    for(int i= 0;i<n;i++)
        cin>>arr[i];
    int start =1;
    int ende =0 ;
    int curr_sum = 0 ;
    while(curr_sum<s && ende<=n){
        curr_sum += arr[ende];
        if(curr_sum  <s){
            ende++;
        }
        else if(curr_sum>s){
            curr_sum -= arr[start -1];
            curr_sum -= arr[ende];
            start ++;
        }
        else{
            ende++;
            break;
        }

    }
    if(curr_sum == s)
       {
       cout<<start<<" "<<ende;
       }
       else
        cout<<-1;

        cout<<endl;
}
return 0;
}
