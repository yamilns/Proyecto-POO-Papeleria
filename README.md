# ¿De qué trata el proyecto?
Como base de mi proyecto decidí hacer algo referente al negocio familiar ya que
tengo mas conocimiento en ese ámbito y se me facilitaría mucho abordar eso en mi 
proyecto.
A continuación desglosare los tipos de clases que utilice:
## ¿Como funciona?
El programa modela una papelería que gestiona un inventario de productos. Utiliza una estructura de clases en C++ para representar distintos tipos de productos y la papelería que los contiene. 

**1. Creación de la Papelería:**
Se crea una instancia de la clase Papeleria llamada "_miPapeleria_", que almacena información sobre la papelería, como su nombre, número de teléfono y ubicación.

**2. Creación de Productos:**
Se crean instancias de productos específicos, en este caso, una "_Pluma_" y una "_Libreta_", que son clases derivadas de "_Producto_". Cada producto tiene propiedades como "_precio_", "_ID_", "_categoría_", "_marca_" y atributos adicionales específicos de su tipo.

**3. Agregar Productos al Inventario:**
Los productos creados "(Pluma y Libreta)" se agregan al inventario de la papelería mediante el método "_agregarProducto_" del Inventario, que es una clase miembro de Papeleria.

**4. Mostrar el Inventario:**
Se llama al método "_mostrarInventario_" de Papeleria, que a su vez llama al método "_mostrarInventario_" de Inventario. Este método recorre todos los productos en el inventario y muestra su información utilizando el método mostrarInformacion de cada producto.

**5. Liberación de Memoria:**
Se libera la memoria asignada para los productos y la papelería utilizando "_delete_", evitando así fugas de memoria

### Clases Utilizadas en el Programa
**1. Clase Producto:**
* Es una clase abstracta que define la interfaz básica para todos los productos en la papelería. Contiene propiedades comunes como precio, ID, categoría y marca.
* Tiene un método virtual puro mostrarInformacion, que hace de esta una clase abstracta.
* Las clases derivadas deben implementar mostrarInformacion para proporcionar información específica sobre cada tipo de producto

**2. Clase Pluma**
* Es una clase derivada de Producto que añade propiedades específicas de una pluma, como color y tipo de punta.
* Implementa el método mostrarInformacion para mostrar detalles específicos de la pluma.

**3.Clase Libreta:**
* Es otra clase derivada de Producto que añade propiedades específicas de una libreta, como el número de hojas y el tipo de libreta.
* Implementa el método mostrarInformacion para mostrar detalles específicos de la libreta.

**4. Clase Inventario:**
* Gestiona una colección de productos. Utiliza un array de punteros a Producto para almacenar los productos.
* Permite agregar y eliminar productos del inventario, así como mostrar todos los productos en el inventario.

**5. Clase Papeleria:**
* Representa la papelería en sí. Contiene información sobre la papelería y su inventario.
* Proporciona métodos para mostrar el inventario y acceder al inventario para agregar productos.

#### Conclusión
Este programa es un buen ejemplo de cómo utilizar la programación orientada a objetos en C++ para modelar sistemas complejos. Al emplear clases abstractas, herencia, polimorfismo y composición, el programa logra una estructura clara y extensible.

##### Errores en el programa
Para concluir algunos posibles escenarios posibles que se pueden dar en el proyecto para que este deje de funcionar serian:
1. Errores en el código, esto es un escenario muy posible y se podría solucionar haciendo muchas pruebas en el código para poder lograr el objetivo (que el código funcione).
   
2. Otro posible escenario seria simplemente un error del que este utilizando el programa ya que puede introducir datos incorrectos a la hora de estar haciendo el inventario (en este caso seria que digites el numero de articulo de mala manera. En pocas palabras error de dedo) y esto se podría solucionar revisando arduamente los datos que estes introduciendo para no generar complicaciones.

##### Observaciones
Este es el formato corregido ya que no sabia que llebaba este formato y lo estaba haciendo mal ya que yo creaba repositorios por cada avance que teniamos pero ya esta corregido.
A continuacion dejo los links de los avances:
**Avance 1:** https://github.com/yamilns/Primer-avance
**Avance 2:** https://github.com/yamilns/Segundo-Avance
**Avance 3:** https://github.com/yamilns/Tercer-Avance
