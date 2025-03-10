/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MatrizEnteros.h
 * Author: Carlos Fernandez Arrabal
 *
 * Created on 20 de febrero de 2024
 */

#ifndef MATRIZENTEROS_H
#define MATRIZENTEROS_H
#include <string>
using namespace std;
class MatrizEnteros {
public: 
    /**@brief Inicializa la clase MatrizEnteros
        @param fil Número de filas de la matriz.
     * @param col Número de columnas de la matriz.
     * @param def valor por defecto de la matriz (de inicialización). 
     */
    MatrizEnteros(int fil=7, int col=7, int def=0);
    /**@brief dejar vacío*/
    MatrizEnteros(const MatrizEnteros& orig);
    /**@brief dejar vacío*/
    ~MatrizEnteros();
    /**@brief Devuelve un string que contiene la matriz. Se usará
     * \n al final de cada fila y se dejará un espacio entre los elementos.
     * Ejemplo (matriz de 2 filas y 5 columnas:
     * 1 2 3 4 5 \n 9 8 7 6 4 \n
     * Cuando se imprima con cout se mostrará:
     * 1 2 3 4 5
     * 9 8 7 6 4
     */
    string matriztostring() const;
    
    /**
     * @brief Devuelve una referencia a un valor de la matriz lo que permite 
     * su modificación
     * @param fil número de fila.
     * @param col número de columna.
     * Ejemplo de uso:
     * 1 2 3 
     * 4 5 6
     * 7 8 9
     *  m.putValue(1,1) = 4
     * 1 2 3 
     * 4 4 6
     * 7 8 9
     */
    int & putValue(int fil, int col);
    
    /**
     * @brief Devuelve un valor de la matriz
     * @param fil
     * @param col
     * @return el valor de esa posición de la matriz
     */
    int getValue(int fil, int col);
    
    /**
     * @brief Devuelve cuál es el valor por defecto o de vacío de la matriz
     * @return 
     */
    int valordefecto();
    
    /**
     * @brief Todos los valores de la matriz pasan a ser el valor por defecto
     * (elimina la información). 
     */
    void inicializarMatriz();
    
    /**
     * @brief  Reserva memoria para la matriz m
     * @param f numero de filas
     * @param c numero de columnas
     */
    void reservarMemoria(int f, int c);
    
    /**
     * @brief  Libera memoria para la matriz m
     */    
    void liberarMemoria();
    
    /**  
     * @brief Operador de asignación (asigna los valores de orig al objeto). 
     * @param orig objeto matriz que se asigna.
     * @return Devuelve el objeto matriz ya asignado. 
     */
    MatrizEnteros& operator=(const MatrizEnteros& orig);  
    
    /**
     * @brief Modifica el tamaño de la matriz. Si la nueva matriz es más grande
     * que la original entonces se conservan los valores. Si es más chica se borra
     * la información.  
     * @param newf nuevo tamaño de fila
     * @param newc nuevo tamaño de columna
     */
    void resize(int newf, int newc);
    
    /**@brief Operador de flujo de salida. Introduce en la variable ostream os
     * Los valores están separados por espacios. 
     * @return Devuelve flujo con los valores del objeto matrizEnteros introducidos.
     */   
    friend ostream& operator<<(ostream& os, const MatrizEnteros& matriz);
    
private:
    int **m;
    int filas;
    int columnas;
    int defecto=0;
};

#endif /* MATRIZENTEROS_H */

