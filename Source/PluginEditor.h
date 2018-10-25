/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class Iir_filterAudioProcessorEditor  : public AudioProcessorEditor
                                        //private Slider::Listener

{
public:
    Iir_filterAudioProcessorEditor (Iir_filterAudioProcessor&, AudioProcessorValueTreeState&);
    ~Iir_filterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    //void sliderValueChanged(Slider* slider) override;

private:
    AudioProcessorValueTreeState& valueStateTree;
    
    Slider filterCutoffDial;
    Label filterCutoffLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    
    Slider filterResDial;
    Label filterResLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Iir_filterAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Iir_filterAudioProcessorEditor)
};
