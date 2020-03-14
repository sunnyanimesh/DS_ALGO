
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int size;
        int d ;
        cin>>size>>d;
        int arr[size];
        for(int &x: arr){
            cin>>x;
        }

        reverse(arr,arr+(size-d));
        for(int &x: arr){
            cout<<x<<" ";
        }
        cout<<endl;
       reverse(arr + (size-d),arr + size);
        for(int &x: arr){
            cout<<x<<" ";
        }
                cout<<endl;
        reverse(arr,arr+size);
        for(int &x: arr){
            cout<<x<<" ";
        }
                cout<<endl;
    }

    return 0;
}