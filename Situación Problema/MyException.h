//Autor: Misael Octavio Rodríguez Macías A01639786
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class MyException:public exception{
    private:
        string msg;
    public:
        MyException(string msg);
        string what();
};

#endif