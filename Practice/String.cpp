#include <bits/stdc++.h>

using namespace std;

int main(){
    string a = "Animesh is best ok";
   char b[a.size() +1] ;
   strcpy(b,a.c_str());
   int temp = 0;
    for(int i=0;i<=strlen(b);i++){
        if(b[i]==' ' || b[i] == '\0'){
            reverse(b +temp,b+i);
        temp = i+1;
        }
    }

cout<<b<<endl;
reverse(b,b+ strlen(b));
cout<<b;
//     cout<<a;
//   reverse(a,a+a.size());
//   cout<<a;

}