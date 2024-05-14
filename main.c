/*
 * Author: Prashant Divate
 * Description: Sample native C application which will test communication with sentry server
 *
 * This program demonstrates connection to specified DSN to trigger message event
 *
 *
 * Usage:
 * - Compile: gcc -o main main.c
 * - Run: ./main
 *
 *
 */

#include "sentry.h"

int main(void) {
  sentry_options_t *options = sentry_options_new();
  sentry_options_set_dsn(options, "http://32ca5b715ed047e3888f7105764c4c45@151.100.91.112:9000/2");
  sentry_options_set_handler_path(options, "/home/prashant/sentry.io/sampleapp/crashpad_handler");
  sentry_options_set_database_path(options, ".sentry-native");
  sentry_options_set_release(options, "my-project-name@2.3.12");
  sentry_options_set_debug(options, 1);
  sentry_init(options);

  /* ....user space code.... */

  sentry_capture_event(sentry_value_new_message_event(
  /*   level */ SENTRY_LEVEL_INFO,
  /*  logger */ "custom",
  /* message */ "It works!"
  ));

  sentry_close();  // flush data to sentry server
}
