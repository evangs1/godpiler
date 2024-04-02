// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 5 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"

#define YYDEBUG 0
#include <stdio.h>
#include <string.h>

#include "../ASTNode/FunctionASTNode.h"

void yyerror(char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;


#line 58 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"


#include "parser.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 135 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 56: // MainMethod
      case 63: // StaticMethodDecl
        value.YY_MOVE_OR_COPY< FunctionASTNode > (YY_MOVE (that.value));
        break;

      case 64: // StaticMethodDeclStar
        value.YY_MOVE_OR_COPY< function_list > (YY_MOVE (that.value));
        break;

      case 33: // INTEGER_LITERAL
        value.YY_MOVE_OR_COPY< integer > (YY_MOVE (that.value));
        break;

      case 54: // Program
      case 55: // MainClass
      case 57: // VarDecl
      case 58: // StaticVarDecl
      case 59: // OptionalExp
      case 60: // MoreStaticVarDecl
      case 61: // MoreVarDecl
      case 62: // StaticVarDeclStar
      case 66: // FormalList
      case 67: // FormalListTail
      case 68: // PrimeType
      case 69: // Type
      case 72: // LeftValue
      case 73: // MethodCall
      case 74: // Exp
      case 75: // ExpOr
      case 76: // ExpAnd
      case 77: // ExpEq
      case 78: // ExpLessMore
      case 79: // ExpAdd
      case 80: // ExpMult
      case 81: // Factor
        value.YY_MOVE_OR_COPY< node > (YY_MOVE (that.value));
        break;

      case 71: // Statements
        value.YY_MOVE_OR_COPY< statements > (YY_MOVE (that.value));
        break;

      case 70: // Statement
        value.YY_MOVE_OR_COPY< statment > (YY_MOVE (that.value));
        break;

      case 82: // ExpList
      case 83: // ExpListStar
        value.YY_MOVE_OR_COPY< std::vector<ExpASTNode *> > (YY_MOVE (that.value));
        break;

      case 34: // STRING_LITERAL
      case 35: // ID
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 56: // MainMethod
      case 63: // StaticMethodDecl
        value.move< FunctionASTNode > (YY_MOVE (that.value));
        break;

      case 64: // StaticMethodDeclStar
        value.move< function_list > (YY_MOVE (that.value));
        break;

      case 33: // INTEGER_LITERAL
        value.move< integer > (YY_MOVE (that.value));
        break;

      case 54: // Program
      case 55: // MainClass
      case 57: // VarDecl
      case 58: // StaticVarDecl
      case 59: // OptionalExp
      case 60: // MoreStaticVarDecl
      case 61: // MoreVarDecl
      case 62: // StaticVarDeclStar
      case 66: // FormalList
      case 67: // FormalListTail
      case 68: // PrimeType
      case 69: // Type
      case 72: // LeftValue
      case 73: // MethodCall
      case 74: // Exp
      case 75: // ExpOr
      case 76: // ExpAnd
      case 77: // ExpEq
      case 78: // ExpLessMore
      case 79: // ExpAdd
      case 80: // ExpMult
      case 81: // Factor
        value.move< node > (YY_MOVE (that.value));
        break;

      case 71: // Statements
        value.move< statements > (YY_MOVE (that.value));
        break;

      case 70: // Statement
        value.move< statment > (YY_MOVE (that.value));
        break;

      case 82: // ExpList
      case 83: // ExpListStar
        value.move< std::vector<ExpASTNode *> > (YY_MOVE (that.value));
        break;

      case 34: // STRING_LITERAL
      case 35: // ID
        value.move< string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 56: // MainMethod
      case 63: // StaticMethodDecl
        value.copy< FunctionASTNode > (that.value);
        break;

      case 64: // StaticMethodDeclStar
        value.copy< function_list > (that.value);
        break;

      case 33: // INTEGER_LITERAL
        value.copy< integer > (that.value);
        break;

      case 54: // Program
      case 55: // MainClass
      case 57: // VarDecl
      case 58: // StaticVarDecl
      case 59: // OptionalExp
      case 60: // MoreStaticVarDecl
      case 61: // MoreVarDecl
      case 62: // StaticVarDeclStar
      case 66: // FormalList
      case 67: // FormalListTail
      case 68: // PrimeType
      case 69: // Type
      case 72: // LeftValue
      case 73: // MethodCall
      case 74: // Exp
      case 75: // ExpOr
      case 76: // ExpAnd
      case 77: // ExpEq
      case 78: // ExpLessMore
      case 79: // ExpAdd
      case 80: // ExpMult
      case 81: // Factor
        value.copy< node > (that.value);
        break;

      case 71: // Statements
        value.copy< statements > (that.value);
        break;

      case 70: // Statement
        value.copy< statment > (that.value);
        break;

      case 82: // ExpList
      case 83: // ExpListStar
        value.copy< std::vector<ExpASTNode *> > (that.value);
        break;

      case 34: // STRING_LITERAL
      case 35: // ID
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 56: // MainMethod
      case 63: // StaticMethodDecl
        value.move< FunctionASTNode > (that.value);
        break;

      case 64: // StaticMethodDeclStar
        value.move< function_list > (that.value);
        break;

      case 33: // INTEGER_LITERAL
        value.move< integer > (that.value);
        break;

      case 54: // Program
      case 55: // MainClass
      case 57: // VarDecl
      case 58: // StaticVarDecl
      case 59: // OptionalExp
      case 60: // MoreStaticVarDecl
      case 61: // MoreVarDecl
      case 62: // StaticVarDeclStar
      case 66: // FormalList
      case 67: // FormalListTail
      case 68: // PrimeType
      case 69: // Type
      case 72: // LeftValue
      case 73: // MethodCall
      case 74: // Exp
      case 75: // ExpOr
      case 76: // ExpAnd
      case 77: // ExpEq
      case 78: // ExpLessMore
      case 79: // ExpAdd
      case 80: // ExpMult
      case 81: // Factor
        value.move< node > (that.value);
        break;

      case 71: // Statements
        value.move< statements > (that.value);
        break;

      case 70: // Statement
        value.move< statment > (that.value);
        break;

      case 82: // ExpList
      case 83: // ExpListStar
        value.move< std::vector<ExpASTNode *> > (that.value);
        break;

      case 34: // STRING_LITERAL
      case 35: // ID
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 56: // MainMethod
      case 63: // StaticMethodDecl
        yylhs.value.emplace< FunctionASTNode > ();
        break;

      case 64: // StaticMethodDeclStar
        yylhs.value.emplace< function_list > ();
        break;

      case 33: // INTEGER_LITERAL
        yylhs.value.emplace< integer > ();
        break;

      case 54: // Program
      case 55: // MainClass
      case 57: // VarDecl
      case 58: // StaticVarDecl
      case 59: // OptionalExp
      case 60: // MoreStaticVarDecl
      case 61: // MoreVarDecl
      case 62: // StaticVarDeclStar
      case 66: // FormalList
      case 67: // FormalListTail
      case 68: // PrimeType
      case 69: // Type
      case 72: // LeftValue
      case 73: // MethodCall
      case 74: // Exp
      case 75: // ExpOr
      case 76: // ExpAnd
      case 77: // ExpEq
      case 78: // ExpLessMore
      case 79: // ExpAdd
      case 80: // ExpMult
      case 81: // Factor
        yylhs.value.emplace< node > ();
        break;

      case 71: // Statements
        yylhs.value.emplace< statements > ();
        break;

      case 70: // Statement
        yylhs.value.emplace< statment > ();
        break;

      case 82: // ExpList
      case 83: // ExpListStar
        yylhs.value.emplace< std::vector<ExpASTNode *> > ();
        break;

      case 34: // STRING_LITERAL
      case 35: // ID
        yylhs.value.emplace< string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 68 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
              {
        yylhs.value.as < node > () = new_node(NODETYPE_PROGRAM);
        yylhs.value.as < node > ()->line_number = yylineno;
        root = yylhs.value.as < node > ();
        add_child(yylhs.value.as < node > (), yystack_[0].value.as < node > ());
    }
#line 793 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 3:
#line 78 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
    {

    }
#line 801 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 4:
#line 84 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                                                         {

        FunctionSymbolTableEntry * main_method_symtab_entry =
        new FunctionSymbolTableEntry(VARIABLE_TYPE_VOID, std::string("main"), 0, true, 1, false);
        //need to add this to a global symtab or something


        yylhs.value.as < FunctionASTNode > () = new FunctionASTNode(yystack_[1].value.as < statements > (), main_method_symtab_entry, true);

	}
