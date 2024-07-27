/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tablero.h
 * Author: Carlos Fernandez Arrabal
 *
 * Created on 20 de febrero de 2024
 */

#ifndef TABLERO_H
#define TABLERO_H
#include "MatrizEnteros.h"
#include <string>

using namespace std;

class Tablero {
    /**
     * @class
     * - Esta clase utiliza un objeto de MatrizEnteros para 
     * implementar un tablero de conectaN.
     * - El valor por defecto es 0 y la matriz utilizada es cuadrada. Su tamaño viene determinado por tam. 
     * - Si en una casilla del tablero hay una ficha, está tendrá el id del jugador. 
     * - Si en una casilla del tablero no hay una ficha, entonces ésta tendrá valor 0
     *   que será el valor por defecto. 
     * - En el futuro implementaremos un conjunto de jugadores y cada uno tendrá su id. 
     */
public:
    /**
     * @brief constructor de la clase. El valor por defecto de la matriz es 0.  
     * @param newtam tamaño de la matriz (la matriz es cuadrada)
     * @param newNtowin cantidad de fichas en línea para ganar
     */
    Tablero(int newtam,int newNtowin);
    
       /**
     * @brief constructor vacío de la clase..  
     */
    Tablero();

    /**
     * @brief dejar vacío. 
     */
    Tablero(const Tablero& orig);
 
    /**
     * @brief Cada ficha está identificada con el id del jugador. El jugador 
     * introduce la ficha en la columna y ésta baja hasta la posición
     * más baja del tablero en esa columna que no contenga ya una ficha. 
     * @param col Columna en la que se introduce la ficha. 
     * @param jug id del jugador que la introduce.
     * @return true si la inserción ha sido posible (la columna no está llena 
     * de fichas) o false en otro caso
     */
    bool introducirFicha(int col, int jug);
    
    /**
     * @return Devuelve true si el tablero está lleno de fichas
     * y no se puede introducir ni una más. 
     */
    bool tableroLleno();
    
    /**
     * dejar vacío
     */
    virtual ~Tablero();
    
    /**
     * @brief Imprime la matriz asociada al tablero.
     * @return un string con la matriz con la misma estructura
     * que la de la clase MatrizEnteros. 
     */
    string tablerotostring();
    
    /**
     * @brief Devuelve 0 si ningun jugador ha ganado o el id del jugador   
     * @return El id del jugador ganador en caso de haber un vencedor
     */ 
    int ganador();
    
    /**  
     * @brief Operador de asignación (asigna los valores de orig al objeto). 
     * @param orig objeto tablero que se asigna.
     * @return Devuelve el objeto tablero ya asignado. 
     */
    Tablero & operator=(const Tablero& orig);
    
    /*
     * @brief Introduce en flujo la información de la clase referente a tablero.
     * Utilizamos el operador << de tablero para hacer este proceso y entre elemento y
     * elemento se introduce el caracter "\n" para que cada jugador aparezca en una línea
     * si lo imprimimos con cout. 
     */
    friend std::ostream& operator<<(std::ostream & os, const Tablero & tablero);
    
private:
    MatrizEnteros t;
    int tam;
    int Ntowin;
};

#endif /* TABLERO_H */

