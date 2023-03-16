//Autor: Misael Octavio Rodríguez Macías A01639786
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>

using namespace std;

class Video{
    protected:
        string id,
               nombre,
               genero,
               serie;
        int num,
            cantEval;
        double duracion;
        double* calificaciones;
    public:
        virtual void setCalificacion(double) = 0;
        virtual double getCalificacion() = 0;
        virtual string getNombre() = 0;
        virtual string getGenero() = 0;
        virtual string getSerie() = 0;
};

#endif