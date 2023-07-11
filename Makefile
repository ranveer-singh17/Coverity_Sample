# Project: Project1
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = hangman.o draw.o
LINKOBJ  = hangman.o draw.o
LIBS     = -L"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/lib" -L"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib"
INCS     = -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/include" -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/include" -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"D:/DuongMinhHieu_16020226/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = Project1.exe
CXXFLAGS = $(CXXINCS) -Wall
CFLAGS   = $(INCS) -Wall
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

hangman.o: hangman.cpp
	$(CPP) -c hangman.cpp -o hangman.o $(CXXFLAGS)

draw.o: draw.cpp
	$(CPP) -c draw.cpp -o draw.o $(CXXFLAGS)
