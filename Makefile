OBJECTS=date.o original.o resort.o output.o accratioresultreader.o accratio.o main.o

app: date.o original.o resort.o output.o accratioresultreader.o accratio.o main.o
	g++ -g3 -o $@ $^

all: $(OBJECTS)
$(OBJECTS):%.o: %.cpp
	g++ -g3 -c -o $@ $<

