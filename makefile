all:
	x86_64-w64-mingw32-g++.exe -static cpu.cpp -o cpu.exe
	x86_64-w64-mingw32-g++.exe -static assembler.cpp -o assembler.exe
cpu:
	x86_64-w64-mingw32-g++.exe -static cpu.cpp -o cpu.exe
assembler:
	x86_64-w64-mingw32-g++.exe -static assembler.cpp -o assembler.exe