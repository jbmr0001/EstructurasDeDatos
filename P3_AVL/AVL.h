/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: Juan Bautista
 *
 * Created on 4 de noviembre de 2020, 17:38
 */

#ifndef AVL_H
#define AVL_H
#include <iostream>
template<typename U>
class Nodo{
    public:
        Nodo<U> *izq, *der;
        U dato;
        char bal;
        
        Nodo(U &ele):
            izq(0),
            der(0),
            dato(ele),
            bal(0)
        {
        }
        Nodo(const Nodo<U> &orig):
            izq(0),
            der(0),
            dato(orig.dato),
            bal(orig.bal)
        {
        }
        ~Nodo(){}
};

template<typename T>
class AVL{
    private:
        Nodo<T> *raiz;
        int inserta(Nodo<T>* &c,T &dato);
        void rotDecha(Nodo<T>*& p);
        void rotIzqda(Nodo<T>*& p);
        
        void inorden(Nodo<T> *p,int nivel);
        unsigned int alturaArbolAVL(Nodo<T>* nodo,int nivel,int& nNiveles);
        unsigned int numElementosAVL(Nodo<T>* nodo);
        Nodo<T> *buscaClave(const T &dato,Nodo<T> *p);
        void copiar (Nodo<T>* &nuevo,Nodo<T>* viejo);
        void destruir(Nodo<T>* nodo);
    public:
        AVL();
        AVL(const AVL<T>& orig);
        ~AVL();
        
        void reccoreInorden();
        bool insertar(T &dato);
        unsigned int altura();
        unsigned int numElementos();
        AVL<T>& operator=(AVL<T>& orig);
        bool buscaR(const T &dato,T &result);
        bool buscaIt(const T &dato,T &result);
        
};
template<typename T>
AVL<T>::AVL(){
    raiz=0;
}
template<typename T>
AVL<T>::AVL(const AVL<T>& orig){
    copiar(raiz,orig.raiz);
}
template<typename T>
AVL<T>& AVL<T>::operator =(AVL<T>& orig){
    copiar(raiz,orig.raiz);
    return *this;
}
template<typename T>
void AVL<T>::copiar(Nodo<T>*& nuevo, Nodo<T>* viejo){
    if(viejo){
        nuevo=new Nodo<T>(*viejo);
        copiar(nuevo->izq,viejo->izq);
        copiar(nuevo->der,viejo->der);
    }else{
        nuevo=0;
    }
}
template<typename T>
AVL<T>::~AVL(){
    destruir(raiz);
}
template<typename T>
void AVL<T>::destruir(Nodo<T>* nodo){
    if(nodo){
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
        nodo=0;
    }
}
template<typename T>
Nodo<T> *AVL<T>::buscaClave(const T& dato, Nodo<T>* p){
    if(!p){
        return 0;
    }else if(dato<p->dato){
        return buscaClave(dato,p->izq);
    }else if(dato>p->dato){
        return buscaClave(dato,p->der);
    }else{
        return p;
    }
}
template<typename T>
bool AVL<T>::buscaR(const T& dato, T& result){
    Nodo<T> *p=buscaClave(dato,raiz);
    if(p){
        result=p->dato;
        return true;
    }
    return false;
}
template<typename T>
void AVL<T>::rotDecha(Nodo<T>*& p){
    Nodo<T> *q = p, *l;
    p = l = q->izq;
    q->izq = l->der;
    l->der = q;
    q->bal--;
    if(l->bal > 0) q->bal -= l->bal;
    l->bal--;
    if(q->bal < 0) l->bal -= -q->bal;
}
template<typename T>
void AVL<T>::rotIzqda(Nodo<T>*& p){
    Nodo<T> *q = p, *r;
    p = r = q->der;
    q->der = r->izq;
    r->izq = q;
    q->bal++;
    if(r->bal < 0) q->bal +=-r->bal;
    r->bal++;
    if(q->bal > 0) r->bal += q->bal;
}
template<typename T>
void AVL<T>::reccoreInorden(){
    inorden(raiz,0);
}
template<typename T>
void AVL<T>::inorden(Nodo<T>* p, int nivel){
    if(p){
        inorden(p->izq,nivel+1);
        std::cout<<p->dato<<" NIVEL "<<nivel<<std::endl;
        inorden(p->der,nivel+1);
    }
}
template<typename T>
int AVL<T>::inserta(Nodo<T>*& c, T& dato){
    Nodo<T> *p=c;
    int deltaH=0;
    if(!p){
        p=new Nodo<T>(dato);
        c=p;
        deltaH=1;
    }else if(dato>p->dato){
        if(inserta(p->der,dato)){
            p->bal--;
            if(p->bal==-1){
                deltaH=1;
            }else if(p->bal==-2){
                if(p->der->bal==1){
                    rotDecha(p->der);
                    rotIzqda(c);
                }
            }
        }
    }else if(dato<p->dato){
        if(inserta(p->izq,dato)){
            p->bal++;
            if(p->bal==1){
                deltaH=1;
            }else if(p->bal==2){
                if(p->izq->bal==-1){
                    rotIzqda(p->izq);
                    rotDecha(c);
                }
            }
        }
    }
    return deltaH;
}
template<typename T>
bool AVL<T>::insertar(T& dato){
    return inserta(raiz,dato);
}
template<typename T>
unsigned int AVL<T>::alturaArbolAVL(Nodo<T>* nodo, int nivel, int& nNiveles){
    if(nodo){
        alturaArbolAVL(nodo->izq,nivel+1,nNiveles);
        if(nivel>nNiveles){
            nNiveles=nivel;
        }
        alturaArbolAVL(nodo->der,nivel+1,nNiveles);
    }
}
template<typename T>
unsigned int AVL<T>::altura(){
    int nNiveles=0;
    alturaArbolAVL(raiz,0,nNiveles);
    return nNiveles;
}
template<typename T>
unsigned int AVL<T>::numElementos(){
    return numElementosAVL(raiz);
}
template<typename T>
unsigned int AVL<T>::numElementosAVL(Nodo<T>* nodo){
    if(nodo){
        return numElementosAVL(nodo->izq)+numElementosAVL(nodo->der)+1;
    }else{
        return 0;
    }
}
template<typename T>
bool AVL<T>::buscaIt(const T& dato, T& result){
    Nodo<T> *nodo=raiz;
    while(nodo){
        if(dato<nodo->dato){
            nodo=nodo->izq;
        }else if(dato>nodo->dato){
            nodo=nodo->der;
        }else{
            result=nodo->dato;
            return true;
        }
    }
    return false;
}

#endif /* AVL_H */

