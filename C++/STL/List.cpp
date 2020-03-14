#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);    

list<int>::iterator it = lst.begin();
while(it!=lst.end()){
    lst.insert(it,2);
    cout<<*it;
    it++;
}

 it = lst.begin();
while(it!=lst.end()){
    cout<<*it;
    it++;
}
}

