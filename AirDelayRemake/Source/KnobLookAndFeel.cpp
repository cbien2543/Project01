/*
  ==============================================================================

    KnobLookAndFeel.cpp
    Created: 28 Apr 2025 7:07:21pm
    Author:  Chris Bienvenu

  ==============================================================================
*/

#include "KnobLookAndFeel.h"
#include "BinaryData.h"   

KnobLookAndFeel::KnobLookAndFeel()
{
    // Table
    static const struct { const void* data; int size; } frameRes[] = {
        { BinaryData::Knob_small_0000_png, BinaryData::Knob_small_0000_pngSize },
            { BinaryData::Knob_small_0001_png, BinaryData::Knob_small_0001_pngSize },
            { BinaryData::Knob_small_0002_png, BinaryData::Knob_small_0002_pngSize },
            { BinaryData::Knob_small_0003_png, BinaryData::Knob_small_0003_pngSize },
            { BinaryData::Knob_small_0004_png, BinaryData::Knob_small_0004_pngSize },
            { BinaryData::Knob_small_0005_png, BinaryData::Knob_small_0005_pngSize },
            { BinaryData::Knob_small_0006_png, BinaryData::Knob_small_0006_pngSize },
            { BinaryData::Knob_small_0007_png, BinaryData::Knob_small_0007_pngSize },
            { BinaryData::Knob_small_0008_png, BinaryData::Knob_small_0008_pngSize },
            { BinaryData::Knob_small_0009_png, BinaryData::Knob_small_0009_pngSize },
            { BinaryData::Knob_small_0010_png, BinaryData::Knob_small_0010_pngSize },
            { BinaryData::Knob_small_0011_png, BinaryData::Knob_small_0011_pngSize },
            { BinaryData::Knob_small_0012_png, BinaryData::Knob_small_0012_pngSize },
            { BinaryData::Knob_small_0013_png, BinaryData::Knob_small_0013_pngSize },
            { BinaryData::Knob_small_0014_png, BinaryData::Knob_small_0014_pngSize },
            { BinaryData::Knob_small_0015_png, BinaryData::Knob_small_0015_pngSize },
            { BinaryData::Knob_small_0016_png, BinaryData::Knob_small_0016_pngSize },
            { BinaryData::Knob_small_0017_png, BinaryData::Knob_small_0017_pngSize },
            { BinaryData::Knob_small_0018_png, BinaryData::Knob_small_0018_pngSize },
            { BinaryData::Knob_small_0019_png, BinaryData::Knob_small_0019_pngSize },
            { BinaryData::Knob_small_0020_png, BinaryData::Knob_small_0020_pngSize },
            { BinaryData::Knob_small_0021_png, BinaryData::Knob_small_0021_pngSize },
            { BinaryData::Knob_small_0022_png, BinaryData::Knob_small_0022_pngSize },
            { BinaryData::Knob_small_0023_png, BinaryData::Knob_small_0023_pngSize },
            { BinaryData::Knob_small_0024_png, BinaryData::Knob_small_0024_pngSize },
            { BinaryData::Knob_small_0025_png, BinaryData::Knob_small_0025_pngSize },
            { BinaryData::Knob_small_0026_png, BinaryData::Knob_small_0026_pngSize },
            { BinaryData::Knob_small_0027_png, BinaryData::Knob_small_0027_pngSize },
            { BinaryData::Knob_small_0028_png, BinaryData::Knob_small_0028_pngSize },
            { BinaryData::Knob_small_0029_png, BinaryData::Knob_small_0029_pngSize },
            { BinaryData::Knob_small_0030_png, BinaryData::Knob_small_0030_pngSize },
            { BinaryData::Knob_small_0031_png, BinaryData::Knob_small_0031_pngSize },
            { BinaryData::Knob_small_0032_png, BinaryData::Knob_small_0032_pngSize },
            { BinaryData::Knob_small_0033_png, BinaryData::Knob_small_0033_pngSize },
            { BinaryData::Knob_small_0034_png, BinaryData::Knob_small_0034_pngSize },
            { BinaryData::Knob_small_0035_png, BinaryData::Knob_small_0035_pngSize },
            { BinaryData::Knob_small_0036_png, BinaryData::Knob_small_0036_pngSize },
            { BinaryData::Knob_small_0037_png, BinaryData::Knob_small_0037_pngSize },
            { BinaryData::Knob_small_0038_png, BinaryData::Knob_small_0038_pngSize },
            { BinaryData::Knob_small_0039_png, BinaryData::Knob_small_0039_pngSize },
            { BinaryData::Knob_small_0040_png, BinaryData::Knob_small_0040_pngSize },
            { BinaryData::Knob_small_0041_png, BinaryData::Knob_small_0041_pngSize },
            { BinaryData::Knob_small_0042_png, BinaryData::Knob_small_0042_pngSize },
            { BinaryData::Knob_small_0043_png, BinaryData::Knob_small_0043_pngSize },
            { BinaryData::Knob_small_0044_png, BinaryData::Knob_small_0044_pngSize },
            { BinaryData::Knob_small_0045_png, BinaryData::Knob_small_0045_pngSize },
            { BinaryData::Knob_small_0046_png, BinaryData::Knob_small_0046_pngSize },
            { BinaryData::Knob_small_0047_png, BinaryData::Knob_small_0047_pngSize },
            { BinaryData::Knob_small_0048_png, BinaryData::Knob_small_0048_pngSize },
            { BinaryData::Knob_small_0049_png, BinaryData::Knob_small_0049_pngSize },
            { BinaryData::Knob_small_0050_png, BinaryData::Knob_small_0050_pngSize },
            { BinaryData::Knob_small_0051_png, BinaryData::Knob_small_0051_pngSize },
            { BinaryData::Knob_small_0052_png, BinaryData::Knob_small_0052_pngSize },
            { BinaryData::Knob_small_0053_png, BinaryData::Knob_small_0053_pngSize },
            { BinaryData::Knob_small_0054_png, BinaryData::Knob_small_0054_pngSize },
            { BinaryData::Knob_small_0055_png, BinaryData::Knob_small_0055_pngSize },
            { BinaryData::Knob_small_0056_png, BinaryData::Knob_small_0056_pngSize },
            { BinaryData::Knob_small_0057_png, BinaryData::Knob_small_0057_pngSize },
            { BinaryData::Knob_small_0058_png, BinaryData::Knob_small_0058_pngSize },
            { BinaryData::Knob_small_0059_png, BinaryData::Knob_small_0059_pngSize },
            { BinaryData::Knob_small_0060_png, BinaryData::Knob_small_0060_pngSize },
            { BinaryData::Knob_small_0061_png, BinaryData::Knob_small_0061_pngSize },
            { BinaryData::Knob_small_0062_png, BinaryData::Knob_small_0062_pngSize },
            { BinaryData::Knob_small_0063_png, BinaryData::Knob_small_0063_pngSize },
            { BinaryData::Knob_small_0064_png, BinaryData::Knob_small_0064_pngSize },
            { BinaryData::Knob_small_0065_png, BinaryData::Knob_small_0065_pngSize },
            { BinaryData::Knob_small_0066_png, BinaryData::Knob_small_0066_pngSize },
            { BinaryData::Knob_small_0067_png, BinaryData::Knob_small_0067_pngSize },
            { BinaryData::Knob_small_0068_png, BinaryData::Knob_small_0068_pngSize },
            { BinaryData::Knob_small_0069_png, BinaryData::Knob_small_0069_pngSize },
            { BinaryData::Knob_small_0070_png, BinaryData::Knob_small_0070_pngSize },
            { BinaryData::Knob_small_0071_png, BinaryData::Knob_small_0071_pngSize },
            { BinaryData::Knob_small_0072_png, BinaryData::Knob_small_0072_pngSize },
            { BinaryData::Knob_small_0073_png, BinaryData::Knob_small_0073_pngSize },
            { BinaryData::Knob_small_0074_png, BinaryData::Knob_small_0074_pngSize },
            { BinaryData::Knob_small_0075_png, BinaryData::Knob_small_0075_pngSize },
            { BinaryData::Knob_small_0076_png, BinaryData::Knob_small_0076_pngSize },
            { BinaryData::Knob_small_0077_png, BinaryData::Knob_small_0077_pngSize },
            { BinaryData::Knob_small_0078_png, BinaryData::Knob_small_0078_pngSize },
            { BinaryData::Knob_small_0079_png, BinaryData::Knob_small_0079_pngSize },
            { BinaryData::Knob_small_0080_png, BinaryData::Knob_small_0080_pngSize },
            { BinaryData::Knob_small_0081_png, BinaryData::Knob_small_0081_pngSize },
            { BinaryData::Knob_small_0082_png, BinaryData::Knob_small_0082_pngSize },
            { BinaryData::Knob_small_0083_png, BinaryData::Knob_small_0083_pngSize },
            { BinaryData::Knob_small_0084_png, BinaryData::Knob_small_0084_pngSize },
            { BinaryData::Knob_small_0085_png, BinaryData::Knob_small_0085_pngSize },
            { BinaryData::Knob_small_0086_png, BinaryData::Knob_small_0086_pngSize },
            { BinaryData::Knob_small_0087_png, BinaryData::Knob_small_0087_pngSize },
            { BinaryData::Knob_small_0088_png, BinaryData::Knob_small_0088_pngSize },
            { BinaryData::Knob_small_0089_png, BinaryData::Knob_small_0089_pngSize },
            { BinaryData::Knob_small_0090_png, BinaryData::Knob_small_0090_pngSize },
            { BinaryData::Knob_small_0091_png, BinaryData::Knob_small_0091_pngSize },
            { BinaryData::Knob_small_0092_png, BinaryData::Knob_small_0092_pngSize },
            { BinaryData::Knob_small_0093_png, BinaryData::Knob_small_0093_pngSize },
            { BinaryData::Knob_small_0094_png, BinaryData::Knob_small_0094_pngSize },
            { BinaryData::Knob_small_0095_png, BinaryData::Knob_small_0095_pngSize },
            { BinaryData::Knob_small_0096_png, BinaryData::Knob_small_0096_pngSize },
            { BinaryData::Knob_small_0097_png, BinaryData::Knob_small_0097_pngSize },
            { BinaryData::Knob_small_0098_png, BinaryData::Knob_small_0098_pngSize },
            { BinaryData::Knob_small_0099_png, BinaryData::Knob_small_0099_pngSize },
            { BinaryData::Knob_small_0100_png, BinaryData::Knob_small_0100_pngSize },
            { BinaryData::Knob_small_0101_png, BinaryData::Knob_small_0101_pngSize },
            { BinaryData::Knob_small_0102_png, BinaryData::Knob_small_0102_pngSize },
            { BinaryData::Knob_small_0103_png, BinaryData::Knob_small_0103_pngSize },
            { BinaryData::Knob_small_0104_png, BinaryData::Knob_small_0104_pngSize },
            { BinaryData::Knob_small_0105_png, BinaryData::Knob_small_0105_pngSize },
            { BinaryData::Knob_small_0106_png, BinaryData::Knob_small_0106_pngSize },
            { BinaryData::Knob_small_0107_png, BinaryData::Knob_small_0107_pngSize },
            { BinaryData::Knob_small_0108_png, BinaryData::Knob_small_0108_pngSize },
            { BinaryData::Knob_small_0109_png, BinaryData::Knob_small_0109_pngSize },
            { BinaryData::Knob_small_0110_png, BinaryData::Knob_small_0110_pngSize },
            { BinaryData::Knob_small_0111_png, BinaryData::Knob_small_0111_pngSize },
            { BinaryData::Knob_small_0112_png, BinaryData::Knob_small_0112_pngSize },
            { BinaryData::Knob_small_0113_png, BinaryData::Knob_small_0113_pngSize },
            { BinaryData::Knob_small_0114_png, BinaryData::Knob_small_0114_pngSize },
            { BinaryData::Knob_small_0115_png, BinaryData::Knob_small_0115_pngSize },
            { BinaryData::Knob_small_0116_png, BinaryData::Knob_small_0116_pngSize },
            { BinaryData::Knob_small_0117_png, BinaryData::Knob_small_0117_pngSize },
            { BinaryData::Knob_small_0118_png, BinaryData::Knob_small_0118_pngSize },
            { BinaryData::Knob_small_0119_png, BinaryData::Knob_small_0119_pngSize },
            { BinaryData::Knob_small_0120_png, BinaryData::Knob_small_0120_pngSize },
            { BinaryData::Knob_small_0121_png, BinaryData::Knob_small_0121_pngSize },
            { BinaryData::Knob_small_0122_png, BinaryData::Knob_small_0122_pngSize },
            { BinaryData::Knob_small_0123_png, BinaryData::Knob_small_0123_pngSize },
            { BinaryData::Knob_small_0124_png, BinaryData::Knob_small_0124_pngSize },
            { BinaryData::Knob_small_0125_png, BinaryData::Knob_small_0125_pngSize },
            { BinaryData::Knob_small_0126_png, BinaryData::Knob_small_0126_pngSize },
            { BinaryData::Knob_small_0127_png, BinaryData::Knob_small_0127_pngSize }
        };


    const int numFrames = int (std::size(frameRes));
    knobFrames.ensureStorageAllocated(numFrames);

    for (int i = 0; i < numFrames; ++i)
    {
        auto img = juce::ImageCache::getFromMemory(frameRes[i].data, frameRes[i].size);
        jassert(img.isValid());  // catches missing resources in debug
        knobFrames.add(img);
    }
}

