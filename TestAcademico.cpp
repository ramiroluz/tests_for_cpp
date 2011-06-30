// TestAcademico.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include <cppunit/portability/Stream.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/ui/text/TestRunner.h>

bool text_runner()
{
    // Get the top level suite from the registry
    CppUnit::Test *suite = 
        CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    // Adds the test to the list of test to run
    CppUnit::TextUi::TestRunner runner;

    runner.addTest( suite );

    // Change the default outputter to a compiler error format outputter
    runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
    // Run the tests.
    return runner.run();   
}

bool xml_runner()
{
    // Get the top level suite from the registry
    CppUnit::Test *suite = 
        CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    CppUnit::TextUi::TestRunner runner;
 
    runner.addTest( suite );

    std::ofstream file( "result.xml" );
    CppUnit::XmlOutputter* outputter =
       new CppUnit::XmlOutputter(&runner.result(), file);
    runner.setOutputter(outputter);

    // use the suite factory, then execute all tests
    return runner.run( "", false );
}

int main(int argc, char* argv[])
{
    // Run the tests.
    //bool wasSucessful = text_runner();
    bool wasSucessful = xml_runner();

    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;
}
