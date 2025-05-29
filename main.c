#include <string.h>
#include <stdio.h>
#include <tree_sitter/api.h>
#include <assert.h>

TSLanguage *tree_sitter_janet_simple();

int main() {

  TSParser *parser = ts_parser_new();
  ts_parser_set_language(parser, tree_sitter_janet_simple());

  char *source = "``long string``";

  TSTree *tree =
    ts_parser_parse_string(parser, NULL, source, strlen(source));

  TSNode root = ts_tree_root_node(tree);

  printf("\nParse tree:\n%s\n", ts_node_string(root));

  return 0;
}
