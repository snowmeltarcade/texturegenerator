# System Design
## Nodes
Textures are generated using nodes. Each node is a separate program, but with a common API, accepting both inputs and outputs. Nodes pass their outputs to the inputs of other nodes, which then process those inputs to create their own outputs. There is no limit on how many nodes one node may call. Nodes are stateless, so a node can call itself recursively and is able to be called in parallel. They can be run either locally on a single machine as separate processes, or in docker containers on a distributed system.

The calling of nodes is controlled by a graph. This graph is passed to the first node in the tree, which then uses the graph to decide which nodes to call next.

The graph can be created by either a UI or in plain text.

A node has three types of inputs and two types of outputs:

#### Inputs
1. Graph
   1. Origin - The point in space the function should act on. This acts as the _bottom left_ of the frame
   2. Frame width - The number of pixels wide that should be generated
   3. Frame height - The number of pixels high that should be generated
2. Socket
3. Parameters

#### Outputs
1. Socket
2. Preview

## Image Generation
Images are generated either on the CPU or the GPU. The GPU will be utilized if a GPU is available, else the CPU will be used. If a node only supports a GPU but a GPU is not available, the node will simply pass the input to the output.

## Technologies
The nodes will be written in C++17 (soon to be C++20). GPU graphics will be OpenGL using GLSL.
