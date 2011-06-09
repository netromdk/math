### Libs ###

SET( CORELIBS math )
LINK_DIRECTORIES( ${PROJECT_BINARY_DIR} )
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/src )

### Build and link ####

ADD_EXECUTABLE( PollardRhoI PollardRhoI.cpp ) 
TARGET_LINK_LIBRARIES( PollardRhoI ${CORELIBS} )

ADD_EXECUTABLE( PollardRho PollardRho.cpp ) 
TARGET_LINK_LIBRARIES( PollardRho ${CORELIBS} )

ADD_EXECUTABLE( PollardRhoFactor PollardRhoFactor.cpp ) 
TARGET_LINK_LIBRARIES( PollardRhoFactor ${CORELIBS} )

ADD_EXECUTABLE( EratosthenesRangeI EratosthenesRangeI.cpp ) 
TARGET_LINK_LIBRARIES( EratosthenesRangeI ${CORELIBS} )

ADD_EXECUTABLE( EratosthenesRange EratosthenesRange.cpp ) 
TARGET_LINK_LIBRARIES( EratosthenesRange ${CORELIBS} )

