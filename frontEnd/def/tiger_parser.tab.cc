// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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


// First part of user declarations.

#line 37 "tiger_parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "tiger_parser.tab.hh"

// User implementation prologue.

#line 51 "tiger_parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 27 "tiger_parser.yy" // lalr1.cc:413

	#include <iostream>
	#include <cstdlib>
	#include <fstream>
   
	/* include for all driver functions */
	#include "../Tiger_Driver.hpp"

	#undef yylex
	#define yylex scanner.yylex

#line 65 "tiger_parser.tab.cc" // lalr1.cc:413


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "tiger_parser.yy" // lalr1.cc:479
namespace Tiger {
#line 151 "tiger_parser.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Tiger_Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Tiger_Parser::Tiger_Parser (Tiger_Scanner &scanner_yyarg, Tiger_Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Tiger_Parser::~Tiger_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Tiger_Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Tiger_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Tiger_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  Tiger_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Tiger_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Tiger_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  Tiger_Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Tiger_Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Tiger_Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Tiger_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  Tiger_Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Tiger_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Tiger_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Tiger_Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Tiger_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Tiger_Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  Tiger_Parser::symbol_type
  Tiger_Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_NEWLINE (const location_type& l)
  {
    return symbol_type (token::NEWLINE, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_COMMENT (const location_type& l)
  {
    return symbol_type (token::COMMENT, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_VAR (const location_type& l)
  {
    return symbol_type (token::VAR, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_LET (const location_type& l)
  {
    return symbol_type (token::LET, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_TYPE (const location_type& l)
  {
    return symbol_type (token::TYPE, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_THEN (const location_type& l)
  {
    return symbol_type (token::THEN, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_FOR (const location_type& l)
  {
    return symbol_type (token::FOR, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::WHILE, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_LBRAC (const location_type& l)
  {
    return symbol_type (token::LBRAC, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_RBRAC (const location_type& l)
  {
    return symbol_type (token::RBRAC, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_LPAREN (const location_type& l)
  {
    return symbol_type (token::LPAREN, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_RPAREN (const location_type& l)
  {
    return symbol_type (token::RPAREN, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_NIL (const location_type& l)
  {
    return symbol_type (token::NIL, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_ARRAY (const location_type& l)
  {
    return symbol_type (token::ARRAY, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_TO (const location_type& l)
  {
    return symbol_type (token::TO, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_DO (const location_type& l)
  {
    return symbol_type (token::DO, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_IN (const location_type& l)
  {
    return symbol_type (token::IN, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_ENDD (const location_type& l)
  {
    return symbol_type (token::ENDD, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_OF (const location_type& l)
  {
    return symbol_type (token::OF, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_BREAK (const location_type& l)
  {
    return symbol_type (token::BREAK, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_IMPORT (const location_type& l)
  {
    return symbol_type (token::IMPORT, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_PRIMITIVE (const location_type& l)
  {
    return symbol_type (token::PRIMITIVE, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_TRY (const location_type& l)
  {
    return symbol_type (token::TRY, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_FUNCTION (const location_type& l)
  {
    return symbol_type (token::FUNCTION, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_CLASS (const location_type& l)
  {
    return symbol_type (token::CLASS, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_EXTENDS (const location_type& l)
  {
    return symbol_type (token::EXTENDS, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_METHOD (const location_type& l)
  {
    return symbol_type (token::METHOD, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_NEW (const location_type& l)
  {
    return symbol_type (token::NEW, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_ADD (const location_type& l)
  {
    return symbol_type (token::ADD, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_SUB (const location_type& l)
  {
    return symbol_type (token::SUB, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_MULTI (const location_type& l)
  {
    return symbol_type (token::MULTI, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_DIVIDE (const location_type& l)
  {
    return symbol_type (token::DIVIDE, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_EQ (const location_type& l)
  {
    return symbol_type (token::EQ, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_ASSIGNEQ (const location_type& l)
  {
    return symbol_type (token::ASSIGNEQ, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_LOWER (const location_type& l)
  {
    return symbol_type (token::LOWER, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_GREATER (const location_type& l)
  {
    return symbol_type (token::GREATER, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_LOWEREQ (const location_type& l)
  {
    return symbol_type (token::LOWEREQ, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_GREATEREQ (const location_type& l)
  {
    return symbol_type (token::GREATEREQ, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_AND (const location_type& l)
  {
    return symbol_type (token::AND, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_OR (const location_type& l)
  {
    return symbol_type (token::OR, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::SEMICOLON, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_BECOMES (const location_type& l)
  {
    return symbol_type (token::BECOMES, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_DOT (const location_type& l)
  {
    return symbol_type (token::DOT, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_STRING_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING_ID, v, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_NUMBER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NUMBER, v, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_TYPE_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TYPE_ID, v, l);
  }

  Tiger_Parser::symbol_type
  Tiger_Parser::make_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }



  // by_state.
  inline
  Tiger_Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Tiger_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Tiger_Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Tiger_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Tiger_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Tiger_Parser::symbol_number_type
  Tiger_Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Tiger_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Tiger_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Tiger_Parser::stack_symbol_type&
  Tiger_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Tiger_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Tiger_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Tiger_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Tiger_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Tiger_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Tiger_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Tiger_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Tiger_Parser::debug_level_type
  Tiger_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Tiger_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Tiger_Parser::state_type
  Tiger_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Tiger_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Tiger_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Tiger_Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 50: // STRING_ID
      case 51: // NUMBER
      case 52: // TYPE_ID
      case 53: // ID
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 108 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1042 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 109 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1048 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 110 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1054 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 111 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1060 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 112 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1066 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 116 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "Stmt\n"; }
#line 1072 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 117 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1078 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 118 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "SeqExpr \n";}
#line 1084 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 119 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "If Stmt\n";}
#line 1090 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 120 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "For Stmt\n";}
#line 1096 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 121 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "Declaration Stmt\n";}
#line 1102 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 122 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "While Stmt\n";}
#line 1108 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 123 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "Array Decl\n";}
#line 1114 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 124 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "Array Build\n";}
#line 1120 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 125 "tiger_parser.yy" // lalr1.cc:859
    {std::cout << "Function call\n";}
#line 1126 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 126 "tiger_parser.yy" // lalr1.cc:859
    {	
												std::cout << "String value\n";

											}
#line 1135 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 130 "tiger_parser.yy" // lalr1.cc:859
    {
												int number = atoi(yystack_[0].value.as< std::string > ().c_str());
												driver.addIntegerLiteral(number);
												std::cout << "number\n";
											}
#line 1145 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 137 "tiger_parser.yy" // lalr1.cc:859
    {
										std::cout<<"expr\n";
										driver.addBinaryOperator(Expr::ADD);
										
									}
#line 1155 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 142 "tiger_parser.yy" // lalr1.cc:859
    {
										driver.addBinaryOperator(Expr::SUB);
									}
#line 1163 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 145 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1169 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 148 "tiger_parser.yy" // lalr1.cc:859
    {
										driver.addBinaryOperator(Expr::MUL);
									}
#line 1177 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 151 "tiger_parser.yy" // lalr1.cc:859
    {
										driver.addBinaryOperator(Expr::DIV);
									}
#line 1185 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 154 "tiger_parser.yy" // lalr1.cc:859
    {
										int number = atoi(yystack_[0].value.as< std::string > ().c_str());
										driver.addIntegerLiteral(number);
										std::cout << "number\n";
									}
#line 1195 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 159 "tiger_parser.yy" // lalr1.cc:859
    {
										driver.add_id(yystack_[0].value.as< std::string > ().c_str(),"void");
										std::cout << "Identifier\n";
									}
#line 1204 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 165 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1210 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 166 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1216 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 169 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1222 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 172 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1228 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 173 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1234 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 176 "tiger_parser.yy" // lalr1.cc:859
    {
																									std::cout << "FunctionDec No return type \n";
																									driver.addToBodyStmt();
																									driver.add_function_def(yystack_[5].value.as< std::string > ().c_str(),"void");
																								}
#line 1244 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 181 "tiger_parser.yy" // lalr1.cc:859
    {	
																									std::cout <<"FunctionDef has return type\n";
																									driver.addToBodyStmt();
																									driver.add_function_def(yystack_[7].value.as< std::string > ().c_str(),yystack_[3].value.as< std::string > ().c_str());
																								}
#line 1254 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 189 "tiger_parser.yy" // lalr1.cc:859
    {std::cout<<"args\n";}
#line 1260 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 190 "tiger_parser.yy" // lalr1.cc:859
    {
																	std::cout<<"args last\n";
																	driver.add_id(yystack_[2].value.as< std::string > ().c_str(),yystack_[0].value.as< std::string > ().c_str()); 
																}
#line 1269 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 194 "tiger_parser.yy" // lalr1.cc:859
    {std::cout<<"no arg\n";}
#line 1275 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 197 "tiger_parser.yy" // lalr1.cc:859
    {
																	std::cout << "ID type int\n";
																}
#line 1283 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 201 "tiger_parser.yy" // lalr1.cc:859
    {
																	std::cout << "ID with type\n";
																	driver.add_id(yystack_[4].value.as< std::string > ().c_str(),yystack_[2].value.as< std::string > ().c_str());
																}
#line 1292 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 205 "tiger_parser.yy" // lalr1.cc:859
    { driver.add_id(yystack_[2].value.as< std::string > ().c_str(),yystack_[0].value.as< std::string > ().c_str()); }
#line 1298 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 210 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1304 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 211 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1310 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 214 "tiger_parser.yy" // lalr1.cc:859
    {std::cout<<"if else stmt\n";}
#line 1316 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 215 "tiger_parser.yy" // lalr1.cc:859
    {std::cout<<"only if stmt\n";}
#line 1322 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 218 "tiger_parser.yy" // lalr1.cc:859
    {std::cout<< "for stmt\n";}
#line 1328 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 221 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1334 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 225 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1340 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 228 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1346 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 231 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1352 "tiger_parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 235 "tiger_parser.yy" // lalr1.cc:859
    {}
#line 1358 "tiger_parser.tab.cc" // lalr1.cc:859
    break;


#line 1362 "tiger_parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
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
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

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
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Tiger_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Tiger_Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Tiger_Parser::yypact_ninf_ = -44;

  const signed char Tiger_Parser::yytable_ninf_ = -25;

  const signed char
  Tiger_Parser::yypact_[] =
  {
      25,   -44,     3,   -43,   -30,   118,   -25,   118,     3,    11,
      -6,   -44,    10,    34,    60,   -44,     4,   -19,     3,     3,
     -44,   -44,     3,     3,     3,     3,     3,   -44,     3,   -44,
     -44,   -42,    12,    40,    16,    31,   118,     5,    45,     9,
     -44,   -44,   -44,   -40,   -40,   -44,    13,    18,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,    14,   126,    20,   118,
     118,   118,   -44,   107,   -44,    58,    35,    64,   -44,   -44,
     -19,   -19,   -44,   -44,    38,    15,   -44,   -44,    69,    70,
     -44,   -44,   -44,   -37,    39,   -44,   118,   118,   118,   118,
       3,    41,    46,   -44,    77,   -44,    74,   118,    59,     9,
      75,   118,   -44,     3,   -44,   118,   -44,   118,   -44,   -44
  };

  const unsigned char
  Tiger_Parser::yydefact_[] =
  {
       0,     6,    40,     0,     0,     0,     0,     0,    40,     0,
       0,    17,    18,    25,     0,     3,    40,    21,    40,    40,
       5,    27,    40,    40,    40,    40,    40,    26,    40,    39,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       1,     2,     4,     0,     0,     7,     0,     0,    12,     9,
      10,    11,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     0,    30,     0,    45,     0,     0,     0,    24,    25,
      19,    20,    22,    23,    38,    25,    36,    47,    42,     0,
      44,    28,    29,     0,     0,    48,     0,     0,     0,     0,
      40,     0,    34,    37,     0,    41,     0,     0,     0,    35,
       0,     0,    31,    40,    33,     0,    43,     0,    46,    32
  };

  const signed char
  Tiger_Parser::yypgoto_[] =
  {
     -44,   -44,    -5,   -44,    -3,   -44,   -44,   -44,    87,     6,
     -44,    -4,   -44,   -44,   -44,   -44,   -44,   -44,   -44
  };

  const signed char
  Tiger_Parser::yydefgoto_[] =
  {
      -1,    14,    15,    16,    17,    18,    19,    63,    20,    67,
      21,    30,    22,    23,    24,    25,    26,    27,    28
  };

  const signed char
  Tiger_Parser::yytable_[] =
  {
      33,    90,    35,    56,    36,    57,    29,    29,    91,    41,
      31,    68,    45,    69,    48,    49,    46,    47,    50,    51,
      52,    53,    54,    32,    55,     1,     2,    87,    34,    39,
       3,    62,     4,     5,    37,     6,     7,    43,    44,     8,
      70,    71,     9,   -24,   -24,   -24,   -24,    38,    39,    59,
      58,    61,    76,    10,    78,    79,    80,    64,    82,    65,
      40,     2,    66,    60,    72,     3,    74,     4,     5,    73,
       6,     7,    77,    83,     8,    11,    12,     9,    13,    85,
      84,    93,    94,    95,    96,    86,    97,    88,    10,    89,
     100,    92,   102,    98,   101,    99,   106,   103,   105,   107,
     108,    42,   109,     0,     0,   104,     0,     0,     2,     0,
      11,    12,     3,    13,     4,     5,     0,     6,     7,     2,
       0,     8,    81,     3,     9,     4,     5,     2,     6,     7,
       0,     3,     8,     4,     5,     9,     6,     7,     0,     0,
       8,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,    13,     0,     0,     0,     0,    11,    12,     0,    75
  };

  const signed char
  Tiger_Parser::yycheck_[] =
  {
       5,    38,     7,    45,     8,    47,     3,     3,    45,    14,
      53,    51,    16,    53,    18,    19,    35,    36,    22,    23,
      24,    25,    26,    53,    28,     0,     1,    12,    53,    14,
       5,    36,     7,     8,    23,    10,    11,    33,    34,    14,
      43,    44,    17,    33,    34,    35,    36,    53,    14,     9,
      38,    20,    57,    28,    59,    60,    61,    52,    63,    14,
       0,     1,    53,    47,    51,     5,    52,     7,     8,    51,
      10,    11,    52,    15,    14,    50,    51,    17,    53,    15,
      45,    86,    87,    88,    89,    47,    90,    18,    28,    19,
      13,    52,    97,    52,    20,    49,   101,    38,    23,   103,
     105,    14,   107,    -1,    -1,    99,    -1,    -1,     1,    -1,
      50,    51,     5,    53,     7,     8,    -1,    10,    11,     1,
      -1,    14,    15,     5,    17,     7,     8,     1,    10,    11,
      -1,     5,    14,     7,     8,    17,    10,    11,    -1,    -1,
      14,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    -1,    -1,    -1,    -1,    50,    51,    -1,    53
  };

  const unsigned char
  Tiger_Parser::yystos_[] =
  {
       0,     0,     1,     5,     7,     8,    10,    11,    14,    17,
      28,    50,    51,    53,    55,    56,    57,    58,    59,    60,
      62,    64,    66,    67,    68,    69,    70,    71,    72,     3,
      65,    53,    53,    56,    53,    56,    65,    23,    53,    14,
       0,    56,    62,    33,    34,    65,    35,    36,    65,    65,
      65,    65,    65,    65,    65,    65,    45,    47,    38,     9,
      47,    20,    56,    61,    52,    14,    53,    63,    51,    53,
      58,    58,    51,    51,    52,    53,    56,    52,    56,    56,
      56,    15,    56,    15,    45,    15,    47,    12,    18,    19,
      38,    45,    52,    56,    56,    56,    56,    65,    52,    49,
      13,    20,    56,    38,    63,    23,    56,    65,    56,    56
  };

  const unsigned char
  Tiger_Parser::yyr1_[] =
  {
       0,    54,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    58,    58,    59,    59,    60,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    68,    69,    70,    71,    72
  };

  const unsigned char
  Tiger_Parser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     4,     2,
       1,     7,     9,     5,     3,     0,     4,     6,     4,     1,
       0,     6,     4,     8,     4,     3,     9,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Tiger_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NEWLINE", "COMMENT", "VAR",
  "LET", "TYPE", "IF", "THEN", "FOR", "WHILE", "LBRAC", "RBRAC", "LPAREN",
  "RPAREN", "NIL", "ARRAY", "ELSE", "TO", "DO", "IN", "ENDD", "OF",
  "BREAK", "IMPORT", "PRIMITIVE", "TRY", "FUNCTION", "CLASS", "EXTENDS",
  "METHOD", "NEW", "ADD", "SUB", "MULTI", "DIVIDE", "EQ", "ASSIGNEQ",
  "LOWER", "GREATER", "LOWEREQ", "GREATEREQ", "AND", "OR", "COLON",
  "SEMICOLON", "BECOMES", "DOT", "COMMA", "STRING_ID", "NUMBER", "TYPE_ID",
  "ID", "$accept", "Goal", "Stmt", "Expr", "Term", "Declaration",
  "SeqExpr", "Stmts", "FunctionDecl", "Args", "VarDecl", "AllowNewline",
  "IfStmt", "ForStmt", "WhileStmt", "ArrayDecl", "ArrayBuild", "TypeDecl",
  "FunctionCall", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Tiger_Parser::yyrline_[] =
  {
       0,   108,   108,   109,   110,   111,   112,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   130,   137,
     142,   145,   148,   151,   154,   159,   165,   166,   169,   172,
     173,   176,   181,   189,   190,   194,   197,   201,   205,   210,
     211,   214,   215,   218,   221,   225,   228,   231,   235
  };

  // Print the state stack on the debug stream.
  void
  Tiger_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Tiger_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Tiger_Parser::token_number_type
  Tiger_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
    };
    const unsigned int user_token_number_max_ = 308;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "tiger_parser.yy" // lalr1.cc:1167
} // Tiger
#line 1863 "tiger_parser.tab.cc" // lalr1.cc:1167
#line 239 "tiger_parser.yy" // lalr1.cc:1168

void 
Tiger::Tiger_Parser::error( const location_type &l, 
						const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
