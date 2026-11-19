
build: ./src/main.c ./src/builtin.c ./src/shell.c ./src/config.c
	cc ./src/main.c -o ./build/eres

run: ./build/eres
	./build/eres

clean:
	rm -f ./build/eres
