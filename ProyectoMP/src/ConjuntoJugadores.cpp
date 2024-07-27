
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conjuntoJugadores.cpp
 * Author: Carlos Fernandez Arrabal
 * 
 * Created on 8 de febrero de 2024
 */

#include "ConjuntoJugadores.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

ConjuntoJugadores::ConjuntoJugadores(int k) { 
  tamreservado = k; 
  numjugadores = 0;
  vectorJugadores = new Jugador[tamreservado];
  competicion = MatrizEnteros(k, k, 0); 
}

ConjuntoJugadores::~ConjuntoJugadores() { 
    delete [] vectorJugadores;
}

ConjuntoJugadores & ConjuntoJugadores::operator+=(const Jugador& newjug){
    
    if(numjugadores >= tamreservado){
        resize(tamreservado*2);
    }

    vectorJugadores[numjugadores] = newjug;
    numjugadores++;

    ordenaporId();
    
    return *this;
}


void ConjuntoJugadores::resize(int newtam){
    if (newtam >= tamreservado) {
        Jugador* jug = new Jugador[newtam];

        for (int i = 0; i < numjugadores; ++i) {
            jug[i] = vectorJugadores[i];
        }

        delete[] vectorJugadores;

        vectorJugadores = jug;
        tamreservado = newtam;
    }   
}

ConjuntoJugadores::ConjuntoJugadores(const ConjuntoJugadores& orig){ 
          
    this->numjugadores = orig.numjugadores;
    this->tamreservado = orig.tamreservado;
    this->vectorJugadores = new Jugador[this->tamreservado];
        
    for (int i = 0; i < this->numjugadores; i++) {
        this->vectorJugadores[i] = orig.vectorJugadores[i];
    }  
    competicion = orig.competicion;
}

void ConjuntoJugadores::ordenaporId(){
    for(int i = 0; i<numjugadores; i++){
        int menor = vectorJugadores[i].getId();
        int pos = i;
        
        for(int j = i+1; j<numjugadores; j++){
            if(vectorJugadores[j].getId()<menor){
                menor = vectorJugadores[j].getId();
                pos = j;
            }
        }
        
        Jugador aux = vectorJugadores[i];
        vectorJugadores[i] = vectorJugadores[pos];
        vectorJugadores[pos] = aux;    
    }
}

std::ostream & operator<< (std::ostream & flujo, const ConjuntoJugadores & conjug){
    flujo<< "Conjunto de jugadores:";
    
    for (int i = 0; i < conjug.numjugadores; ++i) {
        flujo<<"\n";
        flujo << conjug.vectorJugadores[i].getId() << " ";
        flujo << conjug.vectorJugadores[i].getNombre() << " ";
        flujo << conjug.vectorJugadores[i].getApellidos() << " ";
        flujo << conjug.vectorJugadores[i].getPartidasGanadas() << " "; 
        flujo << conjug.vectorJugadores[i].getPartidasJugadas() << " ";

    } 
    
    return flujo;
}
   
int ConjuntoJugadores::buscaJugador(int jugid){
    int pos = -1;
    for(int i = 0; i<numjugadores; i++){
        if(vectorJugadores[i].getId() == jugid){
            pos =  i;
        }
    }
    return pos;
}

string ConjuntoJugadores::rankingJugadores(){
    string ranking;
    double ratioV1;
    double ratioV2;

    for (int i = 0; i <numjugadores-1; i++){
        for (int j = 0; j < numjugadores-i-1; j++){
            if (vectorJugadores[j].getPartidasJugadas() == 0){
                ratioV1 = 0;
            } 
            else {
                ratioV1 =  static_cast<double>(vectorJugadores[j].getPartidasGanadas()) / vectorJugadores[j].getPartidasJugadas();
            }          

            if (vectorJugadores[j + 1].getPartidasJugadas() == 0) {
                ratioV2 = 0;
            } 
            else {
                ratioV2 = static_cast<double>(vectorJugadores[j + 1].getPartidasGanadas()) / vectorJugadores[j + 1].getPartidasJugadas();
            }

             if (ratioV1 < ratioV2) {
                std::swap(vectorJugadores[j], vectorJugadores[j + 1]);
            }
        }
    }

    ranking += "Ranking:\n";
    double ratio;

    for (int i = 0; i < numjugadores; i++){
        if (vectorJugadores[i].getPartidasJugadas() == 0){
            ratio = 0;
        } 
        else{
            ratio = static_cast<double>(vectorJugadores[i].getPartidasGanadas()) / vectorJugadores[i].getPartidasJugadas();
        }
        ranking += to_string(vectorJugadores[i].getId()) + "," + vectorJugadores[i].getNombre() + "," + vectorJugadores[i].getApellidos() + "," + to_string(ratio) + "\n";
    }

    return ranking;  
}


