# recipe № 043 - Settings environment variable inside JVM

JVM doesn't allow to set environmnent variables once it is loaded. But, why not use JNI
to get them set.

This approach might be useful in case you work with legacy code that expects
some information to be passed via environment variables.


