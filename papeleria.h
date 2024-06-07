#ifndef PAPELERIA_H
#define PAPELERIA_H

#include <iostream>
#include <string>
#include "producto.h"  // Necesito incluir esto porque usaré la clase Producto en Inventario
using namespace std;

// Clase Inventario
class Inventario {
private:
    Producto* productos[100]; // Utilizo un arreglo de punteros a Producto para almacenar hasta 100 productos
    int count; // Lleva la cuenta del número de productos en el inventario

public:
    // Constructor
    // Inicializo el inventario con count a 0, indicando que está vacío al principio
    Inventario() : count(0) {}

    // Métodos

    // Método para agregar un producto al inventario
    void agregarProducto(Producto* producto);

    // Método para eliminar un producto del inventario por ID
    void eliminarProducto(int id);

    // Método para mostrar todos los productos en el inventario
    void mostrarInventario(void);
};

// Defino las funciones miembro de Inventario

// Método para agregar un producto
// Verifico si hay espacio en el arreglo y, si lo hay, agrego el producto y aumento el contador
void Inventario::agregarProducto(Producto* producto) {
    if (count < 100) {
        productos[count++] = producto;
    } else {
        cout << "Inventario lleno" << endl; // Informo que el inventario está lleno
    }
}

// Método para eliminar un producto por ID
// Busco el producto por su ID, y si lo encuentro, muevo todos los productos subsiguientes una posición hacia atrás
void Inventario::eliminarProducto(int id) {
    for (int i = 0; i < count; ++i) {
        if (productos[i]->getId() == id) { // Encuentro el producto por ID
            for (int j = i; j < count - 1; ++j) { // Muevo los productos subsiguientes hacia atrás
                productos[j] = productos[j + 1];
            }
            --count; // Reduzco el contador del inventario
            break;
        }
    }
}

// Método para mostrar todos los productos en el inventario
// Recorro el arreglo de productos y llamo al método mostrarInformacion() de cada producto
void Inventario::mostrarInventario(void) {
    for (int i = 0; i < count; ++i) {
        productos[i]->mostrarInformacion();  // Uso -> para acceder al método del objeto al que apunta el puntero
    }
}

// Clase Papeleria
class Papeleria {
private:
    string nombre; // Nombre de la papelería
    int telefono; // Teléfono de contacto de la papelería
    string ubicacion; // Dirección de la papelería
    Inventario inventario;  // El inventario de la papelería

public:
    // Constructores
    // Constructor por defecto que inicializa los atributos con valores vacíos o cero
    Papeleria() : nombre(""), telefono(0), ubicacion("") {}
    
    // Constructor que inicializa la papelería con nombre, teléfono y ubicación específicos
    Papeleria(string nombre, int telefono, string ubicacion)
    : nombre(nombre), telefono(telefono), ubicacion(ubicacion) {}

    // Getters
    // Obtengo el nombre de la papelería
    string getNombre() { return nombre; }
    
    // Obtengo el teléfono de la papelería
    int getTelefono() { return telefono; }
    
    // Obtengo la ubicación de la papelería
    string getUbicacion() { return ubicacion; }

    // Setters
    // Establezco el nombre de la papelería
    void setNombre(string nom) { nombre = nom; }
    
    // Establezco el teléfono de la papelería
    void setTelefono(int telef) { telefono = telef; }
    
    // Establezco la ubicación de la papelería
    void setUbicacion(string ubi) { ubicacion = ubi; }

    // Métodos
    // Método para mostrar el inventario de la papelería
    // Llama al método mostrarInventario() del objeto inventario
    void mostrarInventario() {
        inventario.mostrarInventario();
    }

    // Método para obtener una referencia al inventario
    // Esto me permite acceder al inventario desde fuera de la clase Papeleria
    Inventario& getInventario() { return inventario; }
};

#endif 
