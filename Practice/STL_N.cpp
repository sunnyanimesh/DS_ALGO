#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 
int main() 
{ 
        vector<int> vect;

        vect.push_back(6);
        vect.push_back(0);
        vect.push_back(3);
         vect.push_back(1);
           vect.push_back(5);


        // stable_partition(vect.begin(),vect.end(),[](int x){
        //     return x%2 == 0;
        // });

        is_partitioned(vect.begin(),vect.end(),[](int x){
              return x%2 ==0;  
        })? cout<<"is partioned":cout<<"not";


        auto it =  partition_point(vect.begin(),vect.end(),[](int x){
            return x%2 == 0;
        });
        cout<<*it;
        int ctr = 0;
         for(int x :vect){
             ctr++;
             if(vect.at(ctr) ==it)
              break;

             cout<<x<<" ";

         }                               
} 