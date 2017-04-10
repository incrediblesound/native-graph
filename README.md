Native Graph
============

This is a native C++ graph module for Node.js. Currently it is just an experiment. Preliminary tests have shown small scale operations to take more or less the same amount of time as a lightweight vanilla JavaScript graph implementation. I plan to add more methods and do more performance testing.

How to Use
----------
Currently there are only five basic methods. The following code example uses all of them.

```javascript
const graph = require('graph')

/* inserting a node */
graph.insertNode('a')
graph.insertNode('b')

/* nodes are not zero indexed for now */
const node = graph.getById(1)
/* node === 'a' */

/* create an edge */
graph.insertEdge(1, 2)

const edge = graph.hasEdge(1, 2)
/* edge === true */

const sorted = graph.topologicalSort(1)
/* sorted === [2, 1] */

```
