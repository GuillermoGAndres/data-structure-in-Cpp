#Basic compile hello

#No exit any command therebefore it do nothing
all: helloWorld.out
	
helloWorld.out: hello.o
	gcc -o helloWorld.out hello.o

# -c es para crear un objeto con el mismo nombre el archivo no es necesario especificarlo
#gcc -c hello.o hello.c	
hello.o: hello.c 
	gcc -c hello.c	

.PHONY: clean
clear:
	rm hello.o helloWorld.out

#target: pre-req-1 pre-req-2 ...
#	command

#The target and pre-requisites are separated by a colon (:). The command must be preceded by a tab (NOT spaces).

#When make is asked to evaluate a rule, it begins by finding the files in the prerequisites. If any of the prerequisites has an associated rule, make attempts to update those first.

#In the above example, the rule "all" has a pre-requisite "hello.exe". make cannot find the file "hello.exe", so it looks for a rule to create it. The rule "hello.exe" has a pre-requisite "hello.o". Again, it does not exist, so make looks for a rule to create it. The rule "hello.o" has a pre-requisite "hello.c". make checks that "hello.c" exists and it is newer than the target (which does not exist). It runs the command "gcc -c hello.c". The rule "hello.exe" then run its command "gcc -o hello.exe hello.o". Finally, the rule "all" does nothing.

#More importantly, if the pre-requisite is not newer than than target, the command will not be run. #In other words, the command will be run only if the target is out-dated compared with its #pre-requisite. For example, if we re-run the make command: