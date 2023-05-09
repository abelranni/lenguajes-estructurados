
## Diagramas de flujo


### Diagrama de flujo de la función `ia_move`

```mermaid
graph TD
    A[ia_move] --> B{is_empty}
    B -->|Yes| C[add_piece]
    B -->|No| D[Próxima posición]
    C --> E[minimax]
    E --> F[remove_piece]
    F --> G{moveValue < bestValue}
    G -->|Yes| H[Actualizar bestValue y posición]
    G -->|No| D
    H --> D
    D --> I{Todas las posiciones revisadas}
    I -->|Yes| J[Realizar mejor movimiento]
    I -->|No| B
```

---

### Diagrama de flujo de la función `minimax`

```mermaid
graph TD
    A[minimax] --> B{is_winner}
    B -->|Yes| C[Retornar valor de ganador]
    B -->|No| D{is_full_board}
    D -->|Yes| E[Retornar empate]
    D -->|No| F{isMaxPlayer}
    F -->|Yes| G[Iterar movimientos Max]
    F -->|No| H[Iterar movimientos Min]
    G --> I[add_piece]
    H --> I
    I --> J[minimax recursivo]
    J --> K[remove_piece]
    K --> L[Actualizar bestValue]
    L --> M{Todos los movimientos revisados}
    M -->|Yes| N[Retornar bestValue]
    M -->|No| G

```

---
### Diagrama de flujo de la función `is_winner`

```mermaid
graph TD
    A[is_winner] --> B{Revisar filas}
    B -->|Yes| C[Retornar ganador]
    B -->|No| D{Revisar columnas}
    D -->|Yes| C
    D -->|No| E{Revisar diagonales}
    E -->|Yes| C
    E -->|No| F[Retornar no ganador]

```

---

### Diagrama de flujo de la función `is_full_board`
```mermaid
graph TD
    A[is_full_board] --> B{Revisar todas las casillas}
    B -->|Yes| C[Retornar tablero lleno]
    B -->|No| D[Continuar revisión]
    D --> B

```

---
### Diagrama de flujo de la función `is_empty`

```mermaid
graph TD
    A[is_empty] --> B{Verificar casilla vacía}
    B -->|Yes| C[Retornar vacía]
    B -->|No| D[Retornar no vacía]
```
---

### Diagrama de flujo de la función `remove_piece`

```mermaid
graph TD
    A[remove_piece] --> B[Eliminar pieza]

```

---



