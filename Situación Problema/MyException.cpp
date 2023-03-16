//Autor: Misael Octavio Rodríguez Macías A01639786
#include "MyException.h"
#include <iostream>

using namespace std;

MyException::MyException(string msg){
    this->msg = msg;
}

string MyException::what(){
    return this->msg;
}