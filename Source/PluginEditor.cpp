/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Iir_filterAudioProcessorEditor::Iir_filterAudioProcessorEditor (Iir_filterAudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), processor (p), valueStateTree (vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);
    
    //Cutoff Dial
    filterCutoffDial.setSliderStyle(Slider::RotaryVerticalDrag);
    filterCutoffDial.setRange(20.0f, 20000.0f, 0.1f);
    filterCutoffDial.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
    filterCutoffDial.setNumDecimalPlacesToDisplay(2);
    filterCutoffDial.setRange(20.0, 20000.0, 0.1);
    filterCutoffDial.setValue(600.0);
    filterCutoffDial.setTextValueSuffix(" Hz");
    addAndMakeVisible(filterCutoffDial);
    //filterCutoffDial.addListener(this);
    
    //Cutoff Dial Label
    addAndMakeVisible(filterCutoffLabel);
    filterCutoffLabel.setText("Cutoff", dontSendNotification);
    filterCutoffLabel.setJustificationType(Justification::centred);
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment(valueStateTree, "cutoff", filterCutoffDial);
    
    //Resonance Dial
    filterResDial.setRange(0.1f, 5.0f);
    filterResDial.setValue(0.76f);
    filterResDial.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
    filterResDial.setNumDecimalPlacesToDisplay(2);
    filterResDial.setSliderStyle(Slider::RotaryVerticalDrag);
    //filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
    //Resonance Dial Label
    addAndMakeVisible(filterResDial);
    filterResLabel.setText("Resonance", dontSendNotification);
    filterResLabel.setJustificationType(Justification::centred);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment(valueStateTree, "resonance", filterResDial);
}

Iir_filterAudioProcessorEditor::~Iir_filterAudioProcessorEditor()
{
}

//==============================================================================
void Iir_filterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll (Colours::black);
    g.setColour (Colours::aqua);
    g.setFont (15.0f);
    g.drawFittedText ("IIR Filter", getLocalBounds(), Justification::centredTop, 1);
    //g.drawImageAt(Background, 0, 0);
}

void Iir_filterAudioProcessorEditor::resized()
{
    const int labelWidth = getWidth() / 2;
    const int labelHeight = 25;
    const int sliderWidth = getWidth() / 2;
    const int sliderHeight = getHeight() - labelHeight;
    
    filterCutoffDial.setBounds(0, 0, sliderWidth, sliderHeight);
    filterResDial.setBounds(sliderWidth, 0, sliderWidth, sliderHeight);
}
