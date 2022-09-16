# bin2hex

Convert bin file to header file(.h)

1. Compile and build

$ gcc -o bin2hex bin2hex.c
    
2. Generate a DTB from a DTS

$ dtc -O dtb -o xxxxx.dtb xxxxx.dts
    
3. Generate Header file from a DTB.

$ ./bin2hex xxxxx.dtb
