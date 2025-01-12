# **README \- Advent of Code: Día 5**
---
Este ejercicio fué elegido por requerir el uso de grafos dirigidos, un concepto explicado en las sesiones de Programación.
---

## **Técnica y estructuras de datos empleadas**

El problema del Día 5 se aborda utilizando un modelo basado en **grafos dirigidos**, representados mediante una lista de adyacencia, y las siguientes técnicas clave:

1. **Grafos dirigidos**:  
   * El grafo se modela mediante un unordered\_map\<int, vector\<int\>\>, donde cada nodo apunta a una lista de vecinos dirigidos.  
   * Esto permite una representación compacta y eficiente para verificar dependencias entre nodos.  
2. **Cálculo de in-degree**:  
   * Se usa un unordered\_map\<int, int\> para almacenar el número de dependencias (entradas) de cada nodo.  
   * Este mapa facilita la validación de la secuencia ingresada al verificar que los nodos solo se procesan cuando no tienen dependencias pendientes.  
3. **Validación topológica**:  
   * La secuencia ingresada se valida contra las reglas de ordenación topológica del grafo, asegurando que se respeten las dependencias entre nodos.

---

## **Descripción de la resolución del problema**

### **1\. Representación del grafo**

* El grafo dirigido se construye a partir de las reglas proporcionadas, donde cada regla indica una relación de dependencia (a \-\> b).  
* Cada regla se agrega al grafo como una arista dirigida (addRule(int a, int b)) y se actualizan tanto la lista de adyacencia como el conteo de in-degree.

### **2\. Lectura y procesamiento de datos**

* Las reglas se leen desde un archivo de entrada y se procesan para construir el grafo y las dependencias asociadas.  
* Posteriormente, las secuencias ingresadas se almacenan en un vector de vectores (vector\<vector\<int\>\>) para su validación.

### **3\. Validación de secuencia**

* Se valida cada secuencia de páginas asegurando que cumpla con las reglas de ordenación topológica.  
  1. Se verifica que un nodo solo se procese cuando su in-degree sea cero.  
  2. Se reduce el in-degree de los nodos vecinos tras procesar un nodo.  
  3. Se comprueba que todos los nodos de la secuencia sean válidos según las reglas del grafo.

### **4\. Obtención del resultado**

* Si la secuencia es válida, se retorna el nodo central de la secuencia como resultado.  
* Si es inválida, se retorna 0\.  
* El programa acumula el total de nodos válidos en las secuencias para imprimirlo al final.

La realización de este ejercicio ha permitido profundizar en el uso de grafos dirigidos y su aplicación práctica para resolver problemas de orden y dependencias. En particular, se ha aprendido a modelar relaciones jerárquicas mediante un grafo, utilizar técnicas avanzadas como el ordenamiento topológico para garantizar el cumplimiento de reglas, y aplicar algoritmos iterativos para corregir y validar estructuras complejas de datos. Además, este ejercicio ha resaltado la importancia de descomponer problemas en pasos manejables, como la construcción del grafo, la validación de listas y la corrección iterativa, lo que facilita el diseño de soluciones eficientes y modulares.
