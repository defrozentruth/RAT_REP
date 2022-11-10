all: main

main: *.o
	g++ *.o -o main

*.o: *.hpp
	g++ -c *.cpp -Imodules

clean: 
	rm -f *.o
