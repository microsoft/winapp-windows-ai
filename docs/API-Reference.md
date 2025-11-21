# Supported API's

This package supports many of the API's within the [Microsoft.Windows.AI.Text](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text?view=windows-app-sdk-1.8), [Microsoft.Windows.AI.Imaging](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging?view=windows-app-sdk-1.8), and [Microsoft.Windows.AI](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai?view=windows-app-sdk-1.8) namespaces. This package is designed to expose a JavaScript API surface of the native Windows AI API's. Class, method, enum, and parameter names in this package are designed to replicate their native counterparts in WinAppSDK.

Below is the list of supported API's for the `@microsoft/winapp-windows-ai` package. For usage information, see the [Usage Guide](Usage.md).

### Core Classes

#### `LanguageModel`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.LanguageModel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodel?view=windows-app-sdk-1.8)

Main class for text generation and AI model interactions.

**Static Methods:**

- `CreateAsync()` - **Maps to:** [`LanguageModel.CreateAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodel.createasync?view=windows-app-sdk-1.8) - Asynchronously creates a new LanguageModel instance
- `GetReadyState()` - **Maps to:** [`LanguageModel.GetReadyState()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodel.getreadystate?view=windows-app-sdk-1.8) - Returns the current AI feature ready state
- `EnsureReadyAsync()` - **Maps to:** [`LanguageModel.EnsureReadyAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodel.ensurereadyasync?view=windows-app-sdk-1.8) - Ensures AI features are ready for use

**Instance Methods:**

> [!IMPORTANT]  
> This method uses a Windows API which is a part of a [Limited Access Feature](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeatures?view=winrt-26100). To request an unlock token, please use the [LAF Access Token Request Form](https://go.microsoft.com/fwlink/?linkid=2271232&c1cid=04x409). To use this method, you must first call [LimitedAccessFeature.TryUnlockToken](#limitedaccessfeatures). See <TODO> for usage examples.

- `GenerateResponseAsync(string, `[`LanguageModelOptions`](#languagemodeloptions)`?)` - **Maps to:** [`LanguageModel.GenerateResponseAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodel.generateresponseasync?view=windows-app-sdk-1.8) - Generates text response from a prompt

#### `LanguageModelOptions`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.LanguageModelOptions`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodeloptions?view=windows-app-sdk-1.8)

Configuration options for language model behavior.

**Properties:**

