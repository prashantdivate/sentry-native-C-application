# sentry-native-C-application
C language native sample application for sentry.io testing

Make sure to change  DSN, crashpad_handler path and project name before moving to compilation


# compilation

gcc -o main main.c -I/home/prashant/sentry.io/sentry-native/install/include -L/home/prashant/sentry.io/sentry-native/install/lib -lsentry -I/home/prashant/sentry.io/crashpad/depot_tools/crashpad/crashpad -I/home/prashant/sentry.io/crashpad/depot_tools/crashpad/crashpad/third_party/mini_chromium/mini_chromium -L/home/prashant/sentry.io/sampleapp/mylib

# Usage

$ chmod a+x main
$ ./main

NOTE: when the binary is run it will send a log event to sentry dashboard
