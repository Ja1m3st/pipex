# 🌟 ¿Qué es Pipex?
Pipex es un programa que simula el comportamiento de este comando UNIX:

```bash
< archivo entrada cmd1 | cmd2 > archivo salida
```

Lo que significa:

1. Toma un archivo como entrada.
2. Ejecuta dos comandos (cmd1 y cmd2), canalizando la salida de uno como entrada del otro.
3. Guarda el resultado en un archivo de salida.

Ejemplo Práctico:

```bash
./pipex archivo_in "cat -e" "grep foo" archivo_out
```

Es equivalente a:
```bash
< archivo_in cat -e | grep foo > archivo_out
```

## 🛠️ Herramientas Clave
Para cumplir este objetivo, Pipex utiliza:

- Redirección de archivos: Aprende a manejar dup2 y open para redirigir entradas y salidas estándar.
- Tuberías (pipes): Conecta procesos para transferir datos de forma eficiente.
- Ejecutables dinámicos: Usa execve para ejecutar comandos como un verdadero sistema UNIX.
- Procesos (fork): Divide y conquista creando hijos que realicen tareas específicas.

# 🏗️ Estructura del Proyecto
# Archivos Principales
`pipex.c`: El corazón del programa. Controla el flujo principal y organiza los procesos.
`pipex_utils.c`: Funciones auxiliares para manejo de errores, liberación de memoria, etc.
`Makefile`: Compila el proyecto de manera sencilla y elegante.

Prototipo de la función principal:
```bash
int main(int argc, char **argv, char **envp);
```

`argc y argv`: Argumentos para manejar los comandos y archivos.
`envp`: Variables de entorno necesarias para localizar los comandos.

## 🚀 Instrucciones de Uso
1. Clona el repositorio o copia los archivos.

2. Compila el proyecto con el Makefile:
```bash
make
```
Esto generará un ejecutable llamado pipex.

3. Ejecuta tu programa:
```bash
./pipex archivo_in "cmd1" "cmd2" archivo_out
```
![pipex](https://github.com/user-attachments/assets/af6933ac-e8af-44f8-a4d0-92cf28d1737a)


En caso que sea el bonus seria asi:
```bash
./pipex archivo_in "cmd1" "cmd2" "cmd3" ... archivo_out
```

Ejemplo:
```bash
./pipex input.txt "ls -l" "wc -l" output.txt
```

Ejemplo Bonus:
```bash
./pipex input.txt "ls -l" "grep infile" "wc -l" output.txt
```

4. Revisa el archivo de salida:

```bash
cat output.txt
```
