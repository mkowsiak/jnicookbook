# recipe № 054 - Hello Scala!

This is my first sample related to Scala. And this time, I mix it with JNA. I am not quite a fan of JNA, but hey, why not trying something new :)

In this sample I call method of class HelloWorld.


```
class HelloWorld {
  public:
    bool displayMessage(wchar_t *str);
};

bool HelloWorld::displayMessage(wchar_t *str)
{
  ...
}
```

note that in order to make `C++` symbols visible for `JVM` we have to go via `extern C`. In this case, I have one to one mapping of `C` style method for each `C++` method inside `HelloWorld` class. In this case, there is only one function.

```
extern "C" {

bool displayMessageWrapper(wchar_t *str)
{
  ...
}

}
```

Once everything is compiled, you can see how `WString` object is passed to `C++` and used inside native code.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo054
    > make all
    > make test
    > make clean