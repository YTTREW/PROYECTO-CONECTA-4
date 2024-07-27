/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Jugador.cpp
 * Author: Carlos Fernandez Arrabal
 * 
 * Created on 8 de febrero de 2024
 */

#include "Jugador.h"
#include <iostream>
using namespace std;
Jugador::Jugador() {
    //vacio
}

Jugador::Jugador(const Jugador& orig) { 
    id = orig.id;
    nombre = orig.nombre;
    apellidos = orig.apellidos;
    partidasganadas = orig.partidasganadas;
    partidasjugadas = orig.partidasjugadas;
}

Jugador::~Jugador() {
    //vacío
}

Jugador::Jugador(int newid, string newnombre, string newapellidos){

    id = newid;
    nombre = newnombre;
    apellidos = newapellidos;
    partidasganadas = 0;
    partidasjugadas = 0;
}


string Jugador::getApellidos(){
    return apellidos;
}


string Jugador::getNombre(){
    return nombre;
}


int Jugador::getPartidasGanadas() const{
    return partidasganadas;
}


int Jugador::getId(){
    return id;
}


int Jugador::getPartidasJugadas()const{
    return partidasjugadas;
}

void Jugador::partidaGanada(){
    partidasganadas++;
}


void Jugador::partidaJugada(){
    partidasjugadas++;
}

void Jugador::setPartidasGanadas(int ganadas) {
    partidasganadas = ganadas;
}

void Jugador::setPartidasJugadas(int jugadas) {
    partidasjugadas = jugadas;
}

Jugador & Jugador::operator=(const Jugador & orig){ 

    if(this != &orig){
        this->nombre = orig.nombre;
        this->id = orig.id;
        this->apellidos = orig.apellidos;
        this->partidasganadas = orig.partidasganadas;
        this->partidasjugadas = orig.partidasjugadas;
    }
    return *this;
}

 
std::ostream & operator << (std::ostream & flujo, const  Jugador & jug){
    
    flujo << "ID: " << jug.id<< " Nombre: " << jug.nombre << " Apellidos: " << jug.apellidos << " Partidas ganadas: " << jug.partidasganadas << " Partidas jugadas: " << jug.partidasjugadas<<endl;
    return flujo;
}
