### [v1.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v1.0 "1.0"): Versión inicial del juego de la vida
- [x] Utiliza una programación modular y crea un makefile para automatizar la compilación
- [x] Representa el mundo mediante un array bidimensional de tamaño fijo
- [x] Ejecuta un numero fijo de iteraciones
- [x] Muestra el estado inicial y final del mundo mediante printf
- [x] Comprueba los resultados obtenidos con uno de los simuladores enlazados

En esta primera versión se almacena el mundo (tablero + algunas variables) en una estructura. Se puede modificar el tamaño del mapa y el número de iteracciones.
Se incializan dos estructuras para almacenar el mundo, una en la que se guarda el estado actual y otra sobre la que se va iterando para guardar el estado futuro.

Para realizar la lógica del juego se usa la función _transicion()_ la cual recorre todas las células del tablero para comprobar su estado, a su vez, llama a la función _checkVecinas()_ que comprueba el número de células vecinas vivas que hay con respecto a la célula que se le pasa, teniendo en cuenta la frontera del mundo (no comprueba casillas fuera de la matriz) y no se cuenta a ella misma como vecina viva.

Todo el proceso guarda logs en un fichero, donde se puede observar el resultado de todas las comprobaciones realizadas para determinar el estado de las células vecinas.

Finalmente se muestra por pantalla la matriz que representa el mundo en cada iteracción.

### [v2.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v2.0 "2.0"): Utilizar reserva dinámica de memoria y objetos

- [x] El tamaño del mundo debe poder elegirse en tiempo de ejecución
- [x] Descompón tu programa en los módulos y objeto(s) que creas convenientes.

Se han creado el "objeto" para almacenar el mundo, con su constructor y destructor para tratar la reserva de memoria, en la versión 1.0 se realizaba de manera estática dentro de la estructura, en cambio ahora se realiza de manera dinámica con calloc (así por defecto están todas muertas), se reservan dos bloques diferentes, uno para el estado actual y otro para el futuro

Para hacer el cambio del estado N al N+1 se copia el bloque de memoria futuro del estado N como el actual del N+1.

### [v3.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v3.0 "3.0"): Argumentos de main y listas encadenadas

- [x] Haz que el tamaño de tu mundo se pueda pasar como argumentos al lanzar tu programa. Utiliza getoptlong
- [ ] Utiliza las listas encadenadas del núcleo de linux para optimizar el recorrer las células vivas. Por cada una de las células vivas debes inspeccionar ésta y sus vecinas.

Modificado el main para que acepte parámetros al ejecutarse.
```bash
╰─$ ./main.out -h
./main.out -t tamaño -s simulaciones [-r -h]
	 -t tamaño: Tamaño del tablero
	 -s simulaciones: Número de simulaciones
	 -r: Inicializa el mundo con un estado aleatorio
	 -h: Muestra esta ayuda
```
Añadida posibilidad de generar un mundo aleatorio en función de una semilla temporal.

### [v4.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v4.0 "4.0"): Entrada/Salida

- [x] Añade un parámetro de entrada más a tu programa `-f <fichero_config>` para pasarle un archivo de configuración donde tendrás guardados parámetros de la simulación. Haz un análisis simple de este fichero: las opciones con un formato estricto y siempre en el mismo orden.
- [x] Haz que al final de la simulación se guarde en un archivo un historial del número de células vivas en cada iteración. Utiliza un formato que depués puedas representar con un programa como gnuplot: `<num iteración><tabulación><num células vivas><nueva línea>`
- [x] EXTRA: Haz que al final de la simulación se guarde un archivo con el último estado del mundo, y que éste se pueda cargar al inicio del programa para continuar con la simulación.

Añadido todo lo anterior. Las opciones disponibles son:
```bash
╰─$ ./main.out -h
./main.out [opciones]
	 Opción 1: ./main.out -t tam -s sim [-c est ó -r]
		 -t tamaño: Tamaño del tablero
		 -s simulaciones: Número de simulaciones
		 -c [gli | bli | toa | row]: Estado incial conocido
		 -r: Inicializa el mundo con un estado aleatorio
	 Opción 2: ./main.out -f file
		 -f fichero_config: Fichero de configuración
	 Opción 3: ./main.out -e file
		 -e fichero_estado: Fichero de estado anterior
	 -h: Muestra esta ayuda
```

### [v5.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v5.0 "5.0"): Objetos(II): Herencia

- [ ] Divide tu arquitectura en tres objetos:
	- **world:** Objeto abstracto que no tienen implementada las funciones _world_get_cell_ y _world_set_cell_, pero sí el resto
	- **world_normal:** Objeto que hereda de world e implementa las funciones _world_get_cell_ y _world_set_cell_ para acceder a un mundo finito con límites.
	- **world_toroidal:** Objeto que hereda de world e implementa las funciones _world_get_cell_ y _world_set_cell_ para accedar al mundo de forma toroidal.

### [v6.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v6.0 "6.0"): Interfaz gráfica con GTK

- [ ] Usando como plantilla el código que se proporciona, crea una interfaz gráfica para tu juego de la vida, con al menos, las siguientes características:
	- Se puede elegir el tamaño y el tipo del mundo antes de empezar la simulación
	- Se puede detener y continuar la simulación
	- Se puede avanzar la simulación paso a paso
	- Se pueden añadir células vivas haciendo click izquierdo con el ratón en el área de dibujado
	- Se pueden eliminar células vivas haciendo click derecho con el ratón en el área de dibujado
	- Se puede elegir la velocidad de simulación
