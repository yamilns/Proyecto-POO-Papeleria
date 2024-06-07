#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>  
using namespace std;  

/// Clase base Producto, que es abstracta debido a la presencia de un método virtual puro.
class Producto {
private:
    float precio;      // Precio del producto
    int id;            // Identificador único del producto
    string categoria;  // Categoría del producto (e.g., "Oficina", "Escolar")
    string marca;      // Marca del producto (e.g., "BIC", "Scribe")

public:
    // Constructores
    // Constructor por defecto que inicializa todos los atributos a valores predeterminados
    Producto() : precio(0.0), id(0), categoria(""), marca("") {}

    // Constructor que permite inicializar todos los atributos con valores específicos
    Producto(float precio, int id, string categoria, string marca) 
        : precio(precio), id(id), categoria(categoria), marca(marca) {}

    // Destructor virtual para asegurar la correcta eliminación de objetos derivados
    virtual ~Producto() {}

    // Getters
    float getPrecio() { return precio; }     // Devuelve el precio del producto
    int getId() { return id; }               // Devuelve el ID del producto
    string getCategoria() { return categoria; } // Devuelve la categoría del producto
    string getMarca() { return marca; }      // Devuelve la marca del producto

    // Setters
    void setPrecio(float prec) { precio = prec; }    // Establece el precio del producto
    void setId(int idd) { id = idd; }                // Establece el ID del producto
    void setCategoria(string cate) { categoria = cate; } // Establece la categoría del producto
    void setMarca(string marc) { marca = marc; }     // Establece la marca del producto

    // Método para calcular el precio con IVA
    void calcularPrecioIva() { precio *= 1.16; } // Aumenta el precio en un 16% para simular el IVA

    // Método virtual puro para mostrar la información del producto
    // Esta declaración hace que la clase Producto sea abstracta y no se pueda instanciar directamente.
    virtual void mostrarInformacion() = 0;
};

// Implementación del método mostrarInformacion() para la clase Producto
// Aunque esta función no debería ser llamada directamente ya que Producto es abstracta,
// se proporciona una implementación base para ser utilizada por las clases derivadas.
void Producto::mostrarInformacion() {
    cout << "Producto ID: " << id << "\nMarca: " << marca 
         << "\nCategoria: " << categoria << "\nPrecio: " << precio << endl;
}

/// Clase derivada Pluma, que hereda de Producto.
class Pluma : public Producto {
private:
    string color;      // Color de la pluma (e.g., "Azul", "Negro")
    string tipo_punta; // Tipo de punta de la pluma (e.g., "Fina", "Gruesa")

public:
    // Constructores
    // Constructor por defecto que inicializa los atributos de Pluma y de Producto a valores predeterminados
    Pluma() : Producto(), color(""), tipo_punta("") {}

    // Constructor que inicializa todos los atributos de Producto y los atributos específicos de Pluma
    Pluma(float precio, int id, string categoria, string marca, string color, string tipo_punta) 
        : Producto(precio, id, categoria, marca), color(color), tipo_punta(tipo_punta) {}

    // Getters
    string getColor() { return color; }         // Devuelve el color de la pluma
    string getTipoPunta() { return tipo_punta; } // Devuelve el tipo de punta de la pluma

    // Setters
    void setColor(string col) { color = col; }         // Establece el color de la pluma
    void setTipoPunta(string tipo_punt) { tipo_punta = tipo_punt; } // Establece el tipo de punta de la pluma

    // Sobrescritura del método mostrarInformacion para incluir detalles específicos de la pluma
    void mostrarInformacion(void) override;
};

// Implementación del método mostrarInformacion() para la clase Pluma
void Pluma::mostrarInformacion(void) {
    // Llama al método mostrarInformacion de la clase base Producto
    Producto::mostrarInformacion();
    // Agrega la información específica de Pluma
    cout << "Color: " << color << "\nTipo de Punta: " << tipo_punta << endl;
}

/// Clase derivada Libreta, que hereda de Producto.
class Libreta : public Producto {
private:
    int num_hojas; // Número de hojas de la libreta
    string tipo;   // Tipo de libreta (e.g., "Cuadro grande", "Rayada")

public:
    // Constructores
    // Constructor por defecto que inicializa los atributos de Libreta y de Producto a valores predeterminados
    Libreta() : Producto(), num_hojas(0), tipo("") {}

    // Constructor que inicializa todos los atributos de Producto y los atributos específicos de Libreta
    Libreta(float precio, int id, string categoria, string marca, int num_hojas, string tipo) 
        : Producto(precio, id, categoria, marca), num_hojas(num_hojas), tipo(tipo) {}

    // Getters
    int getNumHojas() { return num_hojas; } // Devuelve el número de hojas de la libreta
    string getTipo() { return tipo; }       // Devuelve el tipo de libreta

    // Setters
    void setNumHojas(int num_hoja) { num_hojas = num_hoja; } // Establece el número de hojas de la libreta
    void setTipo(string tip) { tipo = tip; }                 // Establece el tipo de libreta

    // Sobrescritura del método mostrarInformacion para incluir detalles específicos de la libreta
    void mostrarInformacion(void) override;
};

// Implementación del método mostrarInformacion() para la clase Libreta
void Libreta::mostrarInformacion(void) {
    // Llama al método mostrarInformacion de la clase base Producto
    Producto::mostrarInformacion();
    // Agrega la información específica de Libreta
    cout << "Numero de Hojas: " << num_hojas << "\nTipo: " << tipo << endl;
}

#endif 
