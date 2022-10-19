#include "Detail/Smart Modules/SmartModules.hpp"

class CTestModule {
    public:
        static void Print( );
};

void CTestModule::Print( ) {
    std::cout << "Call CTestModule::Print( )" << std::endl;
}

int main( ) {
    std::cout << "Register test module" << std::endl;
    g_SmartModules->Register< CTestModule >( "CTestModule" );

    std::cout << "Get test module" << std::endl;
    const auto TestModule = g_SmartModules->Get< CTestModule >( "CTestModule" );

    std::cout << "Call from test module" << std::endl;
    TestModule->Print( );

    // Stop console
    std::cin.get( );
}