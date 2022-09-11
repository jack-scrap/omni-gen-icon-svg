SH=/bin/bash

CXX=g++

BUILDDIR=build

all: mk_build omni_gen_icon_svg

$(BUILDDIR)/main.o: main.cpp
	$(CXX) -c $< -o $@

omni_gen_icon_svg: $(BUILDDIR)/main.o
	$(CXX) $^ -o $@

.PHONY: mk_build
mk_build:
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o omni_gen_icon_svg
