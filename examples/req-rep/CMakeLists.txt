 ################################################################################
 #    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    #
 #                                                                              #
 #              This software is distributed under the terms of the             #
 #              GNU Lesser General Public Licence (LGPL) version 3,             #
 #                  copied verbatim in the file "LICENSE"                       #
 ################################################################################

add_library(ExampleReqRepLib STATIC
    "Client.cxx"
    "Client.h"
    "Server.cxx"
    "Server.h"
)

target_link_libraries(ExampleReqRepLib PUBLIC FairMQ)

add_executable(fairmq-ex-req-rep-client runClient.cxx)
target_link_libraries(fairmq-ex-req-rep-client PRIVATE ExampleReqRepLib)


add_executable(fairmq-ex-req-rep-server runServer.cxx)
target_link_libraries(fairmq-ex-req-rep-server PRIVATE ExampleReqRepLib)

add_custom_target(ExampleReqRep DEPENDS fairmq-ex-req-rep-client fairmq-ex-req-rep-server)

install(
    TARGETS
    fairmq-ex-req-rep-client
    fairmq-ex-req-rep-server

    LIBRARY DESTINATION ${PROJECT_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${PROJECT_INSTALL_BINDIR}
)

# configure run script with different executable paths for build and for install directories
set(EX_BIN_DIR ${CMAKE_CURRENT_BINARY_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fairmq-start-ex-req-rep.sh.in ${CMAKE_CURRENT_BINARY_DIR}/fairmq-start-ex-req-rep.sh)
set(EX_BIN_DIR ${CMAKE_INSTALL_PREFIX}/${PROJECT_INSTALL_BINDIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fairmq-start-ex-req-rep.sh.in ${CMAKE_CURRENT_BINARY_DIR}/fairmq-start-ex-req-rep.sh_install)

install(
    PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/fairmq-start-ex-req-rep.sh_install
    DESTINATION ${PROJECT_INSTALL_BINDIR}
    RENAME fairmq-start-ex-req-rep.sh
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test-ex-req-rep.sh.in ${CMAKE_CURRENT_BINARY_DIR}/test-ex-req-rep.sh)

add_test(NAME Example-ReqRep COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test-ex-req-rep.sh)
set_tests_properties(Example-ReqRep PROPERTIES TIMEOUT "30" RUN_SERIAL true PASS_REGULAR_EXPRESSION "Received reply from server: ")