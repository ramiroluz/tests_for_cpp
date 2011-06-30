#ifndef TESTDATA_H
#define TESTDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Datas.h"

class TestData : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( TestData );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testDiferencaAnos_MesMenor );
  CPPUNIT_TEST( testDiferencaAnos_MesMaior );
  CPPUNIT_TEST( testDiferencaAnos_MesmoMesDiaMenor );
  CPPUNIT_TEST( testDiferencaAnos_MesmoMesDiaMaior );
  CPPUNIT_TEST( testDiferencaAnos_MesmosMesDia );
  CPPUNIT_TEST( testDiferencaAnos_AniversarioSimao );
  CPPUNIT_TEST( testDiferencaAnos_AniversarioEistein );
  CPPUNIT_TEST( testDiferencaAnos_AniversarioNewton );
  CPPUNIT_TEST( testDiferencaDias_BissextoMesMenor );
  CPPUNIT_TEST( testDiferencaDias_BissextoMesMaior );
  CPPUNIT_TEST( testDiferencaDias_BissextoMesmoMesDiaMenor );
  CPPUNIT_TEST( testDiferencaDias_BissextoMesmoMesDiaMaior );
  CPPUNIT_TEST( testDiferencaDias_BissextoMesmosMesDia );
  CPPUNIT_TEST( testDiferencaDias_MesMenor );
  CPPUNIT_TEST( testDiferencaDias_AniversarioSimao );
  CPPUNIT_TEST( testDiferencaDias_AniversarioEistein );
  CPPUNIT_TEST( testDiferencaDias_AniversarioNewton );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testDiferencaAnos_MesMenor();
  void testDiferencaAnos_MesMaior();
  void testDiferencaAnos_MesmoMesDiaMenor();
  void testDiferencaAnos_MesmoMesDiaMaior();
  void testDiferencaAnos_MesmosMesDia();
  void testDiferencaAnos_AniversarioSimao();
  void testDiferencaAnos_AniversarioEistein();
  void testDiferencaAnos_AniversarioNewton();
  void testDiferencaDias_BissextoMesMenor();
  void testDiferencaDias_BissextoMesMaior();
  void testDiferencaDias_BissextoMesmoMesDiaMenor();
  void testDiferencaDias_BissextoMesmoMesDiaMaior();
  void testDiferencaDias_BissextoMesmosMesDia();
  void testDiferencaDias_MesMenor();
  void testDiferencaDias_AniversarioSimao();
  void testDiferencaDias_AniversarioEistein();
  void testDiferencaDias_AniversarioNewton();

  void testAddThrow();

  void testConstructor();
};

#endif  // TESTDATA_H

