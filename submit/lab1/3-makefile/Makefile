#define C++ compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

#define object files to be produces
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
