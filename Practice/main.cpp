// #include "util.cpp"

#include "sort.cpp"
 #include "bst.cpp"
void stdiput(){
    int l;
    cout<<"Enter length";
    cin>>l;
    int arr[l];

    for(int i =0;i< l;i++)
        cin>>arr[i];

     printarr(arr,l);
     sort(arr,arr + );
     printarr(arr,l);
}


void readfromfile(){
    fstream file;
    string s, t, q, filename;

   filename = "file.txt";

   file.open(filename.c_str());
   struct node *node;
   while (file >> s)
    {
    char cstr[s.size() + 1];
	s.copy(cstr, s.size() + 1);
	cstr[s.size()] = '\0';
    int av = atoi(cstr);
    cout<<av;
    node = insert(node, av);
    }
    file.close();
//     double a,b;
// 	a = time(0) ;
//     inorder(root);
//     // mergesort(arr,0,size-1);
//     b = time(0) ;
//     cout<<a<<endl<<b<<endl;
//      cout << difftime(b,a);
//  ofstream outfile;
//    outfile.open("output.txt");
//     for(int i =0;i<size;i++){
//    outfile << arr[i] << "\n";

//    }

//   outfile.close();



}
int main(){
readfromfile();
//stdiput();

return 0;
}
