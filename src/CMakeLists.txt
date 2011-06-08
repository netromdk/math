SET( NAME math )

SET( SOURCES
     # Common
     PTypes.h
     Mod.h
     Mod.cpp
     GCD.h
     GCD.cpp
     Random.h
     Random.cpp

     # Factorization
     PollardRho.h
     PollardRho.cpp
     )

### Build and link ####

ADD_LIBRARY( ${NAME} ${SOURCES} ) 
