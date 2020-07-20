
#GNU make
#The "make" utility automates the mundane aspects of building executable from source code. "make" uses a so-called makefile, 
#which contains rules on how to build the executables.
#You can issue "make --help" to list the command-line options; or "man make" to display the man pages.
#@see: https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
#@see: https://hernandis.me/2017/03/20/como-hacer-un-makefile.html
# *The rules are usually organized in such as way the more general rules come first.
#rules is tarjet

#target: dependencias-1 dependencia-2 ...   (Si ya existen ejecuta el comando en otro caso  cuando vea que necesita recurrirá a nuevo tarjet hasta encontrar la dependencia)
#	command

#Compile and Link Separately
# Compile-only with -c option
# > g++ -c -Wall -g Hello.cpp 
# Link object file(s) into an executable
# g++ -g -o Hello.exe Hello.o

#Comman curioso
# file file.exe or file file.cpp or file file.o
#Descripte ek tipo de archivo

#Tags:
#	 -v: verbose mode
#	 -c: Compile into object file "Hello.o". Genera un archivo objeto con el mismo nombre de file.c
#    -o: specifies the output executable filename.
#    -Wall: prints "all" Warning messages.
#    -g: generates additional symbolic debuggging information for use with gdb debugg
#	 -02: Optimiza el codigo nivel 2
#	 -pipe; Avoid temporary files, speeding up builds
#@see: https://developers.redhat.com/blog/2018/03/21/compiler-and-linker-flags-gcc/
#@see: https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
#@see: https://www.rapidtables.com/code/linux/gcc/gcc-wall.html


#Automatic Variables
#Automatic variables are set by make after a rule is matched. There include:
#    $@: the target filename.
#    $*: the target filename without the file extension.
#    $<: the first prerequisite filename.
#    $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
#    $+: similar to $^, but includes duplicates.
#    $?: the names of all prerequisites that are newer than the target, separated by spaces.

# The pattern matching character '%' matches filename without the extension
#A pattern rule, which uses pattern matching character '%' as the filename, can be applied to create a target, if there is no explicit rule. 

#Para usar make, si utilza make y anteponiendo una palabra esa palabra la interpretara como
#un target y ejecutara ese tarjet
#	make clean
#Buscara el tarjet clean y ejecutara el commdan (claro si sus depenendias{requsitos} ya esta hechos)
#Un tarjet no repitara dos veces, ya que make tiene el macanismo que una ves que encuentre ese tarjet
#se actualice, dice make que si una tarjet ya esta actulizado no correra(run)

#Si solo se colo make, buscara el archivo makefile, y empecara por el primer tarjet
#	make

#Nosotro podemos definir variables para poder simplicar varios comando reptitivos o que sean 
#muy extensos
#CC=gcc
#CFLAGS=-Wall -g
#Para ver su valor y nombre es mas de caracter se colocar el sigo$(NOMBRE_VARIABLE) si solo es un $C
#$(CC) $(CFLAGS)

#Puedes usar .PHONY para decirle a make que el target u objetivo clean en este caso es ficticio y no debe crear fichero, ya que si por ejemplo hubiese un fichero llamado clean en el directorio del código fuente, entonces no haría nada.
#.PHONY: clean
#clean:
#	rm hello.o helloWorld.out  #Comandos del OS
#EJEMPLO
#PHONY: dist
#dist: clean
#	mkdir para_enviar # creamos una carpeta con lo que se va a enviar
#	cp *.c *.h Makefile memoria.pdf para_enviar/ # copiamos los archivos necesarios
#	zip entrega.zip para_enviar # comprimimos la carpeta
#	rm -rf para_enviar # borramos la carpeta que habiamos creado, ahora ya tenemos el .zip

#Definimos nuestras variables
CC = g++
CFLAGS = -pipe -O2 -std=c++11 -Wall -g 
OBJS = a 
#Una convecion para el primer tarjet es all
#.PHONY: all   (OPCIONAL depende de quieres hacer algo despues de la ejecucion o no, si es asi mejor comentarlo)
#1) Compilacion en solo paso
# Con esta forma se compila y se ejecuta despues, muy buena para no tener que escrimir ./execute
#RECOMENDABLE para emacs
#En esta forma se simplifica mucho, el linkir lo hace automaticamente ya no lo tenemos que hacer
#Primero hace g++ file1 file2 y creas sus objetos file1.o, file2.o y despues hace el enlace en el mismo
#paso haciendo el linker con los files objetc y creando el ejecutable
#----------------------------------------------------------
#all: main
#	./$<
#main:  main.cpp Cube.cpp
#	$(CC) $(CFLAGS) -o main  Cube.cpp main.cpp

#------------------------------------------------------------
#2 Compilando y linker
# all: main

# main: main.o Cube.o 
# 	$(CC) $(CFLAGS) -o main main.o Cube.o

# #Crea main.o
# main.o: main.cpp
# 	$(CC) -c main.cpp

# Cube.o: Cube.cpp
# 	$(CC) -c Cube.cpp

# .PHONY: clear
# clear : 
# 	rm *.o 
#---------------------------------------
#3) Compilando and linker Patter patron (#Automatic Variables)

# all: main

# main: main.o Cube.o 
# 	$(CC) $(CFLAGS) -o $@ $^

# #Crea main.o
# main.o: main.cpp
# 	$(CC) -c $<

# Cube.o: Cube.cpp
# 	$(CC) -c $<

# .PHONY: clear
# clear : 
# 	rm *.o 
# 	echo Clean done

#----------------------------------------------
#4) Compiler linker separate files
# all: main.out

# main.out: main.o Cube.o 
# 	$(CC) $(CFLAGS) -o $@ .objs/main.o .objs/Cube.o

# #Crea main.o
# main.o: main.cpp
# 	$(CC) -c main.cpp -o .objs/main.o

# Cube.o: Cube.cpp
# 	$(CC) -c Cube.cpp -o .objs/$*.o

# .PHONY: clear
# clear : 
# 	rm .objs/*.o 
# 	@echo "eliminate object files"
#----------------------------------
#5) Pattern Rules
OBJS = main.o Cube.o
all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#Aqui dice: cualquier archivo con extension .o
#Entraria main.o y Cube.o y despues se identificaria con main.cpp and Cube.cpp
%.o: %.cpp
	$(CC) -c $<

.PHONY: clear
clear : 
	rm *.o 
	echo Clean done


#@see: https://users.cs.cf.ac.uk/Dave.Marshall/PERL/node79.html

