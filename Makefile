# test fuer configfile
CC          = g++
CCFLAGS     = -c -Wall -O3 
LDFLAGS     = -lm 
CCFLAGS    += -MD -MP -MT $(*F).o -MF dep/$(@F).d
MY_NAME     = configtest
LIBS        = 
MYOBJECTS   = main.o configfile.o 



all: $(MYOBJECTS) $(MYHEADER) Makefile 
	$(CC) $(MYOBJECTS) $(LIBS) $(LDFLAGS)  -o $(MY_NAME)

.cpp.o: $< $(MYHEADER) Makefile
	 $(CC) $(INCLUDES) $(CCFLAGS) $<

clean:
	rm -rf $(MYOBJECTS) $(MY_NAME) dep/

-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
