CC = g++
FLAG = -std=c++11 -c -Wall -O3

all: read ini exp metho bnd gss fin
	$(CC) *.o -o _convection
read:
	$(CC) $(FLAG) read.cpp
ini:
	$(CC) $(FLAG) initialize.cpp 
exp:
	$(CC) $(FLAG) export.cpp
metho:
	$(CC) $(FLAG) method.cpp
bnd:
	$(CC) $(FLAG) boundary.cpp
gss:
	$(CC) $(FLAG) gauss.cpp
fin:
	$(CC) $(FLAG) convection.cpp
clean:
	rm *.o