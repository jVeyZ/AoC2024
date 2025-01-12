# **README \- Advent of Code: Día 1**

## **Técnicas y estructuras de datos empleadas**

1. **Tablas hash y programación dinámica**:  
   * Se utiliza un unordered\_map (tabla hash) para construir una tabla de frecuencias de los elementos en la segunda columna.  
   * Esto permite acceder rápidamente a la frecuencia de cualquier número, evitando recalcularla repetidamente.  
2. **Divide y vencerás**:  
   * La suma del puntaje de similitud se divide en subproblemas más pequeños, dividiendo el rango de índices de la primera columna.  
   * Cada subproblema calcula el puntaje para una sección de la columna y los resultados se combinan recursivamente.

   ---

   ## **Descripción de la resolución del problema**

   ### **1\. Lectura de datos**

* Se lee un archivo de entrada que contiene dos columnas de datos en cada línea. Los datos se almacenan en dos vectores: column1 y column2.  
* Para cada línea, los valores de ambas columnas se separan y se agregan a los vectores correspondientes.

  ### **2\. Construcción de una tabla de frecuencias**

* Usamos un unordered\_map (tabla hash) para registrar cuántas veces aparece cada número en column2.  
* Este paso permite reutilizar esta información en lugar de recalcular frecuencias cada vez que se procesa un número de column1.

  ### **3\. Aplicación de divide y vencerás**

* La función calculateSimilarityScore divide el rango de índices de column1 en dos mitades.  
* Calcula el puntaje para cada mitad de forma recursiva y combina los resultados.  
* Si el rango tiene un solo elemento, calcula directamente el puntaje utilizando la tabla de frecuencias.

  ### **4\. Cálculo del puntaje total**

* La función principal utiliza calculateSimilarityScore para procesar toda la columna column1 y el puntaje se imprime como resultado final, representando la similitud total entre las dos columnas de datos.

