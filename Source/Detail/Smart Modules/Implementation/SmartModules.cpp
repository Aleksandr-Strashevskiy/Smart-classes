#include "../SmartModules.hpp"

namespace nDetail::nSmartModules {
    void CSmartModules::Release( ) {
        // Checks if the container has elements
        if ( !m_umModules.empty( ) ) {
            // Erases all elements from the container
            m_umModules.clear( );
            // Sets the number of buckets to null, to clear memory
            m_umModules.rehash( 0U );
        }
    }

    void CSmartModules::Unregister( const std::string_view strModuleName ) {
        // Removes element from the container
        m_umModules.erase( GetHash( strModuleName ) );
    }
}