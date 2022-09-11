CXX=g++

all: omni_gen_icon_svg

main.o: main.cpp
	$(CXX) -c $< -o $@

omni_gen_icon_svg: main.o
	$(CXX) $^ -o $@

.PHONY: clean
clean:
	rm *.o omni_gen_icon_svg
