# **README \- Advent of Code: Día 23**

## **Técnicas y estructuras de datos empleadas**

El problema se aborda utilizando un grafo no dirigido para representar las conexiones entre ordenadores, empleando las siguientes técnicas:

1. **Representación del Grafo**:  
   * Se utiliza un map\<string, set\<string\>\> llamado grafo para representar el grafo.  
   * Las claves del mapa son los nombres de los ordenadores.  
   * Los valores son conjuntos que contienen los nombres de los ordenadores directamente conectados al ordenador clave.  
2. **Construcción del Grafo**:  
   * Se lee cada conexión desde un archivo llamado input23.  
   * Las conexiones se dividen en dos nodos utilizando la función dividirCadena.  
   * Cada nodo se inserta en el conjunto del otro nodo, creando así una conexión bidireccional (no dirigida).  
3. **Búsqueda de Tripletas**:  
   * Se iteran todas las combinaciones posibles de tres nodos.  
   * Para cada combinación, se verifica si los tres nodos están completamente conectados entre sí utilizando el grafo.  
   * Las tripletas válidas se almacenan en un conjunto para evitar duplicados.

---

## **Descripción de la resolución del problema**

### **1\. Lectura de conexiones**

* Se lee un archivo llamado input23 que contiene las conexiones entre ordenadores en formato de texto.  
* Cada línea del archivo representa una conexión entre dos nodos.

### **2\. División de cadenas**

* La función dividirCadena se utiliza para dividir cada conexión en nodos individuales.  
* Los nodos se procesan y se insertan en el grafo.

### **3\. Construcción del grafo**

* Para cada conexión, se actualizan las claves y los valores en el mapa para reflejar la relación bidireccional entre los nodos.  
* Esto asegura que el grafo represente correctamente todas las conexiones no dirigidas.

### **4\. Búsqueda de tripletas**

* Se exploran todas las combinaciones posibles de tres nodos dentro del grafo.  
* Se verifica que todos los nodos de una combinación estén conectados entre sí.  
* Además, se filtran tripletas que contengan nodos cuyos nombres comiencen con una letra específica, como la 't'.

### **5\. Salida de resultados**

* Se imprime el número total de tripletas encontradas.  
* También se muestran las tripletas que cumplen el filtro adicional (por ejemplo, que contienen nodos cuyos nombres comienzan con 't').

---

Este ejercicio permitió explorar cómo modelar y trabajar con grafos no dirigidos para resolver problemas de conectividad. Destacó la búsqueda de subestructuras específicas, como tripletas completamente conectadas, y demostró cómo usar mapas y conjuntos para manejar relaciones bidireccionales de manera eficiente.

