#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int i= 0;
        int j = n-1;    
        int mc = 0,pc = 0;
        float mhc = 0,phc = 0;
        while(i<=j){
            mc ++;
            mhc = mhc + (float)arr[i];
            i++;
          //  cout<<" for i : "<<i;
           //                 cout<<"  mhc"<<mhc<<endl;
            while(j>=i && phc< (mhc /2)){
           //     cout<<"   j:"<<j;
                pc++;
                phc =phc + (float)arr[j];
           //     cout<<"phc  "<<phc<<endl;
                j--;
            }
        }
        cout<<mc<<"\t"<<pc<<endl;
        (mc>pc)?cout<<"Motu":((mc==pc)?cout<<"Tie":cout<<"Patlu");


    }   
    return 0;
}