//Autor: Misael Octavio Rodríguez Macías A01639786
#include "Aplicacion.h"
#include "Episodio.h"
#include "Pelicula.h"
#include <string.h>

Aplicacion::Aplicacion(){
    this->cantEpisodios = 0;
    this->cantPeliculas = 0;
}

void Aplicacion::cargarDatos(string name){
    ifstream file; 
    file.open(name.c_str(), ios::in);
    if(file.fail()){
        cout << "\nNo se puede acceder al archivo.\nVerifique el nombre del archivo y su ubicacion." <<endl;
    }
    else{
        string line,
               elemento;
        string atributos[7]; 
        while(!file.eof()){
            getline(file, line);
            stringstream video(line);
            int i = 0;
            while (getline(video, elemento, ',')){
                atributos[i] = elemento;
                i++;
            }

            int num;
            double duracion;
            string id, 
                   nombre,
                   genero,
                   serie;

            if (atributos[0] == "c"){
                id = atributos[1];
                nombre = atributos[2];
                stringstream valor3(atributos[3]);
                valor3 >> duracion;
                genero = atributos[4];
                serie = atributos[5];
                stringstream valor6(atributos[6]);
                valor6 >> num;

                Episodio ep(id, nombre, duracion, genero, serie, num);

                if (this->cantEpisodios != 0){
                    Episodio* temporal = new Episodio[this->cantEpisodios];
                    for (int i = 0; i < this->cantEpisodios; i++){
                        temporal[i] = this->episodios[i];
                    }
                    this->cantEpisodios++;

                    this->episodios = new Episodio[this->cantEpisodios];
                    for (int i = 0; i < this->cantEpisodios-1; i++){
                        this->episodios[i] = temporal[i];
                    }
                    this->episodios[this->cantEpisodios-1] = ep;
                }
                else{
                    this->cantEpisodios++;
                    this->episodios = new Episodio[this->cantEpisodios];
                    this->episodios[this->cantEpisodios-1] = ep;
                }
            }
            else{
                id = atributos[1];
                nombre = atributos[2];
                stringstream valor3(atributos[3]);
                valor3 >> duracion;
                genero = atributos[4];

                Pelicula pel(id, nombre, duracion, genero);

                if (this->cantPeliculas != 0){
                    Pelicula* temporal = new Pelicula[this->cantPeliculas];
                    for (int i = 0; i < this->cantPeliculas; i++){
                        temporal[i] = this->peliculas[i];
                    }
                    this->cantPeliculas++;

                    this->peliculas = new Pelicula[this->cantPeliculas];
                    for (int i = 0; i < this->cantPeliculas-1; i++){
                        this->peliculas[i] = temporal[i];
                    }
                    this->peliculas[this->cantPeliculas-1] = pel;
                }
                else{
                    this->cantPeliculas++;
                    this->peliculas = new Pelicula[this->cantPeliculas];
                    this->peliculas[this->cantPeliculas-1] = pel;
                }
            }
        }
    }
}

void Aplicacion::mostrarVideos(double calificacion){
    bool videos = false;
    cout << "Id, Nombre, Duracion, Genero, [Serie, Episodio]\n" <<endl;
    for (int i = 0; i < this->cantEpisodios; i++){
        if (this->episodios[i].getCalificacion() >= calificacion){
            cout << "Cap: ";
            cout << this->episodios[i] <<endl;
            videos = true;
        }
    }

    cout <<endl;
    for (int i = 0; i < this->cantPeliculas; i++){
        if (this->peliculas[i].getCalificacion() >= calificacion){
            cout << "P: ";
            cout << this->peliculas[i] <<endl;
            videos = true;
        }
    }

    if (videos == false){
        cout << "Lo sentimos, actualmente no hay videos registrados con una calificacion igual o mayor a " << calificacion <<endl;
    }
}

void Aplicacion::mostrarVideos(string genero){
    bool videos = false;
    cout << "Id, Nombre, Duracion, Genero, [Serie, Episodio]\n" <<endl;
    for (int i = 0; i < this->cantEpisodios; i++){
        if (this->episodios[i].getGenero() == genero){
            cout << "Cap: ";
            cout << this->episodios[i] <<endl;
            videos = true;
        }
    }

    cout <<endl;
    for (int i = 0; i < this->cantPeliculas; i++){
        if (this->peliculas[i].getGenero() == genero){
            cout << "P: ";
            cout << this->peliculas[i] <<endl; 
            videos = true;
        }
    }

    if (videos == false){
        cout << "Lo sentimos, actualmente no hay videos registrados con el genero de " << genero << "." <<endl;
    }
}

void Aplicacion::mostrarEpisodios(string serie, double calificacion){
    bool videos = false;
    cout << "Id, Nombre, Duracion, Genero, Serie, Episodio\n" <<endl;
    for (int i = 0; i < this->cantEpisodios; i++){
        if (this->episodios[i].getSerie() == serie){
            if (this ->episodios[i].getCalificacion() >= calificacion){
                cout << "Cap: ";
                cout << this->episodios[i] <<endl;
                videos = true;
            }
        }
    }

    if (videos == false){
        cout << "Lo sentimos, actualmente no hay episodios de la serie " << serie;
        cout << " con una califiacion mayor o igual a " << calificacion <<endl;
    }
}

void Aplicacion::mostrarPeliculas(double calificacion){
    bool videos = false;
    cout << "Id, Nombre, Duracion, Genero\n" <<endl;
    for (int i = 0; i < this->cantPeliculas; i++){
        if (this->peliculas[i].getCalificacion() >= calificacion){
            cout << "P: ";
            cout << this->peliculas[i] <<endl;
            videos = true;
        }
    }

    if (videos == false){
        cout << "Lo sentimos, actualmente no hay peliculas registradas con una califiacion mayor o igual a" << calificacion <<endl;
    }
}

bool Aplicacion::calificarVideo(string titulo, double valor){
    bool success = false;
    for (int i = 0; i < this->cantEpisodios; i++){
        if (this->episodios[i].getNombre() == titulo){
            this->episodios[i].setCalificacion(valor);
            success = true;
        }
    }
    for (int i = 0; i < this->cantPeliculas; i++){
        if (this->peliculas[i].getNombre() == titulo){
            this->peliculas[i].setCalificacion(valor);
            success = true;
        }
    }

    return success;
}