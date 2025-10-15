#ifndef LIST_H
#define LIST_H

#include <stdexcept>  // para std::out_of_range

// Clase genérica e interfaz abstracta pura
template <typename T>
class List {
public:
    // Destructor virtual para asegurar destrucción correcta en clases derivadas
    virtual ~List() {}

    // Métodos virtuales puros
    virtual void insert(int pos, T e) = 0;
    virtual void append(T e) = 0;
    virtual void prepend(T e) = 0;
    virtual T remove(int pos) = 0;
    virtual T get(int pos) const = 0;
    virtual int search(T e) const = 0;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
};

#endif

