/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: Carlos Fernandez Arrabal
 * 
 * Created on 20 de febrero de 2024
 */

#include "Tablero.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <valarray>
using namespace std;

//Constructor
Tablero::Tablero(){
}
Tablero::Tablero(int newN=4, int newNtowin=4){
    if (newN <= 0) {
        std::cerr << "Error: El tamaño del tablero tiene que ser mayor que cero." << std::endl;
        exit(-1);
    }

    if (newNtowin <= 0) {
        std::cerr << "Error: El número de fichas tiene que ser mayor que cero." << std::endl;
        exit(-1);
    } 
    
    tam = newN;
    Ntowin = newNtowin;
    t = MatrizEnteros(tam,tam,0);
}

//Constructor de Copia
Tablero::Tablero(const Tablero& orig) {

}

//Destructor
Tablero::~Tablero() {
    
}

//ntroducir fichas
bool Tablero::introducirFicha(int col, int jug){
    if(col < 0 || col >= tam){
        return false;
    }
    
    int fila = tam -1; // Se cuenta desde 0
    while(fila >= 0 && t.getValue(fila,col)!= t.valordefecto() ){ // mientras no haya recorrido todas las filas y la casilla no este vacia
        fila--;
    }
    
    if(fila<0){
        return false;
    }
    else{
        t.putValue(fila,col) = jug;
        return true;
    }
}

//Comprobar si el tablero esta lleno
bool Tablero:: tableroLleno(){
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            if(t.getValue(i,j)==0){
                return false;   
            }
        }
    }      
    return true;    
}

//Pasar tablero a string
string Tablero::tablerotostring(){
    string tablero_resultado;
    
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            tablero_resultado += std::to_string(t.getValue(i, j)); 
            if(j < tam -1){
            tablero_resultado += " "; 
            }
        }
        tablero_resultado += "\n"; 
    } 
    return tablero_resultado;
}

//Operador de Asignación
Tablero& Tablero::operator=(const Tablero& orig) {
    if (this != &orig) {
        tam = orig.tam;
        Ntowin = orig.Ntowin;
        t = orig.t; 
    }
    return *this;
}

int Tablero::ganador(){
 //Buscamos en horizontal/vertical y diagonales
for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            int jug = t.getValue(i, j);
            if (jug != 0) {
                if (j <= tam - Ntowin) {
                    bool ganar = true;
                    for (int k = 1; k < Ntowin; k++) {
                        if (t.getValue(i, j + k) != jug) {
                            ganar = false;
                            break;
                        }
                    }
                    if (ganar) {
                        cout << "El jugador " << jug << " ha ganado la partida" << endl;
                        return jug;
                    }
                }
                
                if (i <= tam - Ntowin) {
                    bool ganar = true;
                    for (int k = 1; k < Ntowin; k++) {
                        if (t.getValue(i + k, j) != jug) {
                            ganar = false;
                            break;
                        }
                    }
                    if (ganar) {
                        cout << "El jugador " << jug << " ha ganado la partida" << endl;
                        return jug;
                    }
                }
                
                 if (i <= tam - Ntowin && j <= tam - Ntowin) {
                    bool ganar = true;
                    for (int k = 1; k < Ntowin; k++) {
                        if (t.getValue(i + k, j + k) != jug) {
                            ganar = false;
                            break;
                        }
                    }
                    if (ganar) {
                        cout << "El jugador " << jug << " ha ganado la partida" << endl;
                        return jug;
                    }
                }
                
                 if (i <= tam - Ntowin && j >= Ntowin - 1) {
                    bool ganar = true;
                    for (int k = 1; k < Ntowin; k++) {
                        if (t.getValue(i + k, j - k) != jug) {
                            ganar = false;
                            break;
                        }
                    }
                    if (ganar) {
                        cout << "El jugador " << jug << " ha ganado la partida" << endl;
                        return jug;
                    }
                }           
            }
        }  
    }
    if (tableroLleno()) {
           cout << "Los jugadores han empatado." << endl;
           return -1;
       }

    return 0; 
}

ostream& operator<<(ostream& os, const Tablero& tablero) {
    os << tablero.t.matriztostring();
    return os;
}