#line 816 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 5:
#line 98 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                        {
//        $$ = new_node(NODETYPE_VARDECL);
//        set_string_value($$, $2);
//        //printf("********VARDECL STRING VALUE: %s", $$->data.value.string_value);
//        add_child($$, $1);
//        add_child($$, $3);
//        add_child($$, $4);
//        $$->line_number = yylineno;

		yylhs.value.as < node > () = new AssignmentStatementASTNode();

    }
#line 833 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 6:
#line 113 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                                       {
		yylhs.value.as < node > () = new_node(NODETYPE_STATIC_VARDECL);
		set_string_value(yylhs.value.as < node > (), yystack_[3].value.as < string > ());
		add_child(yylhs.value.as < node > (), yystack_[4].value.as < node > ());
		add_child(yylhs.value.as < node > (), yystack_[2].value.as < node > ());
		add_child(yylhs.value.as < node > (), yystack_[1].value.as < node > ());
		yylhs.value.as < node > ()->line_number = yylineno;
    }
#line 846 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 7:
#line 124 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 854 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 8:
#line 127 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		yylhs.value.as < node > () = NULL;
	}
#line 862 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 9:
#line 135 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                             {
		yylhs.value.as < node > () = new_node(NODETYPE_MORE_STATIC_VARDECL);
        set_string_value(yylhs.value.as < node > (), yystack_[1].value.as < string > ());
        add_child(yylhs.value.as < node > (), yystack_[3].value.as < node > ());
        add_child(yylhs.value.as < node > (), yystack_[0].value.as < node > ());
        yylhs.value.as < node > ()->line_number = yylineno;
	}
