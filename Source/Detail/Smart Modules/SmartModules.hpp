#ifndef DETAIL_SMARTMODULES_SMARTMODULES_HPP
#define DETAIL_SMARTMODULES_SMARTMODULES_HPP

#include <any>
#include <string_view>
#include <unordered_map>

namespace nDetail::nSmartModules {
    class CSmartModules {
        public:
            /**
             * \brief Removing all items from the container and clearing the memory
             */
            void Release( );

            /**
             * \brief Adding a new class to the container
             * \tparam Module The class to which we get a smart pointer
             * \param strModuleName The string storing the name of the module
             */
            template< class Module >
            void Register( std::string_view strModuleName );
            /**
             * \brief a
             * \param strModuleName a
             */
            void Unregister( std::string_view strModuleName );

            /**
             * \brief Get a unique pointer to the module
             * \tparam Module The class to which we get a smart pointer
             * \param strModuleName The string storing the name of the module
             * \return Returns pointer to module
             */
            template< class Module >
            Module *Get( std::string_view strModuleName );

        private:
            /**
             * \brief Simple hashing string using std::hash
             * \param strString The string for which we get the hash
             * \return Returns hash of the string
             */
            static std::size_t GetHash( std::string_view strString );

            /**
             * \brief Container that stores the string hash and a smart pointer to the class
             */
            std::unordered_map< std::size_t, std::any > m_umModules;
    };
}

#include "Implementation/SmartModules.inl"
#include "Implementation/SmartModules.ipp"

inline const auto g_SmartModules = std::make_unique< nDetail::nSmartModules::CSmartModules >( );

#endif // DETAIL_SMARTMODULES_SMARTMODULES_HPP