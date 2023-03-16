//Autor: Misael Octavio Rodríguez Macías A01639786
#ifndef EPISODIO_H
#define EPISODIO_H

#include "Pelicula.h"

class Episodio:public Pelicula{
    public:
        Episodio();
        Episodio(string id, string name, double duration, string gender, string serie, int num);
        string getSerie();
        
        friend ostream& operator<<(ostream& os, Episodio& ep){
            os << ep.id << ", " << ep.nombre << ", " << ep.duracion << ", ";
            os << ep.genero << ", " << ep.serie << ", " << ep.num;
            return os;
        }
};

#endif