/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SummativeAssessmentAudioProcessorEditor  : public AudioProcessorEditor
                                               {
public:
    SummativeAssessmentAudioProcessorEditor (SummativeAssessmentAudioProcessor&, AudioProcessorValueTreeState& );
    ~SummativeAssessmentAudioProcessorEditor();
    
    //typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
                                                   
                                                                                                

private:
   
    Slider quantSlider;
    Slider lowPassSlider;
    Slider hiPassSlider;
    Slider mixSlider;
    Slider inputGainSlider;
    Slider outputGainSlider;
                                                   
    Label quantSliderLabel;
    Label lowPassSliderLabel;
    Label hiPassSliderLabel;
    Label mixSliderLabel;
    Label inputGainSliderLabel;
    Label outputGainSliderLabel;
                                                   
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> quantSliderAttachment;
    //std::unique_ptr<SliderAttachment> lowPassAttachment;
    //std::unique_ptr<SliderAttachment> hiPassAttachment;
    //std::unique_ptr<SliderAttachment> quantSliderAttachment;
    //std::unique_ptr<SliderAttachment> quantSliderAttachment;
    //std::unique_ptr<SliderAttachment> quantSliderAttachment;
    
    LookAndFeel_V4 otherLookAndFeel;
    LookAndFeel_V4 bar1LookAndFeel;
    LookAndFeel_V4 bar2LookAndFeel;
    LookAndFeel_V4 anotherLookAndFeel;
                                                   
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SummativeAssessmentAudioProcessor& processor;
    AudioProcessorValueTreeState& tree;
                                                   
                                                   
    public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sliderValue;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SummativeAssessmentAudioProcessorEditor)
};
