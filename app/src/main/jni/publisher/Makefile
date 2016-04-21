# Makefile

ONTOLOGY_SOURCE := ../hello.c
ONTOLOGY_HEADER := ../hello.h
ONTOLOGY_OBJECT := ../hello.o

pkg_packages := smartslog ckpi

PKG_CFLAGS  := $(shell pkg-config --cflags $(pkg_packages))
PKG_LDFLAGS := $(shell pkg-config --libs $(pkg_packages))

INCLUDES :=
LIBS :=

CC    := gcc

DEBUG := -g
EXTRA_FLAGS :=
EXTRA_OPTION := -std=c99

CFLAGS := -c $(DEBUG) $(INCLUDES) $(PKG_CFLAGS) $(EXTRA_FLAGS)
LFLAGS := $(DEBUG) $(PKG_LDFLAGS) $(LIBS)

PROGRAM_NAME := publisher

targets = main

o_files :=  ./publisher_kp.o \
		    $(ONTOLOGY_OBJECT)

.PHONY: all
all : $(targets)

main: $(o_files)
	$(CC) $(o_files) -o $(PROGRAM_NAME) $(EXTRA_OPTION) $(LFLAGS)

.c.o:
	$(CC) $(EXTRA_OPTION) $(CFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -f *.o
	rm -f $(PROGRAM_NAME)

