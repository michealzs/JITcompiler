# JITcompiler

An interpreter for the small teaching language used in the UMGC CMSC 430
(Compiler Theory and Design) projects, built with flex and bison (project 3).
It reads one function from standard input and evaluates it while parsing:
each bison grammar action computes the value of its part of the program, so
there is no syntax tree and no code generation. Despite the repository name,
nothing is compiled to machine code. All values are held as C++ `double`.

The language is one function with an optional parameter list (`integer`,
`real` or `character`), optional variable declarations (scalars, and
`list of` lists written as `(1, 2, 3)`), and a `begin ... end` body holding
one statement. Statements are plain expressions, `when` conditional
expressions, `if / elsif / else / endif`, `switch / case / others /
endswitch`, and `fold left|right <operator> <list> endfold`, where `<list>` is a
literal list or a list variable name, which reduces the
list with an arithmetic operator. Expressions use `+ - * / % ^` and `~`
(negate), the relational operators `< <= = <> >= >`, and the logical
operators `& | !`. Literals are integers, reals, quoted characters and
`#hex`. `name(i)` reads element `i` of a list variable. Comments start with
`//` or `--`.

## Build

Requires `flex`, `bison` 3.x, `g++` and `make`. The grammar uses `%empty` and
`%define parse.error verbose`, which Bison 2.x rejects (macOS ships Bison
2.3, so install a newer one there).

The repository also contains the generated `scanner.c`, `parser.c`,
`parser.tab.h`, `tokens.h` and `parser.output`, the object files, and a
Linux x86-64 `compile` binary from an earlier build. To rebuild everything
from the `.l` and `.y` sources regardless of those files:

```sh
make -B
```

`make` on its own may treat the committed outputs as up to date and skip
regeneration, depending on file timestamps after checkout.

## Run

```sh
./compile 3 4 < program.txt
```

Command-line arguments are converted with `atof` and bound, in order, to the
function's parameters. The program listing goes to standard output with line
numbers; if there are no errors it ends with `Compiled Successfully` and
`Result = <value>`, otherwise with a count of lexical, syntax and semantic
errors. Undeclared identifiers are reported as semantic errors. The hex
literal rule also prints the converted value to standard output (a debug
print left in `scanner.l`).

## Layout

- `parser.y` - bison grammar with evaluation actions, the scalar and list
  symbol tables, and `main()`
- `parser2.y` - an older, simpler version of the grammar; not built by the
  makefile
- `scanner.l` - flex rules; fills `yylval` for literals, identifiers and
  operators
- `values.h`, `values.cc` - the `Operators` enum, `evaluateArithmetic`,
  `evaluateRelational`, `fold_left` and `fold_right`
- `symbols.h` - `Symbols<T>`, a `map`-based symbol table template
- `listing.h`, `listing.cc` - line-numbered listing output and error counting
- `tokens.h` - copied from bison's `parser.tab.h` by the makefile
- `makefile` - build rules
- `note.txt` - a one-line cleanup command
- `scanner.c`, `parser.c`, `parser.tab.h`, `parser.output`, `*.o`,
  `compile` - generated output committed from a previous Linux build

Status: coursework project, kept for reference.
