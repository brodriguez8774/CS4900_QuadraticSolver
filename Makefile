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


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: build distribute test clean

# Default command if nothing is passed.
default: build


# Build and zip up project into tar file.
distribute:
	make -C src clean
	make -C tests clean
	rm -rf $(PROGRAM_NAME)-$(VERSION)
	mkdir -p $(PROGRAM_NAME)-$(VERSION)
	cp -R $(FILE_LIST) $(PROGRAM_NAME)-$(VERSION)
	tar cf - $(PROGRAM_NAME)-$(VERSION) | gzip -9c > $(PROGRAM_NAME)-$(VERSION).tar.gz
	rm -rf $(PROGRAM_NAME)-$(VERSION)

# Build project in src directory.
build:
	make -C src
	@echo "Binary created at src/quad_solver"

# Run all program tests.
test:
	make -C src
	make -C tests


# Remove older builds and clear temp files.
clean:
	make -C src clean
	make -C tests clean
	rm -rf $(PROGRAM_NAME)-$(VERSION).tar.gz
