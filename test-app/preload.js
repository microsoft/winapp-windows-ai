const { contextBridge } = require("electron");
const {
  LanguageModel,
  TextSummarizer,
  AIFeatureReadyResultState,
  LanguageModelResponseStatus
} = require("../index.js");

contextBridge.exposeInMainWorld("windowsAI", {
  summarizeText: async (prompt, progressCallback) => {
    try {
    const readyResult = await LanguageModel.EnsureReadyAsync();
    if (readyResult.Status !== AIFeatureReadyResultState.Success) {
      console.log("AI not ready:", readyResult.Status);
      return "";
    }

    const model = await LanguageModel.CreateAsync();
    const textSummarizer = new TextSummarizer(model);

    const summarizationPromise = textSummarizer.SummarizeAsync(prompt);

    if (summarizationPromise.progress) {
      summarizationPromise.progress((error, progressText) => {
        progressCallback(progressText);
      });
    }

    const result = await summarizationPromise;

    if (result.Status === LanguageModelResponseStatus.Complete) {
      console.log(result.Text);
      return result.Text;
    } else {
      console.log("Summarization failed with status:", result.Status);
      return "Error generating summary. Please check if your machine meets the requirements for Windows AI features.";
    }
  } catch (error) {
    console.error("Error:", error);
  }
},
});