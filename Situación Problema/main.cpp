//Autor: Misael Octavio Rodríguez Macías A01639786
#include "Aplicacion.h"
#include "MyException.h"

using namespace std;

int main(){

    string menu = "";
    bool salir = false,
         errorMenu = false,
         errorEntrada = false;
    char continuar;
    Aplicacion sistema;

    system("cls");
    do{
        try{
            cout << "-------------------------Menu para servicios de streaming-------------------------" <<endl;
            cout << "1. Cargar archivo de datos" <<endl;
            cout << "2. Mostrar los videos en general con una cierta calificacion o de un cierto genero" <<endl;
            cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" <<endl;
            cout << "4. Mostrar las peliculas con cierta calificacion" <<endl;
            cout << "5. Calificar un video" <<endl;
            cout << "0. Salir" <<endl;

            cout << "\nEscriba el numero de la opcion que desee: " <<endl;
            cin >> menu;

            if (menu == "0"){
                system("cls");
                salir = true;
                cout << "Muchas gracias por utilizar nuestros servicios." <<endl;
            }

            else if (menu == "1"){
                system("cls");

                string archivo;
                cout << "Nombre del archivo (sin extension):" <<endl;
                cin >> archivo;
                archivo += ".txt";

                sistema.cargarDatos(archivo);

                cout << "Introduzca cualquier caracter para continuar: " <<endl;
                cin >> continuar;
                system("cls");
            }

            else if (menu == "2"){
                string opcion;
                double calificacion;
                system("cls");
                do{
                    try{
                        errorMenu = false;
                        errorEntrada = false;

                        cout << "\nDesea mostrar videos basados en calificacion(1) o en genero(2)?" <<endl;
                        cout << "Escriba el numero de la opcion que desee: " <<endl;
                        cin >> opcion;

                        if (opcion == "1"){
                            system("cls");
                            cout << "Introduzca la calificacion: " <<endl;
                            cin >> calificacion; 
                            if (cin.fail()){
                                cin.clear();
                            }

                            if (calificacion < 1.0 || calificacion > 5.0){
                                errorEntrada = true;
                            }
                            else{
                                system("cls");
                                sistema.mostrarVideos(calificacion);
                            }
                        }
                        else if (opcion == "2"){
                            system("cls");
                            string genero;
                            cout << "Introduzca el genero: " <<endl;
                            std::getline(std::cin >> std::ws, genero);

                            system("cls");
                            sistema.mostrarVideos(genero);
                        }
                        else{
                            errorMenu = true;
                            system("cls");
                        }

                        if (errorMenu){
                            throw MyException("Entrada invalida, por favor intentelo de nuevo.");
                        }
                        if (errorEntrada){
                            throw MyException("El valor de la calificacion debe estar entre 1 y 5, por favor intentelo de nuevo.");
                        }
                    }
                    catch (MyException& ex){
                        system("cls");
                        cout << ex.what() <<endl;
                    }
                }
                while (errorMenu || errorEntrada);

                cout << "\nIntroduzca cualquier caracter para continuar: " <<endl;
                cin >> continuar;
                system("cls");
            }

            else if (menu == "3"){
                system("cls");
                double calificacion;
                string serie;
                do{
                    try{
                        errorEntrada = false;

                        cout << "Introduzca el nombre de la serie: " <<endl;
                        std::getline(std::cin >> std::ws, serie);

                        cout << "Introduzca la calificacion para los episodios: " <<endl;
                        cin >> calificacion;
                        if (cin.fail()){
                            cin.clear();
                        }

                        if (calificacion < 1.0 || calificacion > 5.0){
                            errorEntrada = true;
                            system("cls");
                        }
                        else{
                            system("cls");
                            sistema.mostrarEpisodios(serie, calificacion);
                        }

                        if (errorEntrada){
                            throw MyException("El valor de la calificacion debe estar entre 1 y 5, por favor intentelo de nuevo.\n");
                        }
                    }
                    catch (MyException& ex){
                        system("cls");
                        cout << ex.what() <<endl;
                    }
                }
                while (errorEntrada);

                cout << "\nIntroduzca cualquier caracter para continuar: " <<endl;
                cin >> continuar;
                system("cls");
            }

            else if (menu == "4"){
                system("cls");
                double calificacion;
                do{
                    try{
                        errorEntrada = false;

                        cout << "Introduzca la calificacion minima para las peliculas: " <<endl;
                        cin >> calificacion;
                        if (cin.fail()){
                            cin.clear();
                        }

                        if (calificacion < 1.0 || calificacion > 5.0){
                            errorEntrada = true;
                            system("cls");
                        }
                        else{
                            system("cls");
                            sistema.mostrarPeliculas(calificacion);
                        }

                        if (errorEntrada){
                            throw MyException("El valor de la calificacion debe estar entre 1 y 5, por favor intentelo de nuevo.\n");
                        }
                    }
                    catch (MyException& ex){
                        system("cls");
                        cout << ex.what() <<endl;
                    }
                }
                while (errorEntrada);

                cout << "\nIntroduzca cualquier caracter para continuar: " <<endl;
                cin >> continuar;
                system("cls");
            }

            else if (menu == "5"){
                system("cls");
                double calificacion;
                string titulo;
                do{
                    try{
                        errorEntrada = false;

                        cout << "Introduzca el titulo del video a calificar: " <<endl;
                        std::getline(std::cin >> std::ws, titulo);

                        cout << "Introduzca el valor de calificacion para el video: " <<endl;
                        cin >> calificacion;
                        if (cin.fail()){
                            cin.clear();
                        }

                        if (calificacion < 1.0 || calificacion > 5.0){
                            errorEntrada = true;
                            system("cls");
                        }
                        else{
                            system("cls");
                            bool calificado = sistema.calificarVideo(titulo, calificacion);

                            if (calificado == false){
                                cout << "Lo sentimos, el video que usted intenta calificar no se encuentra registrado o tiene un nombre diferente." <<endl;
                            }
                        }

                        if (errorEntrada){
                            throw MyException("El valor de la calificacion debe estar entre 1 y 5, por favor intentelo de nuevo.\n");
                        }
                    }
                    catch (MyException& ex){
                        system("cls");
                        cout << ex.what() <<endl;
                    }
                }
                while (errorEntrada);

                cout << "\nIntroduzca cualquier caracter para continuar: " <<endl;
                cin >> continuar;
                system("cls");
            }

            else{
                errorMenu = true;
                system("cls");
            } 

            if (errorMenu){
                throw MyException("Entrada invalida, por favor intentelo de nuevo.\n");
            }
        }
        catch (MyException& ex){
            cout << ex.what() <<endl;
            errorMenu = false;
        }
    }
    while (!salir);
    exit(0);

    return 0;
}