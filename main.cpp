#include <iostream>
#include "producto.h"  // Incluye la definición de las clases Producto, Pluma y Libreta
#include "papeleria.h"  // Incluye la definición de las clases Papeleria e Inventario

int main() {
    // Crear una papelería
    Papeleria* miPapeleria = new Papeleria("Papeleria Esperanza", 123456789, "Calle Amapola #34");

    // Crear productos de todos los tipos
    Pluma* pluma1 = new Pluma(10.0, 102, "Oficina", "BIC", "Azul", "Fina");
    Libreta* libreta1 = new Libreta(20.0, 103, "Escolar", "Scribe", 100, "Cuadro grande");

    // Agregar productos al inventario
    miPapeleria->getInventario().agregarProducto(pluma1);
    miPapeleria->getInventario().agregarProducto(libreta1);

    // Mostrar el inventario de la papelería
    miPapeleria->mostrarInventario();

    // Liberar memoria
    delete pluma1;
    delete libreta1;
    delete miPapeleria;

    return 0;
}
