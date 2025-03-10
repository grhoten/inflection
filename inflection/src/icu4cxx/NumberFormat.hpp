/*
 * Copyright 2017-2024 Apple Inc. All rights reserved.
 */
// This is a generated file. Do not edit this file.
#pragma once
#include <string_view>
#include <inflection/exception/ICUException.hpp>
#include <inflection/exception/NullPointerException.hpp>
#include <unicode/unum.h>

namespace icu4cxx {
class NumberFormat {
public:
NumberFormat(UNumberFormatStyle style, std::u16string_view pattern, const char * locale, UParseError * parseErr) {
    UErrorCode ec = U_ZERO_ERROR;
    wrappee_ = unum_open(style, (const UChar *)pattern.data(), (int32_t)pattern.size(), locale, parseErr, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
}
~NumberFormat() noexcept {
    if (owned_) unum_close(wrappee_);
}
NumberFormat(NumberFormat &&other) noexcept : wrappee_(other.wrappee_), owned_(other.owned_) {
    other.wrappee_ = nullptr;
}
NumberFormat& operator=(NumberFormat &&other) noexcept {
    if (owned_) unum_close(wrappee_);
    wrappee_ = other.wrappee_;
    owned_ = other.owned_;
    other.wrappee_ = nullptr;
    other.owned_ = false;
    return *this;
}
NumberFormat(const NumberFormat &fmt) {
    UErrorCode ec = U_ZERO_ERROR;
    wrappee_ = unum_clone(fmt.wrappee_, &ec);
    owned_ = true;
    ::inflection::exception::ICUException::throwOnFailure(ec);
}
NumberFormat& operator=(const NumberFormat &other) noexcept {
    NumberFormat tmp(other);
    *this = std::move(tmp);
    return *this;
}
int32_t format(int32_t number, UChar * result, int32_t resultLength, UFieldPosition * pos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_format(wrappee_, number, result, resultLength, pos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t formatInt64(int64_t number, UChar * result, int32_t resultLength, UFieldPosition * pos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_formatInt64(wrappee_, number, result, resultLength, pos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t formatDouble(double number, UChar * result, int32_t resultLength, UFieldPosition * pos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_formatDouble(wrappee_, number, result, resultLength, pos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t formatDoubleForFields(double number, UChar * result, int32_t resultLength, UFieldPositionIterator * fpositer) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_formatDoubleForFields(wrappee_, number, result, resultLength, fpositer, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t formatDecimal(std::string_view number, UChar * result, int32_t resultLength, UFieldPosition * pos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_formatDecimal(wrappee_, (const char *)number.data(), (int32_t)number.size(), result, resultLength, pos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t formatDoubleCurrency(double number, UChar * currency, UChar * result, int32_t resultLength, UFieldPosition * pos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_formatDoubleCurrency(wrappee_, number, currency, result, resultLength, pos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t formatUFormattable(const UFormattable * number, UChar * result, int32_t resultLength, UFieldPosition * pos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_formatUFormattable(wrappee_, number, result, resultLength, pos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t parse(std::u16string_view text, int32_t * parsePos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_parse(wrappee_, (const UChar *)text.data(), (int32_t)text.size(), parsePos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int64_t parseInt64(std::u16string_view text, int32_t * parsePos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_parseInt64(wrappee_, (const UChar *)text.data(), (int32_t)text.size(), parsePos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
double parseDouble(std::u16string_view text, int32_t * parsePos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_parseDouble(wrappee_, (const UChar *)text.data(), (int32_t)text.size(), parsePos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t parseDecimal(std::u16string_view text, int32_t * parsePos, char * outBuf, int32_t outBufLength) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_parseDecimal(wrappee_, (const UChar *)text.data(), (int32_t)text.size(), parsePos, outBuf, outBufLength, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
double parseDoubleCurrency(std::u16string_view text, int32_t * parsePos, UChar * currency) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_parseDoubleCurrency(wrappee_, (const UChar *)text.data(), (int32_t)text.size(), parsePos, currency, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
UFormattable * parseToUFormattable(UFormattable * result, std::u16string_view text, int32_t * parsePos) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_parseToUFormattable(wrappee_, result, (const UChar *)text.data(), (int32_t)text.size(), parsePos, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
void applyPattern(bool localized, std::u16string_view pattern, UParseError * parseError) {
    UErrorCode ec = U_ZERO_ERROR;
    unum_applyPattern(wrappee_, localized, (const UChar *)pattern.data(), (int32_t)pattern.size(), parseError, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
}
static const char * getAvailable(int32_t localeIndex) {
    return unum_getAvailable(localeIndex);
}
static int32_t countAvailable() {
    return unum_countAvailable();
}
bool hasAttribute(UNumberFormatAttribute attr) const {
    return unum_hasAttribute(wrappee_, attr);
}
int32_t getAttribute(UNumberFormatAttribute attr) const {
    return unum_getAttribute(wrappee_, attr);
}
void setAttribute(UNumberFormatAttribute attr, int32_t newValue) {
    unum_setAttribute(wrappee_, attr, newValue);
}
double getDoubleAttribute(UNumberFormatAttribute attr) const {
    return unum_getDoubleAttribute(wrappee_, attr);
}
void setDoubleAttribute(UNumberFormatAttribute attr, double newValue) {
    unum_setDoubleAttribute(wrappee_, attr, newValue);
}
int32_t getTextAttribute(UNumberFormatTextAttribute tag, UChar * result, int32_t resultLength) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_getTextAttribute(wrappee_, tag, result, resultLength, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
void setTextAttribute(UNumberFormatTextAttribute tag, std::u16string_view newValue) {
    UErrorCode ec = U_ZERO_ERROR;
    unum_setTextAttribute(wrappee_, tag, (const UChar *)newValue.data(), (int32_t)newValue.size(), &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
}
int32_t toPattern(bool isPatternLocalized, UChar * result, int32_t resultLength) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_toPattern(wrappee_, isPatternLocalized, result, resultLength, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
int32_t getSymbol(UNumberFormatSymbol symbol, UChar * buffer, int32_t size) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_getSymbol(wrappee_, symbol, buffer, size, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
void setSymbol(UNumberFormatSymbol symbol, std::u16string_view value) {
    UErrorCode ec = U_ZERO_ERROR;
    unum_setSymbol(wrappee_, symbol, (const UChar *)value.data(), (int32_t)value.size(), &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
}
const char * getLocaleByType(ULocDataLocaleType type) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_getLocaleByType(wrappee_, type, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}
void setContext(UDisplayContext value) {
    UErrorCode ec = U_ZERO_ERROR;
    unum_setContext(wrappee_, value, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
}
UDisplayContext getContext(UDisplayContextType type) const {
    UErrorCode ec = U_ZERO_ERROR;
    auto retVal = unum_getContext(wrappee_, type, &ec);
    ::inflection::exception::ICUException::throwOnFailure(ec);
    return retVal;
}

UNumberFormat *wrappee_ {  };
NumberFormat(const UNumberFormat *other, bool owned = true) : wrappee_((UNumberFormat *)other), owned_(owned) {}
private:
bool owned_ = true;
};
} //namespace icu4xx 
