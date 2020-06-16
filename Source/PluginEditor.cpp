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
    gainSlider.setRange(0.0, 1.0);
       gainSlidertwo.setRange(0.0, 1.0);
       gainSliderthree.setRange(0.0, 1.0);
       gainSliderfour.setRange(0.0, 1.0);
       gainSliderfive.setRange(0.0, 1.0);
       gainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
       gainSlider.setValue(0.5);
       gainSlidertwo.setValue(0.5);
       gainSliderthree.setValue(0.5);
       gainSliderfour.setValue(0.5);
       gainSliderfive.setValue(0.5);
      
       gainSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
       gainSlidertwo.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
       gainSliderthree.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
       gainSliderfour.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
       gainSliderfive.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
       
       getLookAndFeel().setColour(Slider::thumbColourId, Colours::lightgrey);
       getLookAndFeel().setColour(Slider::rotarySliderOutlineColourId, Colours::azure);
       getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::lightblue);
       gainSlidertwo.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
       gainSliderthree.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
       gainSliderfour.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
       gainSliderfive.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
       gainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
       otherLookAndFeel.setColour(Slider::thumbColourId, Colours::lightblue);
       otherLookAndFeel.setColour(Slider::rotarySliderOutlineColourId, Colours::lightgrey);
       otherLookAndFeel.setColour(Slider::rotarySliderFillColourId, Colours::azure);
       anotherLookAndFeel.setColour(Slider::thumbColourId, Colours::azure);
       anotherLookAndFeel.setColour(Slider::rotarySliderOutlineColourId, Colours::lightblue);
       anotherLookAndFeel.setColour(Slider::rotarySliderFillColourId, Colours::lightgrey);
       bar1LookAndFeel.setColour(Slider::trackColourId, Colours::lightgrey);
       bar2LookAndFeel.setColour(Slider::trackColourId, Colours::lightblue);
       
       gainSliderthree.setLookAndFeel(&otherLookAndFeel);
       gainSliderfive.setLookAndFeel(&bar2LookAndFeel);
       gainSliderfour.setLookAndFeel(&bar1LookAndFeel);
       gainSlidertwo.setLookAndFeel(&anotherLookAndFeel);
         
       
    
        addAndMakeVisible(gainSlider);
       addAndMakeVisible(gainSlidertwo);
       addAndMakeVisible(gainSliderthree);
        addAndMakeVisible(gainSliderfour);
        addAndMakeVisible(gainSliderfive);
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
  gainSlider.setBounds(15, 75, 150, 200);
  gainSlidertwo.setBounds(165, 75, 150, 200);
  gainSliderthree.setBounds(315, 75, 150, 200);
  gainSliderfour.setBounds(485, 82.5, 25, 150);
  gainSliderfive.setBounds(545, 82.5, 25, 150);
}

void SummativeAssessmentAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
