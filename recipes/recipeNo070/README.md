# recipe № 070 - Passing structure by reference using JNA

This sample presents how to pass `C` structure (allocated in `Java`) into `C` code (via `JNA`). Then, I fill in passed structure (inside native code) return it back (to `Java`) and retrieve values inside `Java` code.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo070
    > make all
    > make test
    > make clean
