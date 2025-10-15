#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                    // Puntero al array dinámico
    int max;                   // Tamaño actual del array
    int n;                     // Número de elementos almacenados
    static const int MINSIZE = 2;  // Tamaño mínimo del array

    // Redimensiona el array al nuevo tamaño indicado
    void resize(int new_size) {
        if (new_size < MINSIZE) new_size = MINSIZE;

        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i)
            new_arr[i] = arr[i];

        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    // Destructor
    ~ListArray() override {
        delete[] arr;
    }

    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida!");

        if (n == max)
            resize(max * 2);  // Duplica capacidad si está lleno

        // Desplazar los elementos a la derecha
        for (int i = n; i > pos; --i)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        ++n;
    }

    // Añade el elemento al final
    void append(T e) override {
        insert(n, e);
    }

    // Añade el elemento al principio
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento en la posición pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida!");

        T elem = arr[pos];

        // Desplazar los elementos a la izquierda
        for (int i = pos; i < n - 1; ++i)
            arr[i] = arr[i + 1];

        --n;

        // Reducir capacidad si está "demasiado vacío"
        if (n < max / 4 && max / 2 >= MINSIZE)
            resize(max / 2);

        return elem;
    }

    // Devuelve el elemento en la posición pos
    T get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida!");
        return arr[pos];
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida!");
        return arr[pos];
    }

    // Busca la primera ocurrencia del elemento e
    int search(T e) const override {
        for (int i = 0; i < n; ++i)
            if (arr[i] == e)
                return i;
        return -1;
    }

    // Indica si la lista está vacía
    bool empty() const override {
        return n == 0;
    }

    // Devuelve el número de elementos
    int size() const override {
        return n;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "List => [";
        if (list.n > 0) out << "\n";
        for (int i = 0; i < list.n; ++i)
            out << "  " << list.arr[i] << (i < list.n - 1 ? "\n" : "");
        if (list.n > 0) out << "\n";
        out << "]";
        return out;
    }
};

#endif

