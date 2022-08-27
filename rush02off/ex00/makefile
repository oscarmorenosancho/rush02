all: prog.exe
main.o: main.c
	gcc -Wall -c main.c
ft_str.o: ft_str.c
	gcc -Wall -c ft_str.c
prog.exe: main.o ft_str.o
	gcc -Wall main.o ft_str.o -o prog.exe
clean:
	rm main.o
	rm ft_str.o
fclean: clean
	rm prog.exe 
