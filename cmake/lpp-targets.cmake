if(NOT TARGET lpp::lpp)
        add_library(lpp::lpp INTERFACE IMPORTED)
        set_target_properties(lpp::lpp PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${lpp_INCLUDE_DIRS}"
                INTERFACE_LINK_LIBRARIES "${lpp_LIBRARIES}"
        )
endif()
