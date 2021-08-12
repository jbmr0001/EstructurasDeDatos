/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VDinamico.h
 * Author: Juan Bautista
 *
 * Created on 11 de octubre de 2020, 18:22
 */

#ifndef VDINAMICO_H
#define VDINAMICO_H

using std::string;
#include <climits>
#include <algorithm>

template <typename T>
class VDinamico{
    public:
        /////////////////CONSTRUCTORES////////////////////
        VDinamico();
        VDinamico(unsigned long int tam);
        VDinamico(const VDinamico<T>& origen);
        VDinamico(const VDinamico<T>& origen, unsigned int inicio,unsigned int num);
        ~VDinamico();
        ////////////////OPERADORES//////////////////////
        VDinamico &operator=(const VDinamico<T>& origen);
        T& operator[](unsigned long int pos);
        ////////////////FUNCIONES/////////////////////////
        void insertar(const T& dato, unsigned long int pos=UINT_MAX);
        T borrar(unsigned long int pos=UINT_MAX);
        void ordenar();
        void ordenarRev();
        unsigned int busquedaBin(T dato);
        
        unsigned int tam();
        potenciador(unsigned long int tama);
        void aumenta();
        void disminuye();
    private:
        unsigned long int _tamal, _tamaf;
        T *_v;
};
//////////////////////////CONSTRUCTORES//////////////////////////
template<typename T>
VDinamico<T>::VDinamico()://constructor por defecto
       _tamal(0),
       _tamaf(1)
{
    _v=new T[_tamaf];
}
template<typename T>
VDinamico<T>::~VDinamico(){
    delete []_v;
}

template<typename T>
VDinamico<T>::VDinamico(unsigned long int tam)://constructor dando un tamaño lógico
    _tamal(0),
    _tamaf(potenciador(tam))
{
    _v=new T[_tamaf];
}
template<typename T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen)://constructor copia
    _tamal(origen._tamal),
    _tamaf(origen._tamaf)
{
    _v=new T[_tamaf];
    for(int i=0;i<origen._tamal;i++){
        _v[i]=origen._v[i];
    }
}
template<typename T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen, unsigned int inicio, unsigned int num)://constructor copia parcial
    _tamal(num),
    _tamaf(potenciador(num))
{
    _v=new T[_tamaf];
    for(int i=0;i<_tamal;i++){
        _v[i-inicio]=origen._v[i];
    }
}

//////////////////////OPERADORES/////////////////////
template<typename T>
VDinamico<T>& VDinamico<T>::operator =(const VDinamico<T>& origen){
    if(_v){
        delete[]_v;
        _tamal=origen._tamal;
        _v=new T[_tamaf=origen._tamaf];
        for(int i=0;i<_tamal;i++){
            _v[i]=origen._v[i];
        }
    }
    return *this;
}
template<typename T>
T& VDinamico<T>::operator [](unsigned long int pos){
    return _v[pos];
}
/////////////////////FUNCIONES/////////////////////////
template<typename T>
int VDinamico<T>::potenciador(unsigned long int tama){//con esta función se aumenta el tamaño físico a la potencia de dos inmediatamente superior
    int tnuevo;//tamaño nuevo
    int potencia=0;
    do{
        tnuevo=2^potencia;
        potencia++;
    }while(tnuevo<tama);
    return tnuevo;
}
template<typename T>
void VDinamico<T>::insertar(const T& dato, unsigned long int pos){
    if(pos=UINT_MAX){//inserción en última posición
        if(_tamal==_tamaf){
            aumenta();
        }
        _v[_tamal]=dato;
    }else{//inserción entre medias
        if(pos>_tamal){
            throw std::string("Posicion mayor que tamaño logico");
        }
        if(_tamal==_tamaf){
            aumenta();
        }
        for(int i=_tamal-1;i>=pos;i--){
            _v[i+1]=_v[i];//se desplazaz posición de cada elemento
        }
        _v[pos]=dato;
    }
   _tamal++;   
}
template<typename T>
void VDinamico<T>::ordenar(){//algoritmo de ordenación por selección
    T aux;
    int min;
    for(int i=0;i<_tamal;i++){
        min=i;
        for(int j=i+1;j<_tamal;j++){
            if(_v[j]<_v[min]){
                min=j;
            } 
        }
        aux=_v[i];
        _v[i]=_v[min];
        _v[min]=aux;
    }
}
template<typename T>
void VDinamico<T>::ordenarRev(){//algoritmo de ordenación por selección
    T aux;
    int max;
    for(int i=0;i<_tamal;i++){
        max=i;
        for(int j=i+1;j<_tamal;j++){
            if(_v[j]>_v[max]){
                max=j;
            }
        }
        aux=_v[i];
        _v[i]=_v[max];
        _v[max]=aux;
    }
}
template<typename T>
T VDinamico<T>::borrar(unsigned long int pos){
    T borrado;
    if(_tamal==0||pos>=_tamal){//en caso de posición fuera de rando o vector no tenga elementos
        throw string("No se puede borrar");
    }
    if(pos==UINT_MAX){//borrado última posición
        borrado=_v[_tamal-1];
    }else{
        borrado=_v[pos];//borrado entre medias
        for(int i=pos;i<_tamal-1;i++){
            _v[i]=_v[i+1];
        }
    }
    if(_tamal*3<_tamaf){//disminución de tamaño físico
        disminuye();
    }
    _tamal--;
    return borrado;
}
template<typename T>
unsigned int VDinamico<T>::busquedaBin(T dato){
    int inf=0;
    int sup=_tamal-1;
    int curIn;
    while(inf<=sup){
        curIn=(inf+sup)/2;
        if(_v[curIn]==dato){
            return curIn;
        }else{
            if(_v[curIn]<dato){
                inf=curIn+1;
            }else{
                sup=curIn-1;
            }
        }
    }
    return -1;
}
template<typename T>
void VDinamico<T>::disminuye(){//función que reduce el tamaf
    _tamaf=_tamaf/2;
    T *vaux=new T[_tamaf];
    for(int i=0;i<_tamal;i++){
        vaux[i]=_v[i];
    }
    delete []_v;
    _v=vaux;
}
template<typename T>
void VDinamico<T>::aumenta(){
    _tamaf=_tamaf*2;
    T *vaux;
    vaux=new T[_tamaf];
    for(int i=0;i<_tamal;i++){
        vaux[i]=_v[i];
    }
    delete []_v;
    _v=vaux;
}
template<typename T>
unsigned int VDinamico<T>::tam(){
    return _tamal;
}




#endif /* VDINAMICO_H */

