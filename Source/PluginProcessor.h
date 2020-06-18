/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class SummativeAssessmentAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SummativeAssessmentAudioProcessor();
    ~SummativeAssessmentAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    int lastSampleRate;
    void updateFilter();
    void updateParameters();
    float mixValue = 1.0f; //range will be 0.0 to 1.0
   
   AudioProcessorValueTreeState tree;

private:
    std::atomic<float>* quantParam = nullptr;
    std::atomic<float>* lowPassParam = nullptr;
    std::atomic<float>* hiPassParam = nullptr;
    dsp::StateVariableFilter::Filter<float>  lowPassFilter;
    dsp::StateVariableFilter::Parameters<float> lowPassParams;
    dsp::StateVariableFilter::Filter<float>  hiPassFilter;
    dsp::StateVariableFilter::Parameters<float> hiPassParams;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SummativeAssessmentAudioProcessor)
};
