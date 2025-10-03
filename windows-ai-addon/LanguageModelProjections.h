#pragma once

#include <napi.h>
#include <optional>
#include <memory>

#include <winrt/Windows.Foundation.h>
#include <winrt/Microsoft.Windows.AI.Text.h>
#include <winrt/Microsoft.Windows.AI.ContentSafety.h>

#include "ProjectionHelper.h"

using namespace winrt;
using namespace Microsoft::Windows::AI;
using namespace Microsoft::Windows::AI::Text;
using namespace Microsoft::Windows::AI::ContentSafety;

// Forward declarations
class MyLanguageModelResponseResult;
class MyLanguageModelOptions;
class MyContentFilterOptions;
class MyImageContentFilterSeverity;
class MyTextContentFilterSeverity;
class MyAIFeatureReadyResult;
class MyLanguageModel;

// Wrapper for LanguageModelResponseResult
class MyLanguageModelResponseResult : public Napi::ObjectWrap<MyLanguageModelResponseResult> {
public:
    static Napi::FunctionReference constructor;
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    MyLanguageModelResponseResult(const Napi::CallbackInfo& info);
    bool HasResult() const;

private:
    std::optional<LanguageModelResponseResult> m_result;
    
    Napi::Value GetText(const Napi::CallbackInfo& info);
    Napi::Value GetStatus(const Napi::CallbackInfo& info);
    Napi::Value GetExtendedError(const Napi::CallbackInfo& info);
};

// Wrapper for LanguageModelOptions
class MyLanguageModelOptions : public Napi::ObjectWrap<MyLanguageModelOptions> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    MyLanguageModelOptions(const Napi::CallbackInfo& info);
    LanguageModelOptions GetOptions() const;

private:
    LanguageModelOptions m_options;
    
    Napi::Value GetTemperature(const Napi::CallbackInfo& info);
    void SetTemperature(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetTopK(const Napi::CallbackInfo& info);
    void SetTopK(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetTopP(const Napi::CallbackInfo& info);
    void SetTopP(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetContentFilterOptions(const Napi::CallbackInfo& info);
    void SetContentFilterOptions(const Napi::CallbackInfo& info, const Napi::Value& value);
};

// Wrapper for ContentFilterOptions
class MyContentFilterOptions : public Napi::ObjectWrap<MyContentFilterOptions> {
public:
    static Napi::FunctionReference constructor;
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    MyContentFilterOptions(const Napi::CallbackInfo& info);
    ContentFilterOptions GetOptions() const;

private:
    ContentFilterOptions m_options;
    
    Napi::Value GetImageMaxAllowedSeverityLevel(const Napi::CallbackInfo& info);
    void SetImageMaxAllowedSeverityLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetPromptMaxAllowedSeverityLevel(const Napi::CallbackInfo& info);
    void SetPromptMaxAllowedSeverityLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetResponseMaxAllowedSeverityLevel(const Napi::CallbackInfo& info);
    void SetResponseMaxAllowedSeverityLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
};

// Wrapper for ImageContentFilterSeverity
class MyImageContentFilterSeverity : public Napi::ObjectWrap<MyImageContentFilterSeverity> {
public:
    static Napi::FunctionReference constructor;
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    MyImageContentFilterSeverity(const Napi::CallbackInfo& info);
    ImageContentFilterSeverity GetOptions() const;

private:
    ImageContentFilterSeverity m_options;
    
    Napi::Value GetAdultContentLevel(const Napi::CallbackInfo& info);
    void SetAdultContentLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetGoryContentLevel(const Napi::CallbackInfo& info);
    void SetGoryContentLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetRacyContentLevel(const Napi::CallbackInfo& info);
    void SetRacyContentLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetViolentContentLevel(const Napi::CallbackInfo& info);
    void SetViolentContentLevel(const Napi::CallbackInfo& info, const Napi::Value& value);
};

// Wrapper for TextContentFilterSeverity
class MyTextContentFilterSeverity : public Napi::ObjectWrap<MyTextContentFilterSeverity> {
public:
    static Napi::FunctionReference constructor;
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    MyTextContentFilterSeverity(const Napi::CallbackInfo& info);
    TextContentFilterSeverity GetOptions() const;

private:
    TextContentFilterSeverity m_options;
    
    Napi::Value GetHate(const Napi::CallbackInfo& info);
    void SetHate(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetSelfHarm(const Napi::CallbackInfo& info);
    void SetSelfHarm(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetSexual(const Napi::CallbackInfo& info);
    void SetSexual(const Napi::CallbackInfo& info, const Napi::Value& value);
    Napi::Value GetViolent(const Napi::CallbackInfo& info);
    void SetViolent(const Napi::CallbackInfo& info, const Napi::Value& value);
};

// Wrapper for AIFeatureReadyResult
class MyAIFeatureReadyResult : public Napi::ObjectWrap<MyAIFeatureReadyResult> {
public:
    static Napi::FunctionReference constructor;
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    MyAIFeatureReadyResult(const Napi::CallbackInfo& info);
    bool HasResult() const;

private:
    std::optional<AIFeatureReadyResult> m_result;
    
    Napi::Value GetError(const Napi::CallbackInfo& info);
    Napi::Value GetErrorDisplayText(const Napi::CallbackInfo& info);
    Napi::Value GetExtendedError(const Napi::CallbackInfo& info);
    Napi::Value GetStatus(const Napi::CallbackInfo& info);
};

// Wrapper for LanguageModel
class MyLanguageModel : public Napi::ObjectWrap<MyLanguageModel> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    static Napi::Value MyCreateAsync(const Napi::CallbackInfo& info);
    static Napi::Value MyGetReadyState(const Napi::CallbackInfo& info);
    static Napi::Value MyEnsureReadyAsync(const Napi::CallbackInfo& info);
    
    MyLanguageModel(const Napi::CallbackInfo& info);

private:
    std::shared_ptr<LanguageModel> m_languagemodel;
    
    Napi::Value MyGenerateResponseAsync(const Napi::CallbackInfo& info);
};