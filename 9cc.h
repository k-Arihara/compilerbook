#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  TK_RESERVED,
  TK_IDENT,
  TK_NUM,
  TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
  TokenKind kind;
  Token* next;
  int val;
  char* str;
  int len;
};

typedef enum {
  ND_ADD,        // +
  ND_SUB,        // -
  ND_MUL,        // *
  ND_DIV,        // /
  ND_ASSIGN,     // =
  ND_EXPR_STMT,  // ;
  ND_EQ,         // ==
  ND_NE,         // !=
  ND_LT,         // LT
  ND_LE,         // <=
  ND_LVAR,       // ローカル変数
  ND_NUM,        // Integer
} NodeKind;

typedef struct Node Node;

struct Node {
  NodeKind kind;
  Node* lhs;
  Node* rhs;
  int val; // kindがND_NUMの場合のみ
  int offset; // kindがND_LVARの場合のみ
};

typedef struct LVar LVar;

struct LVar{
  LVar* next;
  char* name;
  int len;
  int offset;
};

Node* program();
Node* stmt();
Node* expr();
Node* assign();
Node* equality();
Node* relational();
Node* add();
Node* mul();
Node* unary();
Node* primary();

void gen(Node* node);
Token* tokenize(char* p);