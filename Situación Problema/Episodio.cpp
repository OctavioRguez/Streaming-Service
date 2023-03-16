//Autor: Misael Octavio Rodríguez Macías A01639786
#include "Aplicacion.h"

Episodio::Episodio():Pelicula(){
    this->serie = "Sin serie";
    this->num = 0;
}

Episodio::Episodio(string id, string name, double duration, string gender, string serie, int num):Pelicula(id, name, duration, gender){
    this->serie = serie;
    this->num = num;
}

string Episodio::getSerie(){
    return this->serie;
}