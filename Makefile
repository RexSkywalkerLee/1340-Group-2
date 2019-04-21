otherFunctions.o: otherFunctions.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
accountsManipulation.o: accountsManipulation.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
recordsManipulation.o: recordsManipulation.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
main.o: main.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
main: main.o otherFunctions.o recordsManipulation.o accountsManipulation.o
	g++ $^ -o $@
clean:
	rm *.o main
erase:
	rm *.txt
.PHONY: clean erase
