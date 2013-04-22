memkill
-------

memkill is a simple C program that will consume memory at a fixed rate up to a set point. It 
will sit there using the max memory requested until the program is killed (ctrl-c).

### Compiling

Should just require a basic GCC:

    gcc -o memkill memkill.c

### Usage

    memkill <max memory> <duration>
    ./memkill 5800 300

So ./memkill 5800 300 will consume 5.8GB of memory over the next 5 minutes. It will divide up
the memory into chunks, and allocate a chunk every 5 seconds until the maximum is reached.


