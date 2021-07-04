# recipeNo079 - Passing Java objects into C code

This sample code presents how to pass `Java` object and set its properties inside `C` code. In this sample I pass object of type `CustomClass` that contains both, primitive type and object of type String.

    package recipeNo079.redux;

    public class CustomClass {
        public int    iVal;
        public String sVal;
    }

To compile the code run

    make clean
    make 
    make test


