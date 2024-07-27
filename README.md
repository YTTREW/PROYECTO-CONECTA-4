# ConectaN Championship

## Descripción

Este proyecto implementa el juego del ConectaN con gestión de campeonato entre jugadores. Utiliza las clases desarrolladas en las prácticas anteriores (MatrizEnteros, Tablero, Jugador, ConjuntoJugadores) para crear un juego completo que permite llevar un registro de las partidas y gestionar torneos.

## Clases

### MatrizEnteros
Clase que representa una matriz de enteros, utilizada como base para la implementación del tablero del juego.

### Tablero
Clase que representa el tablero del juego ConectaN. Utiliza MatrizEnteros para almacenar las fichas de los jugadores.

### Jugador
Clase que representa a un jugador en el torneo. Contiene información relevante como el nombre del jugador y su puntaje.

### ConjuntoJugadores
Clase que gestiona un conjunto de jugadores. Permite agregar nuevos jugadores, actualizar información y guardar/cargar datos desde un fichero.

### Partida
Clase que gestiona una partida entre dos jugadores. Controla el flujo del juego, verifica las condiciones de victoria y actualiza la información de los jugadores al finalizar la partida.

## Configuración

El programa se configura mediante un fichero de configuración que debe contener:

- La ruta al fichero de información de los jugadores.
- Indicador de si es un nuevo campeonato.
- Información de los jugadores que participarán en el campeonato.
- Parámetros de la partida, incluyendo los jugadores que jugarán.

## Ejecución

### Paso a Paso

1. **Lectura de la información del fichero de configuración.**
   - El fichero de configuración debe estar en el mismo directorio que el ejecutable o se debe proporcionar la ruta correcta.
   
2. **Creación de objeto ConjuntoJugadores.**
   - Se carga la información de los jugadores desde el fichero indicado en la configuración.
   - En caso de ser un nuevo campeonato, se inicializa la información de los jugadores desde el fichero de configuración.
   
3. **Creación de objeto Tablero.**
   - Se inicializa el tablero para el inicio del juego entre los jugadores indicados en el fichero de configuración.
   
4. **Desarrollo del juego.**
   - Los jugadores introducen las fichas en el tablero hasta que uno de ellos gana o hay empate.
   - La entrada de las columnas se realiza mediante `cin`.
   
5. **Actualización de ConjuntoJugadores.**
   - Se actualiza la información de los jugadores con el resultado de la partida.
   
6. **Almacenamiento de la información.**
   - Se guarda la información de ConjuntoJugadores en el fichero indicado en la configuración.
   
7. **Finalización del programa.**
   - El programa termina tras guardar la información actualizada.

## Ejecución del Programa

Para compilar y ejecutar el programa, sigue estos pasos:

1. Compila el programa usando tu compilador de C++ favorito. Por ejemplo, usando g++:
    ```bash
    g++ -o conectaN main.cpp MatrizEnteros.cpp Tablero.cpp Jugador.cpp ConjuntoJugadores.cpp Partida.cpp
    ```

2. Ejecuta el programa:
    ```bash
    ./conectaN
    ```

## Ficheros de Configuración

### Ejemplo de fichero de configuración

```plaintext
# config.txt
jugadores_fichero=jugadores.dat
nuevo_campeonato=1
jugador1=Alice
jugador2=Bob
