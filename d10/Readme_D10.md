# **README \- Advent of Code: Día 10**
---
Hemos elegido este problema porque era posible aplicar tanto programación dinámica para mejorar el tiempo de ejecución del mismo, como hacer uso de un método de búsqueda DFS(depth first search). Metodo comunmente empleado en problemas de árboles y grafos, por lo que aunque el problema no emplea grafos, permite prácticar técnicas comunmente asociadas con ellos.
---

El planteamiento de este problema es una matriz de integers que varían del 0 al 9, a partir del input se nos pide encontrar todos los gradientes posibles desde todos los puntos de partida que sean igual a 0\. Dichos gradientes deben cumplir la condición que la variación de valor solo sea 1 por etapa, y solo son válidas las casillas adyacentes sin contar las diagonales.

## **Técnicas y estructuras de datos empleadas**

1. **Programación dinámica**:  
   * Se utiliza una pila con formato LIFO para guardar los resultados y no repetir cálculos

   ---

   ## **Descripción de la resolución del problema**

### **Parte 1\*:**

Para la primera estrella se nos pide que hallemos todos los caminos únicos que van de 0 a 9\. Es decir, que para que un camino sea contabilizado la posición de la casilla final debe ser única, no se tienen en cuenta diferentes caminos para un mismo destino.

**Lógica empleada:**

* **Struct PATHS:** Almacena las coordenadas de partida(0), las coordenadas de llegada(9), y un contador para guardar el número de caminos. De esta manera resulta más cómodo acceder a los datos para cada casilla de inicio individual.

* **Función check\_path():** Actúa de forma recursiva comprobando todas las posibles casillas adyacentes, si cumplen la condición de gradiente \[pos\_val \+ 1 \== new\_pos\_val\] son añadidas a una pila con formato LIFO, este tipo de lógica Depth First Search(DFS) se encarga de buscar hasta el final de la rama antes de cambiar de rama, verificando un camino en cada ocasión. Como la longitud de los caminos es fija no hay ventajas al aplicar BFS sobre DFS. Si la pila no está vacía comprueba todos los caminos hasta que se completan o bloquean, si son completados verifica si en el struct ya se han añadido esas coordenadas para evitar los caminos duplicados.  
    
* **main():** Abre el archivo del input y lo guarda en una matriz 2D de integers para poder navegar los datos de manera más cómoda. Después procede a iterar sobre cada casilla del array y si el valor de la casilla es 0 ejecuta la función check\_path(). Después itera sobre cada struct path en PATHS y va añadiendo el número de caminos únicos.

### **Parte 2\*:**

Para la segunda estrella la única variación que se pide es contar el número total de caminos posibles que cumplan la condición de gradiente en vez de el número de caminos únicos. Hay que realizar una pequeña modificación al código en check\_path() para quitar la verificación de final único a la hora de añadir el camino al struct.

Este ejercicio permitió explorar la programación recursiva y su implementación mediante la búsqueda en profundidad (DFS) en una matriz 2D, destacando el manejo de caminos y gradientes en un espacio discreto. En la primera parte, se aprendió a identificar caminos únicos hacia destinos finales, optimizando el proceso mediante estructuras de datos como “struct PATHS” para evitar duplicados. En la segunda parte, se amplió el enfoque para contabilizar todos los caminos posibles, demostrando cómo adaptar algoritmos existentes a nuevos requisitos desconocidos de antemano.

Este ejercicio permitió explorar la programación recursiva y su implementación mediante la búsqueda en profundidad (DFS) en una matriz 2D, destacando el manejo de caminos y gradientes en un espacio discreto. En la primera parte, se aprendió a identificar caminos únicos hacia destinos finales, optimizando el proceso mediante estructuras de datos como “struct PATHS” para evitar duplicados. En la segunda parte, se amplió el enfoque para contabilizar todos los caminos posibles, demostrando cómo adaptar algoritmos existentes a nuevos requisitos desconocidos de antemano.
