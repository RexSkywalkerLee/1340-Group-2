otherFunctions.o: otherFunctions.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
accounts.o: accounts.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
records.o: records.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
budget.o: budget.cpp head.h
	g++ -pedantic-errors -std=c++11 -c $<
report.o: report.cpp head.h
	g++ -pedantic-errors -std=c++11 -c $<
main.o: main.cpp head.h 
	g++ -pedantic-errors -std=c++11 -c $<
main: main.o otherFunctions.o records.o accounts.o budget.o report.o
	g++ $^ -o $@
clean:
	rm *.o main
erase:
	rm *.txt
.PHONY: clean erase
