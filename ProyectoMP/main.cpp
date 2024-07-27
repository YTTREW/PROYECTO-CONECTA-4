/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 16 de mayo de 2024, 21:08
 */

#include <cstdlib>
#include "MatrizEnteros.h"
#include "Tablero.h"
#include "ConjuntoJugadores.h"
#include "Partida.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    
    //Comprobamos que el numero  de argumentos sea 2
    if (argc != 2) {
        cerr << "No se ha encontrado el fichero de configuración" << endl;
        return 1;
    }
    
    //Recibimos el fichero de competicion
    string configFile = argv[1];
    ifstream config(configFile);
    if (!config.is_open()) {
        cerr << "Error al abrir el fichero de configuración" << endl;
        return 1;
    }
    
    //Leemos el ficher y sacamos los datos
    string linea;
    string nuevaPartida, ficheroCampeonato;
    int jug1, jug2, N, Ntowin, numJugadores;
    string* nombres=nullptr;
    string* apellidos=nullptr;   
    
    while (getline(config, linea)) {
        stringstream ss(linea);
        string valor;
        if (ss >> valor) {
            if (valor == "NUEVAPARTIDA") {
                ss.ignore(3); // En todas las lineas : Se ignora ' = '
                ss >> nuevaPartida;
            } else if (valor == "FICHEROCAMPEONATO") {
                ss.ignore(3); 
                ss >> ficheroCampeonato;
            } else if (valor == "JUGADORESID") {
                ss.ignore(3); 
                ss >> jug1 >> jug2;
            } else if (valor == "TAM") {
                ss.ignore(3); 
                ss >> N;
            } else if (valor == "NTWIN") {
                ss.ignore(3); 
                ss >> Ntowin;
            } else if (valor == "JUGADORES") {
                ss.ignore(3);
                ss >> numJugadores;
                nombres = new string[numJugadores];
                apellidos = new string[numJugadores];
                 for (int i = 0; i < numJugadores; i++) {
                    getline(config, linea);
                    stringstream ssJugador(linea);
                    ssJugador >> nombres[i] >> apellidos[i];
                }
            }
        }
    }

    config.close();
    
    if (nuevaPartida == "sí") {
        cout<< "Creando nueva partida..." << endl;
        NuevaPartida(ficheroCampeonato, numJugadores, nombres, apellidos, jug1, jug2, N, Ntowin);
    }
    else if (nuevaPartida == "no") {
        cout<< "Cargando una partida existente..." << endl;
        CargaPartida(ficheroCampeonato, jug1, jug2, N, Ntowin);
    } else {
        cerr << "Valor de NUEVAPARTIDA no válido." << endl;
        return 1;
    }
    
    return 0;
}