void KnobLookAndFeel::drawRotarySlider(juce::Graphics& g,
                                       int x, int y, int width, int height,
                                       float sliderPos,
                                       float /*startAngle*/, float /*endAngle*/,
                                       juce::Slider& /*slider*/)
{
    // pick the correct frame
    int frameIndex = juce::jlimit(0,
                         knobFrames.size() - 1,
                         int(sliderPos * (knobFrames.size() - 1) + 0.5f));
    auto& img = knobFrames.getReference(frameIndex);

    // 10% padding on each side
    float padX = width  * 0.01f;
    float padY = height * 0.01f;
    juce::Rectangle<float> dest ((float)x + padX,
                                 (float)y + padY,
                                 width  - padX * 2.0f,
                                 height - padY * 2.0f);

    // compute scale to fit image inside dest without distortion
    float imgW = (float) img.getWidth();
    float imgH = (float) img.getHeight();
    float scale = juce::jmin(dest.getWidth()  / imgW,
                             dest.getHeight() / imgH);

    // center a scaled rectangle inside 'dest'
    auto finalRect = dest.withSizeKeepingCentre(imgW * scale,
                                                imgH * scale);

    // draw the image into that rect
    g.drawImage(img,
                finalRect.getX(), finalRect.getY(),
                finalRect.getWidth(), finalRect.getHeight(),
                0, 0, img.getWidth(), img.getHeight());
}
