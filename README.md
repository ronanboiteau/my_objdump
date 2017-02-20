# my_objdump

A command-line tool that reproduces the behavior of [`objdump`](https://en.wikipedia.org/wiki/Objdump) with the `-fs` options.

## Requirements

 - [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## Compilation

Navigate to the root of the repository from your Terminal and run `make` to build the `my_objdump` executable file.

## How to use my_objdump?

`my_objdump` works like GNU Binutils's [objdump](https://en.wikipedia.org/wiki/Objdump). However `my_objdump` only reproduces objdump's standard behavior, it does not support any option.

To analyze a binary file, pass it to `my_objdump` as argument.

As an example, if you have the `my_objdump` executable file & a `a.out` binary file in your current shell working directory, use this command to analyze `a.out` with `my_objdump`:
```
./my_objdump a.out
```
