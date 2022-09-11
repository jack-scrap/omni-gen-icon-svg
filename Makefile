CXX=g++

.PHONY: clean

all: omni_gen_icon_svg

main.o: main.cpp
	$(CXX) -c $< -o $@

omni_gen_icon_svg: main.o
	$(CXX) $^ -o $@

clean:
	rm *.o omni_gen_icon_svg
