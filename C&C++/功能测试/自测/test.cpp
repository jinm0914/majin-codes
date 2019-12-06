#include<iostream>
using namespace std; 

int Abs2(int x)
{
     return x > 0 ? x : -x;
}

int Abs(int x)
{
     return Abs2(x);
}

int main(int argc, char **argv) {  
    cout<<Abs(atoi(argv[1]))<<endl;
    return 0;  
} 
