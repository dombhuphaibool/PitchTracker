package com.bandonleon.pitchtracker;

/**
 * Created by dombhuphaibool on 11/14/15.
 */
public class PitchTracker {

    private int mNeedeSamples;

    public PitchTracker(int minFequency) {
        mNeedeSamples = getNeedeSamples(minFequency);
        init();
    }

    public int getMinSamples() {
        return mNeedeSamples;
    }

    public double trackPitch(double[] samples, int startIdx, int sampleCount) {
        return computePitch(samples, startIdx, sampleCount);
    }

    private native int getNeedeSamples(int minFrequency);
    private native void init();
    private native double computePitch(double[] samples, int startIdx, int sampleCount);

    static {
        System.loadLibrary("pitch-tracker");
    }
}
