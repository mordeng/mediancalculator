compile: 
	make -C ./src
all:
	make -C ./src
	make -C ./tests 
clean:
	make -C ./src clean
	make -C ./tests clean
test:
	make -C ./tests test
run:
	make -C ./src run