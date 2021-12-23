# recipe № D003 - Simple code that helps to show how to investigate memory leaks using Instruments

This one is a super simple memory allocator. It will consume as much memory as possible.

```
JNIEXPORT jboolean JNICALL Java_recipeNoD003_redux_AllocateMemory_allocate
  (JNIEnv * env, jclass obj, jint size) {

  ...

  malloc( size );

  ...

}
```

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNoD003
    > make all
    > make test
    > make clean