#line 874 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 10:
#line 142 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		yylhs.value.as < node > () = NULL;
	}
#line 882 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 11:
#line 148 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
		yylhs.value.as < node > () = new_node(NODETYPE_MORE_VARDECL);
        set_string_value(yylhs.value.as < node > (), yystack_[1].value.as < string > ());
        add_child(yylhs.value.as < node > (), yystack_[3].value.as < node > ());
        add_child(yylhs.value.as < node > (), yystack_[0].value.as < node > ());
        yylhs.value.as < node > ()->line_number = yylineno;
	}
#line 894 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 12:
#line 155 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		yylhs.value.as < node > () = NULL;
	}
#line 902 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 13:
#line 161 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                        {
		yylhs.value.as < node > () = new_node(NODETYPE_STATIC_VAR_DECL_LIST);
		add_child(yylhs.value.as < node > (), yystack_[1].value.as < node > ());
		add_child(yylhs.value.as < node > (), yystack_[0].value.as < node > ());
        yylhs.value.as < node > ()->line_number = yylineno;
		//????????? MAYBE THIS IS ALL WRONG??!?!?
	}
#line 914 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 14:
#line 168 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		yylhs.value.as < node > () = NULL;
	}
#line 922 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 15:
#line 174 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                                          {
		yylhs.value.as < FunctionASTNode > () = new_node(NODETYPE_STATIC_METHOD_DECL);
		set_string_value(yylhs.value.as < FunctionASTNode > (), yystack_[6].value.as < string > ());
		//Type
		add_child(yylhs.value.as < FunctionASTNode > (), yystack_[7].value.as < node > ());
		//FormalList
		add_child(yylhs.value.as < FunctionASTNode > (), yystack_[4].value.as < node > ());
		//Statements
		add_child(yylhs.value.as < FunctionASTNode > (), yystack_[1].value.as < statements > ());
        yylhs.value.as < FunctionASTNode > ()->line_number = yylineno;
	}
