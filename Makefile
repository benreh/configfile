#	Copyright 2010 Benjamin Reh <ich@benjaminreh.de>
#
#	This file is part of 'configfile'.
#
#    'configfile' is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation version 3 of the License.
#
#    'configfile' is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

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
