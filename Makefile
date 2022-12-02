CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTFLAGS = -DTEST_READ -DPRINT_BEST
GCC = gcc $(CFLAGS) $(TESTFLAGS)
EXEC = main
OBJS =  main.o readfiles.o printbest.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) main.h
	$(GCC) $(OBJS) -o $(EXEC) 

test: $(EXEC)
	./$(EXEC) testcases/car1 testcases/input1 output1
	./$(EXEC) testcases/car2 testcases/input2 output2
	./$(EXEC) testcases/car3 testcases/input3 output3

diff: $(EXEC)
	diff -w output1 expected/expected1
	diff -w output2 expected/expected2
	diff -w output3 expected/expected3

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/car1 testcases/input1 output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/car2 testcases/input2 output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/car3 testcases/input3 output3

%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output? log?
