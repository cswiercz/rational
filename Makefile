#
# Makefile Template
# =================
#
# Will use all CPP files for source. Special files include
#   test/test.cpp - entry point for tests
#   bin/runner      - primary executable produced from /src
#
#
CC       := clang++
SRCDIR   := src
LIBDIR   := lib
INCDIR   := include
BINDIR   := bin
BUILDDIR := build
TARGET   := #lib/librational.so
TARGETNAME := #rational

SRCEXT   := cpp
SOURCES  := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS   := -std=c++11 -stdlib=libc++ -g -Wall -fPIC
LFLAGS   := -stdlib=libc++ -shared
LIB      :=
INC      := -I$(INCDIR)

# link the tester to the library output
TESTLIB    := #-l$(TARGETNAME) -L $(LIBDIR)
TESTINC    := -I $(INCDIR)
TESTCFLAGS := -std=c++11 -g -Wall
TESTSRCDIR   := test
TESTSOURCES  := $(shell find $(TESTSRCDIR) -type f -name *.$(SRCEXT))
TESTOBJECTS  := $(patsubst $(TESTSRCDIR)/%,$(TESTSRCDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

RM := rm

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $(LFLAGS) $(LIB) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

all: $(TARGET) test

clean:
	@echo "Cleaning..."
	$(RM) -rf $(BUILDDIR) $(LIBDIR)/* $(BINDIR)/*
	find . -name "*~" -type f -delete

tester: $(TESTOBJECTS)
	$(CC) $(TESTCFLAGS) test/test.cpp $(TESTINC) $(TESTLIB) -o bin/tester

.PHONY: clean
