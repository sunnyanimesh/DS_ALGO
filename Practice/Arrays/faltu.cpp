#include <iostream>
#include <list>
using namespace std;

int main()
{
    // list declaration of integer type
    list<int> mylist{ 1, 5, 3, 2, 4 };

    // sort function
    mylist.sort();

    // printing the list after sort
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    return 0;
}
