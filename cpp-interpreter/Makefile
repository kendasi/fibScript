# fibscript interpreter

include config.mk

SRC = fibscript.cpp
OBJ = ${SRC:.cpp=.o}

all: fibscript

.cpp.o:
	${CXX} -c ${CXXFLAGS} $<

${OBJ}: config.mk

fibscript: ${OBJ}
	${CXX} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f fibscript ${OBJ}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f fibscript ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/fibscript

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/fibscript

.PHONY: all clean install uninstall
