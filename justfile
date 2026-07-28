alias c := compile
alias m := move

# command list
default:
    @just --list --unsorted

# compile the plugin
compile:
    BZFLAG_INCLUDE_DIR="../bzflag/include" BZFLAG_PLUGIN_DIR="../plugins" cmake -S . -B compile
    cmake --build compile

# move the plugin to bzfs monorepo
move:
    cp plugins/*.so ../bzfs/plugins/
