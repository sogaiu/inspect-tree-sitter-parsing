#include <string.h>
#include <stdio.h>
#include <tree_sitter/api.h>
#include <assert.h>

TSLanguage *tree_sitter_janet_simple();

void log_by_printf(void *payload, TSLogType type, const char *message) {
  (void)payload;
  if (type == TSLogTypeLex) {
    printf("  %s\n", message);
  } else {
    printf("%s\n", message);
  }
}

int main() {

  TSParser *parser = ts_parser_new();
  ts_parser_set_language(parser, tree_sitter_janet_simple());

  // XXX: uncomment following if `tree-sitter parse -d` output desired
  /*
  TSLogger logger = {parser, log_by_printf};
  ts_parser_set_logger(parser, logger);
  */

  char *source = "``long string``";

  TSTree *tree =
    ts_parser_parse_string(parser, NULL, source, strlen(source));

  TSNode root = ts_tree_root_node(tree);

  printf("\nParse tree:\n%s\n", ts_node_string(root));

  return 0;
}

