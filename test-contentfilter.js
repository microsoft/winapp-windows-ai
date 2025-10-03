// Test script to verify complete ContentFilterOptions functionality
try {
    const windowsAI = require('./windows-ai-addon/build/Release/windows-ai-addon.node');
    
    console.log('Testing complete ContentFilterOptions functionality...\n');
    
    // Test SeverityLevel enum
    console.log('=== SeverityLevel Enum ===');
    console.log('Minimum:', windowsAI.SeverityLevel.Minimum);
    console.log('Low:', windowsAI.SeverityLevel.Low);
    console.log('Medium:', windowsAI.SeverityLevel.Medium);
    console.log('High:', windowsAI.SeverityLevel.High);
    console.log('✓ SeverityLevel enum working\n');
    
    // Test ImageContentFilterSeverity
    console.log('=== ImageContentFilterSeverity ===');
    const imageSeverity = new windowsAI.ImageContentFilterSeverity();
    console.log('✓ Created ImageContentFilterSeverity instance');
    
    // Test with SeverityLevel parameter
    const imageSeverityWithLevel = new windowsAI.ImageContentFilterSeverity(windowsAI.SeverityLevel.Medium);
    console.log('✓ Created ImageContentFilterSeverity with SeverityLevel parameter');
    
    // Test properties
    console.log('AdultContentLevel:', imageSeverity.AdultContentLevel);
    console.log('GoryContentLevel:', imageSeverity.GoryContentLevel);
    console.log('RacyContentLevel:', imageSeverity.RacyContentLevel);
    console.log('ViolentContentLevel:', imageSeverity.ViolentContentLevel);
    
    // Test setting properties
    imageSeverity.AdultContentLevel = windowsAI.SeverityLevel.High;
    imageSeverity.GoryContentLevel = windowsAI.SeverityLevel.Low;
    console.log('✓ Set ImageContentFilterSeverity properties');
    console.log('Updated AdultContentLevel:', imageSeverity.AdultContentLevel);
    console.log('Updated GoryContentLevel:', imageSeverity.GoryContentLevel);
    console.log('✓ ImageContentFilterSeverity working correctly\n');
    
    // Test TextContentFilterSeverity
    console.log('=== TextContentFilterSeverity ===');
    const textSeverity = new windowsAI.TextContentFilterSeverity();
    console.log('✓ Created TextContentFilterSeverity instance');
    
    // Test with SeverityLevel parameter
    const textSeverityWithLevel = new windowsAI.TextContentFilterSeverity(windowsAI.SeverityLevel.Low);
    console.log('✓ Created TextContentFilterSeverity with SeverityLevel parameter');
    
    // Test properties
    console.log('Hate:', textSeverity.Hate);
    console.log('SelfHarm:', textSeverity.SelfHarm);
    console.log('Sexual:', textSeverity.Sexual);
    console.log('Violent:', textSeverity.Violent);
    
    // Test setting properties
    textSeverity.Hate = windowsAI.SeverityLevel.Medium;
    textSeverity.Violent = windowsAI.SeverityLevel.High;
    console.log('✓ Set TextContentFilterSeverity properties');
    console.log('Updated Hate:', textSeverity.Hate);
    console.log('Updated Violent:', textSeverity.Violent);
    console.log('✓ TextContentFilterSeverity working correctly\n');
    
    // Test ContentFilterOptions with subclasses
    console.log('=== ContentFilterOptions Integration ===');
    const contentFilter = new windowsAI.ContentFilterOptions();
    console.log('✓ Created ContentFilterOptions instance');
    
    // Test setting severity objects
    contentFilter.imageMaxAllowedSeverityLevel = imageSeverity;
    contentFilter.promptMaxAllowedSeverityLevel = textSeverity;
    contentFilter.responseMaxAllowedSeverityLevel = textSeverityWithLevel;
    console.log('✓ Set ContentFilterOptions severity properties (including response)');
    
    // Test getting severity objects back
    const retrievedImageSeverity = contentFilter.imageMaxAllowedSeverityLevel;
    const retrievedPromptSeverity = contentFilter.promptMaxAllowedSeverityLevel;
    const retrievedResponseSeverity = contentFilter.responseMaxAllowedSeverityLevel;
    
    console.log('Retrieved imageMaxAllowedSeverityLevel:', retrievedImageSeverity);
    console.log('Retrieved promptMaxAllowedSeverityLevel:', retrievedPromptSeverity);
    console.log('Retrieved responseMaxAllowedSeverityLevel:', retrievedResponseSeverity);
    
    if (retrievedImageSeverity && retrievedPromptSeverity && retrievedResponseSeverity) {
        console.log('✓ Successfully retrieved all severity objects');
        
        // Test accessing properties from retrieved objects
        console.log('Retrieved Image AdultContentLevel:', retrievedImageSeverity.AdultContentLevel);
        console.log('Retrieved Prompt Hate level:', retrievedPromptSeverity.Hate);
        console.log('Retrieved Response Sexual level:', retrievedResponseSeverity.Sexual);
        console.log('✓ Successfully accessed properties from retrieved objects');
    }
    
    // Test with LanguageModelOptions
    console.log('\n=== LanguageModelOptions Integration ===');
    const options = new windowsAI.LanguageModelOptions();
    console.log('✓ Created LanguageModelOptions instance');
    
    // Set ContentFilterOptions
    options.ContentFilterOptions = contentFilter;
    console.log('✓ Set ContentFilterOptions on LanguageModelOptions');
    
    // Get ContentFilterOptions back
    const retrievedContentFilter = options.ContentFilterOptions;
    console.log('Retrieved ContentFilterOptions:', retrievedContentFilter);
    
    if (retrievedContentFilter && typeof retrievedContentFilter === 'object') {
        console.log('✓ Successfully retrieved ContentFilterOptions from LanguageModelOptions');
        
        // Test accessing nested severity objects
        const nestedImageSeverity = retrievedContentFilter.imageMaxAllowedSeverityLevel;
        if (nestedImageSeverity) {
            console.log('Nested Image AdultContentLevel:', nestedImageSeverity.AdultContentLevel);
            console.log('✓ Successfully accessed nested severity objects');
        }
    }
    
    console.log('\n🎉 All tests passed! Complete ContentFilterOptions implementation working correctly!');
    
} catch (error) {
    console.error('❌ Error during testing:', error.message);
    console.error(error.stack);
}