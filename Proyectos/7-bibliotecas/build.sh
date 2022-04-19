# Estática
gcc -c  encrypt.c -o encrypt.o
gcc -c  checksum.c -o checksum.o
ar -rcs libcrypt.a encrypt.o checksum.o
gcc test_code.c -L. -lcrypt -o test_code


# Dinámica
gcc -c  encrypt.c -o encrypt.o
gcc -c  checksum.c -o checksum.o
gcc -shared encrypt.o checksum.o -o crypt.dll
gcc -c test_code.c -o test_code.o
gcc test_code.o -L. -lcrypt -o test_code