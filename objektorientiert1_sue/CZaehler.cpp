
#include "CZaehler.h"

CZaehler:: Czaehler()
{
  zaehler = 0;
}
void CZaehler:: erhoehe()
{
  zaehler = zaehler + 1;
}
int CZaehler:: getzaehlerstand()
{
  return zaehler;
}
