/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    TOKEN_LBRACKET = 277,
    TOKEN_RBRACKET = 278,
    TOKEN_LCURLY = 279,
    TOKEN_RCURLY = 280,
    TOKEN_AND = 281,
    TOKEN_OR = 282,
    TOKEN_EQ = 283,
    TOKEN_NEQ = 284,
    TOKEN_GT = 285,
    TOKEN_GEQ = 286,
    TOKEN_LT = 287,
    TOKEN_LEQ = 288,
    TOKEN_IF = 289,
    TOKEN_THEN = 290,
    TOKEN_ELSE = 291,
    TOKEN_LAMBDA = 292,
    TOKEN_FUN = 293,
    TOKEN_COMMA = 294,
    TOKEN_STRING = 295,
    TOKEN_ERROR = 296,
    TOKEN_IN = 297,
    TOKEN_FLOAT = 298,
    TOKEN_LEN = 299,
    TOKEN_DEL = 300,
    TOKEN_COLON = 301,
    TOKEN_LIBCALL = 302,
    EXPR = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
