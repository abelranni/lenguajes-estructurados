---
marp: false
theme: default
size: 16:9
paginate: true
---

# Lenguajes Estructurados

## Algoritmo MinMax

## 03.05.03 -  TicTacToe

---

## Introducción

El algoritmo MiniMax es una técnica de búsqueda en árbol utilizada para tomar decisiones óptimas en juegos de dos jugadores con información perfecta.

Estos juegos son juegos de suma cero donde un jugador gana lo que el otro pierde.

El algoritmo MiniMax se basa en la idea de que un jugador intentará maximizar su puntuación (Max) y el otro intentará minimizar la puntuación (Min).

---

Este teorema establece que en los juegos bipersonales de suma cero, donde cada jugador conoce de antemano la estrategia de su oponente y sus consecuencias, existe una estrategia que permite a ambos jugadores minimizar la pérdida máxima esperada.

En particular, cuando se examina cada posible estrategia, un jugador debe considerar todas las respuestas posibles del jugador adversario y la pérdida máxima que puede acarrear.

El jugador juega, entonces, con la estrategia que resulta en la minimización de su máxima pérdida.

---

## Conceptos básicos

### Nodos Max y Min

Los nodos Max y Min representan las decisiones de los jugadores Max y Min, respectivamente.

En un árbol de juego, cada nodo Max representa una posición desde la cual el jugador Max debe elegir un movimiento, y cada nodo Min representa una posición desde la cual el jugador Min debe elegir un movimiento.

---

### Valores de utilidad

Los valores de utilidad representan la "utilidad" de un estado de juego para un jugador.

En el tres en línea, por ejemplo, podríamos asignar un valor de +10 a un estado de ganar para el jugador Max, -10 a un estado de ganar para el jugador Min y 0 a un empate.

---

## Algoritmo Minimax en el tres en línea

El algoritmo Minimax se aplica al tres en línea evaluando cada posición de juego y eligiendo el mejor movimiento posible para el jugador actual.

El algoritmo se ejecuta de la siguiente manera:

- Si se alcanza un estado terminal (un jugador gana o el tablero está lleno), el algoritmo devuelve el valor de utilidad del estado.

- Si es el turno del jugador Max, el algoritmo busca el movimiento que produce el valor máximo de utilidad llamando a Minimax recursivamente en cada posición hija.

- Si es el turno del jugador Min, el algoritmo busca el movimiento que produce el valor mínimo de utilidad llamando a Minimax recursivamente en cada posición hija.

---

## Implementación en el tres en línea

La función minimax() en el tres en línea se implementa de la siguiente manera:

```c
int minimax(int depth, int isMaxPlayer)
{
    // Si alguien ganó o si el tablero está lleno, retorna el valor correspondiente
    if (is_winner(1))
        return 10 - depth;
    if (is_winner(2))
        return -10 + depth;
    if (is_board_full_board())
        return 0;

    int bestValue;
    if (isMaxPlayer)
    {
        bestValue = -1000; // Inicializa el mejor valor para Max en un valor muy bajo
        // Itera a través de todos los movimientos posibles
        // ... Realiza el movimiento
        // ... Llama a minimax() recursivamente con el siguiente jugador
        // ... Deshace el movimiento
        // ... Compara y actualiza el mejor valor
    }
    else
    {
        bestValue = 1000; // Inicializa el mejor valor para Min en un valor muy alto
        // Itera a través de todos los movimientos posibles
        // ... Realiza el movimiento
        // ... Llama a minimax() recursivamente con el siguiente jugador
        // ... Deshace el movimiento
        // ... Compara y actualiza el mejor valor
    }
    return bestValue;
}
```

---

La función ia_move() utiliza el algoritmo Minimax para encontrar y realizar el mejor movimiento posible:

```c
void ia_move(int current_player)
{
    int bestValue = 1000; // Inicializa el mejor valor en un valor muy alto
    int bestMoveX = -1;
    int bestMoveY = -1;

    // Itera a través de todos los movimientos posibles
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            // Comprueba si la casilla (x, y) está vacía
            if (is_empty(x, y))
            {
                // Realiza el movimiento
                add_chip(x, y, current_player);

                // Calcula el valor minimax del movimiento
                int moveValue = minimax(0, 1); // El jugador humano es el jugador Max (1)

                // Deshace el movimiento
                remove_piece(x, y);

                // Compara y actualiza el mejor valor y la mejor posición
                if (moveValue < bestValue)
                {
                    bestValue = moveValue;
                    bestMoveX = x;
                    bestMoveY = y;
                }
            }
        }
    }

    // Realiza el mejor movimiento encontrado
    add_chip(bestMoveX, bestMoveY, current_player);
}
```

---

## Notas adicionales

### Profundidad

La profundidad en el algoritmo Minimax representa el número de niveles que se han explorado en el árbol de juego. Al incluir la profundidad en los valores de utilidad, se priorizan las victorias rápidas y las derrotas lentas.

