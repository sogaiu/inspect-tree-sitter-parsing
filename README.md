# Using `rr` (or `gdb`) to Examine Tree-Sitter Parsing in Detail

This repository has some code and instructions on how one might
examine tree-sitter parsing in some detail using `rr` (or `gdb`) [1].

The example files are for a grammar that has an external scanner.

## Requirements

* Some kind of Linux environment if using `rr`
* `rr` (or `gdb` if you're really patient or good at not making
  mistakes)
* C compiler

## Sample Session for `rr`

```
# build executable
sh build.sh

# find out what the current level is -- want to end up with 1 for rr
sysctl kernel.perf_event_paranoid

# set to 1 if needed for `rr` use -- reset when done (see below for details)
sudo sysctl kernel.perf_event_paranoid=1

# record executable running
rr record ./sample

# replay, if from terminal [2]
rr replay

# set some breakpoints from within debugger
b tree-sitter/lib/src/parser.c:ts_parser_parse
b tree-sitter-janet-simple/src/scanner.c:tree_sitter_janet_simple_external_scanner_scan

# use debugger as usual, `continue`, `reverse-next`, etc.

# when done, restore to whatever was shown initially
sudo sysctl kernel.perf_event_paranoid=2
```

## Sample Session for `gdb`

```
# build executable
sh build.sh

# run gdb
gdb ./sample

# set some breakpoints from within debugger
b tree-sitter/lib/src/parser.c:ts_parser_parse
b tree-sitter-janet-simple/src/scanner.c:tree_sitter_janet_simple_external_scanner_scan

# use debugger as usual, `continue`, `next`, etc.
```

## Footnotes

[1] Likely the instructions for use with `gdb` can be modified to work
    with `lldb`.

[2] from within emacs:

  1. `M-x gdb RET`
  2. At the resulting prompt: `rr replay -i=mi`
  3. If desired, `M-x gdb-many-windows`

