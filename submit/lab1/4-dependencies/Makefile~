CXX = g++
CXXFLAGS = -g -Wall -std=c++17

OFILES = \
  fns-compare.o \
  constant.o \
  lg.o \
  linear.o \
  nlg.o \
  quadratic.o \
  cubic.o \
  exponential.o \
  fact.o

TARGET = fns-compare

all:		$(TARGET)

$(TARGET):	$(OFILES)
 		$(CXX) $(OFILES) -o $@

.phony:		clean
clean:
		rm -f *~ *.o $(TARGET)


#dependencies
fns-compare.o:	fns-compare.cc fns-compare.hh
constant.o:	constant.cc fns-compare.hh
lg.o:		lg.cc fns-compare.hh
linear.o:	linear.cc fns-compare.hh
nlg.o:		nlg.cc fns-compare.hh
quadratic.o:	quadratic.cc fns-compare.hh
cubic.o:	cubic.cc fns-compare.hh
exponential.o:	exponential.cc fns-compare.hh
fact.o:		fact.cc fns-compare.hh
