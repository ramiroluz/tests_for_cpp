#include "TestData.h"
#include "iostream"
using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( TestData );


void
TestData::setUp()
{
}


void
TestData::tearDown()
{
}

void
TestData::testConstructor()
{
  // Setup
  Data nascimento(14,1,2008);
  int esperado = (14*1000000)+(1*10000)+2008;
  int resultado = (nascimento.GetDia()*1000000);
  resultado += (nascimento.GetMes()*10000);
  resultado += nascimento.GetAno();

  // Check
  CPPUNIT_ASSERT_EQUAL( esperado, resultado );
}

void
TestData::testDiferencaAnos_MesMenor()
{
  // Set up
  Data nascimento(5,2,2008);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 3 );
}

void
TestData::testDiferencaAnos_MesMaior()
{
  // Set up
  Data nascimento(5,5,2008);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 2 );
}

void
TestData::testDiferencaAnos_MesmoMesDiaMenor()
{
  // Set up
  Data nascimento(2,3,2008);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 3 );
}

void
TestData::testDiferencaAnos_MesmoMesDiaMaior()
{
  // Set up
  Data nascimento(5,3,2008);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 2 );
}

void
TestData::testDiferencaAnos_MesmosMesDia()
{
  // Set up
  Data nascimento(3,3,2008);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 3 );
}

void
TestData::testDiferencaAnos_AniversarioSimao()
{
  // Set up
  Data nascimento(3,10,1976);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 34 );
}

void
TestData::testDiferencaAnos_AniversarioEistein()
{
  // Set up
  Data nascimento(14,3,1879);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 131 );
}

void
TestData::testDiferencaAnos_AniversarioNewton()
{
  // Set up
  Data nascimento(4,1,1643);

  // Process
  int diferenca = nascimento.Diferenca_Anos(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 368 );
}

void
TestData::testDiferencaDias_BissextoMesMenor()
{
  // Set up
  Data nascimento(5,2,2008);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 1122 );
}

void
TestData::testDiferencaDias_BissextoMesMaior()
{
  // Set up
  Data nascimento(5,5,2008);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 1032 );
}

void
TestData::testDiferencaDias_BissextoMesmoMesDiaMenor()
{
  // Set up
  Data nascimento(2,3,2008);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 1096 );
}

void
TestData::testDiferencaDias_BissextoMesmoMesDiaMaior()
{
  // Set up
  Data nascimento(5,3,2008);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 1093 );
}

void
TestData::testDiferencaDias_BissextoMesmosMesDia()
{
  // Set up
  Data nascimento(3,3,2008);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 1095 );
}

void
TestData::testDiferencaDias_MesMenor()
{
  // Set up
  Data nascimento(3,2,2001);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 3680 );
}

void
TestData::testDiferencaDias_AniversarioSimao()
{
  // Set up
  Data nascimento(3,10,1976);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 12569 );
}

void
TestData::testDiferencaDias_AniversarioEistein()
{
  // Set up
  Data nascimento(14,3,1879);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 48201 );
}
void
TestData::testDiferencaDias_AniversarioNewton()
{
  // Set up
  Data nascimento(4,1,1643);

  // Process
  int diferenca = nascimento.Diferenca_Dias(3,3,2011);

  // Check
  CPPUNIT_ASSERT( diferenca == 134467 );
}
