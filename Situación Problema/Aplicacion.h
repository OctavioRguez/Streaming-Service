//Autor: Misael Octavio Rodríguez Macías A01639786
#ifndef APLICACION_H
#define APLICACION_H

#include <fstream>
#include <sstream>
#include "Episodio.h"

class Aplicacion{
    private:
        Episodio* episodios;
        Pelicula* peliculas;
        int cantEpisodios,
            cantPeliculas;
    public:
        Aplicacion();
        void cargarDatos(string name);
        void mostrarVideos(double calificacion);
        void mostrarVideos(string genero);
        void mostrarEpisodios(string serie, double calificacion);
        void mostrarPeliculas(double calificacion);
        bool calificarVideo(string titulo, double valor);
};

#endif