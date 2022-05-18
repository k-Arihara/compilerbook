#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  TK_RESERVED,
  TK_NUM,
  TK_EOF,
} TokenKind;

struct Token {
  TokenKind kind;
  Token* next;
  int val;
  char* str;
  int len;
};

typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // LT
  ND_LE,  // <=
  ND_NUM, // Integer
} NodeKind;

struct Node {
  NodeKind kind;
  Node* lhs;
  Node* rhs;
  int val;
};

typedef struct Token Token;
typedef struct Node Node;

Node* expr();
Node* equality();
Node* relational();
Node* add();
Node* mul();
Node* primary();
Node* unary();