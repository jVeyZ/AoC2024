# **README \- Advent of Code: Día 25**
---
Hemos elegido este problema, en primer lugar, por ser el último ejercicio propuesto en el AOC, y además por la posibilidad de integrar la memorización con programación dinámica.
---

En el planteamiento del problema se nos proporciona una lista de llaves y cerraduras, la condición para que una llave sea válida para una cerradura es que no haya solapamiento en los pines al igual que en el mundo real.

**Lógica implementada:**

* **combination\_parser():** Lee la llave o cerradura, y cuenta la longitud de pines por cada columna, posteriormente añade el vector de integers al vector de vectores correspondiente.  
* **main():** Lee el archivo de input y clasifica cada submatriz de carácteres como llave o cerradura en base al valor de la fila superior (todo \# para cerraduras). Después con los resultados de combination\_parser() compara cada cerradura con cada llave y verifica si hay solapamiento, si hay solapamiento en alguna columna se salta a la siguiente llave, de lo contrario se añade al número de combinaciones. 

Este ejercicio ha servido para profundizar y recordar conceptos de programación dinámica, la cual nos permite en este caso calcular los valores para cada llave o cerradura y de esta manera poder compararlos con bruteforce con el resto de posibilidades para hallar el número total de combinaciones. De no haber guardado los valores en un array de memoria el coste de computación sería exponencialmente mayor al tener que calcular todos los valores individuales para cada iteración del loop.
