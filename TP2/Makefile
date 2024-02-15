CPP_SRC = mandel.cpp display.cpp main.cpp

LDPATH=-L /opt/X11/lib

CXX=g++
LDFLAGS=$(LDPATH) -lX11 -std=c++11 -pthread
CFLAGS=-g -O0 -Wall -Wextra

mandel.out: $(CPP_SRC) $(wildcard *.h) $(wildcard *.tpp)
	$(CXX) $(CPP_SRC) -I/opt/X11/include $(CFLAGS) $(LDFLAGS) -o $@

clean:
	-$(RM) *.o mandel.out