- `Temperature` (number) - **Maps to:** [`LanguageModelOptions.Temperature`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodeloptions.temperature?view=windows-app-sdk-1.8) - Controls randomness in generation (0.0-1.0)
- `TopK` (number) - **Maps to:** [`LanguageModelOptions.TopK`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodeloptions.topk?view=windows-app-sdk-1.8) - Limits vocabulary for next token selection
- `TopP` (number) - **Maps to:** [`LanguageModelOptions.TopP`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodeloptions.topp?view=windows-app-sdk-1.8) - Nucleus sampling threshold (0.0-1.0)
- `ContentFilterOptions` ([`ContentFilterOptions`](#contentfilteroptions)) - **Maps to:** [`LanguageModelOptions.ContentFilterOptions`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodeloptions.contentfilteroptions?view=windows-app-sdk-1.8) - Content safety settings

#### `LanguageModelResponseResult`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.LanguageModelResponseResult`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponseresult?view=windows-app-sdk-1.8)

Contains the result of a text generation operation.

**Properties:**

- `Text` (string) - **Maps to:** [`LanguageModelResponseResult.Text`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponseresult.text?view=windows-app-sdk-1.8) - The generated text response
- `Status` (number) - **Maps to:** [`LanguageModelResponseResult.Status`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponseresult.status?view=windows-app-sdk-1.8) - Status code from LanguageModelResponseStatus enum
- `ExtendedError` (string) - **Maps to:** [`LanguageModelResponseResult.ExtendedError`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponseresult.extendederror?view=windows-app-sdk-1.8) - Extended error information if available

#### `TextSummarizer`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.TextSummarizer`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer?view=windows-app-sdk-1.8)

Main class for AI-powered text and conversation summarization.

**Constructor:**

- `new TextSummarizer(`[`LanguageModel`](#languagemodel)`)` - **Maps to:** [`TextSummarizer(LanguageModel)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer.-ctor?view=windows-app-sdk-1.8) - Creates a TextSummarizer with the provided LanguageModel instance

**Instance Methods:**

- `SummarizeAsync(string)` - **Maps to:** [`TextSummarizer.SummarizeAsync(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer.summarizeasync?view=windows-app-sdk-1.8) - Asynchronously summarizes the provided text
- `SummarizeParagraphAsync(string)` - **Maps to:** [`TextSummarizer.SummarizeParagraphAsync(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer.summarizeparagraphasync?view=windows-app-sdk-1.8) - Asynchronously summarizes a paragraph with paragraph-specific optimization
- `SummarizeConversationAsync(`[`ConversationItem`](#conversationitem)`[], `[`ConversationSummaryOptions`](#conversationsummaryoptions)`)` - **Maps to:** [`TextSummarizer.SummarizeConversationAsync(IVectorView<ConversationItem>, ConversationSummaryOptions)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer.summarizeconversationasync?view=windows-app-sdk-1.8) - Asynchronously summarizes a conversation from an array of ConversationItem objects
- `IsPromptLargerThanContext(string)` - **Maps to:** [`TextSummarizer.IsPromptLargerThanContext(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer.ispromptlargerthancontext?view=windows-app-sdk-1.8) - Checks if text prompt exceeds context window (returns boolean)
- `IsPromptLargerThanContext(`[`ConversationItem`](#conversationitem)`[], `[`ConversationSummaryOptions`](#conversationsummaryoptions)`)` - **Maps to:** [`TextSummarizer.IsPromptLargerThanContext(IVectorView<ConversationItem>, ConversationSummaryOptions, UInt64)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textsummarizer.ispromptlargerthancontext?view=windows-app-sdk-1.8) - Checks if conversation prompt exceeds context window (returns object with isLarger boolean and cutoffPosition number)

#### `ConversationItem`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.ConversationItem`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationitem?view=windows-app-sdk-1.8)

Represents a single message in a conversation for summarization.

**Constructor:**

- `new ConversationItem()` - **Maps to:** [`ConversationItem()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationitem.-ctor?view=windows-app-sdk-1.8) - Creates a new conversation item

**Properties:**

- `Message` (string) - **Maps to:** [`ConversationItem.Message`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationitem.message?view=windows-app-sdk-1.8) - The message content
- `Participant` (string) - **Maps to:** [`ConversationItem.Participant`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationitem.participant?view=windows-app-sdk-1.8) - The participant who sent the message (e.g., "User", "Assistant", "Support")

#### `ConversationSummaryOptions`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.ConversationSummaryOptions`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationsummaryoptions?view=windows-app-sdk-1.8)

Configuration options for conversation summarization.

**Properties:**

- `includeMessageCitations` (boolean) - **Maps to:** [`ConversationSummaryOptions.IncludeMessageCitations`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationsummaryoptions.includemessagecitations?view=windows-app-sdk-1.8) - Whether to include references to specific messages in the summary
- `includeParticipantAttribution` (boolean) - **Maps to:** [`ConversationSummaryOptions.IncludeParticipantAttribution`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.conversationsummaryoptions.includeparticipantattribution?view=windows-app-sdk-1.8) - Whether to attribute parts of the summary to specific participants

#### `TextRewriter`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.TextRewriter`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewriter?view=windows-app-sdk-1.8)

Main class for AI-powered text rewriting and tone adjustment.

**Constructor:**

- `new TextRewriter(`[`LanguageModel`](#languagemodel)`)` - **Maps to:** [`TextRewriter(LanguageModel)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewriter.-ctor?view=windows-app-sdk-1.8) - Creates a TextRewriter with the provided LanguageModel instance

**Instance Methods:**

- `RewriteAsync(string)` - **Maps to:** [`TextRewriter.RewriteAsync(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewriter.rewriteasync?view=windows-app-sdk-1.8) - Asynchronously rewrites the provided text using the default tone
- `RewriteAsync(string, `[`TextRewriteTone`](#textrewritetone)`)` - **Maps to:** [`TextRewriter.RewriteAsync(String, TextRewriteTone)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewriter.rewriteasync?view=windows-app-sdk-1.8) - Asynchronously rewrites the provided text using the specified TextRewriteTone

#### `TextToTableConverter`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.TextToTableConverter`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableconverter?view=windows-app-sdk-1.8)

Main class for AI-powered conversion of text content into structured table format.

**Constructor:**

- `new TextToTableConverter(`[`LanguageModel`](#languagemodel)`)` - **Maps to:** [`TextToTableConverter(LanguageModel)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableconverter.-ctor?view=windows-app-sdk-1.8) - Creates a TextToTableConverter with the provided LanguageModel instance

**Instance Methods:**

- `ConvertAsync(string)` - **Maps to:** [`TextToTableConverter.ConvertAsync(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableconverter.convertasync?view=windows-app-sdk-1.8) - Asynchronously converts the provided text into a structured table format, returns [`TextToTableResponseResult`](#texttotableresponseresult)

#### `TextToTableResponseResult`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.TextToTableResponseResult`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableresponseresult?view=windows-app-sdk-1.8)

Result object containing structured table data from text conversion operations.

**Properties:**

- `ExtendedError` (string) - **Maps to:** [`TextToTableResponseResult.ExtendedError`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableresponseresult.extendederror?view=windows-app-sdk-1.8) - Extended error information as hex string (e.g., "0x80004005") if available
- `Status` (number) - **Maps to:** [`TextToTableResponseResult.Status`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableresponseresult.status?view=windows-app-sdk-1.8) - Status code from the conversion operation

**Methods:**

- `GetRows()` - **Maps to:** [`TextToTableResponseResult.GetRows()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotableresponseresult.getrows?view=windows-app-sdk-1.8) - Returns an array of [`TextToTableRow`](#texttotablerow) objects representing the table structure

#### `TextToTableRow`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.TextToTableRow`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotablerow?view=windows-app-sdk-1.8)

Represents a single row in a converted table structure.

**Methods:**

- `GetColumns()` - **Maps to:** [`TextToTableRow.GetColumns()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.texttotablerow.getcolumns?view=windows-app-sdk-1.8) - Returns an array of strings representing the column values for this row

#### `AIFeatureReadyResult`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.AIFeatureReadyResult`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresult?view=windows-app-sdk-1.8)

Result object for AI feature readiness operations.

**Properties:**

- `Error` (number) - **Maps to:** [`AIFeatureReadyResult.Error`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresult.error?view=windows-app-sdk-1.8) - Error code if operation failed
- `ErrorDisplayText` (string) - **Maps to:** [`AIFeatureReadyResult.ErrorDisplayText`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresult.errordisplaytext?view=windows-app-sdk-1.8) - Human-readable error description
- `ExtendedError` (number) - **Maps to:** [`AIFeatureReadyResult.ExtendedError`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresult.extendederror?view=windows-app-sdk-1.8) - Extended error code
- `Status` (number) - **Maps to:** [`AIFeatureReadyResult.Status`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresult.status?view=windows-app-sdk-1.8) - Operation status from [`AIFeatureReadyResultState`](#aifeaturereadyresultstate) enum

### Imaging Classes

#### `ImageDescriptionGenerator`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.ImageDescriptionGenerator`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptiongenerator?view=windows-app-sdk-1.8)

Main class for generating descriptions and captions for images.

**Static Methods:**

- `CreateAsync()` - **Maps to:** [`ImageDescriptionGenerator.CreateAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptiongenerator.createasync?view=windows-app-sdk-1.8) - Asynchronously creates a new ImageDescriptionGenerator instance
- `GetReadyState()` - **Maps to:** [`ImageDescriptionGenerator.GetReadyState()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptiongenerator.getreadystate?view=windows-app-sdk-1.8) - Returns the current AI feature ready state for image description
- `EnsureReadyAsync()` - **Maps to:** [`ImageDescriptionGenerator.EnsureReadyAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptiongenerator.ensurereadyasync?view=windows-app-sdk-1.8) - Ensures image description features are ready for use

**Instance Methods:**

- `DescribeAsync(string, `[`ImageDescriptionKind`](#imagedescriptionkind)`, `[`ContentFilterOptions`](#contentfilteroptions)`)` - **Maps to:** [`ImageDescriptionGenerator.DescribeAsync(String, ImageDescriptionKind, ContentFilterOptions)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptiongenerator.describeasync?view=windows-app-sdk-1.8) - Generates description for an image, file path must be the absolute path to the image
- `Close()` - **Maps to:** [`ImageDescriptionGenerator.Close()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptiongenerator.close?view=windows-app-sdk-1.8) - Closes the generator and releases resources

#### `ImageDescriptionResult`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.ImageDescriptionResult`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresult?view=windows-app-sdk-1.8)

Contains the result of an image description operation.

**Properties:**

- `Description` (string) - **Maps to:** [`ImageDescriptionResult.Description`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresult.description?view=windows-app-sdk-1.8) - The generated image description
- `Status` ([`ImageDescriptionResultStatus`](#imagedescriptionresultstatus)) - **Maps to:** [`ImageDescriptionResult.Status`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresult.status?view=windows-app-sdk-1.8) - Status code from ImageDescriptionResultStatus enum

#### `TextRecognizer`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.TextRecognizer`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer?view=windows-app-sdk-1.8)

Main class for optical character recognition (OCR) on images.

**Static Methods:**

- `CreateAsync()` - **Maps to:** [`TextRecognizer.CreateAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.createasync?view=windows-app-sdk-1.8) - Asynchronously creates a new TextRecognizer instance
- `GetReadyState()` - **Maps to:** [`TextRecognizer.GetReadyState()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.getreadystate?view=windows-app-sdk-1.8) - Returns the current AI feature ready state for text recognition
- `EnsureReadyAsync()` - **Maps to:** [`TextRecognizer.EnsureReadyAsync()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.ensurereadyasync?view=windows-app-sdk-1.8) - Ensures text recognition features are ready for use

**Instance Methods:**

- `RecognizeTextFromImageAsync(string)` - **Maps to:** [`TextRecognizer.RecognizeTextFromImageAsync(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.recognizetextfromimageasync?view=windows-app-sdk-1.8) - Asynchronously recognizes text in an image, file path must be the absolute path to the image
- `RecognizeTextFromImage(string)` - **Maps to:** [`TextRecognizer.RecognizeTextFromImage(String)`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.recognizetextfromimage?view=windows-app-sdk-1.8) - Synchronously recognizes text in an image, file path must be the absolute path to the image
- `Close()` - **Maps to:** [`TextRecognizer.Close()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.close?view=windows-app-sdk-1.8) - Closes the recognizer and releases resources
- `Dispose()` - **Maps to:** [`TextRecognizer.Dispose()`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.textrecognizer.dispose?view=windows-app-sdk-1.8) - Disposes the recognizer and cleans up resources

#### `RecognizedText`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.RecognizedText`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtext?view=windows-app-sdk-1.8)

Contains the complete text recognition results from an image.

**Properties:**

- `Lines` ([`RecognizedLine`](#recognizedline)[]) - **Maps to:** [`RecognizedText.Lines`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtext.lines?view=windows-app-sdk-1.8) - Array of recognized text lines
- `TextAngle` (number) - **Maps to:** [`RecognizedText.TextAngle`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtext.textangle?view=windows-app-sdk-1.8) - Angle of the text in the image

#### `RecognizedLine`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.RecognizedLine`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedline?view=windows-app-sdk-1.8)

Represents a single line of recognized text.

**Properties:**

- `BoundingBox` ([`RecognizedTextBoundingBox`](#recognizedtextboundingbox)) - **Maps to:** [`RecognizedLine.BoundingBox`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedline.boundingbox?view=windows-app-sdk-1.8) - Bounding box coordinates for the line
- `Style` ([`RecognizedLineStyle`](#recognizedlinestyle)) - **Maps to:** [`RecognizedLine.Style`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedline.style?view=windows-app-sdk-1.8) - Text style information from RecognizedLineStyle enum
- `LineStyleConfidence` (number) - **Maps to:** [`RecognizedLine.LineStyleConfidence`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedline.linestyleconfidence?view=windows-app-sdk-1.8) - Confidence level for the line style
- `Text` (string) - **Maps to:** [`RecognizedLine.Text`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedline.text?view=windows-app-sdk-1.8) - The recognized text content
- `Words` ([`RecognizedWord`](#recognizedword)[]) - **Maps to:** [`RecognizedLine.Words`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedline.words?view=windows-app-sdk-1.8) - Array of individual words in the line

#### `RecognizedWord`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.RecognizedWord`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedword?view=windows-app-sdk-1.8)

Represents a single recognized word.

**Properties:**

- `BoundingBox` ([`RecognizedTextBoundingBox`](#recognizedtextboundingbox)) - **Maps to:** [`RecognizedWord.BoundingBox`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedword.boundingbox?view=windows-app-sdk-1.8) - Bounding box coordinates for the word
- `MatchConfidence` (number) - **Maps to:** [`RecognizedWord.MatchConfidence`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedword.matchconfidence?view=windows-app-sdk-1.8) - Confidence level for the word recognition
- `Text` (string) - **Maps to:** [`RecognizedWord.Text`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedword.text?view=windows-app-sdk-1.8) - The recognized word text

#### `RecognizedTextBoundingBox`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.RecognizedTextBoundingBox`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtextboundingbox?view=windows-app-sdk-1.8)

Defines the bounding box coordinates for recognized text elements.

**Properties:**

- `TopLeft` (object) - **Maps to:** [`RecognizedTextBoundingBox.TopLeft`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtextboundingbox.topleft?view=windows-app-sdk-1.8) - Top-left corner coordinates {X, Y}
- `TopRight` (object) - **Maps to:** [`RecognizedTextBoundingBox.TopRight`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtextboundingbox.topright?view=windows-app-sdk-1.8) - Top-right corner coordinates {X, Y}
- `BottomLeft` (object) - **Maps to:** [`RecognizedTextBoundingBox.BottomLeft`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtextboundingbox.bottomleft?view=windows-app-sdk-1.8) - Bottom-left corner coordinates {X, Y}
- `BottomRight` (object) - **Maps to:** [`RecognizedTextBoundingBox.BottomRight`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedtextboundingbox.bottomright?view=windows-app-sdk-1.8) - Bottom-right corner coordinates {X, Y}

### Content Safety Classes

#### `ContentFilterOptions`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.ContentSafety.ContentFilterOptions`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.contentfilteroptions?view=windows-app-sdk-1.8)

Configuration for content filtering policies.

**Properties:**

- `imageMaxAllowedSeverityLevel` ([`ImageContentFilterSeverity`](#imagecontentfilterseverity)) - **Maps to:** [`ContentFilterOptions.ImageMaxAllowedSeverityLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.contentfilteroptions.imagemaxallowedseveritylevel?view=windows-app-sdk-1.8) - Maximum allowed severity for image content
- `promptMaxAllowedSeverityLevel` ([`TextContentFilterSeverity`](#textcontentfilterseverity)) - **Maps to:** [`ContentFilterOptions.PromptMaxAllowedSeverityLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.contentfilteroptions.promptmaxallowedseveritylevel?view=windows-app-sdk-1.8) - Maximum allowed severity for prompt text
- `responseMaxAllowedSeverityLevel` ([`TextContentFilterSeverity`](#textcontentfilterseverity)) - **Maps to:** [`ContentFilterOptions.ResponseMaxAllowedSeverityLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.contentfilteroptions.responsemaxallowedseveritylevel?view=windows-app-sdk-1.8) - Maximum allowed severity for response text

#### `ImageContentFilterSeverity`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.ContentSafety.ImageContentFilterSeverity`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.imagecontentfilterseverity?view=windows-app-sdk-1.8)

Severity levels for different types of image content.

**Properties:**

- `AdultContentLevel` (number) - **Maps to:** [`ImageContentFilterSeverity.AdultContentLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.imagecontentfilterseverity.adultcontentlevel?view=windows-app-sdk-1.8) - Severity level for adult content
- `GoryContentLevel` (number) - **Maps to:** [`ImageContentFilterSeverity.GoryContentLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.imagecontentfilterseverity.gorycontentlevel?view=windows-app-sdk-1.8) - Severity level for gory content
- `RacyContentLevel` (number) - **Maps to:** [`ImageContentFilterSeverity.RacyContentLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.imagecontentfilterseverity.racycontentlevel?view=windows-app-sdk-1.8) - Severity level for racy content
- `ViolentContentLevel` (number) - **Maps to:** [`ImageContentFilterSeverity.ViolentContentLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.imagecontentfilterseverity.violentcontentlevel?view=windows-app-sdk-1.8) - Severity level for violent content

#### `TextContentFilterSeverity`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.ContentSafety.TextContentFilterSeverity`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.textcontentfilterseverity?view=windows-app-sdk-1.8)

Severity levels for different types of text content.

**Properties:**

- `Hate` (number) - **Maps to:** [`TextContentFilterSeverity.Hate`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.textcontentfilterseverity.hate?view=windows-app-sdk-1.8) - Severity level for hate speech
- `SelfHarm` (number) - **Maps to:** [`TextContentFilterSeverity.SelfHarm`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.textcontentfilterseverity.selfharm?view=windows-app-sdk-1.8) - Severity level for self-harm content
- `Sexual` (number) - **Maps to:** [`TextContentFilterSeverity.Sexual`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.textcontentfilterseverity.sexual?view=windows-app-sdk-1.8) - Severity level for sexual content
- `Violent` (number) - **Maps to:** [`TextContentFilterSeverity.Violent`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.textcontentfilterseverity.violent?view=windows-app-sdk-1.8) - Severity level for violent content

### Limited Access Features Classes

> [!IMPORTANT]  
> This class is currently needed to be able to use `GenerateResponseAsync`. To use this class, you will need to request an unlock token, please use the [LAF Access Token Request Form](https://go.microsoft.com/fwlink/?linkid=2271232&c1cid=04x409).

#### `LimitedAccessFeatures`

**Maps to WinAppSDK** [`Windows.ApplicationModel.LimitedAccessFeatures`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeatures?view=winrt-26100)

Provides access to Windows limited access features that require special permissions or tokens.

**Static Methods:**

> [!IMPORTANT]  
> When attempting to gain access to `GenerateResponseAsync`, the feature ID should be `com.microsoft.windows.ai.languagemodel` and the developer signature should be `<insert-app-id> has registered their use of com.microsoft.windows.ai.languagemodel with Microsoft and agrees to the terms of use.`.

- `TryUnlockFeature(string, string, string)` - **Maps to:** [`LimitedAccessFeatures.TryUnlockFeature(String, String, String)`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeatures.tryunlockfeature?view=winrt-26100) - Attempts to unlock a limited access feature using feature ID, token, and developer signature. Returns [`LimitedAccessFeatureRequestResult`](#limitedaccessfeaturerequestresult)

#### `LimitedAccessFeatureRequestResult`

**Maps to WinAppSDK** [`Windows.ApplicationModel.LimitedAccessFeatureRequestResult`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturerequestresult?view=winrt-26100)

Contains the result of a limited access feature unlock request.

**Properties:**

- `FeatureId` (string) - **Maps to:** [`LimitedAccessFeatureRequestResult.FeatureId`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturerequestresult.featureid?view=winrt-26100) - The identifier of the requested feature
- `Status` ([`LimitedAccessFeatureStatus`](#limitedaccessfeaturestatus)) - **Maps to:** [`LimitedAccessFeatureRequestResult.Status`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturerequestresult.status?view=winrt-26100) - The status of the unlock request
- `EstimatedRemovalDate` (Date | null) - **Maps to:** [`LimitedAccessFeatureRequestResult.EstimatedRemovalDate`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturerequestresult.estimatedremovaldate?view=winrt-26100) - Estimated date when the feature will be removed, if applicable

### Enums and Constants

#### `AIFeatureReadyState`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.AIFeatureReadyState`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadystate?view=windows-app-sdk-1.8)

- `Ready` (0) - **Maps to:** [`AIFeatureReadyState.Ready`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadystate?view=windows-app-sdk-1.8) - AI features are ready for use
- `NotReady` (1) - **Maps to:** [`AIFeatureReadyState.NotReady`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadystate?view=windows-app-sdk-1.8) - AI features are not ready yet
- `NotSupportedOnCurrentSystem` (2) - **Maps to:** [`AIFeatureReadyState.NotSupportedOnCurrentSystem`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadystate?view=windows-app-sdk-1.8) - AI not supported on this system
- `DisabledByUser` (3) - **Maps to:** [`AIFeatureReadyState.DisabledByUser`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadystate?view=windows-app-sdk-1.8) - AI disabled by user settings

#### `LanguageModelResponseStatus`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.LanguageModelResponseStatus`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8)

- `Complete` (0) - **Maps to:** [`LanguageModelResponseStatus.Complete`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - Generation completed successfully
- `InProgress` (1) - **Maps to:** [`LanguageModelResponseStatus.InProgress`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - Generation is still in progress
- `BlockedByPolicy` (2) - **Maps to:** [`LanguageModelResponseStatus.BlockedByPolicy`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - Request blocked by policy
- `PromptLargerThanContext` (3) - **Maps to:** [`LanguageModelResponseStatus.PromptLargerThanContext`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - Prompt exceeds context length
- `PromptBlockedByContentModeration` (4) - **Maps to:** [`LanguageModelResponseStatus.PromptBlockedByContentModeration`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - Prompt blocked by content filter
- `ResponseBlockedByContentModeration` (5) - **Maps to:** [`LanguageModelResponseStatus.ResponseBlockedByContentModeration`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - Response blocked by content filter
- `Error` (6) - **Maps to:** [`LanguageModelResponseStatus.Error`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.languagemodelresponsestatus?view=windows-app-sdk-1.8) - An error occurred during generation

#### `SeverityLevel`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.ContentSafety.SeverityLevel`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.severitylevel?view=windows-app-sdk-1.8)

- `Minimum` (10) - **Maps to:** [`SeverityLevel.Minimum`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.severitylevel?view=windows-app-sdk-1.8) - Minimal content filtering
- `Low` (11) - **Maps to:** [`SeverityLevel.Low`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.severitylevel?view=windows-app-sdk-1.8) - Low severity threshold
- `Medium` (12) - **Maps to:** [`SeverityLevel.Medium`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.severitylevel?view=windows-app-sdk-1.8) - Medium severity threshold
- `High` (13) - **Maps to:** [`SeverityLevel.High`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.contentsafety.severitylevel?view=windows-app-sdk-1.8) - High severity threshold

#### `AIFeatureReadyResultState`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.AIFeatureReadyResultState`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresultstate?view=windows-app-sdk-1.8)

- `InProgress` (0) - **Maps to:** [`AIFeatureReadyResultState.InProgress`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresultstate?view=windows-app-sdk-1.8) - Operation is in progress
- `Success` (1) - **Maps to:** [`AIFeatureReadyResultState.Success`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresultstate?view=windows-app-sdk-1.8) - Operation completed successfully
- `Failure` (2) - **Maps to:** [`AIFeatureReadyResultState.Failure`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.aifeaturereadyresultstate?view=windows-app-sdk-1.8) - Operation failed

#### `ImageDescriptionKind`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.ImageDescriptionKind`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionkind?view=windows-app-sdk-1.8)

- `BriefDescription` (0) - **Maps to:** [`ImageDescriptionKind.BriefDescription`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionkind?view=windows-app-sdk-1.8) - Generate a brief description for the image
- `DetailedDescription` (1) - **Maps to:** [`ImageDescriptionKind.DetailedDescription`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionkind?view=windows-app-sdk-1.8) - Generate a detailed description of the image
- `DiagramDescription` (2) - **Maps to:** [`ImageDescriptionKind.DiagramDescription`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionkind?view=windows-app-sdk-1.8) - Generate a description suitable for diagrams and technical images
- `AccessibleDescription` (3) - **Maps to:** [`ImageDescriptionKind.AccessibleDescription`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionkind?view=windows-app-sdk-1.8) - Generate accessible description optimized for screen readers

#### `TextRewriteTone`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Text.TextRewriteTone`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewritetone?view=windows-app-sdk-1.8)

- `Default` (0) - **Maps to:** [`TextRewriteTone.Default`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewritetone?view=windows-app-sdk-1.8) - Use the default tone for text rewriting
- `General` (1) - **Maps to:** [`TextRewriteTone.General`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewritetone?view=windows-app-sdk-1.8) - Use a general, neutral tone
- `Casual` (2) - **Maps to:** [`TextRewriteTone.Casual`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewritetone?view=windows-app-sdk-1.8) - Use a casual, informal tone
- `Formal` (3) - **Maps to:** [`TextRewriteTone.Formal`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.text.textrewritetone?view=windows-app-sdk-1.8) - Use a formal, professional tone

#### `ImageDescriptionResultStatus`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.ImageDescriptionResultStatus`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresultstatus?view=windows-app-sdk-1.8)

- `Success` (0) - **Maps to:** [`ImageDescriptionResultStatus.Success`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresultstatus?view=windows-app-sdk-1.8) - Image description generated successfully
- `Failure` (1) - **Maps to:** [`ImageDescriptionResultStatus.Failure`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresultstatus?view=windows-app-sdk-1.8) - Image description generation failed
- `ContentFiltered` (2) - **Maps to:** [`ImageDescriptionResultStatus.ContentFiltered`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.imagedescriptionresultstatus?view=windows-app-sdk-1.8) - Image description blocked by content filtering

#### `RecognizedLineStyle`

**Maps to WinAppSDK** [`Microsoft.Windows.AI.Imaging.RecognizedLineStyle`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedlinestyle?view=windows-app-sdk-1.8)

- `None` (0) - **Maps to:** [`RecognizedLineStyle.None`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedlinestyle?view=windows-app-sdk-1.8) - No specific style detected
- `Handwritten` (1) - **Maps to:** [`RecognizedLineStyle.Handwritten`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedlinestyle?view=windows-app-sdk-1.8) - Handwritten text style
- `Printed` (2) - **Maps to:** [`RecognizedLineStyle.Printed`](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.windows.ai.imaging.recognizedlinestyle?view=windows-app-sdk-1.8) - Printed text style

#### `LimitedAccessFeatureStatus`

**Maps to WinAppSDK** [`Windows.ApplicationModel.LimitedAccessFeatureStatus`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturestatus?view=winrt-26100)

- `Available` (0) - **Maps to:** [`LimitedAccessFeatureStatus.Available`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturestatus?view=winrt-26100) - Limited access feature is available with proper authentication
- `AvailableWithoutToken` (1) - **Maps to:** [`LimitedAccessFeatureStatus.AvailableWithoutToken`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturestatus?view=winrt-26100) - Limited access feature is available without requiring a token
- `Unknown` (2) - **Maps to:** [`LimitedAccessFeatureStatus.Unknown`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturestatus?view=winrt-26100) - Limited access feature status is unknown
- `Unavailable` (3) - **Maps to:** [`LimitedAccessFeatureStatus.Unavailable`](https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.limitedaccessfeaturestatus?view=winrt-26100) - Limited access feature is not available
