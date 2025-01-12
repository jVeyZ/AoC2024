# **README \- Advent of Code: Día 2**
---
Hemos elegido ese problema por su uso de recursividad, y por ser el segundo ejercicio del AOC, sacado en un periodo en el que realizar todos los ejercicios a medida que salían no resultaba un peso importante respecto a otros compromisos académicos.
---

Este problema se divide en dos partes:

1. **Determinar la cantidad de informes seguros bajo reglas estrictas.**  
2. **Incluir la posibilidad de ignorar un nivel incorrecto (con el "Problem Dampener").**

### **Parte 1: Informes seguros bajo reglas estrictas**

El objetivo aquí es verificar si cada informe cumple las siguientes condiciones:

1. **Los niveles son todos crecientes o decrecientes.**  
2. **La diferencia absoluta entre niveles consecutivos debe estar entre 1 y 3 (ambos incluidos).**

#### **Algoritmo:**

1. Leer cada línea del archivo que contiene los informes.  
2. Convertir la línea en un vector de enteros (`row`).  
3. Verificar si el vector cumple las condiciones utilizando la función `checkSafety`:  
   * Determinar si el informe es incremental o decremental basado en los dos primeros niveles.  
   * Continuar verificando las diferencias entre cada par de niveles consecutivos.  
   * Si alguna diferencia no cumple las reglas o hay una inconsistencia, el informe se marca como **no seguro**.

#### **Implementación destacada:**

* **Función `checkSafety`:**  
  Esta función realiza una verificación recursiva sobre los niveles del informe.  
  * Si detecta un incremento/decremento inconsistente o una diferencia fuera del rango permitido, marca el informe como inseguro.

### **Parte 2: Introducir el "Problem Dampener"**

El "Problem Dampener" permite ignorar un solo nivel incorrecto en un informe. Esto significa que si eliminando un nivel el informe cumple las reglas, se considera **seguro**.

#### **Algoritmo:**

1. Para cada informe:  
   * Primero verificar si es seguro utilizando las reglas estrictas de la **Parte 1**.  
   * Si no es seguro, probar eliminando cada nivel del informe (uno por uno).  
2. Para cada versión modificada del informe (con un nivel eliminado), verificar si cumple las reglas de la **Parte 1**.  
3. Si al menos una versión es segura, el informe se considera seguro con el "Problem Dampener".

#### **Implementación destacada:**

* **Función `isSafeWithDampener`:**  
  * Primero verifica si el informe original es seguro utilizando `checkSafety`.  
  * Si no lo es, genera versiones modificadas eliminando cada nivel y verifica si alguna de ellas es segura.

En este problema, concretamente en la parte 2, se ha podido poner en práctica la recursividad mediante las funciones “isSafeWithDampener” y “checkSafety”,  sin embargo, no se ha aplicado otra técnica de mayor complejidad al no encontrar un uso efectivo para ella.

