app: original.o resort.o output.o main.o
	g++ -g3 -o $@ $^
