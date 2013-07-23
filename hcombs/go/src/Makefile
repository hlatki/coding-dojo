all: build test

build: main.go datamodel.go ranking.go
	go build -o poker

test: build
	./bowl_test.sh

clean:
	rm -f poker
