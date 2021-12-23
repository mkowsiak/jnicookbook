# recipe № 071 - Be carefull with errno. It can bite.

This sample is the illustration of potential issues related to `errno` (you can read about `errno` here: [IBM](https://www.ibm.com/developerworks/aix/library/au-errnovariable/index.html)) also, you can read about some good practices here: [The CERT ® C Coding Standard: 98 Rules for Developing Safe, Reliable, and Secure Systems, Second Edition](https://learning.oreilly.com/library/view/the-cert/9780133812275/)

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo071
    > make all
    > make test
    > make clean
