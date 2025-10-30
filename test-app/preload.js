const { contextBridge } = require("electron");
const {
  LanguageModel,
  AIFeatureReadyState,
} = require("../index.js");

contextBridge.exposeInMainWorld("windowsAI", {
  generateText: async (prompt) => {
    try{
        var readyState = LanguageModel.GetReadyState();
        if (readyState == AIFeatureReadyState.NotReady) {
            await LanguageModel.EnsureReadyAsync();
        } else if (readyState == AIFeatureReadyState.Ready) {
            var languageModel = await LanguageModel.CreateAsync();
            if (languageModel) {
                var result = await languageModel.GenerateResponseAsync(prompt);
                return result.Text;
            }
        }
    } catch (error) {
        console.error("Error generating text:", error);
        throw error;
    }
},
});