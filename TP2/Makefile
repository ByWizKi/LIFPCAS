CPP_SRC = mandel.cpp display.cpp main.cpp

LDPATH=-L /opt/X11/lib/
Include = -I /opt/X11/include/
CXX=g++
LDFLAGS= $(Include)  $(LDPATH) -std=c++17 -lX11 -pthread
CFLAGS=-g -O0 -Wall -Wextra

mandel.out: $(CPP_SRC) $(wildcard *.h) $(wildcard *.tpp)
	$(CXX) $(CPP_SRC) $(CFLAGS) $(LDFLAGS) -o $@

clean:
	-$(RM) *.o mandel
