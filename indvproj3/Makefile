ifeq ($(OS),Windows_NT)
    RM = del
    EXE = .exe
    RUN = demo.exe
	RUN_TEST = test.exe
else
    RM = rm -f
    EXE =
    RUN = ./demo
	RUN_TEST = ./test
endif

all: demo run_tests

baseInvoice: base_invoice.cpp
	@g++ -c $^ -o base_invoice.o

dicountInvoice: discount_invoice.cpp
	@g++ -c $^ -o discount_invoice.o

vatInvoice: vat_invoice.cpp
	@g++ -c $^ -o vat_invoice.o

nameInvoice: name_invoice.cpp
	@g++ -c $^ -o name_invoice.o

demo: base_invoice.o discount_invoice.o vat_invoice.o demo.cpp
	@g++ $^ -o demo$(EXE)
	@$(RUN)

test: base_invoice.o name_invoice.o test.cpp
	@g++ $^ -o test$(EXE)

run_tests: test
	$(RUN_TEST)

clean:
	@$(RM) *.o demo$(EXE) test$(EXE)

rebuild: clean all