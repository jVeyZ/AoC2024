# DÍA 4
---
Este ejercicio fué realizado de manera lúdica por un miembro del equipo, puesto que el problema fué sacado en un periodo en el que realizar todos los ejercicios a medida que salían no resultaba un peso importante respecto a otros compromisos académicos.
---

## Parte 1: Encontrar todas las ocurrencias de "XMAS"

El objetivo es buscar la palabra **"XMAS"** en un tablero. Las palabras pueden aparecer en cualquier dirección: horizontal, vertical, diagonal, y pueden estar escritas hacia adelante o hacia atrás.

### Detalles del problema

**Direcciones posibles:**
- **Horizontal:** izquierda a derecha y derecha a izquierda.
- **Vertical:** arriba a abajo y abajo a arriba.
- **Diagonales:** cuatro posibles direcciones (↘, ↙, ↗, ↖).

### Estrategia
1. Para cada celda en el tablero, verifica todas las direcciones posibles para encontrar la palabra.
2. Si los caracteres coinciden en la dirección actual, cuenta una ocurrencia.

### Implementación

**Funciones principales:**
- `countWordInDirection`: Verifica si "XMAS" comienza en una celda específica y coincide en una dirección específica (definida por `dx, dy`).
- `countOccurrences`: Itera por todas las celdas del tablero y prueba todas las direcciones desde cada celda usando `countWordInDirection`.

**Eficiencia:**
- Cada celda se analiza en las 8 direcciones.
- Se verifica si los índices están dentro de los límites del tablero para evitar errores.

---

## Parte 2: Encontrar patrones "X-MAS"

Ahora buscamos patrones específicos que formen una **X** con dos diagonales, cada una conteniendo "MAS" o "SAM".

### Detalles del problema

**Forma del patrón:**
- La letra **A** está en el centro.
- Ambas diagonales contienen **"MAS"** o **"SAM"**.

### Estrategia
1. Identificar todas las celdas que contienen "A" en el tablero.
2. Para cada celda con "A", verificar las diagonales que pasan por ella para encontrar coincidencias con **"MAS"** o **"SAM"**.

### Implementación

**Funciones principales:**
- `checkDiag`: Comprueba si las dos diagonales que pasan por una celda (con "A" en el centro) coinciden con **"MAS"** o **"SAM"**.
- `findA`: Busca todas las celdas con "A" en el tablero y verifica sus diagonales con `checkDiag`.

**Eficiencia:**
- Solo se verifican celdas con "A".
- Las operaciones son rápidas porque se analiza un máximo de 4 celdas por diagonal.

---

## Resumen

Este problema permite asentar conocimientos sobre:
- Movimientos en matrices: horizontales, verticales y diagonales.
- Cómo trabajar con patrones complejos en matrices.
- Una mejor comprensión de la **programación dinámica** en estructuras de alta complejidad.

Estos conceptos resultan útiles para proyectos futuros que involucren operaciones con tableros o matrices.
