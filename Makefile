CC=$(CROSS_COMPILE)gcc
LIBS=-ldvdcss `pkg-config --cflags libdvdcss`

%.o: %.c
	$(CC) -c -o $@ $< $(LIBS) $(CFLAGS)

all: dvdopen

dvdopen: dvdopen.o
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)

clean:
	rm -f dvdopen dvdopen.o

install: dvdopen
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 dvdopen $(DESTDIR)$(PREFIX)/bin