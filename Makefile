all:
	@test -s build || { mkdir -p build && cd build && cmake ..; }
	@cd build && $(MAKE)

run:
	@test -s build || { mkdir -p build && cd build && cmake ..; }
	@cd build && $(MAKE)

	cd build && Sandbox/Sandbox

test:
	@test -s build || { mkdir -p build && cd build && cmake ..; }
	@cd build && $(MAKE)

	cd build && Tests/Tests
