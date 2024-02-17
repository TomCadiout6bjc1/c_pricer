# C++ commands
# ============
# Build the whole cmake project
build:
	cmake . -B build_/
	make -C build_/.

execute_test: build
	(cd build_/; ./run)

clean:
	rm -rf build_/



