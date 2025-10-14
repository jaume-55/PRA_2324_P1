#ifndef LIST_H
#define LIST_H

#include <stdexcept> // Para std::out_of_range

template <typename T>
class List {
public:
    virtual void insert(int pos, T e) = 0;
    virtual void append(T e) = 0;
    virtual void prepend(T e) = 0;
    virtual T remove(int pos) = 0;
    virtual T get(int pos) const = 0;
    virtual int search(T e) const = 0;
    virtual bool empty() const = 0;
    virtual int size() const = 0;

    // Destructor virtual para asegurar destrucción correcta de objetos derivados
    virtual ~List() {}
};

#endif
