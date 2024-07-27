/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Jugador.cpp
 * Author: Carlos Fernandez Arrabal
 * 
 * Created on 24 de Mayo de 2024
 */
#include "Partida.h"
#include "Tablero.h"
#include "ConjuntoJugadores.h"
#include <iostream>


//Constructor
Partida::Partida(Tablero & newtab, ConjuntoJugadores & newjug) : jugs(newjug) {
    tab = newtab;
    jug1 = 0;
    jug2 = 0;
    turnoactual = 0;
}

//Constructor de copia
Partida::Partida(const Partida & orig) 
    : tab(orig.tab), jugs(orig.jugs), jug1(orig.jug1), jug2(orig.jug2), turnoactual(orig.turnoactual) {

}

Partida::~Partida() {
    
}

//Método Turno
void Partida::turno() {
    cout <<tab.tablerotostring();
    int columna;

    cout << "Jugador " << turnoactual << ", introduzca ficha (escoge columna): ";
    cin >> columna;
    if( tab.introducirFicha(columna, turnoactual)){ 
        if (turnoactual == jug1){
            turnoactual = jug2;
        } 
        else{
            turnoactual = jug1;
        }
    } 
    else{
        cout << "Movimiento inválido. Intentelo de nuevo.\n";
    }
}

//Método Inicializar Partida
void Partida::inicializaPartida(int newjug1, int newjug2) {
    jug1 = newjug1;
    jug2 = newjug2;
    turnoactual = jug1;
}

//Método para guardar la partida
void Partida::save(string file) {
    jugs.save(file); 
}

//Método para cargar la partida
void Partida::load(string file) {
    jugs.load(file); 
}

//Método para realizar una partida
void Partida::realizaPartida() {
    int ganador = 0;
    while ((ganador = tab.ganador()) == 0) { 
        turno();
    }
    if(ganador==1)
        jugs.apuntaPartida(jug1, jug2); 
    
    else if(ganador==2)
        jugs.apuntaPartida(jug2, jug1); 
    
    else
        jugs.apuntaEmpate(jug1, jug2); 
    
}

//Método Opcional para mostrar los resultados
void Partida::muestraResultadosCompeticion() {
    cout << "Matriz De Competicion:"<<endl;
    cout << jugs.esquemaCompeticion();
    
    cout << jugs.rankingJugadores();
}

void NuevaPartida(string savefile, int numjugadores, string * nombres, string * apellidos, int jug1, int jug2, int N, int Ntowin) {
    Tablero tab(N, Ntowin);

    // Inicializa el objeto ConjuntoJugadores
    ConjuntoJugadores jugs(numjugadores, nombres, apellidos);

    if (jugs.buscaJugador(jug1) == -1 || jugs.buscaJugador(jug2)== -1) {
        cerr << "Error: Uno o ambos jugadores no existen en el conjunto de jugadores." << endl;
        return;
    }

    //Inicializa el objeto Partida
    Partida partida(tab, jugs);

    //Inicia la partida
    partida.inicializaPartida(jug1, jug2);

    //Realiza la partida
    partida.realizaPartida();
    
    //Muestra los resultados de la partida
    partida.muestraResultadosCompeticion();

    //Guarda los resultados de la partida
    partida.save(savefile);    
}

void CargaPartida(string savefile, int jug1, int jug2, int N, int Ntowin) {
    
    //Inicializa un objeto Tablero
    Tablero tab(N, Ntowin);

    // Inicializa un objeto ConjuntoJugadores y se carga la partida
    ConjuntoJugadores jugadores;
    jugadores.load(savefile);
    
    //Inicializa un objeto Partida 
    Partida partida(tab, jugadores);

    //Inicia la partida
    partida.inicializaPartida(jug1, jug2);

    //Realiza la partida
    partida.realizaPartida();
    
    partida.muestraResultadosCompeticion();

    //Guarda los resultados de la partida
    partida.save(savefile);
}
