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

ADD_EXECUTABLE( SmoothnessI SmoothnessI.cpp ) 
TARGET_LINK_LIBRARIES( SmoothnessI ${CORELIBS} )

ADD_EXECUTABLE( Smoothness Smoothness.cpp ) 
TARGET_LINK_LIBRARIES( Smoothness ${CORELIBS} )

ADD_EXECUTABLE( SquareFreeI SquareFreeI.cpp ) 
TARGET_LINK_LIBRARIES( SquareFreeI ${CORELIBS} )

ADD_EXECUTABLE( SquareFree SquareFree.cpp ) 
TARGET_LINK_LIBRARIES( SquareFree ${CORELIBS} )

ADD_EXECUTABLE( CarmichaelI CarmichaelI.cpp ) 
TARGET_LINK_LIBRARIES( CarmichaelI ${CORELIBS} )

ADD_EXECUTABLE( Carmichael Carmichael.cpp ) 
TARGET_LINK_LIBRARIES( Carmichael ${CORELIBS} )

ADD_EXECUTABLE( PollardPm1I PollardPm1I.cpp ) 
TARGET_LINK_LIBRARIES( PollardPm1I ${CORELIBS} )

