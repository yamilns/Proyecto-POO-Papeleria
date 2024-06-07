#include <iostream>
#include "producto.h"  // Incluyo las definiciones de las clases Producto, Pluma y Libreta
#include "papeleria.h"  // Incluyo las definiciones de las clases Papeleria e Inventario

int main() {
    // Crear una papelería
    // Uso el operador new para crear un objeto de la clase Papeleria.
    // Le asigno un nombre "Papeleria Esperanza", un número de teléfono y una dirección.
    Papeleria* miPapeleria = new Papeleria("Papeleria Esperanza", 123456789, "Calle Amapola #34");

    // Crear productos de todos los tipos
    // Aqui, creo una Pluma con atributos especificos como precio, ID, categoría, marca, color y tipo de punta.
    Pluma* pluma1 = new Pluma(10.0, 102, "Oficina", "BIC", "Azul", "Fina");
    // Tambien creo una Libreta con sus propios atributos como precio, ID, categoría, marca, número de hojas y tipo de libreta.
    Libreta* libreta1 = new Libreta(20.0, 103, "Escolar", "Scribe", 100, "Cuadro grande");

    // Agregar productos al inventario
    // Llamo al método getInventario() de la papelería para obtener una referencia al inventario y 
    // uso agregarProducto() para añadir la pluma y la libreta al inventario.
    miPapeleria->getInventario().agregarProducto(pluma1);
    miPapeleria->getInventario().agregarProducto(libreta1);

    // Mostrar el inventario de la papelería
    // Llamo al método mostrarInventario() de la papelería para ver todos los productos que he agregado.
    // Este método recorrerá todos los productos en el inventario y mostrará su información.
    miPapeleria->mostrarInventario();

    // Liberar memoria
    // Esto es crucial para evitar fugas de memoria en el programa.
    delete pluma1;
    delete libreta1;
    delete miPapeleria;

    return 0; // Retorno 0 para indicar que el programa terminó correctamente.
}
