#pragma once

#if defined(CC_DISABLE_METADATA)
    #define CC_ROOT_NAMESPACE_METADATA(simple_namespace)
#else
    #define CC_ROOT_NAMESPACE_METADATA(simple_namespace) \
        namespace $namespace { \
            constexpr inline const char *Name = #simple_namespace; \
            constexpr inline const char *QualifiedName = "::" #simple_namespace; \
        }
#endif