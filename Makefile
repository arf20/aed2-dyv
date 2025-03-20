TARGET := proyecto
GENERATOR := generator

CXX_FLAGS := -g -O0 -Wall -pedantic

all: $(TARGET) $(GENERATOR)

$(TARGET): main.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $? $(LD_FLAGS)

$(GENERATOR): generador.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $+ $(LD_FLAGS)

