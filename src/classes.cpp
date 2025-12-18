#include <iostream>

class Example{
    public:
    Example(){
        std::cout << "this is the constructor running";
    }
};
int x= 1337;
int main(){
    int x;
    x=157;
    x++;
    Example ex;
}
