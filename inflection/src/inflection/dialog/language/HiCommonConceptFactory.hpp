/*
 * Copyright 2019-2024 Apple Inc. All rights reserved.
 */
#pragma once

#include <inflection/dialog/language/fwd.hpp>
#include <inflection/dialog/CommonConceptFactoryImpl.hpp>

class inflection::dialog::language::HiCommonConceptFactory
    : public CommonConceptFactoryImpl
{
public:
    typedef CommonConceptFactoryImpl super;
public:
    explicit HiCommonConceptFactory(const ::inflection::util::ULocale& language);
    ~HiCommonConceptFactory() override;
};
