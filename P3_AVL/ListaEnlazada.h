/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEnlazada.h
 * Author: Juan Bautista
 *
 * Created on 20 de octubre de 2020, 16:38
 */

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <string>

template<typename T>
class ListaEnlazada{
    template<class U>
    class Nodo{
        public:
            U dato;
            Nodo* sig;
            Nodo(const U& aDato, Nodo* aSig=0):
            dato(aDato),sig(aSig)
            {
            }
            ~Nodo(){}
    };
    public:
        template<typename V>
        class Iterador{
            public:
                Nodo<V> *nodo;
                Iterador(Nodo<V> *aNodo):nodo(aNodo){}
                ~Iterador(){}
                bool fin(){return(nodo==0);}
                void siguiente(){nodo= nodo->sig;}
                bool haySiguiente(){return nodo!=0;}
                V &dato(){return nodo->dato;}
        };
    ListaEnlazada();
    ListaEnlazada(const ListaEnlazada<T>& origen);
    ~ListaEnlazada();
    
    Iterador<T> iterador() const;
    ListaEnlazada<T> &operator=(ListaEnlazada<T>& list);
    void insertaInicio(T& dato);
    void insertaFinal(T& dato);
    void inserta(Iterador<T> &i,T& dato);
    void borraInicio();
    void borraFinal();
    void borrar(Iterador<T> &i);
    bool insertaOrdenado(T& dato);
    void borrarRepetidos();
    
    T &inicio();
    T &final();
    int tama(){return _tam;}
    private:
        Nodo<T> *_cabecera,*_cola;
        unsigned long int _tam;
};
template<typename T>
ListaEnlazada<T>::ListaEnlazada():
_cabecera(0),_cola(0),_tam(0)
{
}
template<typename T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T>& origen){
    Nodo<T> *i=origen._cabecera;
    _tam=origen._tam;
    _cabecera=_cola=0;
    while(i){
        Nodo<T> *nuevo =new Nodo<T>(i->dato,0);
        if(_cola!=0){
            _cola->sig=nuevo;
        }
        if(_cabecera==0){
            _cabecera=nuevo;
        }
        _cola=nuevo;
        i=i->sig;
    }
}
template<typename T>
ListaEnlazada<T>::~ListaEnlazada(){
    if(_cabecera){
        Nodo<T> *elimina=_cabecera;
        while(elimina){
            _cabecera=_cabecera->sig;
            delete elimina;
            elimina=_cabecera;
        }
        _cola=0;
    }
}
template<typename T>
ListaEnlazada<T>::Iterador<T> ListaEnlazada<T>::iterador() const{
    return Iterador<T>(_cabecera);
}
template<typename T>
ListaEnlazada<T> &ListaEnlazada<T>::operator =(ListaEnlazada<T>& list){
    if(_cabecera){//borramos todos los nodos (mismo codigo que el destructor)
        Nodo<T> *elimina=_cabecera;
        while(elimina){
            _cabecera=_cabecera->sig;
            delete elimina;
            elimina=_cabecera;
        }
        _cola=0;
    }
    Nodo<T> *i=list._cabecera;//copiamos la lista(mismo codigo que el construcor copia)
    _cabecera=_cola=0;
    _tam=list._tam;
    while(i){
        Nodo<T> *nuevo=new Nodo<T>(i->dato,0);
        if(_cola!=0){
            _cola->sig=nuevo;
        }
        if(_cabecera==0){
            _cabecera=nuevo;
        }
            _cola=nuevo;
            i=i->sig;
        
    }
    return *this;
}
template<typename T>
void ListaEnlazada<T>::insertaInicio(T& dato){
    Nodo<T> *nuevo=new Nodo<T>(dato,_cabecera);
    if(_cola==0){
        _cola=nuevo;
    }
    _cabecera=nuevo;
    _tam++;
}
template<typename T>
void ListaEnlazada<T>::insertaFinal(T& dato){
    Nodo<T> *nuevo=new Nodo<T>(dato,0);
    if(_cola!=0){
        _cola->sig=nuevo;
    }
    if(_cabecera==0){
        _cabecera=nuevo;
        
    }
    _cola=nuevo;
    _tam++;
}
template<typename T>
void ListaEnlazada<T>::inserta(Iterador<T>& i, T& dato){
    if(!i.fin()){
        if(i.nodo==_cabecera){
            insertaInicio(dato);
        }else if(i.nodo==_cola){
            insertaFinal(dato);
        }else{
           Nodo<T> *anterior=0;
           anterior=_cabecera;
           while(anterior->sig!=i.nodo){
               anterior=anterior->sig;
           }
           Nodo<T> *nuevo =new Nodo<T>(dato,i.nodo);
           anterior->sig=nuevo;
           tama++;
        }
    }
}
template<typename T>
void ListaEnlazada<T>::borraInicio(){
    Nodo<T> *borrado=_cabecera;
    _cabecera=_cabecera->sig;
    delete borrado;
    if(_cabecera==0){
       _cola=0;
    }
    _tam--;
}
template<typename T>
void ListaEnlazada<T>::borraFinal(){
    Nodo<T> *anterior=0;
    if(_cabecera!=_cola){
        anterior=_cabecera;
        while(anterior->sig!=_cola){
            anterior=anterior->sig;
        }
    }
    delete _cola;
    _cola=anterior;
    if(anterior !=0){
       anterior->sig=0;
    }else{
       _cabecera=0;
    }
    _tam--;
      
}

