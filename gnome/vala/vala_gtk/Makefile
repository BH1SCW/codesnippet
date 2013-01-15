CC = valac
CFLAGS = --pkg gtk+-3.0 

all:

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@


SOURCES = $(wildcard *.vala )
OBJS = $(patsubst %.vala,%,$(SOURCES))

$(OBJS) : % : %.vala
	$(CC) $(CFLAGS) -o $@ $<

all : $(OBJS)

clean:
#	@echo $(OBJS)
	rm -f $(OBJS)
