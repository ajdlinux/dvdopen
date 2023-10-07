// dvdopen: a program to unlock your DVD drive
// Andrew Donnellan, 2023, public domain

#include <stdio.h>
#include <dvdcss.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s [path to DVD block device]\n",
			argv[0]);
		return 1;
	}

	dvdcss_t css = dvdcss_open(argv[1]);
	if (!css) {
		fprintf(stderr, "%s: error while opening device\n", argv[0]);
		return 2;
	}

	int rc = dvdcss_close(css);
	if (rc) {
		fprintf(stderr, "%s: error while closing device\n", argv[0]);
		return 3;
	}

	return 0;
}
