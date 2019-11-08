#include "stdio.h"
#include "iomanip"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "string.h"
#include "vector"
#include "schoolmap.h"

using namespace std;

int main()
{
    SchoolMap *M=(SchoolMap *)malloc(sizeof(SchoolMap));
    init(*M);

    queryShortEdge(M);

    queryAllPos(M);
}
