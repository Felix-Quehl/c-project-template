all:

release: lib test exe
debug: lib test exe

.PHONY: lib test exe clean

lib:
	cd lib && make $(MAKECMDGOALS)

exe:
	cd exe && make $(MAKECMDGOALS)

test:
	cd test && make $(MAKECMDGOALS)

clean:
	cd lib && make $(MAKECMDGOALS)
	cd test && make $(MAKECMDGOALS)
	cd exe && make $(MAKECMDGOALS)

