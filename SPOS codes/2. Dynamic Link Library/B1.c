#include <jni.h>

#include <stdio.h>

#include <B1.h>



 JNIEXPORT int JNICALL Java_B1_add(JNIEnv *env, jobject obj, jint a, jint b)

 {

	printf("\n%d + %d = %d\n",a,b,(a+b));

	return 0;

 }
