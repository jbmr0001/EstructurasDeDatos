/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashPalabra.h
 * Author: Juan Bautista
 *
 * Created on 13 de diciembre de 2020, 16:12
 */

#ifndef THASHPALABRA_H
#define THASHPALABRA_H

#include "Palabra.h"
#include <vector>

enum Est{Libre,Ocupada,Disponible};

inline unsigned long djb2(unsigned char *str){
    unsigned long hash=5381;
    int c;
    while(c=*str++){
        hash=((hash<<5)+hash)+c;
    }
    return hash;
}
class THashPalabra {
public:
    ///////////CONSTRUCTORES//////////
    THashPalabra(unsigned long tamTabla=0);
    THashPalabra(const THashPalabra& orig);
    virtual ~THashPalabra();
    //////////OPERADORES////////////
    THashPalabra& operator=(const THashPalabra& orig);
    //////////FUNCIONES/////////////
    bool insertar(unsigned long clave,const std::string &ter, Palabra &pal);
    bool buscar(unsigned long clave,const std::string &ter,Palabra* &pal);
    bool borrar(unsigned long clave,const std::string &ter);
    ////////GETTERS/////////
    unsigned int getMaxColisiones();
    float getPromedioColisiones();
    float getFactorCarga();
    unsigned int getTamTabla();
    unsigned int getNColisiones();
    unsigned int getNumElem();
    
private:
    class Entrada{
         public:
             unsigned long _clave;
             std::string _termino;
             Palabra _pal;
             Est _estado;
             
             Entrada():
                _clave(0),
                _termino(""),
                _pal(Palabra()),
                _estado(Libre)
             {}
             ~Entrada(){}
             
    };
    
    unsigned int _primo;
    unsigned int _tamaTabla;
    unsigned int _nElem;
    unsigned int _nTerRepetidos;
    unsigned int _nColisiones;
    unsigned int _maxColisiones;
    std::vector<Entrada> _tabla;
    
    /////////FUNCIONES NECESARIAS////////////
    //Dispersion cuadrática
    unsigned hashCuadratica(unsigned long clave, int i){
        unsigned long posFinal=(clave+(i*i))%_tamaTabla;
        return posFinal;
    }
    //Dispersiones dobles
    inline unsigned hashDoble1(unsigned long clave, int i){
        unsigned long pos,posFinal;
        pos=clave%_tamaTabla;
        posFinal=(pos+(i*(1+(clave%_primo))))%_tamaTabla;
        return posFinal;
    }
    inline unsigned hashDoble2(unsigned long clave,int i){
        unsigned long pos,posFinal;
        pos=clave%_tamaTabla;
        posFinal=(pos+(i*(_primo-(clave%_primo))))%_tamaTabla;
        return posFinal;
    }
    //función que nos devuelve si es primo
    bool primo(unsigned p){
        for(unsigned i=2;i<p/2;++i){
            if(p%i==0){//en caso de tener divisores distintos de 1 o 2 no es primo
                return false;
            }
        }
        return true;
    }
    //funcion que decrementa hasta encontrar un primo
    int calcularPrimoMenor(unsigned p){
        int pMenor=p-1;
        while(!primo(pMenor)){
            pMenor--;
        }
        return pMenor;
    }

};

#endif /* THASHPALABRA_H */

