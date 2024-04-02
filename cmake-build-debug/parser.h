/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_EVAN_CLIONPROJECTS_GODPILER_CMAKE_BUILD_DEBUG_PARSER_H_INCLUDED
# define YY_YY_HOME_EVAN_CLIONPROJECTS_GODPILER_CMAKE_BUILD_DEBUG_PARSER_H_INCLUDED
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
    KW_BOOLEAN = 258,
    KW_CLASS = 259,
    KW_FALSE = 260,
    KW_INT = 261,
    MAIN = 262,
    KW_PUBLIC = 263,
    KW_PRIVATE = 264,
    KW_TRUE = 265,
    KW_VOID = 266,
    KW_STATIC = 267,
    KW_STRING = 268,
    SYSTEM_OUT_PRINT = 269,
    SYSTEM_OUT_PRINTLN = 270,
    INTEGER_PARSEINT = 271,
    KW_IF = 272,
    KW_ELSE = 273,
    KW_WHILE = 274,
    KW_RETURN = 275,
    KW_LENGTH = 276,
    KW_NEW = 277,
    KW_SHORTCIRCUITOR = 278,
    KW_SHORTCIRCUITAND = 279,
    KW_COMPARISONEQUALS = 280,
    KW_GREATERTHANEQUALS = 281,
    KW_LESSTHANEQUALS = 282,
    KW_NOTEQUALS = 283,
    KW_OPEN_BRACE = 284,
    KW_OPEN_PAREN = 285,
    KW_SEMICOLON = 286,
    KW_EQUALS = 287,
    INTEGER_LITERAL = 288,
    STRING_LITERAL = 289,
    ID = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"

    struct ASTNode* node;
    int integer;
    char * string;

#line 99 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_EVAN_CLIONPROJECTS_GODPILER_CMAKE_BUILD_DEBUG_PARSER_H_INCLUDED  */
