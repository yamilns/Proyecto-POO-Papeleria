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

    Producto(float precio, int id, string categoria, string marca) 
        : precio(precio), id(id), categoria(categoria), marca(marca) {}

    
    virtual ~Producto() {}

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
    float calcularPrecioIva() { return precio * 1.16; } // Aumenta el precio en un 16% para simular el IVA

    virtual void mostrarInformacion() {
        cout << "Producto ID: " << getId()
             << "\nMarca: " << getMarca()
             << "\nCategoria: " << getCategoria()
             << "\nPrecio: " << getPrecio() << endl;
    }
};



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

// Sobrescritura del método mostrarInformacion para incluir detalles específicos de la pluma
    void mostrarInformacion (void) override;
    
};

void Pluma::mostrarInformacion (void) {
    
    Producto::mostrarInformacion();
    
    cout << "Producto ID: " << getId()
             << "\nMarca: " << getMarca()
             << "\nCategoria: " << getCategoria()
             << "\nPrecio: " << getPrecio()
             << "\nColor: " << color
             << "\nTipo de Punta: " << tipo_punta << endl;
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

    // Sobrescritura del método mostrarInformacion para incluir detalles específicos de la libreta
    void mostrarInformacion(void) override;
};


void Libreta::mostrarInformacion(void) {
    
    Producto::mostrarInformacion();
    
    cout << "Producto ID: " << getId()
             << "\nMarca: " << getMarca()
             << "\nCategoria: " << getCategoria()
             << "\nPrecio: " << getPrecio()
             << "\nNumero de Hojas: " << num_hojas
             << "\nTipo: " << tipo << endl;
    }

#endif 
