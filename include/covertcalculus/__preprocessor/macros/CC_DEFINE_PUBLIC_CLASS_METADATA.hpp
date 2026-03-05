#pragma once

#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_This.hpp>

#if defined(CC_DISABLE_METADATA)
    #define CC_DEFINE_PUBLIC_CLASS_METADATA(fully_qualified_namespace, simple_class_name) \
        CC_DEFINE_PUBLIC_This(simple_class_name)
#else
    #define CC_DEFINE_PUBLIC_CLASS_METADATA(fully_qualified_namespace, simple_class_name) \
        CC_DEFINE_PUBLIC_This(simple_class_name); \
        public: \
            struct $class final { \
                $class() = delete; \
            public: \
                using This = fully_qualified_namespace::simple_class_name; \
                static inline constexpr const char *Name = #simple_class_name; \
                static inline constexpr const char *QualifiedName = \
                    #fully_qualified_namespace "::" #simple_class_name; \
            };
#endif
