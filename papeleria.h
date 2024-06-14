#ifndef PAPELERIA_H
#define PAPELERIA_H

#include <iostream>
#include <string>
#include "producto.h"  
using namespace std;

// Clase Inventario
class Inventario {
private:
    Producto* productos[100]; 
    int count; 

public:
    // Constructor
    
    Inventario() : count(0) {}
     ~Inventario() {
        for (int i = 0; i < count; ++i) {
            delete productos[i];  
        }
    }

    // Métodos

    void agregarProducto(Producto* producto);

    void eliminarProducto(int id);

    void mostrarInventario(void);
};



void Inventario::agregarProducto(Producto* producto) {
    if (count < 100) {
        productos[count++] = producto;
        cout << "Producto agregado" << endl;
        producto->mostrarInformacion();
    } else {
        cout << "Inventario lleno" << endl; 
    }
}


void Inventario::eliminarProducto(int id) {
    for (int i = 0; i < count; ++i) {
        if (productos[i]->getId() == id) {
            delete productos[i];  // Liberar la memoria del producto eliminado
            for (int j = i; j < count - 1; ++j) {
                productos[j] = productos[j + 1];
            }
            productos[count - 1] = nullptr;  // Asegurarse de que el último lugar esté vacío
            --count;
            cout << "Producto con ID " << id << " eliminado del inventario." << endl;
            return;
        }
    }
    cout << "Producto con ID " << id << " no encontrado en el inventario." << endl;
}


void Inventario::mostrarInventario(void) {
    if (count == 0) {
        cout << "El inventario está vacio." << endl;
    } else {
        for (int i = 0; i < count; ++i) {
            productos[i]->mostrarInformacion();
        }
    }
}

// Clase Papeleria
class Papeleria {
private:
    string nombre; 
    int telefono; 
    string ubicacion; 
    Inventario inventario; 

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
    void crearInventario();
    void mostrarInventario() {
        inventario.mostrarInventario();
    }

    Inventario& getInventario() { return inventario; }
};

void Papeleria::crearInventario() {
    int numProductos;
    cout << "¿Cuantos productos diferentes quieres agregar?: ";
    cin >> numProductos;
    cin.ignore();  // Ignorar el carácter de nueva línea residual

    for (int i = 0; i < numProductos; ++i) {
        int id;
        float precio;
        string categoria, marca, tipo;

        cout << "Producto " << i + 1 << ":" << endl;

        cout << "ID: ";
        cin >> id;
        cin.ignore();  // Ignorar el carácter de nueva línea

        cout << "Categoria (Pluma/Libreta): ";
        getline(cin, categoria);

        cout << "Precio: ";
        cin >> precio;
        cin.ignore();

        cout << "Marca (BIC/Scribe): ";
        getline(cin, marca);

        if (categoria == "Pluma") {
            string color;
            cout << "Color: ";
            getline(cin, color);

            cout << "Tipo de punta (Fina/Gruesa): ";
            getline(cin, tipo);

            getInventario().agregarProducto(new Pluma(precio, id, categoria, marca, color, tipo));
        } else if (categoria == "Libreta") {
            int num_hojas;
            cout << "Tipo de cuaderno (Cuadro grande/Cuadro chico/Raya): ";
            getline(cin, tipo);

            cout << "Numero de hojas: ";
            cin >> num_hojas;
            cin.ignore();

            getInventario().agregarProducto(new Libreta(precio, id, categoria, marca, num_hojas, tipo));
        } else {
            cout << "Categoria no valida. El producto no se agregara." << endl;
        }
    }
    cout << "Inventario actualizado." << endl;
}

#endif
