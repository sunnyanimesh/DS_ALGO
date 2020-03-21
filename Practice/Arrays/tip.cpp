#include<bits/stdc++.h>
#define loop(i,f,e) for(int i=f;i<e;i++)
#define in cin>>
#define out cout<<
using namespace std;

int main(){
    int t;
    in t;
    while(t--){
        int n;
        in n;
        list<int> num_list;
        int num;
        loop(i,0,n){
            in num;

            num_list.push_back(num);
        }


        int total = 0;
        int temp = 1;
        for(auto it = num_list.begin() ;it!=num_list.end();it++){
            for(auto it2= next(num_list.begin(),temp++) ; it2!= num_list.end();it2++){
                if(*it != *it2){
                    if (find(num_list.begin(),num_list.end(),*it + *it2) != num_list.end()){

                        total++;
               out "hello"<<*it<<" "<<*it2<<endl;

                    }
                }

            }

        }
            cout<<total<<endl;

    }

return 0;
}
