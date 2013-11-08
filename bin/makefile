GCC_FLAGS=-std=c++11 $(FL)

MAIN_NAME=text2list
LIB_PATH=../lib
objects = $(LIB_PATH)/WordAggregator.o \
		  $(LIB_PATH)/Exceptions.o

$(MAIN_NAME): $(MAIN_NAME).o $(objects)
	g++ $(GCC_FLAGS) -o $(MAIN_NAME) $(MAIN_NAME).o $(objects)

all: $(objects)
$(objects): %.o: %.cc %.h
	g++ -c  $< -o $@


.PHONY: clean
clean:
	rm -f *.o $(MAIN_NAME)
	rm -f $(LIB_PATH)/*.o 


