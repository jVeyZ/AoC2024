# **README \- Advent of Code: Día 6**

### **Parte 1: Contar las posiciones visitadas**

La lógica para contar las posiciones visitadas por el guardia se basa en:

1. **Identificar la posición inicial** del guardia (`^`) en el mapa. Esta posición se convierte en un `.` para que sea navegable.  
2. **Simular el movimiento del guardia**, siguiendo estas reglas:  
   * Si el guardia tiene un obstáculo delante, gira 90° a la derecha.  
   * De lo contrario, avanza una posición en la dirección actual.  
3. **Registrar las posiciones visitadas** en una matriz secundaria (`visited`), marcando cada posición nueva que alcanza.  
4. **Detener la simulación** cuando el guardia intenta salir del mapa.

El código usa un bucle para simular el patrullaje del guardia y una lista de pares para manejar las direcciones (`arriba`, `derecha`, `abajo`, `izquierda`). Cada vez que el guardia gira, se actualiza su dirección usando `(currentDir + 1) % 4`.

### **Parte 2: Encontrar posiciones que generen un bucle**

El objetivo es colocar un obstáculo (`#`) en una posición vacía (`.`) para que el guardia quede atrapado en un bucle infinito.

#### **Pasos:**

1. **Identificar la posición inicial** y todas las posibles posiciones vacías (`.`).  
2. **Simular el movimiento del guardia** para cada posible ubicación del nuevo obstáculo:  
   * Crear una copia del mapa con el obstáculo colocado en la posición probada.  
   * Usar un conjunto (`set`) para almacenar estados únicos del guardia (posición y dirección).  
   * Si el guardia repite un estado, se detecta un bucle.  
3. **Contar las posiciones que generan bucles**.

#### **Detalles importantes:**

* **Estado único**: Cada estado del guardia incluye `(x, y, dir)` para evitar contar direcciones diferentes en la misma celda como estados distintos.  
* **Eficiencia**: Se copia el mapa original para cada prueba, y se verifica cada posición vacía, lo que es costoso pero manejable en mapas pequeños.

Este ejercicio ha permitido profundizar en simulaciones y estructuras de datos avanzadas. En la primera parte, se reforzó el modelado de movimientos en espacios definidos usando reglas de dirección y obstáculos, aprovechando matrices y operaciones modulares. En la segunda parte, la detección de bucles mediante estados únicos en conjuntos mostró cómo optimizar simulaciones con múltiples iteraciones. Además, gestionar copias del mapa para probar configuraciones destacó la importancia de la eficiencia en problemas complejos.
