How to build and run:
C1:
    - aclocal
    - automake --add-missing
    - autoreconf -fi
    - automake

    - ./configure
    - make
    - ./main
C2: 
    . build.sh