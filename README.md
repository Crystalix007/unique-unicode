# Unique Unicode

Prints only the first instance of each unicode character.

## Building

Requires:
* [utf8-cpp](http://utfcpp.sourceforge.net/) for UTF-8 parsing
* [tup](http://gittup.org/tup/) for building, or use the included build script

`tup init && tup`

*or*

`./build.sh`

## Running

```
> ./unique <<< "Some unicode text\n"
Some unicdtx
```

```
> cat a.file | ./unique
...
```
