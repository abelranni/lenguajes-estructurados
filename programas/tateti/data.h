#ifndef DATA_H
#define DATA_H

typedef struct cell
{
    int x;
    int y;
} Cell;
typedef struct chip_selection
{
    Cell cell;
    int player;
} ChipSelection;

#endif // DATA_H
