/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Jugador.h
 * Author: Carlos Fernandez Arrabal
 *
 * Created on 24 de Mayo de 2024
 */

/**@class Partida
 * @brief La clase Partida es la clase principal que debe configurarse desde el main para el correcto 
 * funcionamiento de la partida de conectaN 
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
#include "Tablero.h"
#include "ConjuntoJugadores.h"
#include "MatrizEnteros.h"

class Partida {
public:
    /**
     * @brief Constructor que inicializa una nueva partida con un tablero y un conjunto de jugadores.
     * @param newtab Objeto Tablero que representa el tablero del juego.
     * @param newjug Objeto ConjuntoJugadores que representa los jugadores.
     */
    Partida(Tablero & newtab, ConjuntoJugadores & newjug);

    /**
     * @brief Constructor de copia.
     * @param orig Objeto Partida que se va a copiar.
     */
    Partida(const Partida & orig);

    /**
     * @brief Destructor.
     * Libera los recursos utilizados por la partida.
     */
    ~Partida();

    /**
     * @brief Método que maneja el turno actual del juego.
     * Indica quien posee el turno para poder introducir una ficha en el trablero.
     */    
    void turno();
    
    /**
     * @brief Inicializa la partida con los jugadores especificados.
     * @param newjug1 ID del primer jugador.
     * @param newjug2 ID del segundo jugador.
     */   
    void inicializaPartida(int newjug1, int newjug2);
    
    /**
     * @brief Guarda el estado actual de la partida en un archivo.
     * @param file Nombre del archivo donde se guarda el estado de la partida.
     */
    void save(string file);

    /**
     * @brief Carga el estado de una partida desde un archivo.
     * @param file Nombre del archivo desde donde se carga el estado de la partida.
     */
    void load(string file);
   
    
    /**
     * @brief Arranca la partida.
     * Llama reiteradamente al metódo turno hasta que uno de los jugadores gane la partida.
     */
    void realizaPartida();
    
    /**
     * @brief Imprime por pantalla la matriz competición y el ranking de jugadores.
     * Muestra el resultado de la matriz y como han quedado los jugadores tras la partida.
     */    
    void muestraResultadosCompeticion();
       
private:
    Tablero tab;
    ConjuntoJugadores jugs;
    int jug1, jug2;
    int turnoactual;
};

/**
 * @brief Inicializa una nueva partida y la guarda en un archivo.
 * @param savefile Nombre del archivo donde se guarda el estado de la partida.
 * @param numjugadores Número de jugadores en la partida.
 * @param nombres Vector de nombres de los jugadores.
 * @param apellidos Vector de apellidos de los jugadores.
 * @param jug1 ID del primer jugador.
 * @param jug2 ID del segundo jugador.
 * @param N Tamaño del tablero para jugar.
 * @param Ntowin Número de fichas seguidas necesarias para ganar.
 */
void NuevaPartida(string savefile, int numjugadores, string * nombres, string * apellidos, int jug1, int jug2, int N, int Ntowin);

/**
 * @brief Carga una partida desde un archivo, la inicializa con los jugadores especificados y la vuelve a guardar.
 * @param savefile Nombre del archivo desde donde se guarda y carga el estado de la partida.
 * @param jug1 ID del primer jugador.
 * @param jug2 ID del segundo jugador.
 * @param N Tamaño del tablero para jugar.
 * @param Ntowin Número de fichas seguidas necesarias para ganar.
 */
void CargaPartida(string savefile, int jug1, int jug2, int N, int Ntowin);
#endif // PARTIDA_H
