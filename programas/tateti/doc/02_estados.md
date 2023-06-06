---
marp: true
theme: default
size: 16:9
paginate: true
---

# 03.05.02 -  TicTacToe - Estados

## Lenguajes Estructurados

---

**Estado `INITIAL`**: En este estado, los jugadores están colocando sus fichas en el tablero.
    - Asumamos que las fichas son colocadas alternativamente por cada jugador.
    - Necesitamos seguir el turno del jugador y permitirles seleccionar una celda vacía para colocar su ficha.
    - Después de cada movimiento, verificamos si el tablero tiene algún ganador.
    - Si un jugador gana, pasamos al estado `END_GAME`.
    - Si todos las fichas han sido colocadas y no hay ganador, pasamos al estado`SELECT_CHIP`.

---

**Estado `SELECT_CHIP`**: En este estado, el jugador cuyo turno es, seleccionaría una de sus fichas existentes para moverla. 
    - Si el jugador selecciona una de sus fichas (haciendo clic en una de sus fichas), entonces guardamos esa ficha como la ficha seleccionada y pasarías al estado `MOVE_CHIP`.

---

**Estado `MOVE_CHIP`**: En este estado, el jugador debería seleccionar una celda adyacente vacía a la celda de la ficha seleccionada para mover la ficha.
    - Si el jugador selecciona una celda adyacente vacía, movemos la ficha seleccionada a la nueva celda y verificamos nuevamente si hay algún ganador.
     - Si un jugador gana, pasamos al estado `END_GAME`.
     - Si ninguno de estos casos se cumple, cambiamos el turno al otro jugador y volvemos al estado `SELECT_CHIP`.

---

**Estado `END_GAME`**: En este estado, el juego ha terminado.
    - Mostramos un mensaje indicando quién ha ganado o si el juego ha terminado en empate.
    - También podemos proporcionar una opción para reiniciar el juego.
  
---

```mermaid
stateDiagram
    [*] --> INITIAL
    INITIAL --> SELECT_CHIP: Todos los chips están en el tablero y no hay ganador
    SELECT_CHIP --> MOVE_CHIP: El jugador selecciona uno de sus chips
    MOVE_CHIP --> SELECT_CHIP: El chip se mueve y no hay ganador
    MOVE_CHIP --> END_GAME: El chip se mueve y hay un ganador
    INITIAL --> END_GAME: Hay un ganador antes de mover chips
    END_GAME --> [*]: El juego se reinicia o se cierra

```