#line 938 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 16:
#line 187 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                      { yylhs.value.as< function_list > () = new FunctionASTNode(); }
#line 944 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 17:
#line 188 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                          {

	}
#line 952 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 18:
#line 191 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		yylhs.value.as < function_list > () = NULL;
	}
#line 960 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 19:
#line 197 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                               {

	}
#line 968 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 20:
#line 203 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                   {

	}
#line 976 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 21:
#line 206 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
	}
#line 983 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 22:
#line 211 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
           {

    }
#line 991 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 23:
#line 214 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {

    }
#line 999 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 24:
#line 217 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                {

    }
#line 1007 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 25:
#line 223 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                  {

	}
#line 1015 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 26:
#line 226 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                       {

	}
#line 1023 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 27:
#line 233 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
            {
        yylhs.value.as < statment > () = yystack_[0].value.as < node > ();
    }
#line 1031 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 28:
#line 236 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                         {
        yylhs.value.as < statment > () = yystack_[1].value.as < statements > ();

    }
#line 1040 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 29:
#line 240 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                    {
        StatementsASTNode *stmt_blck_true = dynamic_cast<StatementsASTNode *>(yystack_[2].value.as < statment > ());
        if (stmt_blck_true == nullptr) {
            stmt_blck_true = new StatementsASTNode();
            stmt_blck_true->add_statement(yystack_[2].value.as < statment > ());
        }

        StatementsASTNode *stmt_blck_false = dynamic_cast<StatementsASTNode *>(yystack_[0].value.as < statment > ());
        if (stmt_blck_false == nullptr) {
            stmt_blck_false = new StatementsASTNode();
            stmt_blck_false->add_statement(yystack_[0].value.as < statment > ());
        }

        yylhs.value.as < statment > () = new IfElseStatementASTNode(yystack_[4].value.as < node > (), stmt_blck_true, stmt_blck_false);

    }
#line 1061 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 30:
#line 256 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                     {
        StatementsASTNode *stmt_blck = dynamic_cast<StatementsASTNode *>(yystack_[0].value.as < statment > ());
        if (stmt_blck == nullptr) {
            stmt_blck = new StatementsASTNode();
            stmt_blck->add_statement(yystack_[0].value.as < statment > ());
        }

        yylhs.value.as < statment > () = new WhileStatementASTNode(yystack_[2].value.as < node > (), stmt_blck);

    }
#line 1076 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 31:
#line 266 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                         {
        //$$ = new_node(NODETYPE_PRINTLN);
        //add_child($$, $3);
        //$$->line_number = yylineno;
    }
#line 1086 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 32:
#line 271 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
        //$$ = new_node(NODETYPE_PRINT);
        //add_child($$, $3);
        //$$->line_number = yylineno;
    }
#line 1096 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 33:
#line 276 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                            {

        AssignmentStatementASTNode * assn_stmt = new AssignmentStatementASTNode(yystack_[3].value.as < node > (), yystack_[1].value.as < node > ());
        yylhs.value.as < statment > () = assn_stmt;
        //don't think we actually can cast to StatementASTNode

    }
#line 1108 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 34:
#line 283 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                        {
        yylhs.value.as < statment > () = new ReturnStatementTmpASTNode(yystack_[1].value.as < node > ());
    }
#line 1116 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 35:
#line 286 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {
        yylhs.value.as < statment > () = yystack_[1].value.as < node > ();
    }
