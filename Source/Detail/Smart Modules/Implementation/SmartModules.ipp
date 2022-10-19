#ifndef DETAIL_SMARTMODULES_IMPLEMENTATION_SMARTMODULES_IPP
#define DETAIL_SMARTMODULES_IMPLEMENTATION_SMARTMODULES_IPP

#include <functional>
#include <iostream>
#include <memory>

namespace nDetail::nSmartModules {
    template< class Module >
    void CSmartModules::Register( const std::string_view strModuleName ) {
        // Inserts a new element into the container with key and value constructed unique pointer
        m_umModules.try_emplace( GetHash( strModuleName ), std::move( std::make_unique< Module > ) );
    }

    template< class Module >
    Module *CSmartModules::Get( const std::string_view strModuleName ) {
        // Finds an element with key equivalent to key
        const auto Search = m_umModules.find( GetHash( strModuleName ) );

        // Check if an element with this hash exists
        if ( Search == m_umModules.end( ) )
            throw std::runtime_error( "Error, element not found" );

        // Cast to module type unique pointer
        return std::any_cast< Module >( &Search->second );
    }
}

#endif // DETAIL_SMARTMODULES_IMPLEMENTATION_SMARTMODULES_IPP