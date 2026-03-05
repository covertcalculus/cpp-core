#pragma once

#include <covertcalculus/classes/mixins/crtp/metadata/__/namespace.hpp>
#include <covertcalculus/classes/mixins/crtp/metadata/ThisOf-T.hpp>

namespace covertcalculus::classes::mixins::crtp::metadata {
    template <typename T>
    struct InjectMetadata final
        : public ThisOf<T>
    {
        InjectMetadata() = delete;
    };
}