SH=/bin/bash

EXEC=omni_gen_icon_svg

CXX=g++

BUILDDIR=build

all: mk_build $(EXEC)

$(BUILDDIR)/main.o: main.cpp
	$(CXX) -c $< -o $@

$(EXEC): $(BUILDDIR)/main.o
	$(CXX) $^ -o $@

.PHONY: mk_build
mk_build:
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o $(EXEC)
