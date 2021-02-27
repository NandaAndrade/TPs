#include <iostream>
#include <string>

using namespace std;
class Erros : exception{
    
    string msg;

    public:
        Erros(const string &tp) : msg(tp) {}
        void out() { cout<<msg<<endl; }
};