ConjuntoJugadores::ConjuntoJugadores(int n, string *nombres, string * apellidos){
    tamreservado = n;
    numjugadores = n;
    vectorJugadores = new Jugador[tamreservado];
    
    for(int i = 0; i<n; i++){
        vectorJugadores[i]= Jugador( i+1,nombres[i], apellidos[i]);
    }
    
    competicion = MatrizEnteros(n, n, 0);
}

string ConjuntoJugadores::esquemaCompeticion(){
    string matriz_resultado;
    
    for(int i = 0; i<numjugadores; i++){
        for(int j = 0; j<numjugadores; j++){
            if (i == j) {
                matriz_resultado += "- ";
            } 
            else {
                matriz_resultado += to_string(competicion.getValue(i, j)) + " ";
            }     
        }
    matriz_resultado += "\n";   
    }
    
    return matriz_resultado;        
}

void ConjuntoJugadores::apuntaPartida(int jug1, int jug2) {
    int pos1 = buscaJugador(jug1);
    int pos2 = buscaJugador(jug2);
    
    vectorJugadores[pos1].partidaJugada();
    vectorJugadores[pos1].partidaGanada();
    vectorJugadores[pos2].partidaJugada();
    
    competicion.putValue(pos1,pos2)+=1;
}

void ConjuntoJugadores::apuntaEmpate(int jug1, int jug2) {
    int pos1 = buscaJugador(jug1);
    int pos2 = buscaJugador(jug2);

    vectorJugadores[pos1].partidaJugada();
    vectorJugadores[pos2].partidaJugada();
}

void ConjuntoJugadores::save(string fichero) {
    ofstream fo("./data/" + fichero);

    if (fo.is_open()) {
        // Guardar información de cada jugador
        fo << "#Lista de Jugadores:\n";

        for (int i = 0; i < numjugadores; ++i) {
            Jugador jugador = vectorJugadores[i];
            fo << jugador.getNombre() << " " << jugador.getApellidos() << " "
               << jugador.getPartidasGanadas() << " " << jugador.getPartidasJugadas() << "\n";
        }

        // Guardar matriz de competición
        fo << "\n#Matriz de competición:\n";
        fo << esquemaCompeticion();
    } 
    else {
        cerr << "Error al abrir el archivo para guardar la partida" << endl;
    }

    fo.close();
}

void ConjuntoJugadores::load(string fichero) {
    ifstream fi;
    fi.open("./data/" + fichero);
    string linea;
 
    if (fi.is_open()){
        bool leerJugadores = false;
        bool leerMatriz = false;
        
        while(getline(fi, linea)){
            if (linea.empty()) {
                continue; // Saltar líneas vacías
            }
             if (linea == "#Lista de Jugadores:") {
                leerJugadores = true;
                continue; 
            }

            if (linea == "#Matriz de competición:") {
                leerMatriz = true;
                leerJugadores = false;

            }
             
            if (leerJugadores) {
                stringstream ss(linea);
                int ganadas, jugadas;
                string nombre, apellidos;
                
                ss >> nombre >> apellidos >> ganadas >> jugadas;
                
                static int idCounter = 1;
                Jugador jugador(idCounter++, nombre, apellidos);
                jugador.setPartidasGanadas(ganadas);
                jugador.setPartidasJugadas(jugadas);
                *this += jugador;
            } 
           
            if (leerMatriz) {
                int value;
                for (int i = 0; i < numjugadores; i++) {
                    for (int j = 0; j < numjugadores; j++) {
                        string guion;
                        fi >> guion;
                        if (guion == "-") {
                            value = 0; 
                        }
                        else {
                            value = stoi(guion);
                        }

                        if (i != j) {
                            competicion.putValue(i, j)=value;
                        }
                    }
                }
                break;
            }
        }
    }
}




  

 
