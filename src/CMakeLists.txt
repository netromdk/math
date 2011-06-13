SET( NAME math )

SET( SOURCES
     ### Common
     PTypes.h
     Constants.h
     Constants.cpp
     Common.h 
     Common.cpp
     Mod.h
     Mod.cpp
     GCD.h
     GCD.cpp
     LCM.h
     LCM.cpp
     Log.h
     Log.cpp
     Random.h
     Random.cpp
     EulerTotient.h
     EulerTotient.cpp
     PrimeTable.h
     SquareFree.h
     SquareFree.cpp

     ### Factorization
     PollardRho.h
     PollardRho.cpp
     PollardPm1.h
     PollardPm1.cpp
     Smooth.h
     Smooth.cpp
     Carmichael.h
     Carmichael.cpp

     ### Sieving
     Eratosthenes.h
     Eratosthenes.cpp
     )

SET( CORELIBS
     ${GMP_LIBRARIES}
     )

### Build and link ####

ADD_LIBRARY( ${NAME} ${SOURCES} ) 
TARGET_LINK_LIBRARIES( ${NAME} ${CORELIBS} )
