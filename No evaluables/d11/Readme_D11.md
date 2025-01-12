\# \*\*README \\- Advent of Code: Día 11\*\*

\#\#\# \*\*Parte 1: Transformar las piedras utilizando reglas específicas\*\*

El objetivo es transformar una lista de piedras según reglas específicas y simular el proceso durante un número determinado de parpadeos.

1\. \*\*Formato de las piedras iniciales:\*\*    
   \* Las piedras iniciales están representadas por números en formato de cadena.    
   \* Cada piedra se transforma según las siguientes reglas:  
 	\* Si la piedra es "0", se reemplaza por "1".  
 	\* Si la piedra tiene un número par de dígitos, se divide en dos piedras. La mitad izquierda y la mitad derecha de los dígitos se convierten en nuevas piedras.  
 	\* Si ninguna de las otras reglas se aplica, la piedra se multiplica por 2024\.  
2\. \*\*Implementación:\*\*    
   \* Usamos una estructura de árbol para representar las transformaciones de las piedras.  
   \* Cada nodo del árbol representa una piedra y sus transformaciones se representan como nodos hijos.  
   \* Utilizamos una cola para procesar los nodos nivel por nivel (travesía en anchura).  
   \* Utilizamos una caché (\`transformCache\`) para almacenar los resultados de las transformaciones y evitar cálculos redundantes.  
3\. \*\*Main:\*\*    
   \* El programa inicializa las piedras y crea los nodos raíz para cada piedra.  
   \* Simula los parpadeos transformando las piedras y añadiendo las piedras resultantes a la cola.  
   \* Imprime el número de piedras después de cada parpadeo.

\#\#\# \*\*Parte 2: Utilizar una estructura de árbol para manejar las transformaciones\*\*

Aquí se introduce el uso de una estructura de árbol para manejar eficientemente las transformaciones de las piedras.

1\. \*\*Estructura del árbol:\*\*    
   \* Cada piedra se representa como un nodo en el árbol.  
   \* Las transformaciones de una piedra se representan como nodos hijos.  
2\. \*\*Comportamiento:\*\*    
   \* Utilizamos una cola para procesar los nodos nivel por nivel, simulando una travesía en anchura.  
   \* La caché (\`transformCache\`) ayuda a evitar cálculos redundantes al almacenar los resultados de las transformaciones.  
3\. \*\*Implementación:\*\*    
   \* Definimos una estructura \`TreeNode\` para representar cada piedra y sus hijos.  
   \* La función \`transformStone\` transforma una piedra según las reglas y añade los resultados como hijos del nodo.  
   \* La función \`simulateBlinks\` simula los parpadeos utilizando la cola para procesar los nodos y transforma las piedras.  
   \* La función principal inicializa las piedras, crea los nodos raíz y llama a \`simulateBlinks\` para simular los parpadeos.

En este problema, hemos aprendido a utilizar estructuras de árbol y técnicas de memoización para manejar eficientemente las transformaciones de datos. La travesía en anchura y el uso de una caché son herramientas poderosas para optimizar el rendimiento y evitar cálculos redundantes.