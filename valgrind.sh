DEBUGINFOD_URLS="https://debuginfod.archlinux.org" G_SLICE=always-malloc valgrind --leak-check=full ./build/qsh-send/qsh-send "$@"
