</$objtype/mkfile

run:
    $CC $CFLAGS tree.c
    $LD $LDFLAGS -o tree tree.$O
