/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MallaRegular.h
 * Author: Juan Bautista
 *
 * Created on 6 de enero de 2021, 21:28
 */

#ifndef MALLAREGULAR_H
#define MALLAREGULAR_H
#include <list>
#include <vector>
template <typename T>
class MallaRegular{
   private:
        class Casilla{
            public:
                std::list<T> _puntos;
                Casilla():_puntos(){}
                ~Casilla(){}
                void insertar(const T &dato){_puntos.push_back(dato);}
                unsigned getTam(){return _puntos.size();}
                T* buscar(const T &dato){
                    typename std::list<T>::iterator it=_puntos.begin();
                    for(it;it!=_puntos.end();it++){
                        if(*it==dato){
                            return &(*it);
                        }
                        return 0;
                    }
                }
                bool borrar(const T &dato){
                    typename std::list<T>::iterator it=_puntos.begin();
                    for(it;it!=_puntos.end();it++){
                        if(*it==dato){
                           _puntos.erase(it);
                           return true;
                        }
                    }
                    return false;
                    
                }
                typename std::list<T>::iterator begin(){return _puntos.begin();}
                typename std::list<T>::iterator end(){return _puntos.end();}
                
                
            
        };
        float _aXMin,_aYMin,_aXMax,_aYMax,_tamaCasillaX,_tamaCasillaY;
        unsigned _nDivX,_nDivY;
        std::vector<std::vector<Casilla>>_mr;
        Casilla* obtenerCasilla(float x,float y){
            int i=(x-_aXMin)/_tamaCasillaX;
            int j=(y- _aYMin)/_tamaCasillaY;
            return &_mr[i][j];
            
        }
   public:
       MallaRegular();
       MallaRegular(float aXmin,float aYMin,float aXMax,float aYMax,int nDivX,int nDivY);
       ~MallaRegular(){}
       
       void insertar(float x,float y,const T& dato);
       bool borrar(float x,float y,const T& dato);

       T* buscar(float x,float y,const T& dato);
       std::vector<T> buscarRango(float rxmin,float rymin,float rxmax,float rymax);
       unsigned maxElementosPorCelda();
       unsigned mediaElementosPorCelda();
       unsigned numElementos();
       unsigned numeroCeldas();
    
};

template <typename T>
MallaRegular<T>::MallaRegular(float aXMin, float aYMin, float aXMax, float aYMax, int nDivX, int nDivY):
    _aXMin(aXMin),
    _aYMin(aYMin),
    _aXMax(aXMax),
    _aYMax(aYMax),
    _nDivX(nDivX),
    _nDivY(nDivY)
        
{
    _tamaCasillaX=((_aXMax-_aXMin)/_nDivX);
    _tamaCasillaY=((_aYMax-_aYMin)/_nDivY);
    _mr.insert(_mr.begin(),nDivX,std::vector<Casilla>(nDivY));
}
template <typename T>
void MallaRegular<T>::insertar(float x, float y, const T& dato){
    Casilla *c=obtenerCasilla(x,y);
    c->insertar(dato);
}
template <typename T>
bool MallaRegular<T>::borrar(float x, float y, const T& dato){
    Casilla *c=obtenerCasilla(x,y);
    c->borrar(dato);
}
template <typename T>
T* MallaRegular<T>::buscar(float x, float y, const T& dato){
    Casilla *c=obtenerCasilla(x,y);
    return &(c->buscar(dato));
}
template <typename T>
unsigned MallaRegular<T>::maxElementosPorCelda(){
    unsigned maxElem=0;
    for(float i=_aXMin;i<=_aXMax;i=i+_tamaCasillaX){
        for(float j=_aYMin;j<=_aYMax;j=j+_tamaCasillaY){
            Casilla *c=obtenerCasilla(i,j);
            if(c->getTam()>maxElem){
                maxElem=c->getTam();
            }
        }
    }
    return maxElem;
}
template<typename T>
unsigned MallaRegular<T>::numElementos(){
    unsigned numElem=0;
    for(float i=_aXMin;i<=_aXMax;i=i+_tamaCasillaX){
        for(float j=_aYMin;j<=_aYMax;j=j+_tamaCasillaY){
            Casilla *c=obtenerCasilla(i,j);
            numElem=numElem+c->getTam();
        }
    }
    return numElem;
}
template<typename T>
unsigned MallaRegular<T>::numeroCeldas(){
    return _nDivX*_nDivY;
}
template <typename T>
unsigned MallaRegular<T>::mediaElementosPorCelda(){
    return (float)(numElementos()/(_nDivX*_nDivY));
}

template <typename T>
std::vector<T> MallaRegular<T>::buscarRango(float rxmin, float rymin, float rxmax, float rymax){
    std::vector<T> v;
    for(float i=rxmin;i<=rxmax;i=i+_tamaCasillaX){
       for(float j=rymin;j<=rymax;j=j+_tamaCasillaY){
           Casilla *c=obtenerCasilla(i,j);
           typename std::list<T>::iterator it=c->_puntos.begin();
           for(it;it!=c->_puntos.end();it++){
               if((*it).getLatitud()>rxmin && (*it).getLongitud()>rymin){
                    v.push_back(*it);
               }
            }
       }
    }
    return v;
}

#endif /* MALLAREGULAR_H */

