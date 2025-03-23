TEST_LOG = testlog.txt

binary_min_heap: binary_min_heap.h binary_min_heap.cpp
	@g++ -c binary_min_heap.cpp 
	
demo: binary_min_heap.o demo.cpp
	@g++ $^ -o demo.exe
	@demo.exe
	
run_tests:
	@echo > $(TEST_LOG)
	@test.exe > $(TEST_LOG)
	
test: binary_min_heap.o test.cpp
	@g++ $^ -o test.exe
	@$(MAKE) run_tests

clean:
	@del -f *.o *.exe
	
all: binary_min_heap demo test

rebuild: clean all