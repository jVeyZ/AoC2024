# **README \- Advent of Code: Día 7**
---
Este ejercicio ha sido elegido por los beneficios que conlleva el uso de técnicas avanzadas de programación en su resolución, en particular con la búsqueda recursiva y la memorización.
---

### **Parte 1: Sumar las combinaciones válidas**

* **split:** Divide una cadena en partes separadas por un delimitador y devuelve un vector de cadenas.  
* **stringToLongLong:** Convierte una cadena en un número entero de tipo long long, validando que solo contenga dígitos.  
* **tryOperatorsCombinations:** Realiza una búsqueda recursiva para verificar si se puede formar el número objetivo combinando operadores (+ y \*). Usa memoización para evitar cálculos redundantes.  
* **canFormNumber:** Comprueba si el número objetivo puede formarse con los números dados y operadores, llamando a tryOperatorsCombinations.  
* **checkPossibleFormation:** Suma todos los números objetivos que pueden formarse con combinaciones válidas de operadores.  
* **Main:** Lee las ecuaciones desde un archivo. Divide cada línea en objetivo y números. Calcula y muestra la suma de los objetivos válidos.

### **Parte 2: Operador ||**

**Nueva función** concatenate(long long a, long long b):

* Concatena dos números convirtiéndolos a cadenas, uniéndolos y convirtiendo el resultado nuevamente a un número entero.  
* Esto permite manejar el operador || como una concatenación directa de números.

**Modificación en** tryOperatorsCombinations:

* Se añade un nuevo caso para probar la concatenación de números:  
* Este caso prueba si concatenar el número actual con el resultado acumulado puede alcanzar el objetivo.

En este ejercicio se ha podido trabajar con técnicas avanzadas de programación, como la búsqueda recursiva, memorización y manipulación de cadenas y números. En la primera parte, se aprendió a generar y evaluar combinaciones de operadores para cumplir un objetivo, optimizando cálculos mediante memorización. La segunda parte introdujo el operador de concatenación (||), destacando cómo ampliar la funcionalidad de algoritmos añadiendo nuevos casos y manejando eficientemente operaciones combinadas. 
