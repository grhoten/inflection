/*
 * Copyright 2017-2024 Apple Inc. All rights reserved.
 */
#pragma once

#include <inflection/dialog/fwd.hpp>
#include <inflection/dialog/SemanticFeature.hpp>
#include <inflection/Object.hpp>
#include <map>
#include <string>

/**
 * @brief Represents a display value with constraint values.
 * @details Typically a set of these are contained in SemanticFeatureModel_DisplayData.
 * The display value is valid for the constraints provided as semantic features.
 * @see SemanticFeatureConceptBase
 */
class INFLECTION_CLASS_API inflection::dialog::DisplayValue
    : public virtual ::inflection::Object
{
public:
    typedef ::inflection::Object super;

private:
    ::std::u16string displayString {  };
    ::std::map<SemanticFeature, ::std::u16string> constraintMap {  };

public:
    /**
     * Returns the display value.
     */
    virtual const ::std::u16string& getDisplayString() const;
    /**
     * Given the semantic feature, return the value
     * @param feature The semantic feature (constraint) to match.
     * @return null if not found
     */
    virtual const ::std::u16string* getFeatureValue(const SemanticFeature& feature) const;
    /**
     * Returns all possible constraint values for this display value.
     */
    virtual const ::std::map<::inflection::dialog::SemanticFeature, ::std::u16string>& getConstraintMap() const;
    bool operator==(const DisplayValue& o) const;
    bool operator!=(const DisplayValue& o) const;
    std::size_t operator()(const DisplayValue& displayValue) const noexcept;

    /**
     * Construct a display value with a string and the associated constraints.
     * @param displayString A value with no speak information.
     * @param constraintMap All constraints that match the displayString.
     */
    DisplayValue(const ::std::u16string& displayString, const ::std::map<SemanticFeature, ::std::u16string>& constraintMap);
    /**
     * Construct a display value with a string and not constraints.
     * @param value A value with no speak information.
     */
    explicit DisplayValue(const ::std::u16string& value);
    /**
     * Construct a display value with a SpeakableString.
     * @param value A SpeakableString
     * @param speakFeature The speakFeature from the SemanticFeatureModel that represents the SemanticFeature for the speak information for a SpeakableString.
     */
    DisplayValue(const SpeakableString& value, const SemanticFeature& speakFeature);
    /**
     * The destructor
     */
    ~DisplayValue() override;

private:
    DisplayValue& operator=(const DisplayValue& other) = delete;

    friend class SemanticFeatureModel;
};
