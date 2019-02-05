CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-return-type -pedantic-errors -g

SRCS = main.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Zoo.cpp menu.cpp
OBJS = ${SRCS: .cpp = .o}
HEADERS = Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Zoo.hpp menu.hpp

MAIN = tycoon

all: ${MAIN}
	@echo sucessfully compiled!

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
