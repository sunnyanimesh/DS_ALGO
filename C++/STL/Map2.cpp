#include<iostream>
#include<map>
using namespace std;

class test {
    int a,b;
    

    public:
    test():a(0),b(0){

    }
     test(int a,int b) : a(a),b(b){
    
    }

    void  print(){
        cout<<a<<"-"<<b;
    }

};
int main(){

    map<int,test> mp;
    mp[1] =  test(1,2);
    mp[3] =  test(1,2);
    mp[5] =  test(1,2);
    mp[6] =  test(1,2);

    for(map<int,test>::iterator it = mp.begin();it!= mp.end();it++){
        cout<<it->first <<" "; it->second.print();
    }


    return 0;
}