TARGET := proyecto
GENERATOR := generador

CXX_FLAGS := -g -O0 -Wall -pedantic
C_FLAGS := -g -O0 -Wall -pedantic

all: $(TARGET)-cpp  $(TARGET)-cpp_exp $(TARGET)-c $(GENERATOR)

$(TARGET)-cpp: main.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $? $(LD_FLAGS)

$(TARGET)-cpp_exp: main_experiments.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $? $(LD_FLAGS)

$(TARGET)-c: main.c
	$(CC) $(C_FLAGS) -o $@ $? $(LD_FLAGS)

$(GENERATOR): generador.cpp
	$(CXX) $(CXX_FLAGS) -o $@ $+ $(LD_FLAGS)

.PHONY: clean measure plot

clean:
	rm $(TARGET)-cpp  $(TARGET)-cpp_exp $(TARGET)-c $(GENERATOR) *.csv

measurelin1:
	./measure.sh 500000 20 lin1 best > lin1best.csv
	./measure.sh 500000 20 lin1 worst > lin1worst.csv
	./measure.sh 500000 20 lin1 random > lin1random.csv

measurelinn:
	./measure.sh 500000 10 linn best > linnbest.csv
	./measure.sh 500000 10 linn worst > linnworst.csv
	./measure.sh 500000 10 linn random > linnrandom.csv

plotlin1:
	./plot.sh lin1best.csv
	./plot.sh lin1worst.csv
	./plot.sh lin1random.csv

plotlinn:
	./plot.sh linnbest.csv
	./plot.sh linnworst.csv
	./plot.sh linnrandom.csv

