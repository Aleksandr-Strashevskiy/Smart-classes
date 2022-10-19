#ifndef DETAIL_SMARTMODULES_IMPLEMENTATION_SMARTMODULES_INL
#define DETAIL_SMARTMODULES_IMPLEMENTATION_SMARTMODULES_INL

#include "../SmartModules.hpp"

namespace nDetail::nSmartModules {
    inline std::size_t CSmartModules::GetHash( const std::string_view strString ) {
        // Get std::string_view hashed value
        return std::hash< std::string_view >{ }( strString );
    }
}

#endif // DETAIL_SMARTMODULES_IMPLEMENTATION_SMARTMODULES_INL