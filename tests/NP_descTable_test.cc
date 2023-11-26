// name=NP_descTable_test ; gcc $name.cc -std=c++11 -lstdc++ -I.. -o /tmp/$name && /tmp/$name

#include "NPX.h"

const char* STR = R"LITERAL(
array([[    0,   209,   223,   265,   265,   489,   505,   522,   723,  2097,  2097, 63816, 63919],
       [    0,   231,   244,   284,   284,   285,   368,   394,   590,   633,   633, 57248, 57356],
       [    0,   233,   245,   285,   285,   286,   351,   380,   638,   681,   681, 57402, 57480],
       [    0,   133,   170,   173,   173,   175,   259,   305,   844, 30887, 30888, 60904, 60961],
       [    0,   187,   226,   229,   230,   232,   396,   471,  1188, 33499, 33500, 63340, 63406],
       [    0,   170,   210,   214,   215,   217,   294,   328,   634, 31164, 31164, 60558, 60630],
       [    0,   131,   171,   174,   175,   177,   237,   273,   570, 32739, 32740, 62156, 62219],
       [    0,   136,   175,   179,   179,   181,   242,   292,   827, 32244, 32244, 62329, 62389],
       [    0,   135,   175,   179,   179,   181,   247,   281,   597, 32904, 32904, 62951, 63012],
       [    0,   132,   170,   174,   175,   177,   237,   271,   565, 32285, 32285, 62043, 62105]])
)LITERAL" ; 


const char* COLUMNS = R"LITERAL(
t_BeginOfEvent
t_setGenstep_0
t_setGenstep_1
t_setGenstep_2
t_setGenstep_3
t_setGenstep_4
t_setGenstep_5
t_setGenstep_6
t_setGenstep_7
t_setGenstep_8
t_PreLaunch
t_PostLaunch
t_EndOfEvent
)LITERAL" ; 

const char* ROWS = R"LITERAL(
p001
p002
p003
p004
p005
p006
p007
p008
p009
p010
)LITERAL" ; 


int main()
{
    std::vector<std::string> cols ; 
    U::LineVector(cols, COLUMNS); 

    std::vector<std::string> rows ; 
    U::LineVector(rows, ROWS); 

    NP* a = NPX::FromNumpyString<int>(STR) ; 
    std::cout << " a " << ( a ? a->sstr() : "-" ) << std::endl ; 

    std::cout 
        << " a->descTable " 
        << std::endl 
        << a->descTable<int>(7, &cols, &rows )
        << std::endl 
        ;

    return 0 ; 
}

 

