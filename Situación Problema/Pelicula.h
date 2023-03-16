//Autor: Misael Octavio Rodríguez Macías A01639786
#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(string id, string name, double duration, string gender);
        void setCalificacion(double);
        double getCalificacion();
        string getNombre();
        string getGenero();
        string getSerie();
        
        friend ostream& operator<<(ostream& os, Pelicula& peli){
            os << peli.id << ", " << peli.nombre << ", " << peli.duracion << ", ";
            os << peli.genero;
            return os;
        }
};

#endif