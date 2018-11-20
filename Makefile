# Root Makefile for Quad Solver
VERSION = 1.0
PROGRAM_NAME = quad-solver
FILE_LIST = \
	LICENSE \
	Makefile \
	readme.md \
	documents \
	src \
	tests \
	spikes \
	stories

.PHONY: build distribute test clean

default: build

distribute:
	make -C src clean
	make -C tests clean
	rm -rf $(PROGRAM_NAME)-$(VERSION)
	mkdir -p $(PROGRAM_NAME)-$(VERSION)
	cp -R $(FILE_LIST) $(PROGRAM_NAME)-$(VERSION)
	tar cf - $(PROGRAM_NAME)-$(VERSION) | gzip -9c > $(PROGRAM_NAME)-$(VERSION).tar.gz
	rm -rf $(PROGRAM_NAME)-$(VERSION)

build:
	make -C src
	@echo "Binary created at src/quad_solver"

test:
	make -C src
	make -C tests

clean:
	make -C src clean
	make -C tests clean
	rm -rf $(PROGRAM_NAME)-$(VERSION).tar.gz