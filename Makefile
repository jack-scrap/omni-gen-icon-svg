SH=/bin/bash

EXEC=omni_gen_icon_svg

CXX=g++

BUILDDIR=build

all: mk_build mk_o $(EXEC)

$(BUILDDIR)/main.o: main.cpp
	$(CXX) -c $< -o $@

$(EXEC): $(BUILDDIR)/main.o
	$(CXX) $^ -o $@

.PHONY: mk_build
mk_build:
	mkdir -p $(BUILDDIR)

.PHONY: mk_o
mk_o:
	mkdir -p o

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o $(EXEC)
