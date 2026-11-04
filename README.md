# JAM-Infinity

Game made during an Epitech game jam, in C++ with SFML. The window is titled "Infinity" and the game follows an incremental loop: you accumulate money, buy and level up a series of objects (a train, a plane, a car and so on), and watch them move on screen with sound.

## Build

```
make
./Infinity
```

SFML (graphics, window, system, audio) and ncurses are required.

## Layout

- `src/display`: rendering and interface
- `src/linked_list`: the list that holds the objects
- `assets`: sprites, font and audio
