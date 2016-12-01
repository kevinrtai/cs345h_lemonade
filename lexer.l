%{

#include "parser-defs.h"
#include "parser.tab.h"

/*
 * You may want to use this string to assemble the lexeme
 * of string constants by adding the current matched character from yytext to it.
 * You can do this as buffer += yytext;
 */
string buffer;


/*
 * You may want to track the comment desting depth with this variable.
 */
int comment_depth = 0;

%}


%option noyywrap

WHITESPACE [ \t\f\r\v]+
NEWLINE [\n]
COMMA [,]
HD [#]
TL [!]
CONS [@]  
DOT [.]
PLUS [+]
MINUS [-]
TIMES [*]
DIVIDE [/]
LPAREN [(]
RPAREN [)]
AND [&]
OR [|]
EQ [=]
NEQ [<>]
GT [>]
GEQ [>=]
LT [<]
LEQ [<=]

ALPHA [a-zA-Z_]
DIGIT [0-9]
IDENTIFIER {ALPHA}({ALPHA}|{DIGIT})*
INT {DIGIT}+
FLOAT [-]?{DIGIT}+(\.{DIGIT}+)([eE][+\-]?{DIGIT}+)?
QUOTE ["]
LCOM [(*]
RCOM [*)]
 
%x STRING
%x COMMENT 

%%

{WHITESPACE} {
  /* Do nothing */
}

"(*" {
    comment_depth = 1;
    char prev = yyinput();
    if (prev == '\n') {
        curr_lineno++;
    }
    if (prev == EOF) {
        return TOKEN_ERROR;
    }
    
    char curr;

    while ((curr = yyinput())) {
        if (curr == EOF) {
            return TOKEN_ERROR;
        }
        if (curr == '\n') {
            curr_lineno++;
        }
        if (prev == '*' && curr == ')') {
            if (--comment_depth == 0) {
                break;
            }
        } else if (prev == '(' && curr == '*') {
            comment_depth++;
            prev = yyinput();
            if (prev == '\n') {
                curr_lineno++;
            }
            if (prev == EOF) {
                return TOKEN_ERROR;
            }
            continue;
        }
        prev = curr;
    }
}

"*)" {
    // right comment without left comment is a lexing error
    return TOKEN_ERROR;
}

(?i:readstring) {
    return TOKEN_READSTRING;
}

(?i:readint) {
    return TOKEN_READINT;
}

(?i:print) {
    return TOKEN_PRINT;
}

(?i:isnil) {
    return TOKEN_ISNIL;
}

(?i:len) {
    return TOKEN_LEN;
}

(?i:del) {
    return TOKEN_DEL;
}

"!" {
    return TOKEN_HD;
}

"#" {
    return TOKEN_TL;
}

"@" {
    return TOKEN_CONS;
}

":" {
    return TOKEN_COLON;
}

(?i:nil) {
    return TOKEN_NIL;
}

"." {
    return TOKEN_DOT;
}

"*" {
    return TOKEN_TIMES;
}

"/" {
    return TOKEN_DIVIDE;
}
(?i:with) {
    return TOKEN_WITH;
}

(?i:let) {
    return TOKEN_LET;
}

"+" {
    return TOKEN_PLUS;
}

"-" {
    return TOKEN_MINUS;
}

"(" {
    return TOKEN_LPAREN;
}

")" {
    return TOKEN_RPAREN;
}

"[" {
    return TOKEN_LBRACKET;
}

"]" {
    return TOKEN_RBRACKET;
}

"{" {
    return TOKEN_LCURLY;
}

"}" {
    return TOKEN_RCURLY;
}

"&" {
    return TOKEN_AND;
}

"|" {
    return TOKEN_OR;
}

"=" {
    return TOKEN_EQ;
}

"<>" {
    return TOKEN_NEQ;
}

">" {
    return TOKEN_GT;
}

">=" {
    return TOKEN_GEQ;
}

"<" {
    return TOKEN_LT;
}

"<=" {
    return TOKEN_LEQ;
}

(?i:if) {
    return TOKEN_IF;
}

(?i:then) {
    return TOKEN_THEN;
}

(?i:else) {
    return TOKEN_ELSE;
}

(?i:lambda) {
    return TOKEN_LAMBDA;
}

(?i:fun) {
    return TOKEN_FUN;
}

(?i:in) {
    return TOKEN_IN;
}

{NEWLINE} {
    /* Do nothing, but increment line numbers */
    curr_lineno++;
}

"," {
    return TOKEN_COMMA;
}


{IDENTIFIER} {
    SET_LEXEME(yytext);
    return TOKEN_IDENTIFIER;
}

{INT} {
    SET_LEXEME(yytext);
    return TOKEN_INT;
}

{FLOAT} {
    SET_LEXEME(yytext);
    return TOKEN_FLOAT;
}

{QUOTE} {
    buffer = "";
    while (char c = yyinput()) {
        if (c == EOF) {
            return TOKEN_ERROR;
        }
        if (c == '\n') {
            curr_lineno++;
        }
        if (c == '"') {
            break;
        }
        buffer += c;
    }
    SET_LEXEME(buffer);
    return TOKEN_STRING;
}

. {
    /* Leave this rule at the end of our lexer 
       to "eat up" all illegal strings */
    SET_LEXEME("Unexpected character in input");
    return TOKEN_ERROR;
}


%%

