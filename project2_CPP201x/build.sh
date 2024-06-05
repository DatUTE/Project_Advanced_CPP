aclocal && 
automake --add-missing && 
autoreconf -fi && 
automake && 
./configure && 
make