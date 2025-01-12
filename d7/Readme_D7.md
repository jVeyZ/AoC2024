# **README \- Advent of Code: Día 7**

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