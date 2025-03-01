# recipe № 080 - Parsing string with date inside JNI

This is a sample that illustrates how to parse `Date` inside `JNI` and pass it back to `Java`.

```
JNIEXPORT jobject JNICALL Java_recipeNo080_redux_ParseDate_parse
  (JNIEnv * env, jstring obj) {

  /* Parse date and return it back */

}
```

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo080
    > make all
    > make test
    > make clean
