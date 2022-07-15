# target: dependencies
# TAB	action
# -c no exec file needed outputs .o file

output: test graph
	g++ test.o graph.o -o test.out

test:
	g++ -c test.cpp

graph: graph.cpp graph.h
	g++ -c graph.cpp

clean:
	rm *.o *.out