# **README \- Advent of Code: Día 3**
---
Este ejercicio fué realizado de manera lúdica por un miembro del equipo, puesto que el problema fué sacado en un periodo en el que realizar todos los ejercicios a medida que salían no resultaba un peso importante respecto a otros compromisos académicos.
---

### **Parte 1: Procesar las instrucciones válidas `mul()`**

El objetivo es encontrar y procesar todas las instrucciones `mul(X,Y)` válidas en un archivo de memoria corrupta. Estas instrucciones representan multiplicaciones de dos números XXX y YYY.

1. **Formato de las instrucciones válidas:**  
   * Las instrucciones válidas tienen el formato `mul(X,Y)` donde XXX y YYY son números entre 1 y 3 dígitos.  
   * Cualquier otra variante, como caracteres especiales o espaciado incorrecto, es inválida.  
2. **Implementación:**  
   * Usamos expresiones regulares para encontrar coincidencias de la forma `mul(X,Y)`.  
   * El patrón `mul\((\d+),(\d+)\)` detecta:  
     * `(\d+)`: Un número de uno o más dígitos (para XXX y YYY).  
   * Los números extraídos se convierten en enteros, se multiplican, y el resultado se agrega al total.  
3. **Ciclo principal:**  
   * El programa recorre cada línea del archivo y busca todas las coincidencias con la expresión regular.  
   * Multiplica los números válidos y suma los resultados.

### **Parte 2: Añadir instrucciones condicionales `do()` y `don't()`**

Aquí se introducen nuevas instrucciones que habilitan o deshabilitan la ejecución de futuras instrucciones `mul()`.

1. **Instrucciones adicionales:**  
   * `do()`: Habilita la ejecución de las instrucciones `mul()` siguientes.  
   * `don't()`: Deshabilita la ejecución de las instrucciones `mul()` siguientes.  
   * Por defecto, las instrucciones `mul()` están habilitadas.  
2. **Comportamiento:**  
   * Solo las instrucciones `mul()` que estén habilitadas (controladas por la última aparición de `do()` o `don't()`) se procesan.  
   * Las instrucciones condicionales afectan todas las instrucciones `mul()` subsiguientes.  
3. **Implementación:**  
   * Usamos la misma expresión regular extendida para capturar `do()` y `don't()` además de `mul(X,Y)`.  
   * Una bandera (`flag`) indica si las instrucciones `mul()` están habilitadas o deshabilitadas.  
   * Cada vez que encontramos un `do()` o `don't()`, ajustamos la bandera.  
   * Solo procesamos las instrucciones `mul()` cuando la bandera está habilitada.

En este problema, si bien no se ha aprendido nada de notoriedad relacionado con el material del aula, sí que hemos aprendido acerca de las “expresiones regulares” o regex en C++, un elemento muy interesante para el parseado de datos, el cual uno de los integrantes del grupo ya ha utilizado para el desarrollo de APIs y obtención de datos con NodeJS.

