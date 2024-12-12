[![Download](https://img.shields.io/badge/download-click%20here-red.svg)](https://github.com/mkowsiak/jnicookbook/archive/master.zip)
<p align="center">
  <img src="https://raw.githubusercontent.com/mkowsiak/jnicookbook/master/images/JNICookbookRedux.png"></a>
</p>

> If you are interested in stories with happy endings, you would better of reading some other book. In this book, not only there is no happy ending, there is no happy beginning, and very few happy things in the middle.
>
> -- Lemony Snicket, The Bad Beginning

Inside this book you can find JNI related codes that I have written over years of working with JNI. I was typically preparing small samples to test some particular concepts. Sometimes, I was preparing solutions for people who were desparatelly looking for help on `stackoverflow`. There is a companion material in form of text, figures, where I describe some topics in details. _JNI Cookbook_ page can be found here: [JNI Cookbook](http://jnicookbook.owsiak.org). Please note that I had no time, yet, to prepare nice and detailed explanation for each end every contept that is tackled in this book.

# Building and running

Seeing is believing. This is why I have decided to provide people with not only the description of some concepts, but with working sample code as well. The code you can find in this repository is an integral part of the book. 

The easiest way to build and run codes is to clone the repository and run all tests.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes
    > make all
    > make test
    > make clean
    
Remember that you can always run each and every sample separatelly. Simply call `make` inside given recipe. Let's say you want to run `recipeNo001`. All you have to do is to run

```
> cd jnicookbook/recipes/recipeNo001
> make
/Library/Java/JavaVirtualMachines/jdk-17.0.1.jdk/...
...
> make test
/Library/Java/JavaVirtualMachines/jdk-17.0.1.jdk/...
library: :./lib
Hello world!
```

<p align="center">
  <img src="https://raw.githubusercontent.com/mkowsiak/jnicookbook/master/images/compile.gif">
</p>
    
# Ready for Java 8 and onwards

_JNI Cookbook_ samples were adapted to `Java 17` release. You shouldn't experience any issues while working with most recent release of `Java`. If you have stuck with `Java 8` - for any reasons - you should be able to use samples as well.

_JNI Cookbook_ samples were tested with:

* JDK 1.8
* JDK 9
* JDK 10
* JDK 11
* JDK 12 
* JDK 13
* JDK 14
* JDK 15
* JDK 16
* JDK 17

# Debugging

Debugging JNI code is not quite like sitting on cloud nine. You have to attach to JVM where JNI code is running and debug native code using external tools (e.g.: `gdb`, `TotalView`, `lldb`). When it comes to debugging JNI code, you can find some hints inside _JNI Cookbook_ as well. Even more, you can find a screencast that demonstates how to debug JNI code using _IntelliJ IDEA_ and _CLion_. In fact, there are more to come. I plan to prepare one that will discuss `lldb`, one for `gdb`, and last but not least one for `TotalView` (this is, however, song of the future).

<p align="center">
  <a href="https://youtu.be/8Cjeq4l5COU"><img src="https://raw.githubusercontent.com/mkowsiak/jnicookbook/master/images/CLion.gif"></a>
</p>

# Requirements

At the moment, _JNI Cookbook_ targets Linux and macOS. It should work on both platforms without any issues.

# Setting up macOS system for JNI Cookbook

Make sure to install [XCode](https://itunes.apple.com/pl/app/xcode/id497799835?mt=12). Once installed, perform installation of `Command Line Tools`.

Make sure to install [OpenJDK 17](https://download.java.net/java/GA/jdk17.0.1/2a2082e5a09d4267845be086888add4f/12/GPL/openjdk-17.0.1_macos-x64_bin.tar.gz) or [Java SE Development Kit 17](https://www.oracle.com/java/technologies/downloads/#jdk17-mac)).

Once installed, make sure to set `JAVA_HOME` following way

```
export JAVA_HOME=$(/usr/libexec/java_home -v 17)
```

If you are one of those brave people who like to live at the edge, you can use the most recent version of [OpenJDK - JDK 19](https://download.java.net/java/early_access/jdk19/3/GPL/openjdk-19-ea+3_macos-x64_bin.tar.gz).

Once installed, make sure to set `JAVA_HOME` following way

```
export JAVA_HOME=$(/usr/libexec/java_home -v 19)
```

# Setting up Ubuntu system for JNI Cookbook

```
sudo apt install openjdk-17-jdk
sudo apt install git
sudo apt install make
sudo apt install gcc
sudo apt install g++

# Inside JNI Cookbook, all the Java stuff is based on JAVA_HOME
# variable - you need it inside the env.
export JAVA_HOME=`readlink -f $(which java) | sed 's|/bin/java||'`

# We need ./lib on LD_LIBRARY_PATH
# Rememer that inside JNI code we no longer use java.library.path
# when it comes to resolving location of the shared library.
# Inside JNI we base on system's way of locating the lib.
export LD_LIBRARY_PATH=./lib:${LD_LIBRARY_PATH}
```

# Setting up Scala

_JNI Cookbook_ contains `Scala` based samples. These samples are using `JNA` to call native code. Please make sure to install most recent version of `Scala` and `sbt`. This will allow you to avoid following error:

```
Exception in thread "main" java.io.IOError: 
    java.lang.RuntimeException: /packages cannot be represented as URI
```

At the time of writing these versions were, respectivelly: [Scala 3.0.1](https://github.com/lampepfl/dotty/releases/tag/3.1.0) and [sbt 1.6.0](https://www.scala-sbt.org/download.html).

# Nobody has time for that!

> Are you crazy? Do you think I have time for all that setup?

You are right, nobody has time for that. This is why this product comes with self sufficient, ready for immediate use, `Docker` file. Once you start the container, everything is there. All you have to do is to build the image and run the container.

```
> cd docker
> docker build -t jnicookbook .
> docker run -it jnicookbook
```

that's it. That's all you have to do, to get all the _JNI Cookbook_ samples ready for testing.

<p align="center">
  <img src="https://raw.githubusercontent.com/mkowsiak/jnicookbook/master/images/docker_jnicookbook.gif">
</p>

# It's no good reading about JNI in 2021

I won't force you to do so, but you are always welcome to read this book.

# I think this book is bad

> I think your book is not really that good (as some people say) and it's not interesting at all.

I totally agree. After all, this is a book related to low level coding. Have you ever read really interesting book that was describing low level coding? I really doubt it. These kind of books can be informative, they might be useful, but calling them entartaining, and really good books - that's euphemism.

Live is way too short to read dull books - like this one. This is why I have prepared a list of books you should have read instead. Each week, I will post a new book that is definitely more exciting and definitely worth way more of your time rather than this one. Stay tuned. [List of books that are way more interesting](https://github.com/mkowsiak/jnicookbook/tree/master/books).

# I don't like your book

I can't make everybody happy. Make sure to double check previous points.

# I think you should ...

No, thank you.

# I think it would be better if ...

No, thank you.

# Bibliography

This book wouldn't have existed if there were no great books on various topics it tackles.

- Java Native Interface Specification, by Oracle
- The Native Intefrace, by S. Liang
- Programming in Scala, by M. Odersky
- JNA documentation, by JNA project
- Komunikacja miedzy procesami w Unixie, by J. S. Gray (tlumaczenie: P. Kresak)
- The C Programming Language, by B.W. Kernighan, D. M. Ritchie
- C++, by B. Stroustrup

I always try to quote places I got inspiration from. Sometimes it's really hard to address each and every line of the code. If some quotations are still missing, it is unintentional. If you think I have missed some well known sources, please let me know, and I am happy to double check the source and update the `Bibliography` section if necesary.

# Table of contents - JNI based code

|Recipe № | Short description |
|---|---|
|[recipe&nbsp;№&nbsp;001](https://jnicookbook.owsiak.org/r001/index.html)|running simple JNI code [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo001)|
|[recipe&nbsp;№&nbsp;002](http://jnicookbook.owsiak.org/)|passing int value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo002)|
|[recipe&nbsp;№&nbsp;003](http://jnicookbook.owsiak.org/)|passing double value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo003)|
|[recipe&nbsp;№&nbsp;004](http://jnicookbook.owsiak.org/)|passing long value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo004)|
|[recipe&nbsp;№&nbsp;005](http://jnicookbook.owsiak.org/)|passing short value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo005)|
|[recipe&nbsp;№&nbsp;006](http://jnicookbook.owsiak.org/)|passing char value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo006)|
|[recipe&nbsp;№&nbsp;007](http://jnicookbook.owsiak.org/)|passing byte value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo007)|
|[recipe&nbsp;№&nbsp;008](http://jnicookbook.owsiak.org/)|passing boolean value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo008)|
|[recipe&nbsp;№&nbsp;009](http://jnicookbook.owsiak.org/)|passing java.lang.String value from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo009)|
|[recipe&nbsp;№&nbsp;010](http://jnicookbook.owsiak.org/)|passing java.lang.String value from C to Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo010)|
|[recipe&nbsp;№&nbsp;011](http://jnicookbook.owsiak.org/)|passing primitive types from C to Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo011)|
|[recipe&nbsp;№&nbsp;012](http://jnicookbook.owsiak.org/)|passing primitives array from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo012)|
|[recipe&nbsp;№&nbsp;013](http://jnicookbook.owsiak.org/)|passing primitives array from Java to C and back (commit changes) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo013)|
|[recipe&nbsp;№&nbsp;014](http://jnicookbook.owsiak.org/)|passing memory allocated in C back to Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo014)|
|[recipe&nbsp;№&nbsp;015](http://jnicookbook.owsiak.org/)|handling SIGSEGV/SIGBUS in JNI code (stop JVM from crashing) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo015)|
|[recipe&nbsp;№&nbsp;016](http://jnicookbook.owsiak.org/)|handling exit calls from external library called via JNI (atexit) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo016)|
|[recipe&nbsp;№&nbsp;017](http://jnicookbook.owsiak.org/)|handling exit calls from external library called via JNI (-Dexit) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo017)|
|[recipe&nbsp;№&nbsp;018](http://jnicookbook.owsiak.org/)|dynamic loading of library in JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo018)|
|[recipe&nbsp;№&nbsp;019](http://jnicookbook.owsiak.org/)|throwing exception from C code [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo019)|
|[recipe&nbsp;№&nbsp;020](http://jnicookbook.owsiak.org/)|accessing fields of object passed as argument [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo020)|
|[recipe&nbsp;№&nbsp;021](http://jnicookbook.owsiak.org/)|calling function from different source file [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo021)|
|[recipe&nbsp;№&nbsp;022](http://jnicookbook.owsiak.org/)|Java based daemon [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo022)|
|[recipe&nbsp;№&nbsp;023](http://jnicookbook.owsiak.org/)|calling code from another shared library [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo023)|
|[recipe&nbsp;№&nbsp;024](http://jnicookbook.owsiak.org/)|calling JNI methods from Threads and how to debug them using gdb [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo024)|
|recipe&nbsp;№&nbsp;025|calling C++ code from C wrapper [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo025)|
|recipe&nbsp;№&nbsp;026|passing 2D arrays from Java to C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo026)|
|[recipe&nbsp;№&nbsp;027](http://jnicookbook.owsiak.org/)|Calling class methods from multiple threads [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo027)|
|recipe&nbsp;№&nbsp;028|Calling JVM class from C (first draft for thread based computations) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo028)|
|[recipe&nbsp;№&nbsp;029](http://jnicookbook.owsiak.org/)|Running Java as daemon – main daemon’s loop in Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo029)|
|[recipe&nbsp;№&nbsp;030](http://jnicookbook.owsiak.org/)|Abstract method and native implementation [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo030)|
|recipe&nbsp;№&nbsp;031|Running simple JNI code from inside JAR file [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo031)|
|recipe&nbsp;№&nbsp;032|Calling JVM from multiple C threads [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo032)|
|recipe&nbsp;№&nbsp;033|Comparing execution time of "Hello world!" executed from JNI/JNA/ProcessBuilder [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo033)|
|recipe&nbsp;№&nbsp;034|Running simple JNI code from Outer class and Inner class [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo034)|
|recipe&nbsp;№&nbsp;035|Running simple JNI code from inside JAR file with libraries it depends on [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo035)|
|recipe&nbsp;№&nbsp;037|Passing HashMap to C code via JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo037)|
|recipe&nbsp;№&nbsp;038|Passing HashMap to C code via JNI (using two arrays) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo038)|
|recipe&nbsp;№&nbsp;039|Calling (from C) Java method that returns 2D array [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo039)|
|recipe&nbsp;№&nbsp;040|Passing ByteBuffer to C code via JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo040)|
|recipe&nbsp;№&nbsp;042|Passing Set of Strings to C code via JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo042)|
|recipe&nbsp;№&nbsp;043|Settings environment variable inside JVM via JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo043)|
|recipe&nbsp;№&nbsp;044|Getting info (inside JNI code) regarding current thread using java.lang.Thread [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo044)|
|[recipe&nbsp;№&nbsp;045](http://jnicookbook.owsiak.org/)|Returning vector<vector<float> > from C++ to Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo045)|
|recipe&nbsp;№&nbsp;046|Filling java.util.List (passed to JNI) with data - inside C++ [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo046)|
|recipe&nbsp;№&nbsp;047|Filling java.util.HashMap (passed to JNI) with data - inside C++ [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo047)|
|recipe&nbsp;№&nbsp;048|Returning map<int, int> from C++ to Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo048)|
|recipe&nbsp;№&nbsp;049|Redirecting JVM's System.out to file inside C code [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo049)|
|recipe&nbsp;№&nbsp;050|How to find location of JAR from JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo050)|
|recipe&nbsp;№&nbsp;051|Very simple, Java based, 'Hello world' code - calling it from C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo051)|
|recipe&nbsp;№&nbsp;052|Registering native symbols without System.load [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo052)|
|recipe&nbsp;№&nbsp;053|Accessing elements of array - GetByteArrayElements vs. GetPrimitiveArrayCritical [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo053)|
|recipe&nbsp;№&nbsp;054|Hello Scala! [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo054)|
|recipe&nbsp;№&nbsp;055|Unboxing primitive types from wrapper objects - method per type [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo055)|
|recipe&nbsp;№&nbsp;056|Unboxing primitive types from wrapper objects - one method and IsInstanceOf [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo056)|
|recipe&nbsp;№&nbsp;057|Hello Scala! I am passing structures! [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo057)|
|recipe&nbsp;№&nbsp;058|Passing "unsigned long" to JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo058)|
|recipe&nbsp;№&nbsp;059|Using code from static library inside JNI based code [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo059)|
|recipe&nbsp;№&nbsp;060|How to run Java code (with Log4j) from C [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo060)|
|recipe&nbsp;№&nbsp;061|Passing std::map<std::string, std::string> from C++ to Java [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo061)|
|recipe&nbsp;№&nbsp;063|Accessing fields of inner class [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo063)|
|recipe&nbsp;№&nbsp;064|Running simple JNI code - using JDK9 modules [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo064)|
|recipe&nbsp;№&nbsp;065|Very simple, Java based, 'Hello world' code - calling it from Objective-C (macOS only) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo065)|
|recipe&nbsp;№&nbsp;066|Embedding JVM inside macOS application bundle and calling JVM from Objective-C (macOS only) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo066)|
|recipe&nbsp;№&nbsp;067|Iterating over objects inside java.util.List - using get method [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo067)|
|recipe&nbsp;№&nbsp;068|Iterating over objects inside java.util.List - using java.util.Iterator [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo068)|
|recipe&nbsp;№&nbsp;069|Iterating over objects inside array of Objects (SimpleBean[]) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo069)|
|recipe&nbsp;№&nbsp;070|Passing structure by reference using JNA [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo070)|
|recipe&nbsp;№&nbsp;071|Be carefull with errno. It can bite. [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo071)|
|recipe&nbsp;№&nbsp;072|Handling errno using custom exception type [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo072)|
|recipe&nbsp;№&nbsp;073|Passing errno and errno string inside wrapper class [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo073)|
|recipe&nbsp;№&nbsp;074|Passing errno via JNI routine's arguments [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo074)|
|recipe&nbsp;№&nbsp;075|Returning object with number of fields from JNI (constructor) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo075)|
|recipe&nbsp;№&nbsp;076|Returning object with number of fields from JNI (setters) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo076)|
|recipe&nbsp;№&nbsp;077|Passing null as method argument inside JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo077)|
|recipe&nbsp;№&nbsp;078|Surprize, surprize ! My stack is so small. [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo078)|
|recipe&nbsp;№&nbsp;079|Passing String value from C via object passed as an argument[[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo079)|
|recipe&nbsp;№&nbsp;080|Parsing string with date inside JNI [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNo080)|
|[recipe&nbsp;№&nbsp;D001](http://jnicookbook.owsiak.org/)|debugging JNI code with CLion [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNoD001)|
|recipe&nbsp;№&nbsp;D003|Profiling JNI based code using Instruments.app (macOS only) [[source]](https://github.com/mkowsiak/jnicookbook/tree/master/recipes/recipeNoD003)|

[![Download](https://img.shields.io/badge/download-click%20here-red.svg)](https://github.com/mkowsiak/jnicookbook/archive/master.zip)

---
Copyright © 2015-2022 Michal K. Owsiak. All rights reserved.
