/*
 * Copyright 2016-2024 Apple Inc. All rights reserved.
 */
#pragma once

#include <inflection/lang/features/fwd.hpp>
#include <inflection/Object.hpp>
#include <inflection/lang/features/LanguageGrammarFeatures_Feature.hpp>
#include <string>
#include <vector>

/**
 * @brief A named feature with a possible set of feature values.
 * @details
 * Grammatical features are usually a set of possible words that need to be in grammatical agreement with semantic concepts.
 * Frequently they are articles, prepositions and measure words. These values are typically based (constrained)
 * on the grammatical category values of the nouns.
 */
class INFLECTION_CLASS_API inflection::lang::features::LanguageGrammarFeatures_GrammarFeatures
    : public virtual inflection::Object
{
public:
    typedef ::inflection::Object super;

private:
    std::u16string name {  };
    std::vector<::inflection::lang::features::LanguageGrammarFeatures_Feature> values {  };

public:
    /**
     * The name of the grammatical feature.
     */
    std::u16string getName() const;
    /**
     * If this feature is bounded, these are the valid values.
     */
    std::vector<::inflection::lang::features::LanguageGrammarFeatures_Feature> getValues() const;
    virtual int32_t compareTo(const LanguageGrammarFeatures_GrammarFeatures& o) const;
    bool operator<(const LanguageGrammarFeatures_GrammarFeatures& other) const;

protected: /* package */
    LanguageGrammarFeatures_GrammarFeatures(const std::u16string& name, const std::vector<::inflection::lang::features::LanguageGrammarFeatures_Feature>& values);
public:
    /**
     * Destructor
     */
    ~LanguageGrammarFeatures_GrammarFeatures() override;

private:
    friend class LanguageGrammarFeatures;
};
