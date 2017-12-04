
# General Usage
Filtering is "smart-case" sensitive;
Use the TAB key to accept a completion and continue pressing TAB to cycle through the completions


# C-family Semantic Completion

2 methods
*  Option 1: Use a compilation database
    ...
* Option2: Provide the flags manually
YCM looks for a .ycm_extra_conf.py file in the directory of the opened file or in any directory above it in the hierarchy (recursively)
* NOTE: It is highly recommended to include -x <language> flag to libclang. This is so that the correct language is detected, particularly for header files. Common values are -x c for C, -x c++ for C++ and -x objc for Objective-C.



# install on ubuntu

Install development tools and CMake:

sudo apt-get install build-essential cmake
Make sure you have Python headers installed:

sudo apt-get install python-dev python3-dev
Compiling YCM with semantic support for C-family languages:

cd ~/.vim/bundle/YouCompleteMe
./install.py --clang-completer
Compiling YCM without semantic support for C-family languages:

cd ~/.vim/bundle/YouCompleteMe
./install.py
The following additional language support options are available:

C# support: install Mono and add --omnisharp-completer when calling ./install.py.
Go support: install Go and add --gocode-completer when calling ./install.py.
TypeScript support: install Node.js and npm then install the TypeScript SDK with npm install -g typescript.
JavaScript support: install Node.js and npm and add --tern-completer when calling ./install.py.
Rust support: install Rust and add --racer-completer when calling ./install.py.
To simply compile with everything enabled, there's a --all flag.  So, to install with all language features, ensure xbuild, go, tsserver, node, npm, rustc, and cargo tools are installed and in your PATH, then simply run:

cd ~/.vim/bundle/YouCompleteMe
./install.py --all
That's it. You're done. Refer to the User Guide section on how to use YCM. Don't forget that if you want the C-family semantic completion engine to work, you will need to provide the compilation flags for your project to YCM. It's all in the User Guide.

YCM comes with sane defaults for its options, but you still may want to take a look at what's available for configuration. There are a few interesting options that are conservatively turned off by default that you may want to turn on.

