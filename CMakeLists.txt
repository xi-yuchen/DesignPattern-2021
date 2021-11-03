cmake_minimum_required(VERSION 3.20)
project(DesignPattern_2021)
set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./Customer/ SRC_LIST_CUSTOMER)
aux_source_directory(./Cart/ SRC_LIST_CART)
aux_source_directory(./Basic/ SRC_LIST_BASIC)
aux_source_directory(./AC_ADSystem/ SRC_LIST_AD)
aux_source_directory(./Commodity/ SRC_LIST_COMMODITY)
aux_source_directory(./Order/ SRC_LIST_ORDER)
#aux_source_directory(./Seller/ SRC_LIST_SELLER)
aux_source_directory(./Shop/ SRC_LIST_SHOP)
aux_source_directory(./ChainOfResponsibility/ SRC_COR)

#file(GLOB SRC_LIST_CUSTOMER "./Customer/*.*")
#file(GlOB SRC_LIST_CART "./Cart/*.*")
#file(GLOB SRC_LIST_BASIC "./Basic/*.*")
#file(GLOB SRC_LIST_AD "./AC_ADSystem/*.*")
#file(GLOB SRC_LIST_COMMODITY "./Commodity/*.*")
#file(GLOB SRC_LIST_ORDER "./Order/*.*")
#file(GLOB SRC_LIST_SELLER "./Seller/*.*")
#file(GLOB SRC_LIST_SHOP "./Shop/*.*")

#add_library(DPlib ${SRC_LIST_CUSTOMER} ${SRC_LIST_CART} ${SRC_LIST_BASIC} ${SRC_LIST_AD}
#            ${SRC_LIST_COMMODITY} ${SRC_LIST_ORDER} ${SRC_LIST_SELLER} ${SRC_LIST_SHOP})
add_executable(DesignPattern_2021
        ${SRC_LIST_CUSTOMER} ${SRC_LIST_CART} ${SRC_LIST_BASIC} ${SRC_LIST_AD}
        ${SRC_LIST_COMMODITY} ${SRC_LIST_ORDER} ${SRC_LIST_SELLER} ${SRC_LIST_SHOP} ${SRC_COR} Application.cpp)
#target_link_libraries(DesignPattern_2021 DPlib)
