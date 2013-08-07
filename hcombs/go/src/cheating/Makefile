all: build

build: allfive.go
	go build -o allfive

debug: clean allfive.go
	go build -o allfive -gcflags "-N -l"

clean:
	rm -f allfive