#line 1124 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 36:
#line 293 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                             {

		yystack_[1].value.as < statements > ()->add_statement(yystack_[0].value.as < statment > ());
	}
#line 1133 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 37:
#line 297 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		yylhs.value.as < statements > () = nullptr;
	}
#line 1141 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 38:
#line 303 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
           {
        yylhs.value.as < node > () = new VariableReferenceTmpASTNode(yystack_[0].value.as < string > ());
	}
#line 1149 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 39:
#line 306 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                {
		yystack_[3].value.as < node > ()->number_of_arrays++;
		yystack_[3].value.as < node > ()->index_exp_list.push_back(yystack_[1].value.as < node > ());
		yylhs.value.as < node > () = yystack_[3].value.as < node > ();
	}
#line 1159 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 40:
#line 314 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                           {
		MethodCallTmpASTNode * tmp_method_call = new MethodCallTmpASTNode();
		tmp_method_call->method_id = yystack_[3].value.as < string > ();
		tmp_method_call->index_exp_list = yystack_[1].value.as < std::vector<ExpASTNode *> > ();
	}
#line 1169 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 41:
#line 320 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {

	}
#line 1177 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 42:
#line 330 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
              {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1185 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 43:
#line 336 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
		yylhs.value.as < node > () = new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_OR, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());
		}
#line 1193 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 44:
#line 339 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1201 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 45:
#line 345 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                        {
		yylhs.value.as < node > () = new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_AND, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

	}
#line 1210 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 46:
#line 349 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1218 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 47:
#line 355 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                              {
		yylhs.value.as < node > () = new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_EQUAL_TO, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

	}
#line 1227 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 48:
#line 359 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                         {
		yylhs.value.as < node > () = new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_NOT_EQUAL, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

	}
#line 1236 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 49:
#line 363 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                      {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1244 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 50:
#line 369 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                {
		yylhs.value.as < node > () = new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_GREATER_THAN_OR_EQUAL_TO, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

	}
#line 1253 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 51:
#line 373 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                               {
        yylhs.value.as < node > () = new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_LESS_THAN_OR_EQUAL_TO, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

    }
#line 1262 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 52:
#line 377 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                 {
		yylhs.value.as < node > () = new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_LESS_THAN, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

    }
#line 1271 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 53:
#line 381 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                 {
		yylhs.value.as < node > () = new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_GREATER_THAN, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

	}
#line 1280 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 54:
#line 385 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1288 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 55:
#line 391 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                           {
		yylhs.value.as < node > () = new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_ADDITION, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());

	}
#line 1297 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 56:
#line 395 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                             {
		yylhs.value.as < node > () = new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_SUBTRACTION, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());
	}
#line 1305 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 57:
#line 398 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                  {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1313 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 58:
#line 404 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                           {
		yylhs.value.as < node > () = new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_MULTIPLICATION, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());
	}
#line 1321 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 59:
#line 407 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                             {
		yylhs.value.as < node > () = new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_DIVISION, yystack_[2].value.as < node > (), yystack_[0].value.as < node > ());
	}
#line 1329 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 60:
#line 410 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();
	}
#line 1337 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 61:
#line 416 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                   {

	}
#line 1345 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 62:
#line 419 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {

	}
#line 1353 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 63:
#line 422 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {

	}
#line 1361 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 64:
#line 425 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                      {
		yylhs.value.as < node > () = yystack_[1].value.as < node > ();
	}
#line 1369 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 65:
#line 428 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                    {
		//LeftValue returns a VariableReferenceTmpASTNode
		yylhs.value.as < node > () = new VariableReferenceExpASTNode(yystack_[0].value.as < node > ());
	}
#line 1378 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 66:
#line 432 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                  {

	}
#line 1386 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 67:
#line 435 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                          {
		yylhs.value.as < node > () = new IntegerLiteralExpASTNode(yystack_[0].value.as < integer > ());
	}
