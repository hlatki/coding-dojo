all: build

build: allfive.go arrays.go fast_eval.go poker.go pokerlib.go
	go build -o allfive

debug: clean allfive.go arrays.go fast_eval.go poker.go pokerlib.go
	go build -o allfive -gcflags "-N -l"

clean:
	rm -f allfive
