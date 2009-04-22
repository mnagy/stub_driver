.PHONY: all clean

NAME = stub_driver.so.1.0.0
SONAME = stub_driver.so.1

OBJS = stub_driver.o

CFLAGS = -Wall -Wextra -pedantic -std=c99 -fPIC `isc-config.sh --cflags dns`

all: $(NAME)

clean:
	rm -f $(NAME) *.o

$(NAME): $(OBJS)
	$(CC) `isc-config.sh --libs dns` -shared -Wl,-soname,$(SONAME) $+ -o $@
