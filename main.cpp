#include <iostream>
#include "producto.h"  
#include "papeleria.h"  

int main() {
    // Crear una papelería
   
    Papeleria* miPapeleria = new Papeleria("Papeleria Esperanza", 123456789, "Calle Amapola #34");
    // Crear productos
    Pluma* pluma1 = new Pluma(10.0, 102, "Pluma", "BIC", "Azul", "Fina");
   
    Libreta* libreta1 = new Libreta(20.0, 103, "Libreta", "Scribe", 100, "Cuadro grande");

    // Agregar productos al inventario
   
    miPapeleria->getInventario().agregarProducto(pluma1);
    miPapeleria->getInventario().agregarProducto(libreta1);

    // Mostrar el inventario de la papelería
    cout << "Inventario inicial:" << endl;
    miPapeleria->mostrarInventario();

    char respuesta;
    cout << "\n¿Desea agregar mas productos al inventario? (s/n): ";
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        miPapeleria->crearInventario();
    } else {
        cout << "No se han agregado mas productos al inventario." << endl;
    }

    // Mostrar el inventario actualizado
    cout << "\nInventario actualizado:" << endl;
    miPapeleria->mostrarInventario();

    // Liberar memoria
    delete pluma1;
    delete libreta1;
    delete miPapeleria;

    return 0;
}
