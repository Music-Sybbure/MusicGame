CC = g++
LDFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lxml2
CFLAGS = -std=c++11 -Wall -I/usr/include/libxml2



EXE = musictomyears.out
SRCDIR = src
OBJDIR = obj

SOURCES=$(wildcard $(SRCDIR)/*.cc)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc $(SRCDIR)/%.h
	$(CC) -c $(CFLAGS) $< -o $@ 

clean:
	rm $(OBJDIR)/*.o

test:
	./musictomyears.out
