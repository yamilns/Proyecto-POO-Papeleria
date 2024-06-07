#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

class Producto {
private:
    float precio;
    int id;
    string categoria;
    string marca;

public:
    // Constructores
    Producto() : precio(0.0), id(0), categoria(""), marca("") {}
    Producto(float precio, int id, string categoria, string marca) : precio(precio), id(id), categoria(categoria), marca(marca) {}
    virtual ~Producto() {}  // Destructor virtual para permitir la eliminación adecuada de objetos derivados
    
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

    // Métodos adicionales
    void calcularPrecioIva() { precio *= 1.16; } // Ejemplo de cálculo con IVA 16%
 
    virtual void mostrarInformacion()=0;           // clase abstacta 
};

void Producto:: mostrarInformacion(){
        cout << "Producto ID: " << id << "\nMarca: " << marca 
             << "\nCategoria: " << categoria << "\nPrecio: " << precio << endl;
    }

class Pluma : public Producto {
private:
    string color;
    string tipo_punta;

public:
    // Constructores
    Pluma() : Producto(), color(""), tipo_punta("") {}
    Pluma(float precio, int id, string categoria, string marca, string color, string tipo_punta) 
        : Producto(precio, id, categoria, marca), color(color), tipo_punta(tipo_punta) {}

    // Getters
    string getColor() { return color; }
    string getTipoPunta() { return tipo_punta; }

    // Setters
    void setColor(string col) { color = col; }
    void setTipoPunta(string tipo_punt) { tipo_punta = tipo_punt; }

    // Sobrescritura de métodos
    void mostrarInformacion(void) override;
};
void Pluma::mostrarInformacion(void){
        Producto::mostrarInformacion();
        cout << "Color: " << color << "\nTipo de Punta: " << tipo_punta << endl;
    }

class Libreta : public Producto {
private:
    int num_hojas;
    string tipo;

public:
    // Constructores
    Libreta() : Producto(), num_hojas(0), tipo("") {}
    Libreta(float precio, int id, string categoria, string marca, int num_hojas, string tipo) 
        : Producto(precio, id, categoria, marca), num_hojas(num_hojas), tipo(tipo) {}

    // Getters
    int getNumHojas() { return num_hojas; }
    string getTipo() { return tipo; }

    // Setters
    void setNumHojas(int num_hoja) { num_hojas = num_hoja; }
    void setTipo(string tip) { tipo = tip; }

    // Sobrescritura de métodos
    void mostrarInformacion(void) override; 
};

void Libreta::mostrarInformacion(void){
        Producto::mostrarInformacion(); 
        cout << "Numero de Hojas: " << num_hojas << "\nTipo: " << tipo << endl;
    }


#endif
