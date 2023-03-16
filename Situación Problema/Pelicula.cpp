//Autor: Misael Octavio Rodríguez Macías A01639786
#include "Pelicula.h"

Pelicula::Pelicula():Pelicula("00000000", "Sin nombre", 0.0, "Sin genero"){}

Pelicula::Pelicula(string id, string name, double duration, string gender){
    this->id = id;
    this->nombre = name;
    this->duracion = duration;
    this->genero = gender;
    this->cantEval = 1;
    this->calificaciones = new double[1];
    this->calificaciones[0] = 1.0;
}

void Pelicula::setCalificacion(double calificacion){
    double* temporal = new double[this->cantEval];
    for (int i = 0; i < this->cantEval; i++){
        temporal[i] = this->calificaciones[i];
    }   
    this->cantEval++;

    this->calificaciones = new double[this->cantEval];
    for (int i = 0; i < this->cantEval-1; i++){
        this->calificaciones[i] = temporal[i];
    } 
    this->calificaciones[this->cantEval-1] = calificacion;
}


double Pelicula::getCalificacion(){
    double calificacion = 0;
    for (int i = 0; i < this->cantEval; i++){
        calificacion += this->calificaciones[i];
    }
    return calificacion/this->cantEval;
} 

string Pelicula::getNombre(){
    return this->nombre;
}

string Pelicula::getGenero(){
    return this->genero;
}

string Pelicula::getSerie(){
    return "No aplica";
}