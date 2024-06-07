#ifndef PAPELERIA_H
#define PAPELERIA_H

#include <iostream>
#include <string>
#include "producto.h"

class Inventario {
private:
    Producto* productos[100]; // Arreglo de punteros a productos                
    int count; // Número de productos en el inventario

public:
    // Constructor
    Inventario() : count(0) {}  // Se inicializa el inventario y la variable count a 0

    // Métodos
    void agregarProducto(Producto* producto); 

    void eliminarProducto(int id) 

    void mostrarInventario(void) 
};
void Inventario::agregarProducto(Producto* producto){
        if (count < 100) {
            productos[count++] = producto;
        } else {
            cout << "Inventario lleno" << endl;
        }
    }

void Inventario::eliminarProducto(int id){
        for (int i = 0; i < count; ++i) {
            if (productos[i]->getId() == id) {
                for (int j = i; j < count - 1; ++j) {
                    productos[j] = productos[j + 1];
                }
                --count;
                break;
            }
        }
    }

void Inventario::mostrarInventario(void){
        for (int i = 0; i < count; ++i) {
            productos[i]->mostrarInformacion();  // -> es para acceder al método de producto mostrar
        }
    }

class Papeleria {
private:
    string nombre;
    int telefono;
    string ubicacion;
    Inventario inventario;  // Se crea un objeto de tipo Inventario

public:
    // Constructores
    Papeleria() : nombre(""), telefono(0), ubicacion("") {}
    Papeleria(string nombre, int telefono, string ubicacion) 
    : nombre(nombre), telefono(telefono), ubicacion(ubicacion) {}

    // Getters
    string getNombre() { return nombre; }
    int getTelefono() { return telefono; }
    string getUbicacion() { return ubicacion; }

    // Setters
    void setNombre(string nom) { nombre = nom; }
    void setTelefono(int telef) { telefono = telef; }
    void setUbicacion(string ubi) { ubicacion = ubi; }

    // Métodos
    void mostrarInventario() {
        inventario.mostrarInventario();
    }

    Inventario& getInventario() { return inventario; }  // Para acceder al inventario desde el exterior
};

#endif