#line 1394 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 68:
#line 438 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                         {

	}
#line 1402 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 69:
#line 441 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                  {
		yylhs.value.as < node > () = new IntegerLiteralExpASTNode(1);
	}
#line 1410 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 70:
#line 444 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                   {
		yylhs.value.as < node > () = new IntegerLiteralExpASTNode(0);
	}
#line 1418 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 71:
#line 447 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {
		yylhs.value.as < node > () = yystack_[0].value.as < node > ();

//	}
//	| KW_NEW PrimeType Index {
//		$$ = new_node(NODETYPE_NEW);
//		add_child($$, $2);
//		add_child($$, $3);
//        $$->line_number = yylineno;
	}
#line 1433 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 72:
#line 461 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                    {
        yystack_[0].value.as < std::vector<ExpASTNode *> > ()->push_back(yystack_[1].value.as < node > ());
        yylhs.value.as < std::vector<ExpASTNode *> > () = yystack_[0].value.as < std::vector<ExpASTNode *> > ();
}
#line 1442 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 73:
#line 469 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                            {
		yystack_[2].value.as < std::vector<ExpASTNode *> > ()->push_back(yystack_[2].value.as < std::vector<ExpASTNode *> > ());
	}
#line 1450 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;

  case 74:
#line 472 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {

	}
#line 1458 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"
    break;


