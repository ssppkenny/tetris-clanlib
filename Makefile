EXAMPLE_BIN=tetris
OBJF = tetris.o precomp.o program.o figure.o figurelist.o borderlist.o leftborderlist.o rightborderlist.o bottomborderlist.o
#LIBS=clanApp clanDisplay clanCore clanGL
#LIBS=clanApp clanDisplay clanCore clanGL1
LIBS=clanApp clanDisplay clanCore clanSWRender

include ./Makefile.conf

# EOF #
# test
