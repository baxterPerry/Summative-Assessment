/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SummativeAssessmentAudioProcessorEditor::SummativeAssessmentAudioProcessorEditor (SummativeAssessmentAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 300);
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
        mixSlider.setLookAndFeel(&bar1LookAndFeel);
    
       inputGainSlider.setRange(0.0, 3.0);
       inputGainSlider.setValue(1.0);
        inputGainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        inputGainSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
        inputGainSlider.setLookAndFeel(&bar2LookAndFeel);
       
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
    
        addAndMakeVisible(quantSlider);
       addAndMakeVisible(lowPassSlider);
       addAndMakeVisible(hiPassSlider);
        addAndMakeVisible(mixSlider);
        addAndMakeVisible(inputGainSlider);
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
  quantSlider.setBounds(15, 75, 150, 200);
  lowPassSlider.setBounds(165, 75, 150, 200);
  hiPassSlider.setBounds(315, 75, 150, 200);
  mixSlider.setBounds(485, 82.5, 25, 150);
  inputGainSlider.setBounds(545, 82.5, 25, 150);
}

void SummativeAssessmentAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
