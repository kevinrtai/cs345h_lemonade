
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     TOKEN_READSTRING = 258,
     TOKEN_READINT = 259,
     TOKEN_PRINT = 260,
     TOKEN_ISNIL = 261,
     TOKEN_HD = 262,
     TOKEN_TL = 263,
     TOKEN_CONS = 264,
     TOKEN_NIL = 265,
     TOKEN_DOT = 266,
     TOKEN_WITH = 267,
     TOKEN_LET = 268,
     TOKEN_PLUS = 269,
     TOKEN_MINUS = 270,
     TOKEN_IDENTIFIER = 271,
     TOKEN_TIMES = 272,
     TOKEN_DIVIDE = 273,
     TOKEN_INT = 274,
     TOKEN_LPAREN = 275,
     TOKEN_RPAREN = 276,
     TOKEN_AND = 277,
     TOKEN_OR = 278,
     TOKEN_EQ = 279,
     TOKEN_NEQ = 280,
     TOKEN_GT = 281,
     TOKEN_GEQ = 282,
     TOKEN_LT = 283,
     TOKEN_LEQ = 284,
     TOKEN_IF = 285,
     TOKEN_THEN = 286,
     TOKEN_ELSE = 287,
     TOKEN_LAMBDA = 288,
     TOKEN_FUN = 289,
     TOKEN_COMMA = 290,
     TOKEN_STRING = 291,
     TOKEN_ERROR = 292,
     TOKEN_IN = 293,
     EXPR = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


