TARGET := proyecto
GENERATOR := generador

CXX_FLAGS := -g -O0 -Wall -pedantic
C_FLAGS := -g -O0 -Wall -pedantic

all: $(TARGET)-cpp $(TARGET)-c $(GENERATOR)

$(TARGET)-cpp: main.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $? $(LD_FLAGS)

$(TARGET)-c: main.c
	$(CC) $(C_FLAGS) -o $@ $? $(LD_FLAGS)

$(GENERATOR): generador.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $+ $(LD_FLAGS)

