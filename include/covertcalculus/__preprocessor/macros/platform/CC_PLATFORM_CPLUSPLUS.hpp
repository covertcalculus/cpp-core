#pragma once

#if defined(_MSVC_LANG)
    #define CC_PLATFORM_CPLUSPLUS _MSVC_LANG
#else
    #define CC_PLATFORM_CPLUSPLUS __cplusplus
#endif
