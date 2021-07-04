# recipe № 078 - Surprize, surprize ! My stack is so small.

This one is a very simple code to demonstrate that you have to be extra careful while playing with local variables in native code. It may happen that `Thread's` stack size won't be enough for you. The code is really simple. What we call from `JNI` wrapper is a plain stupid function

```
void huge_static() {

  // I want to have 1MB data blob inside function
  char huge_static_block[1024*1024];

  printf ("[huge_static] Hello world!\n");

}
```

Once you run it with default settings for `JVM` (64-bit) you will end up with stack size of 1024k. It will not be enough here. Note that `Thread` itself already consumed part of the stack.

The only way to avoid `SIGBUS`/`SIGSEGV` is to pass `-Xss2m` (or even bigger).

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo078
    > make all
    > make test
    > make clean