#line 1462 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -127;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      16,     6,    50,  -127,    27,  -127,  -127,    58,    63,  -127,
      62,  -127,     8,    69,    49,    84,  -127,  -127,  -127,  -127,
     -22,    92,  -127,    93,  -127,    64,    68,   111,     8,    66,
    -127,  -127,    78,    -3,  -127,  -127,    81,  -127,  -127,    82,
      66,    66,    66,    66,   -29,  -127,  -127,    98,   103,   -13,
     -19,    18,    24,  -127,    -9,   117,    94,    66,    66,    90,
    -127,  -127,  -127,    66,   112,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,  -127,    99,    96,
       8,    95,  -127,    97,  -127,   101,  -127,   103,   -13,   -19,
     -19,    18,    18,    18,    18,    24,    24,  -127,  -127,    64,
     102,   114,     7,  -127,   108,  -127,  -127,  -127,   104,   107,
    -127,    66,   115,  -127,   113,  -127,   122,    74,     8,  -127,
     121,   123,   125,   126,    66,  -127,  -127,  -127,    14,  -127,
      12,   118,    17,   109,    66,    66,    66,    66,   124,   134,
      64,    66,  -127,  -127,  -127,   127,   136,   139,   140,  -127,
    -127,  -127,   141,   142,   143,   159,   159,    20,  -127,  -127,
    -127,   149,  -127,  -127,   147,   159,    64,  -127,  -127
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,    14,    16,     0,    13,
       0,    16,     0,     0,     0,     0,    23,    22,    24,    25,
       0,     0,     3,     0,    17,     8,     0,     0,     0,     0,
      10,    26,     0,     0,    70,    69,     0,    67,    68,    38,
       0,     0,     0,     0,    65,    71,     7,    42,    44,    46,
      49,    54,    57,    60,     0,     0,     0,     0,     0,     0,
      62,    63,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,     0,    74,     0,    64,     0,    66,    43,    45,    47,
      48,    50,    51,    52,    53,    55,    56,    58,    59,     8,
       0,     0,     0,    41,    72,    40,    39,     9,     0,     0,
      21,     0,     0,    37,    19,    73,     0,     0,     0,    37,
       0,     0,     0,     0,     0,    37,    15,    27,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,    35,    20,     4,     0,     0,     0,     0,    34,
      28,    12,     0,     0,     0,     0,     0,     0,    33,    32,
      31,     0,    30,     5,     0,     0,     8,    29,    11
  };

  const short
  parser::yypgoto_[] =
  {
    -127,  -127,  -127,  -127,  -127,  -127,   -97,  -127,  -127,  -127,
    -127,   175,  -127,  -127,  -127,  -127,   -12,  -126,   -85,  -111,
    -108,   -39,  -127,   128,   130,    11,   -11,    10,   -38,  -127,
    -127
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    14,   127,     9,    30,    54,   157,     7,
      24,    10,    11,   101,   114,    19,   128,   129,   117,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    83,
     104
  };

  const unsigned char
  parser::yytable_[] =
  {
      20,    59,   107,    60,    61,    62,   130,    69,    70,   131,
      63,    16,    67,    25,    17,    68,    33,    26,    81,    82,
       1,    18,   130,    64,    85,   131,    71,    72,   130,   161,
     162,   131,    56,    77,   133,    78,    26,    97,    98,   167,
     139,     4,   110,   151,   130,   130,    26,   131,   131,   140,
       5,    63,   143,    26,   130,   141,    26,   131,    91,    92,
      93,    94,   163,     6,   164,    73,    74,     8,   102,   168,
      13,    34,   115,    75,    76,    12,    35,    16,    89,    90,
      17,    21,    36,    95,    96,   138,    22,    18,   120,   121,
      36,   122,    23,   123,   124,   145,   146,   147,   148,    37,
      38,    39,   152,    27,    40,    28,   132,    29,    31,    39,
     125,   126,    16,    41,    42,    17,    55,    43,    32,    57,
      58,    65,    18,   120,   121,    36,   122,    66,   123,   124,
      79,    84,    80,    86,    99,   100,   103,    16,   105,   112,
      17,   106,   108,   113,    39,   125,   144,    18,   120,   121,
      36,   122,   111,   123,   124,   109,   116,   118,   119,   134,
     142,   135,    16,   136,   137,    17,   149,   165,   153,    39,
     125,   150,    18,   120,   121,    36,   122,   154,   123,   124,
     155,   156,   166,   158,   159,   160,    15,     0,     0,     0,
       0,     0,     0,    87,    39,   125,    88
  };

  const short
  parser::yycheck_[] =
  {
      12,    40,    99,    41,    42,    43,   117,    26,    27,   117,
      39,     3,    25,    35,     6,    28,    28,    39,    57,    58,
       4,    13,   133,    52,    63,   133,    45,    46,   139,   155,
     156,   139,    35,    42,   119,    44,    39,    75,    76,   165,
     125,    35,    35,   140,   155,   156,    39,   155,   156,    35,
       0,    39,    35,    39,   165,    43,    39,   165,    69,    70,
      71,    72,    42,    36,    44,    47,    48,     9,    80,   166,
       8,     5,   111,    49,    50,    12,    10,     3,    67,    68,
       6,    12,    16,    73,    74,   124,    37,    13,    14,    15,
      16,    17,     8,    19,    20,   134,   135,   136,   137,    33,
      34,    35,   141,    11,    38,    12,   118,    43,    40,    35,
      36,    37,     3,    47,    48,     6,    38,    51,     7,    38,
      38,    23,    13,    14,    15,    16,    17,    24,    19,    20,
      13,    41,    38,    21,    35,    39,    41,     3,    41,    35,
       6,    40,    40,    36,    35,    36,    37,    13,    14,    15,
      16,    17,    44,    19,    20,    41,    41,    44,    36,    38,
      42,    38,     3,    38,    38,     6,    42,    18,    41,    35,
      36,    37,    13,    14,    15,    16,    17,    41,    19,    20,
      41,    41,    35,    42,    42,    42,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    35,    36,    66
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,    54,    55,    35,     0,    36,    62,     9,    58,
      64,    65,    12,     8,    56,    64,     3,     6,    13,    68,
      69,    12,    37,     8,    63,    35,    39,    11,    12,    43,
      59,    40,     7,    69,     5,    10,    16,    33,    34,    35,
      38,    47,    48,    51,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    60,    38,    35,    38,    38,    74,
      81,    81,    81,    39,    52,    23,    24,    25,    28,    26,
      27,    45,    46,    47,    48,    49,    50,    42,    44,    13,
      38,    74,    74,    82,    41,    74,    21,    76,    77,    78,
      78,    79,    79,    79,    79,    80,    80,    81,    81,    35,
      39,    66,    69,    41,    83,    41,    40,    59,    40,    41,
      35,    44,    35,    36,    67,    74,    41,    71,    44,    36,
      14,    15,    17,    19,    20,    36,    37,    57,    69,    70,
      72,    73,    69,    71,    38,    38,    38,    38,    74,    71,
      35,    43,    42,    35,    37,    74,    74,    74,    74,    42,
      37,    59,    74,    41,    41,    41,    41,    61,    42,    42,
      42,    70,    70,    42,    44,    18,    35,    70,    59
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    53,    54,    55,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    65,    64,    64,    66,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    83,    83
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     7,    13,     5,     7,     2,     0,     4,
       0,     4,     0,     2,     0,    10,     0,     3,     0,     3,
       4,     0,     1,     1,     1,     1,     3,     1,     3,     7,
       5,     5,     5,     4,     3,     2,     2,     0,     1,     4,
       4,     4,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     2,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     2,     3,     0
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "KW_BOOLEAN", "KW_CLASS", "KW_FALSE",
  "KW_INT", "MAIN", "KW_PUBLIC", "KW_PRIVATE", "KW_TRUE", "KW_VOID",
  "KW_STATIC", "KW_STRING", "SYSTEM_OUT_PRINT", "SYSTEM_OUT_PRINTLN",
  "INTEGER_PARSEINT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN",
  "KW_LENGTH", "KW_NEW", "KW_SHORTCIRCUITOR", "KW_SHORTCIRCUITAND",
  "KW_COMPARISONEQUALS", "KW_GREATERTHANEQUALS", "KW_LESSTHANEQUALS",
  "KW_NOTEQUALS", "KW_OPEN_BRACE", "KW_OPEN_PAREN", "KW_SEMICOLON",
  "KW_EQUALS", "INTEGER_LITERAL", "STRING_LITERAL", "ID", "'{'", "'}'",
  "'('", "'['", "']'", "')'", "';'", "'='", "','", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'!'", "'.'", "$accept", "Program", "MainClass",
  "MainMethod", "VarDecl", "StaticVarDecl", "OptionalExp",
  "MoreStaticVarDecl", "MoreVarDecl", "StaticVarDeclStar",
  "StaticMethodDecl", "StaticMethodDeclStar", "@1", "FormalList",
  "FormalListTail", "PrimeType", "Type", "Statement", "Statements",
  "LeftValue", "MethodCall", "Exp", "ExpOr", "ExpAnd", "ExpEq",
  "ExpLessMore", "ExpAdd", "ExpMult", "Factor", "ExpList", "ExpListStar", YY_NULLPTR
  };


  const short
  parser::yyrline_[] =
  {
       0,    68,    68,    77,    84,    98,   113,   124,   127,   135,
     142,   148,   155,   161,   168,   174,   187,   187,   191,   197,
     203,   206,   211,   214,   217,   223,   226,   233,   236,   240,
     256,   266,   271,   276,   283,   286,   293,   297,   303,   306,
     314,   320,   330,   336,   339,   345,   349,   355,   359,   363,
     369,   373,   377,   381,   385,   391,   395,   398,   404,   407,
     410,   416,   419,   422,   425,   428,   432,   435,   438,   441,
     444,   447,   461,   469,   472
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1873 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.cpp"

#line 486 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"


void yyerror(char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

int main(int argc, char* argv[] )
{

	#if YYDEBUG
        yydebug = 1;
    #endif

    yyin = fopen( argv[1], "r" );

    // Checks for syntax errors and constructs AST
    if (yyparse() != 0)
        return 1;





    return 0;
}
