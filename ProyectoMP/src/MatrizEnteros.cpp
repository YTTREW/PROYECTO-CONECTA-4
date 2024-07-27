/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MatrizEnteros.cpp
 * Author: Carlos Fernandez Arrabal
 * 
 * Created on 20 de febrero de 2024
 */

#include "MatrizEnteros.h"
#include <iostream>
using namespace std;

//Constructor
MatrizEnteros::MatrizEnteros(int fil, int col, int def) {
    if(fil>100 || col >100){
        std::cerr << "Error: El número de filas y columnas no puede ser mayor que 100." << std::endl;
        exit(-1);
    }
    
    filas = fil;
    columnas = col;
    defecto = def;
    
    reservarMemoria(filas, columnas);
    
    inicializarMatriz();
}

//Inicializar matriz a Valor por Defecto
void MatrizEnteros::inicializarMatriz(){
    for(int i = 0; i<filas; i++){
        for(int j = 0; j<columnas; j++){
            m[i][j] = defecto;
        }
    }   
}

//Constructor de Copia
MatrizEnteros::MatrizEnteros(const MatrizEnteros& orig) {
    m = nullptr;
    filas = orig.filas;
    columnas = orig.columnas;
    defecto = orig.defecto;
    
    reservarMemoria(filas, columnas);
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            m[i][j] = orig.m[i][j];
       }
    }
}

//Operador de Asignación
MatrizEnteros& MatrizEnteros::operator=(const MatrizEnteros& orig) {
    if (this != &orig) {  

        liberarMemoria();

        filas = orig.filas;
        columnas = orig.columnas;
        defecto = orig.defecto;

        reservarMemoria(filas, columnas);

        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                m[i][j] = orig.m[i][j];
            }
        }
    }
    return *this;  
}


//Destructor
MatrizEnteros::~MatrizEnteros() {
    liberarMemoria();
}

//Referencia al valor
int & MatrizEnteros:: putValue(int fil, int col){
    return m[fil][col];
}

//Devolver valor especifico
int MatrizEnteros::getValue(int fil, int col){
   return m[fil][col];
}

//Pasar matriz a String
string MatrizEnteros::matriztostring() const{
    string matriz_resultado;
    
    for(int i = 0; i<filas; i++){
        for(int j = 0; j<columnas; j++){
            matriz_resultado += std::to_string(m[i][j]);
            if(j < columnas -1){
                matriz_resultado += " "; 
            }        
        }
    matriz_resultado += "\n";   
    }
    
    return matriz_resultado; 
}

//Devuelve Valor por Defecto
int MatrizEnteros::valordefecto(){
    return defecto;   
}

//Resize de la matriz
void MatrizEnteros::resize(int newf, int newc){
    if(newf<=0 || newc<=0 || newf>100 || newc>100){
        std::cerr<<"Las dimensiones tienen que ser mayores que 0 y menores que 100"<<endl;
    }
    
    int **matrizaux = new int *[newf];
    for (int i = 0; i < newf; ++i) {
        matrizaux[i] = new int[newc];
    }
    
    for (int i = 0; i < newf; ++i) {
        for (int j = 0; j < newc; ++j) {
            if (i < filas && j < columnas) {
                matrizaux[i][j] = m[i][j];
            } else {
                matrizaux[i][j] = defecto;
            }
        }
    }
    
    liberarMemoria();
    
    m = matrizaux;
    filas = newf;
    columnas = newc;   
}

void MatrizEnteros::reservarMemoria(int fils, int cols){
    
    m = new int * [fils];
    for(int i =0; i<fils; i++){
        m[i] = new int[cols];
    }
}

void MatrizEnteros::liberarMemoria(){
    for(int i = 0; i<filas; ++i){
        delete [] m[i];
    }
    delete [] m;
}

ostream& operator<<(ostream& os, const MatrizEnteros& matriz) {
    for (int i = 0; i < matriz.filas; ++i) {
        for (int j = 0; j < matriz.columnas; ++j) {
            os << matriz.m[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}


