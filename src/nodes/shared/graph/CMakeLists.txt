target_sources(
    "${NODES_SHARED_PROJECT_NAME}"
    PUBLIC
        graph.h
        node.h
        socket.h
        node_types.h
        factory.h
        parameters.h
    PRIVATE
        graph.cpp
        node.cpp
        socket.cpp
        factory.cpp
        parameters.cpp
)

add_subdirectory("sockets")
