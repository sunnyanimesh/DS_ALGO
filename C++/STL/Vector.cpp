#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> strings(9,"hi");
     strings.push_back("one");
     strings.push_back("two");
    // strings.push_back("three");
    
    vector<string>::iterator it ;

    for(it = strings.begin();it!=strings.end();it++){
        cout<<*it<<endl;
    }
    
    cout<<strings.size()<<endl;
    cout<<strings.capacity()<<endl;
    // strings.resize(50);                        // will change capacity/size
    strings.reserve(22);                          // size will not be effected capacity should be minimum this
    cout<<strings.size()<<endl;
    cout<<strings.capacity()<<endl;
    
}