# recipe № 035 - running simple JNI code from inside JAR file

This sample code shows how to run simple JNI based code - `Hello world`

This time, we are extracting native library from inside of JAR. And, in addition to that we extract libs that
JNI lib depends on.

We have to change working dir to some temporary location in order to resolve shared libs locations.
