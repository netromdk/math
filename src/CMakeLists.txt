SET( NAME math )

SET( SOURCES
     # Common
     PTypes.h
     Common.h 
     Common.cpp
     Mod.h
     Mod.cpp
     GCD.h
     GCD.cpp
     Random.h
     Random.cpp
     EulerTotient.h
     EulerTotient.cpp
     PrimeTable.h

     # Factorization
     PollardRho.h
     PollardRho.cpp

     # Sieving
     Eratosthenes.h
     Eratosthenes.cpp
     )

SET( CORELIBS
     ${GMP_LIBRARIES}
     )

### Build and link ####

ADD_LIBRARY( ${NAME} ${SOURCES} ) 
TARGET_LINK_LIBRARIES( ${NAME} ${CORELIBS} )
