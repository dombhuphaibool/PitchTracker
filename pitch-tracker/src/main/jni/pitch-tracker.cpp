#include <jni.h>
#include <string>
#include "dywapitchtrack.h"

#ifdef __cplusplus
extern "C" {
#endif

dywapitchtracker sTrackingData;

JNIEXPORT jint JNICALL
Java_com_bandonleon_pitchtracker_PitchTracker_getNeedeSamples(JNIEnv *env, jobject instance,
                                                             jint minFrequency) {
    return dywapitch_neededsamplecount(minFrequency);
}

JNIEXPORT void JNICALL
Java_com_bandonleon_pitchtracker_PitchTracker_init(JNIEnv *env, jobject instance) {
    dywapitch_inittracking(&sTrackingData);
}

JNIEXPORT jdouble JNICALL
Java_com_bandonleon_pitchtracker_PitchTracker_computePitch(JNIEnv *env, jobject instance,
                                                          jdoubleArray samples_, jint startIdx,
                                                          jint sampleCount) {
    jdouble *samples = env->GetDoubleArrayElements(samples_, NULL);

    double pitchHz = dywapitch_computepitch(&sTrackingData, samples, startIdx, sampleCount);

    env->ReleaseDoubleArrayElements(samples_, samples, 0);

    return pitchHz;
}

#ifdef __cplusplus
}
#endif