</$objtype/mkfile

RC=/rc/bin
BIN=/$objtype/bin
MAN=/sys/man

tree:
	$CC $CFLAGS tree.c
	$LD $LDFLAGS -o tree tree.$O

install:V:
	mv tree $BIN/
	cp man/1/tree $MAN/1/

uninstall:V:
	rm -f $BIN/tree
	rm -f $MAN/1/tree

