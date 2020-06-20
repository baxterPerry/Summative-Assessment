/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SummativeAssessmentAudioProcessorEditor::SummativeAssessmentAudioProcessorEditor (SummativeAssessmentAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), tree (vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
        setSize (750, 300);
    
    
        inputGainSlider.setRange(0.0, 3.0);
        inputGainSlider.setValue(1.0);
        inputGainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        inputGainSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        inputGainSlider.setLookAndFeel(&bar2LookAndFeel);
    
    
        quantSlider.setRange(0.0, 300.0);
        quantSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        quantSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        quantSlider.setValue(10.0);
        quantSlider.setLookAndFeel(&anotherLookAndFeel);
    
    
        lowPassSlider.setRange(20.0, 20000.0);
        lowPassSlider.setValue(20000.0);
        lowPassSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        lowPassSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        lowPassSlider.setLookAndFeel(&anotherLookAndFeel);
    
    
        hiPassSlider.setRange(20.0, 20000.0);
        hiPassSlider.setValue(20.0);
        hiPassSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        hiPassSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        hiPassSlider.setLookAndFeel(&otherLookAndFeel);
    
    
        mixSlider.setRange(0.0, 1.0);
        mixSlider.setValue(1.0);
        mixSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        mixSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
        mixSlider.setLookAndFeel(&bar2LookAndFeel);
    
    
        outputGainSlider.setRange(0.0, 3.0);
        outputGainSlider.setValue(1.0);
        outputGainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        outputGainSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        outputGainSlider.setLookAndFeel(&bar2LookAndFeel);
       
       getLookAndFeel().setColour(Slider::thumbColourId, Colours::lightgrey);
       getLookAndFeel().setColour(Slider::rotarySliderOutlineColourId, Colours::azure);
       getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::lightblue);
       
       otherLookAndFeel.setColour(Slider::thumbColourId, Colours::lightblue);
       otherLookAndFeel.setColour(Slider::rotarySliderOutlineColourId, Colours::lightgrey);
       otherLookAndFeel.setColour(Slider::rotarySliderFillColourId, Colours::azure);
       anotherLookAndFeel.setColour(Slider::thumbColourId, Colours::azure);
       anotherLookAndFeel.setColour(Slider::rotarySliderOutlineColourId, Colours::lightblue);
       anotherLookAndFeel.setColour(Slider::rotarySliderFillColourId, Colours::lightgrey);
       bar1LookAndFeel.setColour(Slider::trackColourId, Colours::lightgrey);
       bar2LookAndFeel.setColour(Slider::trackColourId, Colours::lightblue);
    
       
        addAndMakeVisible(inputGainSlider);
        inputGainSliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (tree, "inputGain", inputGainSlider));
        addAndMakeVisible(quantSlider);
        quantSliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (tree, "degradeAmount", quantSlider));
        addAndMakeVisible(lowPassSlider);
        lowPassSliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (tree, "lowCutoff", lowPassSlider));
        addAndMakeVisible(hiPassSlider);
        hiPassSliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (tree, "hiCutoff", hiPassSlider));
        addAndMakeVisible(mixSlider);
        mixSliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (tree, "mixAmount", mixSlider));
        addAndMakeVisible(outputGainSlider);
        outputGainSliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (tree, "outputGain", outputGainSlider));
    
        addAndMakeVisible(inputGainSliderLabel);
        inputGainSliderLabel.setText("Input Gain", dontSendNotification);
        inputGainSliderLabel.attachToComponent(&inputGainSlider, false);
        addAndMakeVisible(lowPassSliderLabel);
        lowPassSliderLabel.setText("Low Pass", dontSendNotification);
        lowPassSliderLabel.attachToComponent(&lowPassSlider, false);
        addAndMakeVisible(hiPassSliderLabel);
        hiPassSliderLabel.setText("High Pass", dontSendNotification);
        hiPassSliderLabel.attachToComponent(&hiPassSlider, false);
        addAndMakeVisible(quantSliderLabel);
        quantSliderLabel.setText("Quantisation", dontSendNotification);
        quantSliderLabel.attachToComponent(&quantSlider, false);
        addAndMakeVisible(mixSliderLabel);
        mixSliderLabel.setText("Mix", dontSendNotification);
        mixSliderLabel.attachToComponent(&mixSlider, false);
        addAndMakeVisible(outputGainSliderLabel);
        outputGainSliderLabel.setText("Output Gain", dontSendNotification);
        outputGainSliderLabel.attachToComponent(&outputGainSlider, false);
}

SummativeAssessmentAudioProcessorEditor::~SummativeAssessmentAudioProcessorEditor()
{
}

//==============================================================================
void SummativeAssessmentAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll (Colours::darkgrey);
    g.setFont (15.0f);
    
    //g.setColour(Colours::transparentBlack);
    g.fillRect(323, 120, 220, 110);
    
    inputGainSlider.setBounds(15, 82.5, 125, 175);
    quantSlider.setBounds(165, 75, 150, 200);
    lowPassSlider.setBounds(330, 100, 100, 150);
    hiPassSlider.setBounds(435, 100, 100, 150);
    mixSlider.setBounds(560, 82.5, 35, 150);
    outputGainSlider.setBounds(605, 82.5, 125, 175);
    
    
}

void SummativeAssessmentAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
