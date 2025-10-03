#include <napi.h>
#include "LanguageModelProjections.h"

using namespace winrt;
using namespace Microsoft::Windows::AI;
using namespace Microsoft::Windows::AI::Text;
using namespace Microsoft::Windows::AI::ContentSafety;

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::Object aiFeatureReadyState = Napi::Object::New(env);
    aiFeatureReadyState.Set("Ready", Napi::Number::New(env, 0));
    aiFeatureReadyState.Set("NotReady", Napi::Number::New(env, 1));
    aiFeatureReadyState.Set("NotSupportedOnCurrentSystem", Napi::Number::New(env, 2));
    aiFeatureReadyState.Set("DisabledByUser", Napi::Number::New(env, 3));
    
    exports.Set("AIFeatureReadyState", aiFeatureReadyState);
    
    // Add LanguageModelResponseStatus enum
    Napi::Object responseStatus = Napi::Object::New(env);
    responseStatus.Set("Complete", Napi::Number::New(env, 0));
    responseStatus.Set("InProgress", Napi::Number::New(env, 1));
    responseStatus.Set("BlockedByPolicy", Napi::Number::New(env, 2));
    responseStatus.Set("PromptLargerThanContext", Napi::Number::New(env, 3));
    responseStatus.Set("PromptBlockedByContentModeration", Napi::Number::New(env, 4));
    responseStatus.Set("ResponseBlockedByContentModeration", Napi::Number::New(env, 5));
    responseStatus.Set("Error", Napi::Number::New(env, 6));
    
    exports.Set("LanguageModelResponseStatus", responseStatus);
    
    // Add SeverityLevel enum
    Napi::Object severityLevel = Napi::Object::New(env);
    severityLevel.Set("Minimum", Napi::Number::New(env, 10));
    severityLevel.Set("Low", Napi::Number::New(env, 11));
    severityLevel.Set("Medium", Napi::Number::New(env, 12));
    severityLevel.Set("High", Napi::Number::New(env, 13));
    
    exports.Set("SeverityLevel", severityLevel);
    
    // Add AIFeatureReadyResultState enum
    Napi::Object aiFeatureReadyResultState = Napi::Object::New(env);
    aiFeatureReadyResultState.Set("InProgress", Napi::Number::New(env, 0));
    aiFeatureReadyResultState.Set("Success", Napi::Number::New(env, 1));
    aiFeatureReadyResultState.Set("Failure", Napi::Number::New(env, 2));
    
    exports.Set("AIFeatureReadyResultState", aiFeatureReadyResultState);
    
    exports = MyLanguageModel::Init(env, exports);
    exports = MyLanguageModelResponseResult::Init(env, exports);
    exports = MyContentFilterOptions::Init(env, exports);
    exports = MyImageContentFilterSeverity::Init(env, exports);
    exports = MyTextContentFilterSeverity::Init(env, exports);
    exports = MyAIFeatureReadyResult::Init(env, exports);
    return MyLanguageModelOptions::Init(env, exports);
}

NODE_API_MODULE(addon, Init)