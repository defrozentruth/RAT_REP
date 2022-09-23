all: main

main: *.o
		g++ main.o execute.o controller.o fieldview.o player.o cell.o field.o -o main

*.o:
		g++ -c *.cpp -Imodules

clean: 
		rm -f *.o

cleanAll: clean
	rm -f main