template<typename T>
void ListaEnlazada<T>::borrar(Iterador<T>& i){
    Nodo<T>* p=i.nodo;
  if(!i.fin()){  
    if(i.nodo==_cola){
        borraFinal();
    }else if(i.nodo==_cabecera){
        borraInicio();
    }else{
        Nodo<T> *anterior =0;
        if(_cabecera!=_cola){
            anterior=_cabecera;
            while(anterior->sig != p){
                 anterior=anterior->sig;
            }
        }
        anterior->sig=p->sig;
        _tam--;
        }
    }
  
 }

template<typename T>
T &ListaEnlazada<T>::inicio(){
    if(!_cabecera){
       throw std::string("No hay cabecera");
    }
    return _cabecera->dato;
}
template<typename T>
T &ListaEnlazada<T>::final(){
    if(!_cola){
        throw std::string("No hay cola");
    }
    return _cola->dato;
}
template<typename T>
bool ListaEnlazada<T>::insertaOrdenado(T& dato){
    //comprobacion de que esta ordenada
    if(_cabecera!=0){//para evitar casos en la que esta vacía
    Nodo<T> *aux=_cabecera;
        while(aux->sig!=0){//recorremos toda la lista hasta elmomento que el el siguiente es menor que el anterior
              if(aux->dato >aux->sig->dato){
                  return false;
               }
               aux=aux->sig;
           }
    }
    Nodo<T> *nuevo=new Nodo<T>(dato,_cabecera);
    if(_cabecera==0){//en caso de primera inserción
        _cabecera=nuevo;
    }else if(dato < _cabecera->dato){//en caso de ser menor que la cabecera
        nuevo->sig=_cabecera;
        _cabecera=nuevo;
        _tam++;
        
    }else{//inserción ordenada
        Nodo<T> *actual=_cabecera;
        
        while(actual->sig!=0 && actual->sig->dato < dato ){//avanzamos mientras sea menor que dato
            actual=actual->sig;
            
        }
        if(dato!=actual->dato){
        nuevo->sig=actual->sig;
        actual->sig=nuevo;
        
        _tam++;
        }
    }   
    return true;
}
template<typename T>
void ListaEnlazada<T>::borrarRepetidos(){
    Nodo<T> *aux=_cabecera;
    while(aux->sig!=0){//recorremos toda la lista y en caso de ser igual el dato adelantamos punteros
        if(aux->dato==aux->sig->dato){
            aux->sig=aux->sig->sig;
            _tam--;
        }else{
            aux=aux->sig;
        }
    }
}


#endif /* LISTAENLAZADA_H */

