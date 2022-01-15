CXX=g++
CXXFLAGS=-Wall -g -std=c++2a
LDFLAGS=-lmingw32 -lSDL2main -lSDL2

SRC=src
OBJ=obj
BINDIR=bin

SRCS=$(wildcard $(SRC)/*.cc)
OBJS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SRCS))
DEPENDS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.d, $(SRCS))

BIN=$(BINDIR)/Entities.exe

.PHONY: all run clean release

all: $(BIN)

run: all
	./$(BIN)

release: clean
release: CXXFLAGS=-Wall -O2 -DNDEBUG -std=c++2a -mwindows -static-libgcc -static-libstdc++
release: all

-include $(DEPENDS)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX) $(CXXFLAGS) -I include -c -MMD -MP -o $@ $<

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)/*.o $(OBJ)/*.d $(BINDIR)/*.exe