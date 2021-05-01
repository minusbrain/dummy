# Dummy executable

Dummy tool - Tell me what to do and I'll do it.

Might be useful for testing of scripts, shells, ...

Support the following use cases, also in combination

* Wait for a given number of seconds with '-s'
* Tunnel stdin to stdout with '-t'
* Print some text to stdout with '-o'
* Print some text to stderr with '-e'
* Define dummys exit code with '-r'

# Build / Install

* Have CMake >3.11 and C++11 compatible compiler
* Clone repo
* Take the follwoing steps
```shell
cd dummy
mkdir _build
cd _build
cmake ..
make
make install     # Might require sudo
```

# Example

```shell
minusbrain$ echo -n "In" | dummy -t -o Bla -e Blub -r 1 2> test
InBla
minusbrain$ echo $?
1
minusbrain$ cat test
Blub
```

Have fun!
