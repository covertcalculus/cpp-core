#pragma once

#if defined(CC_DISABLE_METADATA)
    #define CC_NAMESPACE_METADATA(fully_qualified_parent_namespace, simple_namespace)
#else
    #define CC_NAMESPACE_METADATA(fully_qualified_parent_namespace, simple_namespace) \
        namespace $namespace {\
            constexpr inline const char *Name = #simple_namespace;\
            constexpr inline const char *QualifiedName = #fully_qualified_parent_namespace "::" #simple_namespace;\
            namespace Parent = fully_qualified_parent_namespace; \
            namespace This = fully_qualified_parent_namespace::simple_namespace; \
        }
#endif
