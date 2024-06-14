#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

// Clase abstracta Producto
class Producto {
protected:
    float precio;
    int id;
    string categoria;
    string marca;

public:
    // Constructores
    Producto() : precio(0.0), id(0), categoria(""), marca("") {}
    Producto(float precio, int id, string categoria, string marca)
        : precio(precio), id(id), categoria(categoria), marca(marca) {}

    // Destructor virtual
    virtual ~Producto() {}

    virtual void mostrarInformacion() = 0; 

    // Getters
    float getPrecio() { return precio; }
    int getId() { return id; }
    string getCategoria() { return categoria; }
    string getMarca() { return marca; }

    // Setters
    void setPrecio(float prec) { precio = prec; }
    void setId(int idd) { id = idd; }
    void setCategoria(string cate) { categoria = cate; }
    void setMarca(string marc) { marca = marc; }

    // Método para calcular el precio con IVA
    float calcularPrecioIva() { return precio * 1.16; }
};

// Clase Pluma, derivada de Producto
class Pluma : public Producto {
private:
    string color;
    string tipo_punta;

public:
    // Constructores
    Pluma() : Producto(), color(""), tipo_punta("") {}
    Pluma(float precio, int id, string categoria, string marca, string color, string tipo_punta)
        : Producto(precio, id, categoria, marca), color(color), tipo_punta(tipo_punta) {}

    // Sobrescritura del método mostrarInformacion para incluir detalles específicos de la pluma
    void mostrarInformacion() override {
        cout << "Producto ID: " << getId()
             << "\nMarca: " << getMarca()
             << "\nCategoria: " << getCategoria()
             << "\nPrecio: " << getPrecio()
             << "\nColor: " << color
             << "\nTipo de Punta: " << tipo_punta << endl;
    }
};

// Clase Libreta, derivada de Producto
class Libreta : public Producto {
private:
    int num_hojas;
    string tipo;

public:
    // Constructores
    Libreta() : Producto(), num_hojas(0), tipo("") {}
    Libreta(float precio, int id, string categoria, string marca, int num_hojas, string tipo)
        : Producto(precio, id, categoria, marca), num_hojas(num_hojas), tipo(tipo) {}

    // Sobrescritura del método mostrarInformacion para incluir detalles específicos de la libreta
    void mostrarInformacion() override {
        cout << "Producto ID: " << getId()
             << "\nMarca: " << getMarca()
             << "\nCategoria: " << getCategoria()
             << "\nPrecio: " << getPrecio()
             << "\nNumero de Hojas: " << num_hojas
             << "\nTipo: " << tipo << endl;
    }
};

#endif 
