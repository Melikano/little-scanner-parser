/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     R_ANGLE = 258,
     L_ANGLE = 259,
     ARRAY = 260,
     INT = 261,
     BOOL = 262,
     EQ = 263,
     COLON = 264,
     ID = 265,
     PLUS = 266,
     MINUS = 267,
     ERROR = 268,
     NUM = 269,
     DIV = 270,
     MULT = 271,
     O_PAREN = 272,
     C_PAREN = 273,
     SEMICOLON = 274
   };
#endif
/* Tokens.  */
#define R_ANGLE 258
#define L_ANGLE 259
#define ARRAY 260
#define INT 261
#define BOOL 262
#define EQ 263
#define COLON 264
#define ID 265
#define PLUS 266
#define MINUS 267
#define ERROR 268
#define NUM 269
#define DIV 270
#define MULT 271
#define O_PAREN 272
#define C_PAREN 273
#define SEMICOLON 274




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parser.y"
{
    struct decl *decl;
    struct expr *expr;
    struct type *type;
    char *id;
    int num;
}
/* Line 1529 of yacc.c.  */
#line 95 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

