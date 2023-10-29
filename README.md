# Scanner & Parser Using Flex and Bison

### For generating the scanner, run:
`flex --header-file=scanner.h -o scanner.c scanner.l`

### For generating the parser, run:
`bison -dvo parser.c parser.y`