all: main

main: *.o
	g++ main.o game.o controller.o field_view.o player.o cell.o field.o mediator.o -o main

*.o: *.hpp
	g++ -c *.cpp -Imodules

clean: 
	rm -f *.o