### Optimizaciones

Para juegos más complejos, el algoritmo Minimax básico puede no ser lo suficientemente eficiente debido al gran número de posiciones posibles.

En estos casos, se pueden utilizar optimizaciones como la poda alfa-beta para acelerar el algoritmo al eliminar las ramas del árbol de juego que no necesitan ser exploradas.

## Implementación

```c	

void ia_move_minimax(int current_player)
{
    int best_value = -1000;
    int best_x = -1;
    int best_y = -1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = current_player;
                int value = minimax(0, 0, current_player);
                board[i][j] = 0;

                if (value > best_value)
                {
                    best_value = value;
                    best_x = i;
                    best_y = j;
                }
            }
        }
    }

    if (best_x != -1 && best_y != -1)
    {
        add_chip(best_x, best_y, current_player);
    }
}

int minimax(int depth, int is_maximizing, int player)
{
    int winner = check_winner();
    if (winner != 0)
    {
        return winner == player ? 1 : -1;
    }

    if (is_board_full())
    {
        return 0;
    }

    int best_value = is_maximizing ? -1000 : 1000;
    int opponent = player == 1 ? 2 : 1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = is_maximizing ? player : opponent;
                int value = minimax(depth + 1, !is_maximizing, player);
                board[i][j] = 0;

                best_value = is_maximizing ? fmax(best_value, value) : fmin(best_value, value);
            }
        }
    }

    return best_value;
}

```


1. **Función ia_move_minimax**: Esta función es la que decide el próximo movimiento de la IA.

   - Inicializa `best_value` a -1000, `best_x` y `best_y` a -1. Estos se utilizarán para rastrear el mejor movimiento que la IA puede hacer.

   - Luego, recorre cada celda en el tablero de juego (3x3 en este caso). Si la celda está vacía (es decir, `board[i][j] == 0`), la IA "hace un movimiento" en esa celda.

   - Luego, llama a la función `minimax` para evaluar este movimiento. Después de la llamada, deshace el movimiento (es decir, `board[i][j] = 0`).

   - Si el valor devuelto por `minimax` es mayor que `best_value`, actualiza `best_value`, `best_x` y `best_y`.

   - Finalmente, si `best_x` y `best_y` son diferentes de -1 (es decir, se encontró un movimiento), la IA realiza el movimiento en esa celda.

2. **Función minimax**: Esta es una implementación del algoritmo Minimax, que es un algoritmo de búsqueda recursiva para decidir el mejor movimiento en juegos de suma cero (como el tateti).

   - Primero, verifica si hay un ganador en el tablero actual. Si hay un ganador, devuelve 1 si el ganador es la IA, o -1 si el ganador es el oponente.

   - Si el tablero está lleno y no hay ganador, devuelve 0, lo que indica un empate.

   - Luego, inicializa `best_value` a -1000 si la IA está maximizando, o a 1000 si está minimizando. También determina quién es el oponente.

   - Luego, recorre cada celda en el tablero. Si la celda está vacía, la IA o el oponente (dependiendo de si está maximizando o minimizando) "hacen un movimiento" en esa celda.

   - Luego, llama a `minimax` recursivamente para evaluar este movimiento. Después de la llamada, deshace el movimiento.

   - Finalmente, actualiza `best_value` con el máximo de `best_value` y `value` si la IA está maximizando, o con el mínimo de `best_value` y `value` si está minimizando. Devuelve `best_value`.

En resumen, este algoritmo realiza una búsqueda en profundidad en el árbol de juego, evaluando cada posible estado del tablero y eligiendo el movimiento que maximiza la posibilidad de ganar para la IA, asumiendo que el oponente también juega de la mejor manera posible.

## Parámetro is_maximizing

El parámetro `is_maximizing` en la función `minimax` se utiliza para alternar entre la IA que intenta maximizar su puntuación y el oponente que intenta minimizarla. En el contexto del algoritmo Minimax, "maximizar" se refiere a obtener la puntuación más alta posible, mientras que "minimizar" se refiere a obtener la puntuación más baja posible.

Cuando se llama a la función `minimax` desde `ia_move_minimax`, `is_maximizing` se establece en 0 (o falso). Esto se debe a que, después de que la IA realiza un movimiento, es el turno del oponente de jugar, y el oponente intentará minimizar la puntuación. En otras palabras, el oponente intentará hacer un movimiento que dé a la IA la puntuación más baja posible en el siguiente turno.

Por lo tanto, `is_maximizing` se establece en 0 para reflejar que, después del movimiento de la IA, el oponente estará jugando para minimizar la puntuación en el siguiente nivel de la recursión.

## Agregar Fonts al proyecto

Links de descarga de las fuentes utilizadas en el proyecto:

- https://fonts.google.com/
- https://www.fontsquirrel.com/
- https://www.1001freefonts.com/
- 
