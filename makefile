CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o room.o objectroom.o objectsroom.o boobietrapped.o vaultroom.o gameworld.o gamesetup.o moverooms.o

SRCS = main.cpp Room.cpp ObjectRoom.cpp ObjectsRoom.cpp BoobieTrapped.cpp VaultRoom.cpp GameWorld.cpp GameSetUp.cpp moveRooms.cpp

HEADERS = Room.hpp ObjectRoom.hpp ObjectsRoom.hpp BoobieTrapped.hpp VaultRoom.hpp GameWorld.hpp GameSetUp.hpp moveRooms.hpp

PROGS = main

all: ${PROGS}

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o $@

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${PROGS} *.o


